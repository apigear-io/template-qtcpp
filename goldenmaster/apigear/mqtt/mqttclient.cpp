#include "mqttclient.h"

#include <QtCore>
#include <QMultiMap>
#include <QtMqtt>

#include "mqtt_common.h"
#include <nlohmann/json.hpp>
#include "payloadconverter.h"
#include "private/multimap_helper.h"

#include <memory>
namespace ApiGear {
namespace Mqtt {

namespace {
const bool noRetain = false;
const quint8 QoS = 2;
}


Client::Client(QString id, QObject *parent)
{
    m_client.setClientId(id);
    m_client.setProtocolVersion(QMqttClient::MQTT_5_0);

    connect(this, &Client::messageToWriteWithProperties, this, &Client::writeMessageWithProperties, Qt::QueuedConnection);
    connect(this, &Client::messageToWrite, this, &Client::writeMessage, Qt::QueuedConnection);

    connect(&m_client, &QMqttClient::stateChanged, this, &Client::handleClientStateChanged);

    connect(this, &Client::subscribeTopicSignal, this, &Client::onSubscribeTopic, Qt::QueuedConnection);
    connect(this, &Client::subscribeForInvokeResponseSignal, this, &Client::onSubscribeForInvokeResponse, Qt::QueuedConnection);
    connect(this, &Client::unsubscribeTopic, this, &Client::onUnsubscribedTopic, Qt::QueuedConnection);
}

void Client::writeMessageWithProperties(const QMqttTopicName& topic, const QByteArray& message, const QMqttPublishProperties &properties)
{
    m_client.publish(topic, properties, message, QoS, noRetain);
}

void Client::writeMessage(const QMqttTopicName& topic, const QByteArray& message)
{
    m_client.publish(topic, message, QoS, noRetain);
}

void Client::onSubscribeTopic(quint64 id, const QString &topic, subscribeCallback callback)
{
    auto subscription = m_client.subscribe(topic, QoS);
    auto subscribedTopic = subscription->topic();
    if (!m_subscriptions.contains(subscribedTopic))
    {
        connect(subscription, &QMqttSubscription::messageReceived,
                [this](const QMqttMessage& message)
                {
                    auto subscription = multimap_helper::find_first_with_matching_topic(m_subscriptions.begin(), m_subscriptions.end(), message.topic());
                    while (subscription != m_subscriptions.end() && subscription.key().match(message.topic()))
                    {
                        if (subscription.value().second)
                        {
                            auto arguments = PayloadConverter::fromPayload(message.payload());
                            subscription.value().second(arguments);
                        }
                        subscription++;
                    }
                });

    }
    m_subscriptions.insert(subscription->topic(), std::make_pair(id, callback));
}

void Client::onSubscribeForInvokeResponse(quint64 id, const QString &topic)
{
    auto subscription = m_client.subscribe(topic, QoS);
    auto topicFilter = subscription->topic();
    if (!m_invokeReplySubscriptions.contains(topicFilter))
    {
        connect(subscription, &QMqttSubscription::messageReceived, this, &Client::handleInvokeResp);
    }
    m_invokeReplySubscriptions.insert(topicFilter, id);
}

void Client::onUnsubscribedTopic(quint64 subscriptionId)
{
    auto removeSubscription = [this](auto& container, auto subscribedItem)
    {
        if (subscribedItem != container.end())
        {
            auto topic = subscribedItem.key();
            container.erase(subscribedItem);
            auto values = container.values(topic);
            if (values.empty())
            {
                m_client.unsubscribe(topic);
            }
        }
    };
    auto subscribedInPropertiesAndSignals = std::find_if(m_subscriptions.begin(), m_subscriptions.end(), 
        [subscriptionId](auto& element){ return element.first == subscriptionId;});
    removeSubscription(m_subscriptions, subscribedInPropertiesAndSignals);
    auto subscribedInInvokeReplies= std::find_if(m_invokeReplySubscriptions.begin(), m_invokeReplySubscriptions.end(), 
        [subscriptionId](auto& element){ return element == subscriptionId;});
    removeSubscription(m_invokeReplySubscriptions, subscribedInInvokeReplies);
}

bool Client::isReady() const
{
    return m_client.state() == QMqttClient::ClientState::Connected;
}

QString Client::clientId() const
{
    return m_client.clientId();
}

void Client::connectToHost(QString hostAddress,int port)
{
    m_client.setHostname(hostAddress);
    m_client.setPort(port);
    m_client.connectToHost();

}

quint64 Client::subscribeTopic(const QString &topic, subscribeCallback callback)
{
    auto id = subscriptionIdGenerator.getId();
    subscribeTopicSignal(id, topic, callback);
    return id;
}

quint64 Client::subscribeForInvokeResponse(const QString &topic)
{
    auto id = subscriptionIdGenerator.getId();
    subscribeForInvokeResponseSignal(id, topic);
    return id;
}

void Client::setRemoteProperty(const QMqttTopicName& topic, const nlohmann::json& value)
{
    messageToWrite(topic, PayloadConverter::toPayload(value));
}

void Client::invokeRemote(const QMqttTopicName& topic,
    const nlohmann::json& arguments,
    const QString& responseTopic,
    quint64  subscriptionId,
    std::function<void(nlohmann::json)> resp)
{
    QMqttPublishProperties properties;
    properties.setResponseTopic(responseTopic);
    auto callId = functionCallIdGenerator.getId();
    auto correlationInfo = PayloadConverter::toPayload(&callId);
    properties.setCorrelationData(correlationInfo);
    m_pendingInvokeReplies.insert(callId, std::make_pair(subscriptionId, resp));
    messageToWriteWithProperties(topic, PayloadConverter::toPayload(arguments), properties);
}

void Client::invokeRemoteNoResponse(const QMqttTopicName& topic, const nlohmann::json& arguments)
{
    messageToWrite(topic, PayloadConverter::toPayload(arguments));
}

void Client::disconnect()
{
    unsubscribeAll();
    m_client.disconnectFromHost();
}

void Client::handleInvokeResp(const QMqttMessage& message)
{
    auto callIdDataArray = message.publishProperties().correlationData();
    quint64 callId;
    PayloadConverter::fromPayload(callIdDataArray, &callId);

    auto pendingReply = m_pendingInvokeReplies.find(callId);
    if (pendingReply != m_pendingInvokeReplies.end())
    {   auto topic = message.topic();
        auto subscriptionId = pendingReply.value().first;
        auto subscription = std::find_if(m_invokeReplySubscriptions.begin(),
                                         m_invokeReplySubscriptions.end(),
                                         [subscriptionId](auto& element) {return element == subscriptionId; });
        bool isSubscriptionStillValid = subscription != m_invokeReplySubscriptions.end();
        if (isSubscriptionStillValid)
        {
            if (pendingReply->second)
            {
                nlohmann::json arguments = PayloadConverter::fromPayload(message.payload());
                pendingReply.value().second(arguments);
            }
        }
        m_pendingInvokeReplies.erase(pendingReply);
    }
}

void Client::handleClientStateChanged(QMqttClient::ClientState state)
{
    if (state == QMqttClient::Connected)
    {
        if (!m_subscriptions.empty() || !m_invokeReplySubscriptions.empty())
        {
            unsubscribeAll();
        }
        emit ready();
    }
    else if (state == QMqttClient::Disconnected)
    {
        emit disconnected();
    }
}

void Client::unsubscribeAll()
{
    for (auto item = m_subscriptions.keyBegin(); item != m_subscriptions.keyEnd(); item++)
    {
        m_client.unsubscribe(*item);
    }
    for (auto item = m_invokeReplySubscriptions.keyBegin(); item != m_invokeReplySubscriptions.keyEnd(); item++)
    {
        m_client.unsubscribe(*item);
    }
    m_subscriptions.clear();
    m_invokeReplySubscriptions.clear();
}

}} // namespace ApiGear::Mqtt

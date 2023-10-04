/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "mqttservice.h"

#include "private/multimap_helper.h"
#include "payloadconverter.h"

namespace ApiGear {
namespace Mqtt {



namespace {
const bool noRetain = false;
const bool withRetain = true;
const quint8 QoS = 2;
}


ServiceAdapter::ServiceAdapter(QString id, QObject* parent)
{
    m_client.setClientId(id);
    m_client.setProtocolVersion(QMqttClient::MQTT_5_0);
    connect(this, &ServiceAdapter::messageToWriteWithProperties, this, &ServiceAdapter::writeMessageWithProperties, Qt::QueuedConnection);
    connect(this, &ServiceAdapter::messageToWrite,this, &ServiceAdapter::writeMessage, Qt::QueuedConnection);
    connect(&m_client, &QMqttClient::stateChanged, this, &ServiceAdapter::handleClientStateChanged);
    connect(this, &ServiceAdapter::subscribeTopicSignal, this, &ServiceAdapter::onSubscribeTopic, Qt::QueuedConnection);
    connect(this, &ServiceAdapter::subscribeForInvokeTopicSignal, this, &ServiceAdapter::onSubscribeForInvokeTopic, Qt::QueuedConnection);
    connect(this, &ServiceAdapter::unsubscribeTopic, this, &ServiceAdapter::onUnsubscribeTopic, Qt::QueuedConnection);
}

ServiceAdapter::~ServiceAdapter()
{
    for (auto subscriptionIter = m_subscriptions.begin(); subscriptionIter != m_subscriptions.end(); subscriptionIter++)
    {
        auto topic = subscriptionIter.key();
        m_client.unsubscribe(topic);
    }
    for (auto subscriptionIter = m_invokeSubscriptions.begin(); subscriptionIter != m_invokeSubscriptions.end(); subscriptionIter++)
    {
        auto topic = subscriptionIter.key();
        m_client.unsubscribe(topic);
    }
}

void ServiceAdapter::writeMessageWithProperties(const QMqttTopicName& topic, const QByteArray& message, const QMqttPublishProperties &properties)
{
    m_client.publish(topic, properties, message, QoS, noRetain);
}

void ServiceAdapter::writeMessage(const QMqttTopicName& topic, const QByteArray& message, bool retain)
{
    m_client.publish(topic, message, QoS, retain);
}

void ServiceAdapter::onSubscribeTopic(quint64 id, const QString &topic, SimpleSubscribeCallback callback)
{
    auto subscription = m_client.subscribe(topic, QoS);
    auto subscribedTopic = subscription->topic();
    if (!m_subscriptions.contains(subscription->topic()))
    {
        connect(subscription, &QMqttSubscription::messageReceived, [this](const QMqttMessage& message)
            {
                auto subscription = multimap_helper::find_first_with_matching_topic(m_subscriptions.begin(), m_subscriptions.end(), message.topic());
                while (subscription != m_subscriptions.end() && subscription.key().match(message.topic()))
                {
                    if (subscription.value().second)
                    {
                        // Assumes payload is single value.
                        auto element = PayloadConverter::fromPayload(message.payload());
                        subscription.value().second(element);
                    }
                    subscription++;
                }
            });
    }
    m_subscriptions.insert(subscription->topic(), std::make_pair(id, callback));
}

void ServiceAdapter::onSubscribeForInvokeTopic(quint64 id, const QString &topic, InvokeSubscribeCallback callback)
{
    auto subscription = m_client.subscribe(topic, QoS);
    auto topicFilter = subscription->topic();
    if (!m_invokeSubscriptions.contains(topicFilter))
    {
        connect(subscription, &QMqttSubscription::messageReceived, this, &ServiceAdapter::handleInvoke);
    }
    m_invokeSubscriptions.insert(topicFilter, std::make_pair(id, callback));
}

bool ServiceAdapter::isReady() const
{
    return m_client.state() == QMqttClient::ClientState::Connected;
}

QString ServiceAdapter::clientId() const
{
    return m_client.clientId();
}

void ServiceAdapter::connectToHost(QString hostAddress,int port)
{
    m_client.setHostname(hostAddress);
    m_client.setPort(port);
    m_client.connectToHost();

}

quint64 ServiceAdapter::subscribeTopic(const QString &topic, std::function<void(const nlohmann::json&)> callback)
{
    auto id = subscriptionIdGenerator.getId();
    subscribeTopicSignal(id, topic, callback);
    return id;
}

quint64 ServiceAdapter::subscribeForInvokeTopic(const QString &topic, std::function<nlohmann::json(const nlohmann::json&)> callback){

    auto id = subscriptionIdGenerator.getId();
    subscribeForInvokeTopicSignal(id,topic, callback);
    return id;
}

void ServiceAdapter::onUnsubscribeTopic(quint64 subscriptionId)
{
    auto removeSubscription = [this, subscriptionId](auto& container)
    {
        auto found = std::find_if(container.begin(), container.end(), [subscriptionId](auto& element) { return element.first == subscriptionId; });
        if (found != container.end())
        {
            auto topic = found.key();
            container.erase(found);
            auto values = container.values(topic);
            if (values.empty())
            {
                m_client.unsubscribe(topic);
            }
        }
    };
    removeSubscription(m_subscriptions);
    removeSubscription(m_invokeSubscriptions);
};

void ServiceAdapter::emitPropertyChange(const QMqttTopicName& topic, const nlohmann::json& value)
{
    messageToWrite(topic, PayloadConverter::toPayload(value), withRetain);
}

void ServiceAdapter::emitSignalChange(const QMqttTopicName& topic, const nlohmann::json& arguments)
{
    messageToWrite(topic, PayloadConverter::toPayload(arguments), noRetain);
}

void ServiceAdapter::disconnect()
{
    m_client.disconnectFromHost();
}

void ServiceAdapter::handleInvoke(const QMqttMessage& message)
{
    auto callIdDataArray = message.publishProperties().correlationData();
    auto responseTopic = message.publishProperties().responseTopic();
    auto messageTopic = message.topic();
    auto subscriptionIter = m_invokeSubscriptions.end();
    for (subscriptionIter = m_invokeSubscriptions.begin(); subscriptionIter!= m_invokeSubscriptions.end(); subscriptionIter++)
    {
        if (subscriptionIter.key().match(messageTopic))
            break;
    }
    while (subscriptionIter != m_invokeSubscriptions.end() && subscriptionIter.key().match(messageTopic))
    {
        if (subscriptionIter->second)
        {
            auto arguments = PayloadConverter::fromPayload(message.payload());
            // Assumes payload is an array of arguments.
            auto response = subscriptionIter->second(arguments);
            if (!responseTopic.isEmpty())
            {
                QMqttPublishProperties properties;
                properties.setCorrelationData(callIdDataArray);
                messageToWriteWithProperties(responseTopic, PayloadConverter::toPayload(response), properties);
            }
            return;
        }
        subscriptionIter++;
    }
}

void ServiceAdapter::handleClientStateChanged(QMqttClient::ClientState state)
{
    if (state == QMqttClient::Connected)
    {
        if (!m_subscriptions.empty() || !m_invokeSubscriptions.empty())
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

void ServiceAdapter::unsubscribeAll()
{
    for (auto item = m_subscriptions.keyBegin(); item != m_subscriptions.keyEnd(); item++)
    {
        m_client.unsubscribe(*item);
    }
    for (auto item = m_invokeSubscriptions.keyBegin(); item != m_invokeSubscriptions.keyEnd(); item++)
    {
        m_client.unsubscribe(*item);
    }
    m_subscriptions.clear();
    m_invokeSubscriptions.clear();
}

}} // namespace ApiGear::Mqtt

/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "mqttcounter.h"

#include "counter/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace counter {

namespace
{
const QString InterfaceName = "counter/Counter";
}

MqttCounter::MqttCounter(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractCounter(parent)
    , m_vector(custom_types::Vector3D())
    , m_extern_vector(QVector3D())
    , m_finishedInitialization(false)
    , m_client(client)
{
    if (m_client.isReady())
    {
        subscribeForPropertiesChanges();
        subscribeForInvokeResponses();
    }
     connect(&m_client, &ApiGear::Mqtt::Client::ready, [this](){
        AG_LOG_DEBUG(Q_FUNC_INFO);
            subscribeForPropertiesChanges();
            subscribeForInvokeResponses();
            m_finishedInitialization = true;
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
    m_finishedInitialization = m_client.isReady();
}

MqttCounter::~MqttCounter()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

bool MqttCounter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}

void MqttCounter::setVector(const custom_types::Vector3D& vector)
{
    static const QString topic = interfaceName() + QString("/set/vector");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( vector ));
}

void MqttCounter::setVectorLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_vector(value.get<custom_types::Vector3D>());
    if (m_vector != in_vector)
    {
        m_vector = in_vector;
        emit vectorChanged(in_vector);
    }
}

custom_types::Vector3D MqttCounter::vector() const
{
    return m_vector;
}

void MqttCounter::setExternVector(const QVector3D& extern_vector)
{
    static const QString topic = interfaceName() + QString("/set/extern_vector");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( extern_vector ));
}

void MqttCounter::setExternVectorLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_extern_vector(value.get<QVector3D>());
    if (m_extern_vector != in_extern_vector)
    {
        m_extern_vector = in_extern_vector;
        emit extern_vectorChanged(in_extern_vector);
    }
}

QVector3D MqttCounter::extern_vector() const
{
    return m_extern_vector;
}

QVector3D MqttCounter::increment(const QVector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = incrementAsync(vec);
    future.waitForFinished();
    return future.result();
}

QFuture<QVector3D> MqttCounter::incrementAsync(const QVector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/increment");
    auto promise = std::make_shared<QPromise<QVector3D>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QVector3D());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QVector3D());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({vec });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QVector3D value = arg.get<QVector3D>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

custom_types::Vector3D MqttCounter::decrement(const custom_types::Vector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = decrementAsync(vec);
    future.waitForFinished();
    return future.result();
}

QFuture<custom_types::Vector3D> MqttCounter::decrementAsync(const custom_types::Vector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/decrement");
    auto promise = std::make_shared<QPromise<custom_types::Vector3D>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(custom_types::Vector3D());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(custom_types::Vector3D());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({vec });       

    auto func = [promise](const nlohmann::json& arg)
        {
            custom_types::Vector3D value = arg.get<custom_types::Vector3D>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttCounter::interfaceName()
{
    return InterfaceName;
}

void MqttCounter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
{
    if (!hasSucceed)
    {
        AG_LOG_WARNING("Subscription failed for  "+ topic+". Try reconnecting the client.");
        return;
    }
    auto iter = std::find_if(m_pendingSubscriptions.begin(), m_pendingSubscriptions.end(), [topic](auto element){return topic == element;});
    if (iter == m_pendingSubscriptions.end()){
         AG_LOG_WARNING("Subscription failed for  "+ topic+". Try reconnecting the client.");
        return;
    }
    m_pendingSubscriptions.erase(iter);
    if (m_finishedInitialization && m_pendingSubscriptions.empty())
    {
        emit ready();
    }
}
void MqttCounter::subscribeForPropertiesChanges()
{
        // Subscription may succeed, before finising the function that subscribes it and assigns an id for if it was already added (and succeeded) for same topic,
        // hence, for pending subscriptions a topic is used, and added before the subscribe function.
        const QString topicvector = interfaceName() + "/prop/vector";
        m_pendingSubscriptions.push_back(topicvector);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicvector,
            [this, topicvector](auto id, bool hasSucceed){handleOnSubscribed(topicvector, id, hasSucceed);},
            [this](auto& value) { setVectorLocal(value);}));
        const QString topicextern_vector = interfaceName() + "/prop/extern_vector";
        m_pendingSubscriptions.push_back(topicextern_vector);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicextern_vector,
            [this, topicextern_vector](auto id, bool hasSucceed){handleOnSubscribed(topicextern_vector, id, hasSucceed);},
            [this](auto& value) { setExternVectorLocal(value);}));
}
void MqttCounter::subscribeForInvokeResponses()
{
    const QString topicincrement = interfaceName() + "/rpc/increment";
    const QString topicincrementInvokeResp = interfaceName() + "/rpc/increment"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicincrementInvokeResp);
    auto id_increment = m_client.subscribeForInvokeResponse(topicincrementInvokeResp, 
                        [this, topicincrementInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicincrementInvokeResp, id, hasSucceed);},
                        [this, topicincrementInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicincrementInvokeResp);
                        });
    m_InvokeCallsInfo[topicincrement] = std::make_pair(topicincrementInvokeResp, id_increment);
    const QString topicdecrement = interfaceName() + "/rpc/decrement";
    const QString topicdecrementInvokeResp = interfaceName() + "/rpc/decrement"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicdecrementInvokeResp);
    auto id_decrement = m_client.subscribeForInvokeResponse(topicdecrementInvokeResp, 
                        [this, topicdecrementInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicdecrementInvokeResp, id, hasSucceed);},
                        [this, topicdecrementInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicdecrementInvokeResp);
                        });
    m_InvokeCallsInfo[topicdecrement] = std::make_pair(topicdecrementInvokeResp, id_decrement);
}

void MqttCounter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_client.unsubscribeTopic(id);
    }
    for(auto info :m_InvokeCallsInfo)
    {
        m_client.unsubscribeTopic(info.second.second);
    }
}

void MqttCounter::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
{
    std::function <void(const nlohmann::json&)> function;
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    auto call = m_pendingCallsInfo.find(callId);
    if (call!= m_pendingCallsInfo.end())
    {
        if (call->second.first == topic)
        {
            function = call->second.second;
            m_pendingCallsInfo.erase(call);
            lock.unlock();
        }
        else
        {
            lock.unlock();
            static std::string log = "Your call went wrong. An answear is no longer expected for ";
            AG_LOG_WARNING(log);
            AG_LOG_WARNING(topic.toStdString());
        }
    }
    if (function) function(value);
}

} // namespace counter

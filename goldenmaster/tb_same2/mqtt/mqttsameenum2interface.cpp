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

#include "mqttsameenum2interface.h"

#include "tb_same2/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_same2 {

namespace
{
const QString InterfaceName = "tb.same2/SameEnum2Interface";
}

MqttSameEnum2Interface::MqttSameEnum2Interface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value1)
    , m_finishedInitialization(false)
    , m_client(client)
{
    if (m_client.isReady())
    {
        subscribeForPropertiesChanges();
        subscribeForSignals();
        subscribeForInvokeResponses();
    }
     connect(&m_client, &ApiGear::Mqtt::Client::ready, [this](){
        AG_LOG_DEBUG(Q_FUNC_INFO);
            subscribeForPropertiesChanges();
            subscribeForSignals();
            subscribeForInvokeResponses();
            m_finishedInitialization = true;
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
    m_finishedInitialization = m_client.isReady();
}

MqttSameEnum2Interface::~MqttSameEnum2Interface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

bool MqttSameEnum2Interface::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}

void MqttSameEnum2Interface::setProp1(Enum1::Enum1Enum prop1)
{
    static const QString topic = interfaceName() + QString("/set/prop1");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop1 ));
}

void MqttSameEnum2Interface::setProp1Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop1(value.get<Enum1::Enum1Enum>());
    if (m_prop1 != in_prop1)
    {
        m_prop1 = in_prop1;
        emit prop1Changed(in_prop1);
    }
}

Enum1::Enum1Enum MqttSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void MqttSameEnum2Interface::setProp2(Enum2::Enum2Enum prop2)
{
    static const QString topic = interfaceName() + QString("/set/prop2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop2 ));
}

void MqttSameEnum2Interface::setProp2Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop2(value.get<Enum2::Enum2Enum>());
    if (m_prop2 != in_prop2)
    {
        m_prop2 = in_prop2;
        emit prop2Changed(in_prop2);
    }
}

Enum2::Enum2Enum MqttSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum MqttSameEnum2Interface::func1(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func1Async(param1);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum1::Enum1Enum> MqttSameEnum2Interface::func1Async(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func1");
    auto promise = std::make_shared<QPromise<Enum1::Enum1Enum>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum1::Value1);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(Enum1::Value1);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            Enum1::Enum1Enum value = arg.get<Enum1::Enum1Enum>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

Enum1::Enum1Enum MqttSameEnum2Interface::func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func2Async(param1, param2);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum1::Enum1Enum> MqttSameEnum2Interface::func2Async(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func2");
    auto promise = std::make_shared<QPromise<Enum1::Enum1Enum>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum1::Value1);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(Enum1::Value1);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1, param2 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            Enum1::Enum1Enum value = arg.get<Enum1::Enum1Enum>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttSameEnum2Interface::interfaceName()
{
    return InterfaceName;
}

void MqttSameEnum2Interface::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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
void MqttSameEnum2Interface::subscribeForPropertiesChanges()
{
        // Subscription may succeed, before finising the function that subscribes it and assigns an id for if it was already added (and succeeded) for same topic,
        // hence, for pending subscriptions a topic is used, and added before the subscribe function.
        const QString topicprop1 = interfaceName() + "/prop/prop1";
        m_pendingSubscriptions.push_back(topicprop1);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop1,
            [this, topicprop1](auto id, bool hasSucceed){handleOnSubscribed(topicprop1, id, hasSucceed);},
            [this](auto& value) { setProp1Local(value);}));
        const QString topicprop2 = interfaceName() + "/prop/prop2";
        m_pendingSubscriptions.push_back(topicprop2);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop2,
            [this, topicprop2](auto id, bool hasSucceed){handleOnSubscribed(topicprop2, id, hasSucceed);},
            [this](auto& value) { setProp2Local(value);}));
}
void MqttSameEnum2Interface::subscribeForSignals()
{
        const QString topicsig1 = interfaceName() + "/sig/sig1";
        m_pendingSubscriptions.push_back(topicsig1);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig1,
            [this, topicsig1](auto id, bool hasSucceed){handleOnSubscribed(topicsig1, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sig1(argumentsArray[0].get<Enum1::Enum1Enum>());}));
        const QString topicsig2 = interfaceName() + "/sig/sig2";
        m_pendingSubscriptions.push_back(topicsig2);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig2,
            [this, topicsig2](auto id, bool hasSucceed){handleOnSubscribed(topicsig2, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sig2(argumentsArray[0].get<Enum1::Enum1Enum>(), argumentsArray[1].get<Enum2::Enum2Enum>());}));
}
void MqttSameEnum2Interface::subscribeForInvokeResponses()
{
    const QString topicfunc1 = interfaceName() + "/rpc/func1";
    const QString topicfunc1InvokeResp = interfaceName() + "/rpc/func1"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfunc1InvokeResp);
    auto id_func1 = m_client.subscribeForInvokeResponse(topicfunc1InvokeResp, 
                        [this, topicfunc1InvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfunc1InvokeResp, id, hasSucceed);},
                        [this, topicfunc1InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc1InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc1] = std::make_pair(topicfunc1InvokeResp, id_func1);
    const QString topicfunc2 = interfaceName() + "/rpc/func2";
    const QString topicfunc2InvokeResp = interfaceName() + "/rpc/func2"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfunc2InvokeResp);
    auto id_func2 = m_client.subscribeForInvokeResponse(topicfunc2InvokeResp, 
                        [this, topicfunc2InvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfunc2InvokeResp, id, hasSucceed);},
                        [this, topicfunc2InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc2InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc2] = std::make_pair(topicfunc2InvokeResp, id_func2);
}

void MqttSameEnum2Interface::unsubscribeAll()
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

void MqttSameEnum2Interface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

} // namespace tb_same2

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

#include "mqttenuminterface.h"

#include "tb_enum/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_enum {

namespace
{
const QString InterfaceName = "tb.enum/EnumInterface";
}

MqttEnumInterface::MqttEnumInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractEnumInterface(parent)
    , m_prop0(Enum0::Value0)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value2)
    , m_prop3(Enum3::Value3)
    , m_isReady(false)
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
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
}

MqttEnumInterface::~MqttEnumInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttEnumInterface::setProp0(Enum0::Enum0Enum prop0)
{
    static const QString topic = interfaceName() + QString("/set/prop0");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop0 ));
}

void MqttEnumInterface::setProp0Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop0(value.get<Enum0::Enum0Enum>());
    if (m_prop0 != in_prop0)
    {
        m_prop0 = in_prop0;
        emit prop0Changed(in_prop0);
    }
}

Enum0::Enum0Enum MqttEnumInterface::prop0() const
{
    return m_prop0;
}

void MqttEnumInterface::setProp1(Enum1::Enum1Enum prop1)
{
    static const QString topic = interfaceName() + QString("/set/prop1");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop1 ));
}

void MqttEnumInterface::setProp1Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop1(value.get<Enum1::Enum1Enum>());
    if (m_prop1 != in_prop1)
    {
        m_prop1 = in_prop1;
        emit prop1Changed(in_prop1);
    }
}

Enum1::Enum1Enum MqttEnumInterface::prop1() const
{
    return m_prop1;
}

void MqttEnumInterface::setProp2(Enum2::Enum2Enum prop2)
{
    static const QString topic = interfaceName() + QString("/set/prop2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop2 ));
}

void MqttEnumInterface::setProp2Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop2(value.get<Enum2::Enum2Enum>());
    if (m_prop2 != in_prop2)
    {
        m_prop2 = in_prop2;
        emit prop2Changed(in_prop2);
    }
}

Enum2::Enum2Enum MqttEnumInterface::prop2() const
{
    return m_prop2;
}

void MqttEnumInterface::setProp3(Enum3::Enum3Enum prop3)
{
    static const QString topic = interfaceName() + QString("/set/prop3");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop3 ));
}

void MqttEnumInterface::setProp3Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop3(value.get<Enum3::Enum3Enum>());
    if (m_prop3 != in_prop3)
    {
        m_prop3 = in_prop3;
        emit prop3Changed(in_prop3);
    }
}

Enum3::Enum3Enum MqttEnumInterface::prop3() const
{
    return m_prop3;
}

Enum0::Enum0Enum MqttEnumInterface::func0(Enum0::Enum0Enum param0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func0Async(param0);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum0::Enum0Enum> MqttEnumInterface::func0Async(Enum0::Enum0Enum param0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func0");
    auto promise = std::make_shared<QPromise<Enum0::Enum0Enum>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum0::Value0);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum0::Value0);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param0 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            Enum0::Enum0Enum value = arg.get<Enum0::Enum0Enum>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

Enum1::Enum1Enum MqttEnumInterface::func1(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func1Async(param1);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum1::Enum1Enum> MqttEnumInterface::func1Async(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func1");
    auto promise = std::make_shared<QPromise<Enum1::Enum1Enum>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum1::Value1);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum1::Value1);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            Enum1::Enum1Enum value = arg.get<Enum1::Enum1Enum>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

Enum2::Enum2Enum MqttEnumInterface::func2(Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func2Async(param2);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum2::Enum2Enum> MqttEnumInterface::func2Async(Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func2");
    auto promise = std::make_shared<QPromise<Enum2::Enum2Enum>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum2::Value2);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum2::Value2);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param2 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            Enum2::Enum2Enum value = arg.get<Enum2::Enum2Enum>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

Enum3::Enum3Enum MqttEnumInterface::func3(Enum3::Enum3Enum param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func3Async(param3);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum3::Enum3Enum> MqttEnumInterface::func3Async(Enum3::Enum3Enum param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func3");
    auto promise = std::make_shared<QPromise<Enum3::Enum3Enum>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum3::Value3);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(Enum3::Value3);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param3 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            Enum3::Enum3Enum value = arg.get<Enum3::Enum3Enum>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttEnumInterface::interfaceName()
{
    return InterfaceName;
}
void MqttEnumInterface::subscribeForPropertiesChanges()
{
        static const QString topicprop0 = interfaceName() + "/prop/prop0";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop0, [this](auto& value) { setProp0Local(value);}));
        static const QString topicprop1 = interfaceName() + "/prop/prop1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop1, [this](auto& value) { setProp1Local(value);}));
        static const QString topicprop2 = interfaceName() + "/prop/prop2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop2, [this](auto& value) { setProp2Local(value);}));
        static const QString topicprop3 = interfaceName() + "/prop/prop3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop3, [this](auto& value) { setProp3Local(value);}));
}
void MqttEnumInterface::subscribeForSignals()
{
        static const QString topicsig0 = interfaceName() + "/sig/sig0";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig0, [this](const nlohmann::json& argumentsArray){
            emit sig0(argumentsArray[0].get<Enum0::Enum0Enum>());}));
        static const QString topicsig1 = interfaceName() + "/sig/sig1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig1, [this](const nlohmann::json& argumentsArray){
            emit sig1(argumentsArray[0].get<Enum1::Enum1Enum>());}));
        static const QString topicsig2 = interfaceName() + "/sig/sig2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig2, [this](const nlohmann::json& argumentsArray){
            emit sig2(argumentsArray[0].get<Enum2::Enum2Enum>());}));
        static const QString topicsig3 = interfaceName() + "/sig/sig3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig3, [this](const nlohmann::json& argumentsArray){
            emit sig3(argumentsArray[0].get<Enum3::Enum3Enum>());}));
}
void MqttEnumInterface::subscribeForInvokeResponses()
{
    const QString topicfunc0 = interfaceName() + "/rpc/func0";
    const QString topicfunc0InvokeResp = interfaceName() + "/rpc/func0"+ m_client.clientId() + "/result";
    auto id_func0 = m_client.subscribeForInvokeResponse(topicfunc0InvokeResp, 
                        [this, topicfunc0InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc0InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc0] = std::make_pair(topicfunc0InvokeResp, id_func0);
    const QString topicfunc1 = interfaceName() + "/rpc/func1";
    const QString topicfunc1InvokeResp = interfaceName() + "/rpc/func1"+ m_client.clientId() + "/result";
    auto id_func1 = m_client.subscribeForInvokeResponse(topicfunc1InvokeResp, 
                        [this, topicfunc1InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc1InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc1] = std::make_pair(topicfunc1InvokeResp, id_func1);
    const QString topicfunc2 = interfaceName() + "/rpc/func2";
    const QString topicfunc2InvokeResp = interfaceName() + "/rpc/func2"+ m_client.clientId() + "/result";
    auto id_func2 = m_client.subscribeForInvokeResponse(topicfunc2InvokeResp, 
                        [this, topicfunc2InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc2InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc2] = std::make_pair(topicfunc2InvokeResp, id_func2);
    const QString topicfunc3 = interfaceName() + "/rpc/func3";
    const QString topicfunc3InvokeResp = interfaceName() + "/rpc/func3"+ m_client.clientId() + "/result";
    auto id_func3 = m_client.subscribeForInvokeResponse(topicfunc3InvokeResp, 
                        [this, topicfunc3InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc3InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc3] = std::make_pair(topicfunc3InvokeResp, id_func3);
}

void MqttEnumInterface::unsubscribeAll()
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

void MqttEnumInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

} // namespace tb_enum

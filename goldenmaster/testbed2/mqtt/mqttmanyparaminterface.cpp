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

#include "mqttmanyparaminterface.h"

#include "testbed2/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace testbed2 {

namespace
{
const QString InterfaceName = "testbed2/ManyParamInterface";
}

MqttManyParamInterface::MqttManyParamInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
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

MqttManyParamInterface::~MqttManyParamInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttManyParamInterface::setProp1(int prop1)
{
    static const QString topic = interfaceName() + QString("/set/prop1");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop1 ));
}

void MqttManyParamInterface::setProp1Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop1(value.get<int>());
    if (m_prop1 != in_prop1)
    {
        m_prop1 = in_prop1;
        emit prop1Changed(in_prop1);
    }
}

int MqttManyParamInterface::prop1() const
{
    return m_prop1;
}

void MqttManyParamInterface::setProp2(int prop2)
{
    static const QString topic = interfaceName() + QString("/set/prop2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop2 ));
}

void MqttManyParamInterface::setProp2Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop2(value.get<int>());
    if (m_prop2 != in_prop2)
    {
        m_prop2 = in_prop2;
        emit prop2Changed(in_prop2);
    }
}

int MqttManyParamInterface::prop2() const
{
    return m_prop2;
}

void MqttManyParamInterface::setProp3(int prop3)
{
    static const QString topic = interfaceName() + QString("/set/prop3");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop3 ));
}

void MqttManyParamInterface::setProp3Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop3(value.get<int>());
    if (m_prop3 != in_prop3)
    {
        m_prop3 = in_prop3;
        emit prop3Changed(in_prop3);
    }
}

int MqttManyParamInterface::prop3() const
{
    return m_prop3;
}

void MqttManyParamInterface::setProp4(int prop4)
{
    static const QString topic = interfaceName() + QString("/set/prop4");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop4 ));
}

void MqttManyParamInterface::setProp4Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop4(value.get<int>());
    if (m_prop4 != in_prop4)
    {
        m_prop4 = in_prop4;
        emit prop4Changed(in_prop4);
    }
}

int MqttManyParamInterface::prop4() const
{
    return m_prop4;
}

int MqttManyParamInterface::func1(int param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func1Async(param1);
    future.waitForFinished();
    return future.result();
}

QFuture<int> MqttManyParamInterface::func1Async(int param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func1");
    auto promise = std::make_shared<QPromise<int>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            int value = arg.get<int>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

int MqttManyParamInterface::func2(int param1, int param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func2Async(param1, param2);
    future.waitForFinished();
    return future.result();
}

QFuture<int> MqttManyParamInterface::func2Async(int param1, int param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func2");
    auto promise = std::make_shared<QPromise<int>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1, param2 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            int value = arg.get<int>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

int MqttManyParamInterface::func3(int param1, int param2, int param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func3Async(param1, param2, param3);
    future.waitForFinished();
    return future.result();
}

QFuture<int> MqttManyParamInterface::func3Async(int param1, int param2, int param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func3");
    auto promise = std::make_shared<QPromise<int>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1, param2, param3 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            int value = arg.get<int>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

int MqttManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = func4Async(param1, param2, param3, param4);
    future.waitForFinished();
    return future.result();
}

QFuture<int> MqttManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func4");
    auto promise = std::make_shared<QPromise<int>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({param1, param2, param3, param4 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            int value = arg.get<int>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttManyParamInterface::interfaceName()
{
    return InterfaceName;
}
void MqttManyParamInterface::subscribeForPropertiesChanges()
{
        const QString topicprop1 = interfaceName() + "/prop/prop1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop1, [this](auto& value) { setProp1Local(value);}));
        const QString topicprop2 = interfaceName() + "/prop/prop2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop2, [this](auto& value) { setProp2Local(value);}));
        const QString topicprop3 = interfaceName() + "/prop/prop3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop3, [this](auto& value) { setProp3Local(value);}));
        const QString topicprop4 = interfaceName() + "/prop/prop4";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop4, [this](auto& value) { setProp4Local(value);}));
}
void MqttManyParamInterface::subscribeForSignals()
{
        const QString topicsig1 = interfaceName() + "/sig/sig1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig1, [this](const nlohmann::json& argumentsArray){
            emit sig1(argumentsArray[0].get<int>());}));
        const QString topicsig2 = interfaceName() + "/sig/sig2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig2, [this](const nlohmann::json& argumentsArray){
            emit sig2(argumentsArray[0].get<int>(),argumentsArray[1].get<int>());}));
        const QString topicsig3 = interfaceName() + "/sig/sig3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig3, [this](const nlohmann::json& argumentsArray){
            emit sig3(argumentsArray[0].get<int>(),argumentsArray[1].get<int>(),argumentsArray[2].get<int>());}));
        const QString topicsig4 = interfaceName() + "/sig/sig4";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig4, [this](const nlohmann::json& argumentsArray){
            emit sig4(argumentsArray[0].get<int>(),argumentsArray[1].get<int>(),argumentsArray[2].get<int>(),argumentsArray[3].get<int>());}));
}
void MqttManyParamInterface::subscribeForInvokeResponses()
{
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
    const QString topicfunc4 = interfaceName() + "/rpc/func4";
    const QString topicfunc4InvokeResp = interfaceName() + "/rpc/func4"+ m_client.clientId() + "/result";
    auto id_func4 = m_client.subscribeForInvokeResponse(topicfunc4InvokeResp, 
                        [this, topicfunc4InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfunc4InvokeResp);
                        });
    m_InvokeCallsInfo[topicfunc4] = std::make_pair(topicfunc4InvokeResp, id_func4);
}

void MqttManyParamInterface::unsubscribeAll()
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

void MqttManyParamInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

} // namespace testbed2

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

#include "mqttnosignalsinterface.h"

#include "tb_simple/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/NoSignalsInterface";
}

MqttNoSignalsInterface::MqttNoSignalsInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractNoSignalsInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_isReady(false)
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
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
}

MqttNoSignalsInterface::~MqttNoSignalsInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttNoSignalsInterface::setPropBool(bool propBool)
{
    static const QString topic = interfaceName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propBool ));
}

void MqttNoSignalsInterface::setPropBoolLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(value.get<bool>());
    if (m_propBool != in_propBool)
    {
        m_propBool = in_propBool;
        emit propBoolChanged(in_propBool);
    }
}

bool MqttNoSignalsInterface::propBool() const
{
    return m_propBool;
}

void MqttNoSignalsInterface::setPropInt(int propInt)
{
    static const QString topic = interfaceName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt ));
}

void MqttNoSignalsInterface::setPropIntLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(value.get<int>());
    if (m_propInt != in_propInt)
    {
        m_propInt = in_propInt;
        emit propIntChanged(in_propInt);
    }
}

int MqttNoSignalsInterface::propInt() const
{
    return m_propInt;
}

void MqttNoSignalsInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcVoidAsync();
    future.waitForFinished();
    return;
}

QFuture<void> MqttNoSignalsInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcVoid");
    auto promise = std::make_shared<QPromise<void>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->finish();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->finish();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({ });       

    auto func = [promise](const nlohmann::json& arg)
        {
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

bool MqttNoSignalsInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<bool> MqttNoSignalsInterface::funcBoolAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcBool");
    auto promise = std::make_shared<QPromise<bool>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(false);
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(false);
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramBool });       

    auto func = [promise](const nlohmann::json& arg)
        {
            bool value = arg.get<bool>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttNoSignalsInterface::interfaceName()
{
    return InterfaceName;
}
void MqttNoSignalsInterface::subscribeForPropertiesChanges()
{
        const QString topicpropBool = interfaceName() + "/prop/propBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropBool, [this](auto& value) { setPropBoolLocal(value);}));
        const QString topicpropInt = interfaceName() + "/prop/propInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt, [this](auto& value) { setPropIntLocal(value);}));
}
void MqttNoSignalsInterface::subscribeForInvokeResponses()
{
    const QString topicfuncVoid = interfaceName() + "/rpc/funcVoid";
    const QString topicfuncVoidInvokeResp = interfaceName() + "/rpc/funcVoid"+ m_client.clientId() + "/result";
    auto id_funcVoid = m_client.subscribeForInvokeResponse(topicfuncVoidInvokeResp, 
                        [this, topicfuncVoidInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncVoidInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncVoid] = std::make_pair(topicfuncVoidInvokeResp, id_funcVoid);
    const QString topicfuncBool = interfaceName() + "/rpc/funcBool";
    const QString topicfuncBoolInvokeResp = interfaceName() + "/rpc/funcBool"+ m_client.clientId() + "/result";
    auto id_funcBool = m_client.subscribeForInvokeResponse(topicfuncBoolInvokeResp, 
                        [this, topicfuncBoolInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncBoolInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncBool] = std::make_pair(topicfuncBoolInvokeResp, id_funcBool);
}

void MqttNoSignalsInterface::unsubscribeAll()
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

void MqttNoSignalsInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

} // namespace tb_simple

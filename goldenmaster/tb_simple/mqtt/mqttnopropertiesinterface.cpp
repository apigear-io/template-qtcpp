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

#include "mqttnopropertiesinterface.h"

#include "tb_simple/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/NoPropertiesInterface";
}

MqttNoPropertiesInterface::MqttNoPropertiesInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractNoPropertiesInterface(parent)
    , m_finishedInitialization(false)
    , m_client(client)
{
    if (m_client.isReady())
    {
        subscribeForSignals();
        subscribeForInvokeResponses();
    }
     connect(&m_client, &ApiGear::Mqtt::Client::ready, [this](){
        AG_LOG_DEBUG(Q_FUNC_INFO);
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

MqttNoPropertiesInterface::~MqttNoPropertiesInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

bool MqttNoPropertiesInterface::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}

void MqttNoPropertiesInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcVoidAsync();
    future.waitForFinished();
    return;
}

QFuture<void> MqttNoPropertiesInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcVoid");
    auto promise = std::make_shared<QPromise<void>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->finish();
        return promise->future();
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

bool MqttNoPropertiesInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<bool> MqttNoPropertiesInterface::funcBoolAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcBool");
    auto promise = std::make_shared<QPromise<bool>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(false);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(false);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramBool });       

    auto func = [promise](const nlohmann::json& arg)
        {
            bool value = arg.get<bool>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttNoPropertiesInterface::interfaceName()
{
    return InterfaceName;
}

void MqttNoPropertiesInterface::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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
void MqttNoPropertiesInterface::subscribeForSignals()
{
        const QString topicsigVoid = interfaceName() + "/sig/sigVoid";
        m_pendingSubscriptions.push_back(topicsigVoid);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigVoid,
            [this, topicsigVoid](auto id, bool hasSucceed){handleOnSubscribed(topicsigVoid, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigVoid();}));
        const QString topicsigBool = interfaceName() + "/sig/sigBool";
        m_pendingSubscriptions.push_back(topicsigBool);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool,
            [this, topicsigBool](auto id, bool hasSucceed){handleOnSubscribed(topicsigBool, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigBool(argumentsArray[0].get<bool>());}));
}
void MqttNoPropertiesInterface::subscribeForInvokeResponses()
{
    const QString topicfuncVoid = interfaceName() + "/rpc/funcVoid";
    const QString topicfuncVoidInvokeResp = interfaceName() + "/rpc/funcVoid"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncVoidInvokeResp);
    auto id_funcVoid = m_client.subscribeForInvokeResponse(topicfuncVoidInvokeResp, 
                        [this, topicfuncVoidInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncVoidInvokeResp, id, hasSucceed);},
                        [this, topicfuncVoidInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncVoidInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncVoid] = std::make_pair(topicfuncVoidInvokeResp, id_funcVoid);
    const QString topicfuncBool = interfaceName() + "/rpc/funcBool";
    const QString topicfuncBoolInvokeResp = interfaceName() + "/rpc/funcBool"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncBoolInvokeResp);
    auto id_funcBool = m_client.subscribeForInvokeResponse(topicfuncBoolInvokeResp, 
                        [this, topicfuncBoolInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncBoolInvokeResp, id, hasSucceed);},
                        [this, topicfuncBoolInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncBoolInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncBool] = std::make_pair(topicfuncBoolInvokeResp, id_funcBool);
}

void MqttNoPropertiesInterface::unsubscribeAll()
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

void MqttNoPropertiesInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

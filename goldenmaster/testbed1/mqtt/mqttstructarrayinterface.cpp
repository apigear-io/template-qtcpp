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

#include "mqttstructarrayinterface.h"

#include "testbed1/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace testbed1 {

namespace
{
const QString InterfaceName = "testbed1/StructArrayInterface";
}

MqttStructArrayInterface::MqttStructArrayInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
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

MqttStructArrayInterface::~MqttStructArrayInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

bool MqttStructArrayInterface::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}

void MqttStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    static const QString topic = interfaceName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propBool ));
}

void MqttStructArrayInterface::setPropBoolLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(value.get<QList<StructBool>>());
    if (m_propBool != in_propBool)
    {
        m_propBool = in_propBool;
        emit propBoolChanged(in_propBool);
    }
}

QList<StructBool> MqttStructArrayInterface::propBool() const
{
    return m_propBool;
}

void MqttStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    static const QString topic = interfaceName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt ));
}

void MqttStructArrayInterface::setPropIntLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(value.get<QList<StructInt>>());
    if (m_propInt != in_propInt)
    {
        m_propInt = in_propInt;
        emit propIntChanged(in_propInt);
    }
}

QList<StructInt> MqttStructArrayInterface::propInt() const
{
    return m_propInt;
}

void MqttStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    static const QString topic = interfaceName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat ));
}

void MqttStructArrayInterface::setPropFloatLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(value.get<QList<StructFloat>>());
    if (m_propFloat != in_propFloat)
    {
        m_propFloat = in_propFloat;
        emit propFloatChanged(in_propFloat);
    }
}

QList<StructFloat> MqttStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void MqttStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    static const QString topic = interfaceName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propString ));
}

void MqttStructArrayInterface::setPropStringLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(value.get<QList<StructString>>());
    if (m_propString != in_propString)
    {
        m_propString = in_propString;
        emit propStringChanged(in_propString);
    }
}

QList<StructString> MqttStructArrayInterface::propString() const
{
    return m_propString;
}

QList<StructBool> MqttStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructBool>> MqttStructArrayInterface::funcBoolAsync(const QList<StructBool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcBool");
    auto promise = std::make_shared<QPromise<QList<StructBool>>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<StructBool>());
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(QList<StructBool>());
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramBool });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<StructBool> value = arg.get<QList<StructBool>>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<StructInt> MqttStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructInt>> MqttStructArrayInterface::funcIntAsync(const QList<StructInt>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt");
    auto promise = std::make_shared<QPromise<QList<StructInt>>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<StructInt>());
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(QList<StructInt>());
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<StructInt> value = arg.get<QList<StructInt>>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<StructFloat> MqttStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructFloat>> MqttStructArrayInterface::funcFloatAsync(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat");
    auto promise = std::make_shared<QPromise<QList<StructFloat>>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<StructFloat>());
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(QList<StructFloat>());
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<StructFloat> value = arg.get<QList<StructFloat>>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<StructString> MqttStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructString>> MqttStructArrayInterface::funcStringAsync(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcString");
    auto promise = std::make_shared<QPromise<QList<StructString>>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<StructString>());
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(QList<StructString>());
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramString });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<StructString> value = arg.get<QList<StructString>>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttStructArrayInterface::interfaceName()
{
    return InterfaceName;
}

void MqttStructArrayInterface::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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
void MqttStructArrayInterface::subscribeForPropertiesChanges()
{
        // Subscription may succeed, before finising the function that subscribes it and assigns an id for if it was already added (and succeeded) for same topic,
        // hence, for pending subscriptions a topic is used, and added before the subscribe function.
        const QString topicpropBool = interfaceName() + "/prop/propBool";
        m_pendingSubscriptions.push_back(topicpropBool);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropBool,
            [this, topicpropBool](auto id, bool hasSucceed){handleOnSubscribed(topicpropBool, id, hasSucceed);},
            [this](auto& value) { setPropBoolLocal(value);}));
        const QString topicpropInt = interfaceName() + "/prop/propInt";
        m_pendingSubscriptions.push_back(topicpropInt);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt,
            [this, topicpropInt](auto id, bool hasSucceed){handleOnSubscribed(topicpropInt, id, hasSucceed);},
            [this](auto& value) { setPropIntLocal(value);}));
        const QString topicpropFloat = interfaceName() + "/prop/propFloat";
        m_pendingSubscriptions.push_back(topicpropFloat);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat,
            [this, topicpropFloat](auto id, bool hasSucceed){handleOnSubscribed(topicpropFloat, id, hasSucceed);},
            [this](auto& value) { setPropFloatLocal(value);}));
        const QString topicpropString = interfaceName() + "/prop/propString";
        m_pendingSubscriptions.push_back(topicpropString);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropString,
            [this, topicpropString](auto id, bool hasSucceed){handleOnSubscribed(topicpropString, id, hasSucceed);},
            [this](auto& value) { setPropStringLocal(value);}));
}
void MqttStructArrayInterface::subscribeForSignals()
{
        const QString topicsigBool = interfaceName() + "/sig/sigBool";
        m_pendingSubscriptions.push_back(topicsigBool);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool,
            [this, topicsigBool](auto id, bool hasSucceed){handleOnSubscribed(topicsigBool, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigBool(argumentsArray[0].get<QList<StructBool>>());}));
        const QString topicsigInt = interfaceName() + "/sig/sigInt";
        m_pendingSubscriptions.push_back(topicsigInt);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt,
            [this, topicsigInt](auto id, bool hasSucceed){handleOnSubscribed(topicsigInt, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigInt(argumentsArray[0].get<QList<StructInt>>());}));
        const QString topicsigFloat = interfaceName() + "/sig/sigFloat";
        m_pendingSubscriptions.push_back(topicsigFloat);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat,
            [this, topicsigFloat](auto id, bool hasSucceed){handleOnSubscribed(topicsigFloat, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigFloat(argumentsArray[0].get<QList<StructFloat>>());}));
        const QString topicsigString = interfaceName() + "/sig/sigString";
        m_pendingSubscriptions.push_back(topicsigString);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString,
            [this, topicsigString](auto id, bool hasSucceed){handleOnSubscribed(topicsigString, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigString(argumentsArray[0].get<QList<StructString>>());}));
}
void MqttStructArrayInterface::subscribeForInvokeResponses()
{
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
    const QString topicfuncInt = interfaceName() + "/rpc/funcInt";
    const QString topicfuncIntInvokeResp = interfaceName() + "/rpc/funcInt"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncIntInvokeResp);
    auto id_funcInt = m_client.subscribeForInvokeResponse(topicfuncIntInvokeResp, 
                        [this, topicfuncIntInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncIntInvokeResp, id, hasSucceed);},
                        [this, topicfuncIntInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncIntInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncInt] = std::make_pair(topicfuncIntInvokeResp, id_funcInt);
    const QString topicfuncFloat = interfaceName() + "/rpc/funcFloat";
    const QString topicfuncFloatInvokeResp = interfaceName() + "/rpc/funcFloat"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncFloatInvokeResp);
    auto id_funcFloat = m_client.subscribeForInvokeResponse(topicfuncFloatInvokeResp, 
                        [this, topicfuncFloatInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncFloatInvokeResp, id, hasSucceed);},
                        [this, topicfuncFloatInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncFloatInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncFloat] = std::make_pair(topicfuncFloatInvokeResp, id_funcFloat);
    const QString topicfuncString = interfaceName() + "/rpc/funcString";
    const QString topicfuncStringInvokeResp = interfaceName() + "/rpc/funcString"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncStringInvokeResp);
    auto id_funcString = m_client.subscribeForInvokeResponse(topicfuncStringInvokeResp, 
                        [this, topicfuncStringInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncStringInvokeResp, id, hasSucceed);},
                        [this, topicfuncStringInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncStringInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncString] = std::make_pair(topicfuncStringInvokeResp, id_funcString);
}

void MqttStructArrayInterface::unsubscribeAll()
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

void MqttStructArrayInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

} // namespace testbed1

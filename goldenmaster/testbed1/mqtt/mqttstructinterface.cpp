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

#include "mqttstructinterface.h"

#include "testbed1/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace testbed1 {

namespace
{
const QString ID = "testbed1/StructInterface";
}

MqttStructInterface::MqttStructInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractStructInterface(parent)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
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
}

MqttStructInterface::~MqttStructInterface()
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

void MqttStructInterface::setPropBool(const StructBool& propBool)
{
    static const QString topic = objectName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propBool });
}

void MqttStructInterface::setPropBoolLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(input.get<StructBool>());
    if (m_propBool != in_propBool)
    {
        m_propBool = in_propBool;
        emit propBoolChanged(in_propBool);
    }
}

StructBool MqttStructInterface::propBool() const
{
    return m_propBool;
}

void MqttStructInterface::setPropInt(const StructInt& propInt)
{
    static const QString topic = objectName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt });
}

void MqttStructInterface::setPropIntLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(input.get<StructInt>());
    if (m_propInt != in_propInt)
    {
        m_propInt = in_propInt;
        emit propIntChanged(in_propInt);
    }
}

StructInt MqttStructInterface::propInt() const
{
    return m_propInt;
}

void MqttStructInterface::setPropFloat(const StructFloat& propFloat)
{
    static const QString topic = objectName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat });
}

void MqttStructInterface::setPropFloatLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(input.get<StructFloat>());
    if (m_propFloat != in_propFloat)
    {
        m_propFloat = in_propFloat;
        emit propFloatChanged(in_propFloat);
    }
}

StructFloat MqttStructInterface::propFloat() const
{
    return m_propFloat;
}

void MqttStructInterface::setPropString(const StructString& propString)
{
    static const QString topic = objectName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propString });
}

void MqttStructInterface::setPropStringLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(input.get<StructString>());
    if (m_propString != in_propString)
    {
        m_propString = in_propString;
        emit propStringChanged(in_propString);
    }
}

StructString MqttStructInterface::propString() const
{
    return m_propString;
}

StructBool MqttStructInterface::funcBool(const StructBool& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcBoolAsync(paramBool)
        .then([&](StructBool result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> MqttStructInterface::funcBoolAsync(const StructBool& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcBool");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramBool });       
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    StructBool value = arg.get<StructBool>();
                    resolve(value);
                });
        }
    };
}

StructBool MqttStructInterface::funcInt(const StructInt& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcIntAsync(paramInt)
        .then([&](StructBool result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> MqttStructInterface::funcIntAsync(const StructInt& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcInt");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt });       
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    StructBool value = arg.get<StructBool>();
                    resolve(value);
                });
        }
    };
}

StructFloat MqttStructInterface::funcFloat(const StructFloat& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return StructFloat();
    }
    StructFloat value{ StructFloat() };
    funcFloatAsync(paramFloat)
        .then([&](StructFloat result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<StructFloat> MqttStructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcFloat");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<StructFloat>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<StructFloat>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat });       
    return QtPromise::QPromise<StructFloat>{[&](
        const QtPromise::QPromiseResolve<StructFloat>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    StructFloat value = arg.get<StructFloat>();
                    resolve(value);
                });
        }
    };
}

StructString MqttStructInterface::funcString(const StructString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return StructString();
    }
    StructString value{ StructString() };
    funcStringAsync(paramString)
        .then([&](StructString result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<StructString> MqttStructInterface::funcStringAsync(const StructString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcString");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<StructString>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<StructString>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramString });       
    return QtPromise::QPromise<StructString>{[&](
        const QtPromise::QPromiseResolve<StructString>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    StructString value = arg.get<StructString>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttStructInterface::objectName()
{
    return ID;
}
void MqttStructInterface::subscribeForPropertiesChanges()
{
        static const QString topicpropBool = objectName() + "/prop/propBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropBool, [this](auto& input) { setPropBoolLocal(input);}));
        static const QString topicpropInt = objectName() + "/prop/propInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt, [this](auto& input) { setPropIntLocal(input);}));
        static const QString topicpropFloat = objectName() + "/prop/propFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat, [this](auto& input) { setPropFloatLocal(input);}));
        static const QString topicpropString = objectName() + "/prop/propString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropString, [this](auto& input) { setPropStringLocal(input);}));
}
void MqttStructInterface::subscribeForSignals()
{
        static const QString topicsigBool = objectName() + "/sig/sigBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool, [this](const nlohmann::json& input){
            emit sigBool(input[0].get<StructBool>());}));
        static const QString topicsigInt = objectName() + "/sig/sigInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt, [this](const nlohmann::json& input){
            emit sigInt(input[0].get<StructInt>());}));
        static const QString topicsigFloat = objectName() + "/sig/sigFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat, [this](const nlohmann::json& input){
            emit sigFloat(input[0].get<StructFloat>());}));
        static const QString topicsigString = objectName() + "/sig/sigString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString, [this](const nlohmann::json& input){
            emit sigString(input[0].get<StructString>());}));
}
void MqttStructInterface::subscribeForInvokeResponses()
{
    // Subscribe for invokeReply and prepare invoke call info for non void functions.
    const QString topicfuncBool = objectName() + "/rpc/funcBool";
    const QString topicfuncBoolInvokeResp = objectName() + "/rpc/funcBool"+ m_client.clientId() + "/result";
    auto id_funcBool = m_client.subscribeForInvokeResponse(topicfuncBoolInvokeResp);
    m_InvokeCallsInfo[topicfuncBool] = std::make_pair(topicfuncBoolInvokeResp, id_funcBool);
    const QString topicfuncInt = objectName() + "/rpc/funcInt";
    const QString topicfuncIntInvokeResp = objectName() + "/rpc/funcInt"+ m_client.clientId() + "/result";
    auto id_funcInt = m_client.subscribeForInvokeResponse(topicfuncIntInvokeResp);
    m_InvokeCallsInfo[topicfuncInt] = std::make_pair(topicfuncIntInvokeResp, id_funcInt);
    const QString topicfuncFloat = objectName() + "/rpc/funcFloat";
    const QString topicfuncFloatInvokeResp = objectName() + "/rpc/funcFloat"+ m_client.clientId() + "/result";
    auto id_funcFloat = m_client.subscribeForInvokeResponse(topicfuncFloatInvokeResp);
    m_InvokeCallsInfo[topicfuncFloat] = std::make_pair(topicfuncFloatInvokeResp, id_funcFloat);
    const QString topicfuncString = objectName() + "/rpc/funcString";
    const QString topicfuncStringInvokeResp = objectName() + "/rpc/funcString"+ m_client.clientId() + "/result";
    auto id_funcString = m_client.subscribeForInvokeResponse(topicfuncStringInvokeResp);
    m_InvokeCallsInfo[topicfuncString] = std::make_pair(topicfuncStringInvokeResp, id_funcString);
}


} // namespace testbed1

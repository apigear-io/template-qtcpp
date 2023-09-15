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
const QString ID = "testbed1/StructArrayInterface";
}

MqttStructArrayInterface::MqttStructArrayInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
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

MqttStructArrayInterface::~MqttStructArrayInterface()
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

void MqttStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    static const QString topic = objectName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propBool });
}

void MqttStructArrayInterface::setPropBoolLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(input.get<QList<StructBool>>());
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
    static const QString topic = objectName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt });
}

void MqttStructArrayInterface::setPropIntLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(input.get<QList<StructInt>>());
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
    static const QString topic = objectName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat });
}

void MqttStructArrayInterface::setPropFloatLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(input.get<QList<StructFloat>>());
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
    static const QString topic = objectName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propString });
}

void MqttStructArrayInterface::setPropStringLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(input.get<QList<StructString>>());
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

StructBool MqttStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
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

QtPromise::QPromise<StructBool> MqttStructArrayInterface::funcBoolAsync(const QList<StructBool>& paramBool)
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

StructBool MqttStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
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

QtPromise::QPromise<StructBool> MqttStructArrayInterface::funcIntAsync(const QList<StructInt>& paramInt)
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

StructBool MqttStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcFloatAsync(paramFloat)
        .then([&](StructBool result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> MqttStructArrayInterface::funcFloatAsync(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcFloat");

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
    auto arguments = nlohmann::json::array({paramFloat });       
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

StructBool MqttStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcStringAsync(paramString)
        .then([&](StructBool result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> MqttStructArrayInterface::funcStringAsync(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcString");

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
    auto arguments = nlohmann::json::array({paramString });       
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


const QString& MqttStructArrayInterface::objectName()
{
    return ID;
}
void MqttStructArrayInterface::subscribeForPropertiesChanges()
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
void MqttStructArrayInterface::subscribeForSignals()
{
        static const QString topicsigBool = objectName() + "/sig/sigBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool, [this](const nlohmann::json& input){
            emit sigBool(input[0].get<QList<StructBool>>());}));
        static const QString topicsigInt = objectName() + "/sig/sigInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt, [this](const nlohmann::json& input){
            emit sigInt(input[0].get<QList<StructInt>>());}));
        static const QString topicsigFloat = objectName() + "/sig/sigFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat, [this](const nlohmann::json& input){
            emit sigFloat(input[0].get<QList<StructFloat>>());}));
        static const QString topicsigString = objectName() + "/sig/sigString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString, [this](const nlohmann::json& input){
            emit sigString(input[0].get<QList<StructString>>());}));
}
void MqttStructArrayInterface::subscribeForInvokeResponses()
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

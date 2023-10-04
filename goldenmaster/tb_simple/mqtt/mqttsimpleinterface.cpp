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

#include "mqttsimpleinterface.h"

#include "tb_simple/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/SimpleInterface";
}

MqttSimpleInterface::MqttSimpleInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propInt32(0)
    , m_propInt64(0LL)
    , m_propFloat(0.0f)
    , m_propFloat32(0.0f)
    , m_propFloat64(0.0)
    , m_propString(QString())
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

MqttSimpleInterface::~MqttSimpleInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttSimpleInterface::setPropBool(bool propBool)
{
    static const QString topic = interfaceName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propBool ));
}

void MqttSimpleInterface::setPropBoolLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(value.get<bool>());
    if (m_propBool != in_propBool)
    {
        m_propBool = in_propBool;
        emit propBoolChanged(in_propBool);
    }
}

bool MqttSimpleInterface::propBool() const
{
    return m_propBool;
}

void MqttSimpleInterface::setPropInt(int propInt)
{
    static const QString topic = interfaceName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt ));
}

void MqttSimpleInterface::setPropIntLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(value.get<int>());
    if (m_propInt != in_propInt)
    {
        m_propInt = in_propInt;
        emit propIntChanged(in_propInt);
    }
}

int MqttSimpleInterface::propInt() const
{
    return m_propInt;
}

void MqttSimpleInterface::setPropInt32(qint32 propInt32)
{
    static const QString topic = interfaceName() + QString("/set/propInt32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt32 ));
}

void MqttSimpleInterface::setPropInt32Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt32(value.get<qint32>());
    if (m_propInt32 != in_propInt32)
    {
        m_propInt32 = in_propInt32;
        emit propInt32Changed(in_propInt32);
    }
}

qint32 MqttSimpleInterface::propInt32() const
{
    return m_propInt32;
}

void MqttSimpleInterface::setPropInt64(qint64 propInt64)
{
    static const QString topic = interfaceName() + QString("/set/propInt64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt64 ));
}

void MqttSimpleInterface::setPropInt64Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt64(value.get<qint64>());
    if (m_propInt64 != in_propInt64)
    {
        m_propInt64 = in_propInt64;
        emit propInt64Changed(in_propInt64);
    }
}

qint64 MqttSimpleInterface::propInt64() const
{
    return m_propInt64;
}

void MqttSimpleInterface::setPropFloat(qreal propFloat)
{
    static const QString topic = interfaceName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat ));
}

void MqttSimpleInterface::setPropFloatLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(value.get<qreal>());
    if (m_propFloat != in_propFloat)
    {
        m_propFloat = in_propFloat;
        emit propFloatChanged(in_propFloat);
    }
}

qreal MqttSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void MqttSimpleInterface::setPropFloat32(float propFloat32)
{
    static const QString topic = interfaceName() + QString("/set/propFloat32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat32 ));
}

void MqttSimpleInterface::setPropFloat32Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat32(value.get<float>());
    if (m_propFloat32 != in_propFloat32)
    {
        m_propFloat32 = in_propFloat32;
        emit propFloat32Changed(in_propFloat32);
    }
}

float MqttSimpleInterface::propFloat32() const
{
    return m_propFloat32;
}

void MqttSimpleInterface::setPropFloat64(double propFloat64)
{
    static const QString topic = interfaceName() + QString("/set/propFloat64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat64 ));
}

void MqttSimpleInterface::setPropFloat64Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat64(value.get<double>());
    if (m_propFloat64 != in_propFloat64)
    {
        m_propFloat64 = in_propFloat64;
        emit propFloat64Changed(in_propFloat64);
    }
}

double MqttSimpleInterface::propFloat64() const
{
    return m_propFloat64;
}

void MqttSimpleInterface::setPropString(const QString& propString)
{
    static const QString topic = interfaceName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propString ));
}

void MqttSimpleInterface::setPropStringLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(value.get<QString>());
    if (m_propString != in_propString)
    {
        m_propString = in_propString;
        emit propStringChanged(in_propString);
    }
}

QString MqttSimpleInterface::propString() const
{
    return m_propString;
}

void MqttSimpleInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return;
    }
    auto arguments = nlohmann::json::array({});
    static const QString topic = interfaceName() + QString("/rpc/funcVoid");
    m_client.invokeRemoteNoResponse(topic, arguments);
}

QtPromise::QPromise<void> MqttSimpleInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcVoid");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    auto arguments = nlohmann::json::array({ });
    m_client.invokeRemoteNoResponse(topic, arguments);
    return QtPromise::QPromise<void>::resolve();
}

bool MqttSimpleInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return false;
    }
    bool value{ false };
    funcBoolAsync(paramBool)
        .then([&](bool result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<bool> MqttSimpleInterface::funcBoolAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcBool");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<bool>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<bool>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramBool });       
    return QtPromise::QPromise<bool>{[&](
        const QtPromise::QPromiseResolve<bool>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    bool value = arg.get<bool>();
                    resolve(value);
                });
        }
    };
}

int MqttSimpleInterface::funcInt(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0;
    }
    int value{ 0 };
    funcIntAsync(paramInt)
        .then([&](int result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<int> MqttSimpleInterface::funcIntAsync(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt });       
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    int value = arg.get<int>();
                    resolve(value);
                });
        }
    };
}

qint32 MqttSimpleInterface::funcInt32(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0;
    }
    qint32 value{ 0 };
    funcInt32Async(paramInt32)
        .then([&](qint32 result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<qint32> MqttSimpleInterface::funcInt32Async(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt32");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<qint32>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<qint32>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt32 });       
    return QtPromise::QPromise<qint32>{[&](
        const QtPromise::QPromiseResolve<qint32>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    qint32 value = arg.get<qint32>();
                    resolve(value);
                });
        }
    };
}

qint64 MqttSimpleInterface::funcInt64(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0LL;
    }
    qint64 value{ 0LL };
    funcInt64Async(paramInt64)
        .then([&](qint64 result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<qint64> MqttSimpleInterface::funcInt64Async(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt64");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<qint64>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<qint64>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt64 });       
    return QtPromise::QPromise<qint64>{[&](
        const QtPromise::QPromiseResolve<qint64>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    qint64 value = arg.get<qint64>();
                    resolve(value);
                });
        }
    };
}

qreal MqttSimpleInterface::funcFloat(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0.0f;
    }
    qreal value{ 0.0f };
    funcFloatAsync(paramFloat)
        .then([&](qreal result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<qreal> MqttSimpleInterface::funcFloatAsync(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<qreal>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<qreal>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat });       
    return QtPromise::QPromise<qreal>{[&](
        const QtPromise::QPromiseResolve<qreal>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    qreal value = arg.get<qreal>();
                    resolve(value);
                });
        }
    };
}

float MqttSimpleInterface::funcFloat32(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0.0f;
    }
    float value{ 0.0f };
    funcFloat32Async(paramFloat32)
        .then([&](float result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<float> MqttSimpleInterface::funcFloat32Async(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat32");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<float>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<float>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat32 });       
    return QtPromise::QPromise<float>{[&](
        const QtPromise::QPromiseResolve<float>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    float value = arg.get<float>();
                    resolve(value);
                });
        }
    };
}

double MqttSimpleInterface::funcFloat64(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0.0;
    }
    double value{ 0.0 };
    funcFloat64Async(paramFloat)
        .then([&](double result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<double> MqttSimpleInterface::funcFloat64Async(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat64");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<double>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<double>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat });       
    return QtPromise::QPromise<double>{[&](
        const QtPromise::QPromiseResolve<double>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    double value = arg.get<double>();
                    resolve(value);
                });
        }
    };
}

QString MqttSimpleInterface::funcString(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QString();
    }
    QString value{ QString() };
    funcStringAsync(paramString)
        .then([&](QString result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QString> MqttSimpleInterface::funcStringAsync(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcString");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QString>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QString>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramString });       
    return QtPromise::QPromise<QString>{[&](
        const QtPromise::QPromiseResolve<QString>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    QString value = arg.get<QString>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttSimpleInterface::interfaceName()
{
    return InterfaceName;
}
void MqttSimpleInterface::subscribeForPropertiesChanges()
{
        static const QString topicpropBool = interfaceName() + "/prop/propBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropBool, [this](auto& value) { setPropBoolLocal(value);}));
        static const QString topicpropInt = interfaceName() + "/prop/propInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt, [this](auto& value) { setPropIntLocal(value);}));
        static const QString topicpropInt32 = interfaceName() + "/prop/propInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt32, [this](auto& value) { setPropInt32Local(value);}));
        static const QString topicpropInt64 = interfaceName() + "/prop/propInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt64, [this](auto& value) { setPropInt64Local(value);}));
        static const QString topicpropFloat = interfaceName() + "/prop/propFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat, [this](auto& value) { setPropFloatLocal(value);}));
        static const QString topicpropFloat32 = interfaceName() + "/prop/propFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat32, [this](auto& value) { setPropFloat32Local(value);}));
        static const QString topicpropFloat64 = interfaceName() + "/prop/propFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat64, [this](auto& value) { setPropFloat64Local(value);}));
        static const QString topicpropString = interfaceName() + "/prop/propString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropString, [this](auto& value) { setPropStringLocal(value);}));
}
void MqttSimpleInterface::subscribeForSignals()
{
        static const QString topicsigVoid = interfaceName() + "/sig/sigVoid";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigVoid, [this](const nlohmann::json& argumentsArray){
            emit sigVoid();}));
        static const QString topicsigBool = interfaceName() + "/sig/sigBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool, [this](const nlohmann::json& argumentsArray){
            emit sigBool(argumentsArray[0].get<bool>());}));
        static const QString topicsigInt = interfaceName() + "/sig/sigInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt, [this](const nlohmann::json& argumentsArray){
            emit sigInt(argumentsArray[0].get<int>());}));
        static const QString topicsigInt32 = interfaceName() + "/sig/sigInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt32, [this](const nlohmann::json& argumentsArray){
            emit sigInt32(argumentsArray[0].get<qint32>());}));
        static const QString topicsigInt64 = interfaceName() + "/sig/sigInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt64, [this](const nlohmann::json& argumentsArray){
            emit sigInt64(argumentsArray[0].get<qint64>());}));
        static const QString topicsigFloat = interfaceName() + "/sig/sigFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat, [this](const nlohmann::json& argumentsArray){
            emit sigFloat(argumentsArray[0].get<qreal>());}));
        static const QString topicsigFloat32 = interfaceName() + "/sig/sigFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat32, [this](const nlohmann::json& argumentsArray){
            emit sigFloat32(argumentsArray[0].get<float>());}));
        static const QString topicsigFloat64 = interfaceName() + "/sig/sigFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat64, [this](const nlohmann::json& argumentsArray){
            emit sigFloat64(argumentsArray[0].get<double>());}));
        static const QString topicsigString = interfaceName() + "/sig/sigString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString, [this](const nlohmann::json& argumentsArray){
            emit sigString(argumentsArray[0].get<QString>());}));
}
void MqttSimpleInterface::subscribeForInvokeResponses()
{
    // Subscribe for invokeReply and prepare invoke call info for non void functions.
    const QString topicfuncBool = interfaceName() + "/rpc/funcBool";
    const QString topicfuncBoolInvokeResp = interfaceName() + "/rpc/funcBool"+ m_client.clientId() + "/result";
    auto id_funcBool = m_client.subscribeForInvokeResponse(topicfuncBoolInvokeResp);
    m_InvokeCallsInfo[topicfuncBool] = std::make_pair(topicfuncBoolInvokeResp, id_funcBool);
    const QString topicfuncInt = interfaceName() + "/rpc/funcInt";
    const QString topicfuncIntInvokeResp = interfaceName() + "/rpc/funcInt"+ m_client.clientId() + "/result";
    auto id_funcInt = m_client.subscribeForInvokeResponse(topicfuncIntInvokeResp);
    m_InvokeCallsInfo[topicfuncInt] = std::make_pair(topicfuncIntInvokeResp, id_funcInt);
    const QString topicfuncInt32 = interfaceName() + "/rpc/funcInt32";
    const QString topicfuncInt32InvokeResp = interfaceName() + "/rpc/funcInt32"+ m_client.clientId() + "/result";
    auto id_funcInt32 = m_client.subscribeForInvokeResponse(topicfuncInt32InvokeResp);
    m_InvokeCallsInfo[topicfuncInt32] = std::make_pair(topicfuncInt32InvokeResp, id_funcInt32);
    const QString topicfuncInt64 = interfaceName() + "/rpc/funcInt64";
    const QString topicfuncInt64InvokeResp = interfaceName() + "/rpc/funcInt64"+ m_client.clientId() + "/result";
    auto id_funcInt64 = m_client.subscribeForInvokeResponse(topicfuncInt64InvokeResp);
    m_InvokeCallsInfo[topicfuncInt64] = std::make_pair(topicfuncInt64InvokeResp, id_funcInt64);
    const QString topicfuncFloat = interfaceName() + "/rpc/funcFloat";
    const QString topicfuncFloatInvokeResp = interfaceName() + "/rpc/funcFloat"+ m_client.clientId() + "/result";
    auto id_funcFloat = m_client.subscribeForInvokeResponse(topicfuncFloatInvokeResp);
    m_InvokeCallsInfo[topicfuncFloat] = std::make_pair(topicfuncFloatInvokeResp, id_funcFloat);
    const QString topicfuncFloat32 = interfaceName() + "/rpc/funcFloat32";
    const QString topicfuncFloat32InvokeResp = interfaceName() + "/rpc/funcFloat32"+ m_client.clientId() + "/result";
    auto id_funcFloat32 = m_client.subscribeForInvokeResponse(topicfuncFloat32InvokeResp);
    m_InvokeCallsInfo[topicfuncFloat32] = std::make_pair(topicfuncFloat32InvokeResp, id_funcFloat32);
    const QString topicfuncFloat64 = interfaceName() + "/rpc/funcFloat64";
    const QString topicfuncFloat64InvokeResp = interfaceName() + "/rpc/funcFloat64"+ m_client.clientId() + "/result";
    auto id_funcFloat64 = m_client.subscribeForInvokeResponse(topicfuncFloat64InvokeResp);
    m_InvokeCallsInfo[topicfuncFloat64] = std::make_pair(topicfuncFloat64InvokeResp, id_funcFloat64);
    const QString topicfuncString = interfaceName() + "/rpc/funcString";
    const QString topicfuncStringInvokeResp = interfaceName() + "/rpc/funcString"+ m_client.clientId() + "/result";
    auto id_funcString = m_client.subscribeForInvokeResponse(topicfuncStringInvokeResp);
    m_InvokeCallsInfo[topicfuncString] = std::make_pair(topicfuncStringInvokeResp, id_funcString);
}

void MqttSimpleInterface::unsubscribeAll()
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

} // namespace tb_simple

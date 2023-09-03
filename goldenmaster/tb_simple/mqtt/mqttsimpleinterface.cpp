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
const QString ID = "tb.simple/SimpleInterface";
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
}

MqttSimpleInterface::~MqttSimpleInterface()
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

void MqttSimpleInterface::setPropBool(bool propBool)
{
    static const QString topic = objectName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propBool });
}

void MqttSimpleInterface::setPropBoolLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(input.get<bool>());
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
    static const QString topic = objectName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt });
}

void MqttSimpleInterface::setPropIntLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(input.get<int>());
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
    static const QString topic = objectName() + QString("/set/propInt32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt32 });
}

void MqttSimpleInterface::setPropInt32Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt32(input.get<qint32>());
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
    static const QString topic = objectName() + QString("/set/propInt64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt64 });
}

void MqttSimpleInterface::setPropInt64Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt64(input.get<qint64>());
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
    static const QString topic = objectName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat });
}

void MqttSimpleInterface::setPropFloatLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(input.get<qreal>());
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
    static const QString topic = objectName() + QString("/set/propFloat32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat32 });
}

void MqttSimpleInterface::setPropFloat32Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat32(input.get<float>());
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
    static const QString topic = objectName() + QString("/set/propFloat64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat64 });
}

void MqttSimpleInterface::setPropFloat64Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat64(input.get<double>());
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
    static const QString topic = objectName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propString });
}

void MqttSimpleInterface::setPropStringLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(input.get<QString>());
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
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    auto arguments = nlohmann::json::array({});
    static const QString topic = objectName() + QString("/rpc/funcVoid");
    m_client.invokeRemoteNoResponse(topic, arguments);
}

QtPromise::QPromise<void> MqttSimpleInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcVoid");

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
    static const QString topic = objectName() + QString("/rpc/funcBool");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcInt");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcInt32");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcInt64");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcFloat");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcFloat32");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcFloat64");

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
                [resolve](const auto& arg)
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
    static const QString topic = objectName() + QString("/rpc/funcString");

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
                [resolve](const auto& arg)
                {
                    QString value = arg.get<QString>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttSimpleInterface::objectName()
{
    return ID;
}
void MqttSimpleInterface::subscribeForPropertiesChanges()
{
        static const QString topicpropBool = objectName() + "/prop/propBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropBool, [this](auto& input) { setPropBoolLocal(input);}));
        static const QString topicpropInt = objectName() + "/prop/propInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt, [this](auto& input) { setPropIntLocal(input);}));
        static const QString topicpropInt32 = objectName() + "/prop/propInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt32, [this](auto& input) { setPropInt32Local(input);}));
        static const QString topicpropInt64 = objectName() + "/prop/propInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt64, [this](auto& input) { setPropInt64Local(input);}));
        static const QString topicpropFloat = objectName() + "/prop/propFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat, [this](auto& input) { setPropFloatLocal(input);}));
        static const QString topicpropFloat32 = objectName() + "/prop/propFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat32, [this](auto& input) { setPropFloat32Local(input);}));
        static const QString topicpropFloat64 = objectName() + "/prop/propFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat64, [this](auto& input) { setPropFloat64Local(input);}));
        static const QString topicpropString = objectName() + "/prop/propString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropString, [this](auto& input) { setPropStringLocal(input);}));
}
void MqttSimpleInterface::subscribeForSignals()
{
        static const QString topicsigVoid = objectName() + "/sig/sigVoid";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigVoid, [this](const auto& input){
            emit sigVoid();}));
        static const QString topicsigBool = objectName() + "/sig/sigBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool, [this](const auto& input){
            emit sigBool(input[0].get<bool>());}));
        static const QString topicsigInt = objectName() + "/sig/sigInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt, [this](const auto& input){
            emit sigInt(input[0].get<int>());}));
        static const QString topicsigInt32 = objectName() + "/sig/sigInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt32, [this](const auto& input){
            emit sigInt32(input[0].get<qint32>());}));
        static const QString topicsigInt64 = objectName() + "/sig/sigInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt64, [this](const auto& input){
            emit sigInt64(input[0].get<qint64>());}));
        static const QString topicsigFloat = objectName() + "/sig/sigFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat, [this](const auto& input){
            emit sigFloat(input[0].get<qreal>());}));
        static const QString topicsigFloat32 = objectName() + "/sig/sigFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat32, [this](const auto& input){
            emit sigFloat32(input[0].get<float>());}));
        static const QString topicsigFloat64 = objectName() + "/sig/sigFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat64, [this](const auto& input){
            emit sigFloat64(input[0].get<double>());}));
        static const QString topicsigString = objectName() + "/sig/sigString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString, [this](const auto& input){
            emit sigString(input[0].get<QString>());}));
}
void MqttSimpleInterface::subscribeForInvokeResponses()
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
    const QString topicfuncInt32 = objectName() + "/rpc/funcInt32";
    const QString topicfuncInt32InvokeResp = objectName() + "/rpc/funcInt32"+ m_client.clientId() + "/result";
    auto id_funcInt32 = m_client.subscribeForInvokeResponse(topicfuncInt32InvokeResp);
    m_InvokeCallsInfo[topicfuncInt32] = std::make_pair(topicfuncInt32InvokeResp, id_funcInt32);
    const QString topicfuncInt64 = objectName() + "/rpc/funcInt64";
    const QString topicfuncInt64InvokeResp = objectName() + "/rpc/funcInt64"+ m_client.clientId() + "/result";
    auto id_funcInt64 = m_client.subscribeForInvokeResponse(topicfuncInt64InvokeResp);
    m_InvokeCallsInfo[topicfuncInt64] = std::make_pair(topicfuncInt64InvokeResp, id_funcInt64);
    const QString topicfuncFloat = objectName() + "/rpc/funcFloat";
    const QString topicfuncFloatInvokeResp = objectName() + "/rpc/funcFloat"+ m_client.clientId() + "/result";
    auto id_funcFloat = m_client.subscribeForInvokeResponse(topicfuncFloatInvokeResp);
    m_InvokeCallsInfo[topicfuncFloat] = std::make_pair(topicfuncFloatInvokeResp, id_funcFloat);
    const QString topicfuncFloat32 = objectName() + "/rpc/funcFloat32";
    const QString topicfuncFloat32InvokeResp = objectName() + "/rpc/funcFloat32"+ m_client.clientId() + "/result";
    auto id_funcFloat32 = m_client.subscribeForInvokeResponse(topicfuncFloat32InvokeResp);
    m_InvokeCallsInfo[topicfuncFloat32] = std::make_pair(topicfuncFloat32InvokeResp, id_funcFloat32);
    const QString topicfuncFloat64 = objectName() + "/rpc/funcFloat64";
    const QString topicfuncFloat64InvokeResp = objectName() + "/rpc/funcFloat64"+ m_client.clientId() + "/result";
    auto id_funcFloat64 = m_client.subscribeForInvokeResponse(topicfuncFloat64InvokeResp);
    m_InvokeCallsInfo[topicfuncFloat64] = std::make_pair(topicfuncFloat64InvokeResp, id_funcFloat64);
    const QString topicfuncString = objectName() + "/rpc/funcString";
    const QString topicfuncStringInvokeResp = objectName() + "/rpc/funcString"+ m_client.clientId() + "/result";
    auto id_funcString = m_client.subscribeForInvokeResponse(topicfuncStringInvokeResp);
    m_InvokeCallsInfo[topicfuncString] = std::make_pair(topicfuncStringInvokeResp, id_funcString);
}


} // namespace tb_simple

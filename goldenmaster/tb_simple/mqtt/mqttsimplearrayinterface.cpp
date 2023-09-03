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

#include "mqttsimplearrayinterface.h"

#include "tb_simple/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_simple {

namespace
{
const QString ID = "tb.simple/SimpleArrayInterface";
}

MqttSimpleArrayInterface::MqttSimpleArrayInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propInt32(QList<qint32>())
    , m_propInt64(QList<qint64>())
    , m_propFloat(QList<qreal>())
    , m_propFloat32(QList<float>())
    , m_propFloat64(QList<double>())
    , m_propString(QList<QString>())
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

MqttSimpleArrayInterface::~MqttSimpleArrayInterface()
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

void MqttSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    static const QString topic = objectName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propBool });
}

void MqttSimpleArrayInterface::setPropBoolLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(input.get<QList<bool>>());
    if (m_propBool != in_propBool)
    {
        m_propBool = in_propBool;
        emit propBoolChanged(in_propBool);
    }
}

QList<bool> MqttSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void MqttSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    static const QString topic = objectName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt });
}

void MqttSimpleArrayInterface::setPropIntLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(input.get<QList<int>>());
    if (m_propInt != in_propInt)
    {
        m_propInt = in_propInt;
        emit propIntChanged(in_propInt);
    }
}

QList<int> MqttSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void MqttSimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    static const QString topic = objectName() + QString("/set/propInt32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt32 });
}

void MqttSimpleArrayInterface::setPropInt32Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt32(input.get<QList<qint32>>());
    if (m_propInt32 != in_propInt32)
    {
        m_propInt32 = in_propInt32;
        emit propInt32Changed(in_propInt32);
    }
}

QList<qint32> MqttSimpleArrayInterface::propInt32() const
{
    return m_propInt32;
}

void MqttSimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    static const QString topic = objectName() + QString("/set/propInt64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propInt64 });
}

void MqttSimpleArrayInterface::setPropInt64Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt64(input.get<QList<qint64>>());
    if (m_propInt64 != in_propInt64)
    {
        m_propInt64 = in_propInt64;
        emit propInt64Changed(in_propInt64);
    }
}

QList<qint64> MqttSimpleArrayInterface::propInt64() const
{
    return m_propInt64;
}

void MqttSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    static const QString topic = objectName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat });
}

void MqttSimpleArrayInterface::setPropFloatLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(input.get<QList<qreal>>());
    if (m_propFloat != in_propFloat)
    {
        m_propFloat = in_propFloat;
        emit propFloatChanged(in_propFloat);
    }
}

QList<qreal> MqttSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void MqttSimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    static const QString topic = objectName() + QString("/set/propFloat32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat32 });
}

void MqttSimpleArrayInterface::setPropFloat32Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat32(input.get<QList<float>>());
    if (m_propFloat32 != in_propFloat32)
    {
        m_propFloat32 = in_propFloat32;
        emit propFloat32Changed(in_propFloat32);
    }
}

QList<float> MqttSimpleArrayInterface::propFloat32() const
{
    return m_propFloat32;
}

void MqttSimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    static const QString topic = objectName() + QString("/set/propFloat64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propFloat64 });
}

void MqttSimpleArrayInterface::setPropFloat64Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat64(input.get<QList<double>>());
    if (m_propFloat64 != in_propFloat64)
    {
        m_propFloat64 = in_propFloat64;
        emit propFloat64Changed(in_propFloat64);
    }
}

QList<double> MqttSimpleArrayInterface::propFloat64() const
{
    return m_propFloat64;
}

void MqttSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    static const QString topic = objectName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { propString });
}

void MqttSimpleArrayInterface::setPropStringLocal(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(input.get<QList<QString>>());
    if (m_propString != in_propString)
    {
        m_propString = in_propString;
        emit propStringChanged(in_propString);
    }
}

QList<QString> MqttSimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> MqttSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<bool>();
    }
    QList<bool> value{ QList<bool>() };
    funcBoolAsync(paramBool)
        .then([&](QList<bool> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<bool>> MqttSimpleArrayInterface::funcBoolAsync(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcBool");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<bool>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<bool>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramBool });       
    return QtPromise::QPromise<QList<bool>>{[&](
        const QtPromise::QPromiseResolve<QList<bool>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<bool> value = arg.get<QList<bool>>();
                    resolve(value);
                });
        }
    };
}

QList<int> MqttSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<int>();
    }
    QList<int> value{ QList<int>() };
    funcIntAsync(paramInt)
        .then([&](QList<int> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<int>> MqttSimpleArrayInterface::funcIntAsync(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcInt");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<int>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<int>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt });       
    return QtPromise::QPromise<QList<int>>{[&](
        const QtPromise::QPromiseResolve<QList<int>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<int> value = arg.get<QList<int>>();
                    resolve(value);
                });
        }
    };
}

QList<qint32> MqttSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<qint32>();
    }
    QList<qint32> value{ QList<qint32>() };
    funcInt32Async(paramInt32)
        .then([&](QList<qint32> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<qint32>> MqttSimpleArrayInterface::funcInt32Async(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcInt32");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<qint32>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<qint32>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt32 });       
    return QtPromise::QPromise<QList<qint32>>{[&](
        const QtPromise::QPromiseResolve<QList<qint32>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<qint32> value = arg.get<QList<qint32>>();
                    resolve(value);
                });
        }
    };
}

QList<qint64> MqttSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<qint64>();
    }
    QList<qint64> value{ QList<qint64>() };
    funcInt64Async(paramInt64)
        .then([&](QList<qint64> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<qint64>> MqttSimpleArrayInterface::funcInt64Async(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcInt64");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<qint64>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<qint64>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramInt64 });       
    return QtPromise::QPromise<QList<qint64>>{[&](
        const QtPromise::QPromiseResolve<QList<qint64>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<qint64> value = arg.get<QList<qint64>>();
                    resolve(value);
                });
        }
    };
}

QList<qreal> MqttSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<qreal>();
    }
    QList<qreal> value{ QList<qreal>() };
    funcFloatAsync(paramFloat)
        .then([&](QList<qreal> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<qreal>> MqttSimpleArrayInterface::funcFloatAsync(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcFloat");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<qreal>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<qreal>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat });       
    return QtPromise::QPromise<QList<qreal>>{[&](
        const QtPromise::QPromiseResolve<QList<qreal>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<qreal> value = arg.get<QList<qreal>>();
                    resolve(value);
                });
        }
    };
}

QList<float> MqttSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<float>();
    }
    QList<float> value{ QList<float>() };
    funcFloat32Async(paramFloat32)
        .then([&](QList<float> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<float>> MqttSimpleArrayInterface::funcFloat32Async(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcFloat32");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<float>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<float>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat32 });       
    return QtPromise::QPromise<QList<float>>{[&](
        const QtPromise::QPromiseResolve<QList<float>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<float> value = arg.get<QList<float>>();
                    resolve(value);
                });
        }
    };
}

QList<double> MqttSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<double>();
    }
    QList<double> value{ QList<double>() };
    funcFloat64Async(paramFloat)
        .then([&](QList<double> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<double>> MqttSimpleArrayInterface::funcFloat64Async(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcFloat64");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<double>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<double>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramFloat });       
    return QtPromise::QPromise<QList<double>>{[&](
        const QtPromise::QPromiseResolve<QList<double>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<double> value = arg.get<QList<double>>();
                    resolve(value);
                });
        }
    };
}

QList<QString> MqttSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return QList<QString>();
    }
    QList<QString> value{ QList<QString>() };
    funcStringAsync(paramString)
        .then([&](QList<QString> result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<QList<QString>> MqttSimpleArrayInterface::funcStringAsync(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/funcString");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<QList<QString>>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<QList<QString>>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({paramString });       
    return QtPromise::QPromise<QList<QString>>{[&](
        const QtPromise::QPromiseResolve<QList<QString>>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    QList<QString> value = arg.get<QList<QString>>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttSimpleArrayInterface::objectName()
{
    return ID;
}
void MqttSimpleArrayInterface::subscribeForPropertiesChanges()
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
void MqttSimpleArrayInterface::subscribeForSignals()
{
        static const QString topicsigBool = objectName() + "/sig/sigBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool, [this](const auto& input){
            emit sigBool(input[0].get<QList<bool>>());}));
        static const QString topicsigInt = objectName() + "/sig/sigInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt, [this](const auto& input){
            emit sigInt(input[0].get<QList<int>>());}));
        static const QString topicsigInt32 = objectName() + "/sig/sigInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt32, [this](const auto& input){
            emit sigInt32(input[0].get<QList<qint32>>());}));
        static const QString topicsigInt64 = objectName() + "/sig/sigInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt64, [this](const auto& input){
            emit sigInt64(input[0].get<QList<qint64>>());}));
        static const QString topicsigFloat = objectName() + "/sig/sigFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat, [this](const auto& input){
            emit sigFloat(input[0].get<QList<qreal>>());}));
        static const QString topicsigFloat32 = objectName() + "/sig/sigFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat32, [this](const auto& input){
            emit sigFloat32(input[0].get<QList<float>>());}));
        static const QString topicsigFloat64 = objectName() + "/sig/sigFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat64, [this](const auto& input){
            emit sigFloat64(input[0].get<QList<double>>());}));
        static const QString topicsigString = objectName() + "/sig/sigString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString, [this](const auto& input){
            emit sigString(input[0].get<QList<QString>>());}));
}
void MqttSimpleArrayInterface::subscribeForInvokeResponses()
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

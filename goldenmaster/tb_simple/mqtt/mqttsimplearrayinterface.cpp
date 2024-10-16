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
const QString InterfaceName = "tb.simple/SimpleArrayInterface";
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
    , m_propReadOnlyString(QString())
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

MqttSimpleArrayInterface::~MqttSimpleArrayInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    static const QString topic = interfaceName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propBool ));
}

void MqttSimpleArrayInterface::setPropBoolLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(value.get<QList<bool>>());
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
    static const QString topic = interfaceName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt ));
}

void MqttSimpleArrayInterface::setPropIntLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(value.get<QList<int>>());
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
    static const QString topic = interfaceName() + QString("/set/propInt32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt32 ));
}

void MqttSimpleArrayInterface::setPropInt32Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt32(value.get<QList<qint32>>());
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
    static const QString topic = interfaceName() + QString("/set/propInt64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt64 ));
}

void MqttSimpleArrayInterface::setPropInt64Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt64(value.get<QList<qint64>>());
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
    static const QString topic = interfaceName() + QString("/set/propFloat");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat ));
}

void MqttSimpleArrayInterface::setPropFloatLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat(value.get<QList<qreal>>());
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
    static const QString topic = interfaceName() + QString("/set/propFloat32");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat32 ));
}

void MqttSimpleArrayInterface::setPropFloat32Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat32(value.get<QList<float>>());
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
    static const QString topic = interfaceName() + QString("/set/propFloat64");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propFloat64 ));
}

void MqttSimpleArrayInterface::setPropFloat64Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propFloat64(value.get<QList<double>>());
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
    static const QString topic = interfaceName() + QString("/set/propString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propString ));
}

void MqttSimpleArrayInterface::setPropStringLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propString(value.get<QList<QString>>());
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

void MqttSimpleArrayInterface::setPropReadOnlyString(const QString& propReadOnlyString)
{
    static const QString topic = interfaceName() + QString("/set/propReadOnlyString");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propReadOnlyString ));
}

void MqttSimpleArrayInterface::setPropReadOnlyStringLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propReadOnlyString(value.get<QString>());
    if (m_propReadOnlyString != in_propReadOnlyString)
    {
        m_propReadOnlyString = in_propReadOnlyString;
        emit propReadOnlyStringChanged(in_propReadOnlyString);
    }
}

QString MqttSimpleArrayInterface::propReadOnlyString() const
{
    return m_propReadOnlyString;
}

QList<bool> MqttSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<bool>> MqttSimpleArrayInterface::funcBoolAsync(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcBool");
    auto promise = std::make_shared<QPromise<QList<bool>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<bool>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<bool>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramBool });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<bool> value = arg.get<QList<bool>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<int> MqttSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<int>> MqttSimpleArrayInterface::funcIntAsync(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt");
    auto promise = std::make_shared<QPromise<QList<int>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<int>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<int>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<int> value = arg.get<QList<int>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<qint32> MqttSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcInt32Async(paramInt32);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<qint32>> MqttSimpleArrayInterface::funcInt32Async(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt32");
    auto promise = std::make_shared<QPromise<QList<qint32>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<qint32>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<qint32>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt32 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<qint32> value = arg.get<QList<qint32>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<qint64> MqttSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcInt64Async(paramInt64);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<qint64>> MqttSimpleArrayInterface::funcInt64Async(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt64");
    auto promise = std::make_shared<QPromise<QList<qint64>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<qint64>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<qint64>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt64 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<qint64> value = arg.get<QList<qint64>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<qreal> MqttSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<qreal>> MqttSimpleArrayInterface::funcFloatAsync(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat");
    auto promise = std::make_shared<QPromise<QList<qreal>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<qreal>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<qreal>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<qreal> value = arg.get<QList<qreal>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<float> MqttSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloat32Async(paramFloat32);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<float>> MqttSimpleArrayInterface::funcFloat32Async(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat32");
    auto promise = std::make_shared<QPromise<QList<float>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<float>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<float>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat32 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<float> value = arg.get<QList<float>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<double> MqttSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloat64Async(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<double>> MqttSimpleArrayInterface::funcFloat64Async(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat64");
    auto promise = std::make_shared<QPromise<QList<double>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<double>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<double>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<double> value = arg.get<QList<double>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QList<QString> MqttSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<QString>> MqttSimpleArrayInterface::funcStringAsync(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcString");
    auto promise = std::make_shared<QPromise<QList<QString>>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<QString>());
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QList<QString>());
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramString });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QList<QString> value = arg.get<QList<QString>>();
            promise->addResult(value);
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttSimpleArrayInterface::interfaceName()
{
    return InterfaceName;
}
void MqttSimpleArrayInterface::subscribeForPropertiesChanges()
{
        const QString topicpropBool = interfaceName() + "/prop/propBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropBool, [this](auto& value) { setPropBoolLocal(value);}));
        const QString topicpropInt = interfaceName() + "/prop/propInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt, [this](auto& value) { setPropIntLocal(value);}));
        const QString topicpropInt32 = interfaceName() + "/prop/propInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt32, [this](auto& value) { setPropInt32Local(value);}));
        const QString topicpropInt64 = interfaceName() + "/prop/propInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt64, [this](auto& value) { setPropInt64Local(value);}));
        const QString topicpropFloat = interfaceName() + "/prop/propFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat, [this](auto& value) { setPropFloatLocal(value);}));
        const QString topicpropFloat32 = interfaceName() + "/prop/propFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat32, [this](auto& value) { setPropFloat32Local(value);}));
        const QString topicpropFloat64 = interfaceName() + "/prop/propFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat64, [this](auto& value) { setPropFloat64Local(value);}));
        const QString topicpropString = interfaceName() + "/prop/propString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropString, [this](auto& value) { setPropStringLocal(value);}));
        const QString topicpropReadOnlyString = interfaceName() + "/prop/propReadOnlyString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropReadOnlyString, [this](auto& value) { setPropReadOnlyStringLocal(value);}));
}
void MqttSimpleArrayInterface::subscribeForSignals()
{
        const QString topicsigBool = interfaceName() + "/sig/sigBool";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool, [this](const nlohmann::json& argumentsArray){
            emit sigBool(argumentsArray[0].get<QList<bool>>());}));
        const QString topicsigInt = interfaceName() + "/sig/sigInt";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt, [this](const nlohmann::json& argumentsArray){
            emit sigInt(argumentsArray[0].get<QList<int>>());}));
        const QString topicsigInt32 = interfaceName() + "/sig/sigInt32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt32, [this](const nlohmann::json& argumentsArray){
            emit sigInt32(argumentsArray[0].get<QList<qint32>>());}));
        const QString topicsigInt64 = interfaceName() + "/sig/sigInt64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt64, [this](const nlohmann::json& argumentsArray){
            emit sigInt64(argumentsArray[0].get<QList<qint64>>());}));
        const QString topicsigFloat = interfaceName() + "/sig/sigFloat";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat, [this](const nlohmann::json& argumentsArray){
            emit sigFloat(argumentsArray[0].get<QList<qreal>>());}));
        const QString topicsigFloat32 = interfaceName() + "/sig/sigFloat32";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat32, [this](const nlohmann::json& argumentsArray){
            emit sigFloat32(argumentsArray[0].get<QList<float>>());}));
        const QString topicsigFloat64 = interfaceName() + "/sig/sigFloat64";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat64, [this](const nlohmann::json& argumentsArray){
            emit sigFloat64(argumentsArray[0].get<QList<double>>());}));
        const QString topicsigString = interfaceName() + "/sig/sigString";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString, [this](const nlohmann::json& argumentsArray){
            emit sigString(argumentsArray[0].get<QList<QString>>());}));
}
void MqttSimpleArrayInterface::subscribeForInvokeResponses()
{
    const QString topicfuncBool = interfaceName() + "/rpc/funcBool";
    const QString topicfuncBoolInvokeResp = interfaceName() + "/rpc/funcBool"+ m_client.clientId() + "/result";
    auto id_funcBool = m_client.subscribeForInvokeResponse(topicfuncBoolInvokeResp, 
                        [this, topicfuncBoolInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncBoolInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncBool] = std::make_pair(topicfuncBoolInvokeResp, id_funcBool);
    const QString topicfuncInt = interfaceName() + "/rpc/funcInt";
    const QString topicfuncIntInvokeResp = interfaceName() + "/rpc/funcInt"+ m_client.clientId() + "/result";
    auto id_funcInt = m_client.subscribeForInvokeResponse(topicfuncIntInvokeResp, 
                        [this, topicfuncIntInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncIntInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncInt] = std::make_pair(topicfuncIntInvokeResp, id_funcInt);
    const QString topicfuncInt32 = interfaceName() + "/rpc/funcInt32";
    const QString topicfuncInt32InvokeResp = interfaceName() + "/rpc/funcInt32"+ m_client.clientId() + "/result";
    auto id_funcInt32 = m_client.subscribeForInvokeResponse(topicfuncInt32InvokeResp, 
                        [this, topicfuncInt32InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncInt32InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncInt32] = std::make_pair(topicfuncInt32InvokeResp, id_funcInt32);
    const QString topicfuncInt64 = interfaceName() + "/rpc/funcInt64";
    const QString topicfuncInt64InvokeResp = interfaceName() + "/rpc/funcInt64"+ m_client.clientId() + "/result";
    auto id_funcInt64 = m_client.subscribeForInvokeResponse(topicfuncInt64InvokeResp, 
                        [this, topicfuncInt64InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncInt64InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncInt64] = std::make_pair(topicfuncInt64InvokeResp, id_funcInt64);
    const QString topicfuncFloat = interfaceName() + "/rpc/funcFloat";
    const QString topicfuncFloatInvokeResp = interfaceName() + "/rpc/funcFloat"+ m_client.clientId() + "/result";
    auto id_funcFloat = m_client.subscribeForInvokeResponse(topicfuncFloatInvokeResp, 
                        [this, topicfuncFloatInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncFloatInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncFloat] = std::make_pair(topicfuncFloatInvokeResp, id_funcFloat);
    const QString topicfuncFloat32 = interfaceName() + "/rpc/funcFloat32";
    const QString topicfuncFloat32InvokeResp = interfaceName() + "/rpc/funcFloat32"+ m_client.clientId() + "/result";
    auto id_funcFloat32 = m_client.subscribeForInvokeResponse(topicfuncFloat32InvokeResp, 
                        [this, topicfuncFloat32InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncFloat32InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncFloat32] = std::make_pair(topicfuncFloat32InvokeResp, id_funcFloat32);
    const QString topicfuncFloat64 = interfaceName() + "/rpc/funcFloat64";
    const QString topicfuncFloat64InvokeResp = interfaceName() + "/rpc/funcFloat64"+ m_client.clientId() + "/result";
    auto id_funcFloat64 = m_client.subscribeForInvokeResponse(topicfuncFloat64InvokeResp, 
                        [this, topicfuncFloat64InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncFloat64InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncFloat64] = std::make_pair(topicfuncFloat64InvokeResp, id_funcFloat64);
    const QString topicfuncString = interfaceName() + "/rpc/funcString";
    const QString topicfuncStringInvokeResp = interfaceName() + "/rpc/funcString"+ m_client.clientId() + "/result";
    auto id_funcString = m_client.subscribeForInvokeResponse(topicfuncStringInvokeResp, 
                        [this, topicfuncStringInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncStringInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncString] = std::make_pair(topicfuncStringInvokeResp, id_funcString);
}

void MqttSimpleArrayInterface::unsubscribeAll()
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

void MqttSimpleArrayInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

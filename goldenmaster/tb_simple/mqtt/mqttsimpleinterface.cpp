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

MqttSimpleInterface::~MqttSimpleInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

bool MqttSimpleInterface::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
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

void MqttSimpleInterface::funcNoReturnValue(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcNoReturnValueAsync(paramBool);
    future.waitForFinished();
    return;
}

QFuture<void> MqttSimpleInterface::funcNoReturnValueAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcNoReturnValue");
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
    auto arguments = nlohmann::json::array({paramBool });       

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

bool MqttSimpleInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<bool> MqttSimpleInterface::funcBoolAsync(bool paramBool)
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

int MqttSimpleInterface::funcInt(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<int> MqttSimpleInterface::funcIntAsync(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt");
    auto promise = std::make_shared<QPromise<int>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(0);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt });       

    auto func = [promise](const nlohmann::json& arg)
        {
            int value = arg.get<int>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

qint32 MqttSimpleInterface::funcInt32(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcInt32Async(paramInt32);
    future.waitForFinished();
    return future.result();
}

QFuture<qint32> MqttSimpleInterface::funcInt32Async(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt32");
    auto promise = std::make_shared<QPromise<qint32>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(0);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt32 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            qint32 value = arg.get<qint32>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

qint64 MqttSimpleInterface::funcInt64(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcInt64Async(paramInt64);
    future.waitForFinished();
    return future.result();
}

QFuture<qint64> MqttSimpleInterface::funcInt64Async(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcInt64");
    auto promise = std::make_shared<QPromise<qint64>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0LL);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(0LL);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramInt64 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            qint64 value = arg.get<qint64>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

qreal MqttSimpleInterface::funcFloat(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<qreal> MqttSimpleInterface::funcFloatAsync(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat");
    auto promise = std::make_shared<QPromise<qreal>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0.0f);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(0.0f);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat });       

    auto func = [promise](const nlohmann::json& arg)
        {
            qreal value = arg.get<qreal>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

float MqttSimpleInterface::funcFloat32(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloat32Async(paramFloat32);
    future.waitForFinished();
    return future.result();
}

QFuture<float> MqttSimpleInterface::funcFloat32Async(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat32");
    auto promise = std::make_shared<QPromise<float>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0.0f);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(0.0f);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat32 });       

    auto func = [promise](const nlohmann::json& arg)
        {
            float value = arg.get<float>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

double MqttSimpleInterface::funcFloat64(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcFloat64Async(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<double> MqttSimpleInterface::funcFloat64Async(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcFloat64");
    auto promise = std::make_shared<QPromise<double>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(0.0);
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(0.0);
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramFloat });       

    auto func = [promise](const nlohmann::json& arg)
        {
            double value = arg.get<double>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

QString MqttSimpleInterface::funcString(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);

    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<QString> MqttSimpleInterface::funcStringAsync(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/funcString");
    auto promise = std::make_shared<QPromise<QString>>();
    promise->start();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
            promise->addResult(QString());
        promise->finish();
        return promise->future();
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        promise->addResult(QString());
        promise->finish();
        return promise->future();
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({paramString });       

    auto func = [promise](const nlohmann::json& arg)
        {
            QString value = arg.get<QString>();
            promise->addResult(value);
            promise->finish();
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}


const QString& MqttSimpleInterface::interfaceName()
{
    return InterfaceName;
}

void MqttSimpleInterface::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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
void MqttSimpleInterface::subscribeForPropertiesChanges()
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
        const QString topicpropInt32 = interfaceName() + "/prop/propInt32";
        m_pendingSubscriptions.push_back(topicpropInt32);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt32,
            [this, topicpropInt32](auto id, bool hasSucceed){handleOnSubscribed(topicpropInt32, id, hasSucceed);},
            [this](auto& value) { setPropInt32Local(value);}));
        const QString topicpropInt64 = interfaceName() + "/prop/propInt64";
        m_pendingSubscriptions.push_back(topicpropInt64);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropInt64,
            [this, topicpropInt64](auto id, bool hasSucceed){handleOnSubscribed(topicpropInt64, id, hasSucceed);},
            [this](auto& value) { setPropInt64Local(value);}));
        const QString topicpropFloat = interfaceName() + "/prop/propFloat";
        m_pendingSubscriptions.push_back(topicpropFloat);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat,
            [this, topicpropFloat](auto id, bool hasSucceed){handleOnSubscribed(topicpropFloat, id, hasSucceed);},
            [this](auto& value) { setPropFloatLocal(value);}));
        const QString topicpropFloat32 = interfaceName() + "/prop/propFloat32";
        m_pendingSubscriptions.push_back(topicpropFloat32);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat32,
            [this, topicpropFloat32](auto id, bool hasSucceed){handleOnSubscribed(topicpropFloat32, id, hasSucceed);},
            [this](auto& value) { setPropFloat32Local(value);}));
        const QString topicpropFloat64 = interfaceName() + "/prop/propFloat64";
        m_pendingSubscriptions.push_back(topicpropFloat64);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropFloat64,
            [this, topicpropFloat64](auto id, bool hasSucceed){handleOnSubscribed(topicpropFloat64, id, hasSucceed);},
            [this](auto& value) { setPropFloat64Local(value);}));
        const QString topicpropString = interfaceName() + "/prop/propString";
        m_pendingSubscriptions.push_back(topicpropString);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicpropString,
            [this, topicpropString](auto id, bool hasSucceed){handleOnSubscribed(topicpropString, id, hasSucceed);},
            [this](auto& value) { setPropStringLocal(value);}));
}
void MqttSimpleInterface::subscribeForSignals()
{
        const QString topicsigBool = interfaceName() + "/sig/sigBool";
        m_pendingSubscriptions.push_back(topicsigBool);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigBool,
            [this, topicsigBool](auto id, bool hasSucceed){handleOnSubscribed(topicsigBool, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigBool(argumentsArray[0].get<bool>());}));
        const QString topicsigInt = interfaceName() + "/sig/sigInt";
        m_pendingSubscriptions.push_back(topicsigInt);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt,
            [this, topicsigInt](auto id, bool hasSucceed){handleOnSubscribed(topicsigInt, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigInt(argumentsArray[0].get<int>());}));
        const QString topicsigInt32 = interfaceName() + "/sig/sigInt32";
        m_pendingSubscriptions.push_back(topicsigInt32);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt32,
            [this, topicsigInt32](auto id, bool hasSucceed){handleOnSubscribed(topicsigInt32, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigInt32(argumentsArray[0].get<qint32>());}));
        const QString topicsigInt64 = interfaceName() + "/sig/sigInt64";
        m_pendingSubscriptions.push_back(topicsigInt64);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigInt64,
            [this, topicsigInt64](auto id, bool hasSucceed){handleOnSubscribed(topicsigInt64, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigInt64(argumentsArray[0].get<qint64>());}));
        const QString topicsigFloat = interfaceName() + "/sig/sigFloat";
        m_pendingSubscriptions.push_back(topicsigFloat);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat,
            [this, topicsigFloat](auto id, bool hasSucceed){handleOnSubscribed(topicsigFloat, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigFloat(argumentsArray[0].get<qreal>());}));
        const QString topicsigFloat32 = interfaceName() + "/sig/sigFloat32";
        m_pendingSubscriptions.push_back(topicsigFloat32);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat32,
            [this, topicsigFloat32](auto id, bool hasSucceed){handleOnSubscribed(topicsigFloat32, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigFloat32(argumentsArray[0].get<float>());}));
        const QString topicsigFloat64 = interfaceName() + "/sig/sigFloat64";
        m_pendingSubscriptions.push_back(topicsigFloat64);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigFloat64,
            [this, topicsigFloat64](auto id, bool hasSucceed){handleOnSubscribed(topicsigFloat64, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigFloat64(argumentsArray[0].get<double>());}));
        const QString topicsigString = interfaceName() + "/sig/sigString";
        m_pendingSubscriptions.push_back(topicsigString);
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsigString,
            [this, topicsigString](auto id, bool hasSucceed){handleOnSubscribed(topicsigString, id, hasSucceed);},
            [this](const nlohmann::json& argumentsArray){ emit sigString(argumentsArray[0].get<QString>());}));
}
void MqttSimpleInterface::subscribeForInvokeResponses()
{
    const QString topicfuncNoReturnValue = interfaceName() + "/rpc/funcNoReturnValue";
    const QString topicfuncNoReturnValueInvokeResp = interfaceName() + "/rpc/funcNoReturnValue"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncNoReturnValueInvokeResp);
    auto id_funcNoReturnValue = m_client.subscribeForInvokeResponse(topicfuncNoReturnValueInvokeResp, 
                        [this, topicfuncNoReturnValueInvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncNoReturnValueInvokeResp, id, hasSucceed);},
                        [this, topicfuncNoReturnValueInvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncNoReturnValueInvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncNoReturnValue] = std::make_pair(topicfuncNoReturnValueInvokeResp, id_funcNoReturnValue);
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
    const QString topicfuncInt32 = interfaceName() + "/rpc/funcInt32";
    const QString topicfuncInt32InvokeResp = interfaceName() + "/rpc/funcInt32"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncInt32InvokeResp);
    auto id_funcInt32 = m_client.subscribeForInvokeResponse(topicfuncInt32InvokeResp, 
                        [this, topicfuncInt32InvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncInt32InvokeResp, id, hasSucceed);},
                        [this, topicfuncInt32InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncInt32InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncInt32] = std::make_pair(topicfuncInt32InvokeResp, id_funcInt32);
    const QString topicfuncInt64 = interfaceName() + "/rpc/funcInt64";
    const QString topicfuncInt64InvokeResp = interfaceName() + "/rpc/funcInt64"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncInt64InvokeResp);
    auto id_funcInt64 = m_client.subscribeForInvokeResponse(topicfuncInt64InvokeResp, 
                        [this, topicfuncInt64InvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncInt64InvokeResp, id, hasSucceed);},
                        [this, topicfuncInt64InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncInt64InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncInt64] = std::make_pair(topicfuncInt64InvokeResp, id_funcInt64);
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
    const QString topicfuncFloat32 = interfaceName() + "/rpc/funcFloat32";
    const QString topicfuncFloat32InvokeResp = interfaceName() + "/rpc/funcFloat32"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncFloat32InvokeResp);
    auto id_funcFloat32 = m_client.subscribeForInvokeResponse(topicfuncFloat32InvokeResp, 
                        [this, topicfuncFloat32InvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncFloat32InvokeResp, id, hasSucceed);},
                        [this, topicfuncFloat32InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncFloat32InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncFloat32] = std::make_pair(topicfuncFloat32InvokeResp, id_funcFloat32);
    const QString topicfuncFloat64 = interfaceName() + "/rpc/funcFloat64";
    const QString topicfuncFloat64InvokeResp = interfaceName() + "/rpc/funcFloat64"+ m_client.clientId() + "/result";
    m_pendingSubscriptions.push_back(topicfuncFloat64InvokeResp);
    auto id_funcFloat64 = m_client.subscribeForInvokeResponse(topicfuncFloat64InvokeResp, 
                        [this, topicfuncFloat64InvokeResp](auto id, bool hasSucceed){handleOnSubscribed(topicfuncFloat64InvokeResp, id, hasSucceed);},
                        [this, topicfuncFloat64InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topicfuncFloat64InvokeResp);
                        });
    m_InvokeCallsInfo[topicfuncFloat64] = std::make_pair(topicfuncFloat64InvokeResp, id_funcFloat64);
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

void MqttSimpleInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

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

#include "mqttnam_es.h"

#include "tb_names/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_names {

namespace
{
const QString InterfaceName = "tb.names/Nam_Es";
}

MqttNam_Es::MqttNam_Es(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractNamEs(parent)
    , m_Switch(false)
    , m_SOME_PROPERTY(0)
    , m_Some_Poperty2(0)
    , m_isReady(false)
    , m_client(client)
{
    if (m_client.isReady())
    {
        subscribeForPropertiesChanges();
        subscribeForSignals();
    }
     connect(&m_client, &ApiGear::Mqtt::Client::ready, [this](){
        AG_LOG_DEBUG(Q_FUNC_INFO);
            subscribeForPropertiesChanges();
            subscribeForSignals();
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
}

MqttNam_Es::~MqttNam_Es()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttNam_Es::setSwitch(bool Switch)
{
    static const QString topic = interfaceName() + QString("/set/Switch");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( Switch ));
}

void MqttNam_Es::setSwitchLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_Switch(value.get<bool>());
    if (m_Switch != in_Switch)
    {
        m_Switch = in_Switch;
        emit SwitchChanged(in_Switch);
    }
}

bool MqttNam_Es::Switch() const
{
    return m_Switch;
}

void MqttNam_Es::setSomeProperty(int SOME_PROPERTY)
{
    static const QString topic = interfaceName() + QString("/set/SOME_PROPERTY");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( SOME_PROPERTY ));
}

void MqttNam_Es::setSomePropertyLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_SOME_PROPERTY(value.get<int>());
    if (m_SOME_PROPERTY != in_SOME_PROPERTY)
    {
        m_SOME_PROPERTY = in_SOME_PROPERTY;
        emit SOME_PROPERTYChanged(in_SOME_PROPERTY);
    }
}

int MqttNam_Es::SOME_PROPERTY() const
{
    return m_SOME_PROPERTY;
}

void MqttNam_Es::setSomePoperty2(int Some_Poperty2)
{
    static const QString topic = interfaceName() + QString("/set/Some_Poperty2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( Some_Poperty2 ));
}

void MqttNam_Es::setSomePoperty2Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_Some_Poperty2(value.get<int>());
    if (m_Some_Poperty2 != in_Some_Poperty2)
    {
        m_Some_Poperty2 = in_Some_Poperty2;
        emit Some_Poperty2Changed(in_Some_Poperty2);
    }
}

int MqttNam_Es::Some_Poperty2() const
{
    return m_Some_Poperty2;
}

void MqttNam_Es::someFunction(bool SOME_PARAM)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return;
    }
    auto arguments = nlohmann::json::array({SOME_PARAM});
    static const QString topic = interfaceName() + QString("/rpc/SOME_FUNCTION");
    m_client.invokeRemoteNoResponse(topic, arguments);
}

QtPromise::QPromise<void> MqttNam_Es::someFunctionAsync(bool SOME_PARAM)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/SOME_FUNCTION");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    auto arguments = nlohmann::json::array({SOME_PARAM });
    m_client.invokeRemoteNoResponse(topic, arguments);
    return QtPromise::QPromise<void>::resolve();
}

void MqttNam_Es::someFunction2(bool Some_Param)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return;
    }
    auto arguments = nlohmann::json::array({Some_Param});
    static const QString topic = interfaceName() + QString("/rpc/Some_Function2");
    m_client.invokeRemoteNoResponse(topic, arguments);
}

QtPromise::QPromise<void> MqttNam_Es::someFunction2Async(bool Some_Param)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/Some_Function2");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    auto arguments = nlohmann::json::array({Some_Param });
    m_client.invokeRemoteNoResponse(topic, arguments);
    return QtPromise::QPromise<void>::resolve();
}


const QString& MqttNam_Es::interfaceName()
{
    return InterfaceName;
}
void MqttNam_Es::subscribeForPropertiesChanges()
{
        static const QString topicSwitch = interfaceName() + "/prop/Switch";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicSwitch, [this](auto& value) { setSwitchLocal(value);}));
        static const QString topicSOME_PROPERTY = interfaceName() + "/prop/SOME_PROPERTY";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicSOME_PROPERTY, [this](auto& value) { setSomePropertyLocal(value);}));
        static const QString topicSome_Poperty2 = interfaceName() + "/prop/Some_Poperty2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicSome_Poperty2, [this](auto& value) { setSomePoperty2Local(value);}));
}
void MqttNam_Es::subscribeForSignals()
{
        static const QString topicSOME_SIGNAL = interfaceName() + "/sig/SOME_SIGNAL";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicSOME_SIGNAL, [this](const nlohmann::json& argumentsArray){
            emit someSignal(argumentsArray[0].get<bool>());}));
        static const QString topicSome_Signal2 = interfaceName() + "/sig/Some_Signal2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicSome_Signal2, [this](const nlohmann::json& argumentsArray){
            emit someSignal2(argumentsArray[0].get<bool>());}));
}

void MqttNam_Es::unsubscribeAll()
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

void MqttNam_Es::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

} // namespace tb_names

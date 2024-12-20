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

#include "mqttnooperationsinterface.h"

#include "tb_simple/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/NoOperationsInterface";
}

MqttNoOperationsInterface::MqttNoOperationsInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractNoOperationsInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_finishedInitialization(false)
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
            m_finishedInitialization = true;
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
    m_finishedInitialization = m_client.isReady();
}

MqttNoOperationsInterface::~MqttNoOperationsInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

bool MqttNoOperationsInterface::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}

void MqttNoOperationsInterface::setPropBool(bool propBool)
{
    static const QString topic = interfaceName() + QString("/set/propBool");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propBool ));
}

void MqttNoOperationsInterface::setPropBoolLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propBool(value.get<bool>());
    if (m_propBool != in_propBool)
    {
        m_propBool = in_propBool;
        emit propBoolChanged(in_propBool);
    }
}

bool MqttNoOperationsInterface::propBool() const
{
    return m_propBool;
}

void MqttNoOperationsInterface::setPropInt(int propInt)
{
    static const QString topic = interfaceName() + QString("/set/propInt");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( propInt ));
}

void MqttNoOperationsInterface::setPropIntLocal(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_propInt(value.get<int>());
    if (m_propInt != in_propInt)
    {
        m_propInt = in_propInt;
        emit propIntChanged(in_propInt);
    }
}

int MqttNoOperationsInterface::propInt() const
{
    return m_propInt;
}


const QString& MqttNoOperationsInterface::interfaceName()
{
    return InterfaceName;
}

void MqttNoOperationsInterface::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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
void MqttNoOperationsInterface::subscribeForPropertiesChanges()
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
}
void MqttNoOperationsInterface::subscribeForSignals()
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

void MqttNoOperationsInterface::unsubscribeAll()
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

void MqttNoOperationsInterface::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
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

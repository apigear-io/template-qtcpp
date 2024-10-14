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


#include "mqttnooperationsinterfaceadapter.h"
#include "tb_simple/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/NoOperationsInterface";
}


MqttNoOperationsInterfaceAdapter::MqttNoOperationsInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNoOperationsInterface> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_finishedInitialization(false)
    , m_mqttServiceAdapter(mqttServiceAdapter)
{
    if (m_mqttServiceAdapter.isReady())
    {
        subscribeForPropertiesChanges();
        connectServicePropertiesChanges();
        connectServiceSignals();
    }
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, [this]()
    {
        subscribeForPropertiesChanges();
        connectServicePropertiesChanges();
        connectServiceSignals();
        m_finishedInitialization = true;
    });
    
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, [this](){
    AG_LOG_DEBUG(Q_FUNC_INFO);
        m_subscribedIds.clear();
    });
    m_finishedInitialization = m_mqttServiceAdapter.isReady();
}

MqttNoOperationsInterfaceAdapter::~MqttNoOperationsInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttNoOperationsInterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttNoOperationsInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttNoOperationsInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_propBool = interfaceName() + "/set/propBool";
    m_pendingSubscriptions.push_back(setTopic_propBool);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propBool,
        [this, setTopic_propBool](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propBool, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            bool propBool = value.get<bool>();
            m_impl->setPropBool(propBool);
        }));
    const auto setTopic_propInt = interfaceName() + "/set/propInt";
    m_pendingSubscriptions.push_back(setTopic_propInt);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt,
        [this, setTopic_propInt](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propInt, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            int propInt = value.get<int>();
            m_impl->setPropInt(propInt);
        }));
}


void MqttNoOperationsInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_propBool = interfaceName() + "/prop/propBool";
    connect(m_impl.get(),&AbstractNoOperationsInterface::propBoolChanged,
        this, [this, publishTopic_propBool](bool propBool)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propBool, propBool);
        });
    const auto publishTopic_propInt = interfaceName() + "/prop/propInt";
    connect(m_impl.get(),&AbstractNoOperationsInterface::propIntChanged,
        this, [this, publishTopic_propInt](int propInt)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt, propInt);
        });    
}

void MqttNoOperationsInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigVoid = interfaceName() + "/sig/sigVoid";
    connect(m_impl.get(), &AbstractNoOperationsInterface::sigVoid, this,
        [this, topic_sigVoid]()
        {
            nlohmann::json args = {  };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigVoid, args);
        });
    const auto topic_sigBool = interfaceName() + "/sig/sigBool";
    connect(m_impl.get(), &AbstractNoOperationsInterface::sigBool, this,
        [this, topic_sigBool](bool paramBool)
        {
            nlohmann::json args = { paramBool };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigBool, args);
        });
}

void MqttNoOperationsInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttNoOperationsInterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

} // namespace tb_simple

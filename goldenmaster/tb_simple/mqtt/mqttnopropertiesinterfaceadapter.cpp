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


#include "mqttnopropertiesinterfaceadapter.h"
#include "tb_simple/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/NoPropertiesInterface";
}


MqttNoPropertiesInterfaceAdapter::MqttNoPropertiesInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNoPropertiesInterface> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_finishedInitialization(false)
    , m_mqttServiceAdapter(mqttServiceAdapter)
{
    if (m_mqttServiceAdapter.isReady())
    {
        subscribeForInvokeRequests();
        connectServiceSignals();
    }
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, [this]()
    {
        subscribeForInvokeRequests();
        connectServiceSignals();
        m_finishedInitialization = true;
    });
    
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, [this](){
    AG_LOG_DEBUG(Q_FUNC_INFO);
        m_subscribedIds.clear();
    });
    m_finishedInitialization = m_mqttServiceAdapter.isReady();
}

MqttNoPropertiesInterfaceAdapter::~MqttNoPropertiesInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttNoPropertiesInterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttNoPropertiesInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}


void MqttNoPropertiesInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_funcVoid = interfaceName() + "/rpc/funcVoid";
    m_pendingSubscriptions.push_back(invokeTopic_funcVoid);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcVoid,
        [this, invokeTopic_funcVoid](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcVoid, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            m_impl->funcVoid( );
            return nlohmann::json {};
        }));
    const auto invokeTopic_funcBool = interfaceName() + "/rpc/funcBool";
    m_pendingSubscriptions.push_back(invokeTopic_funcBool);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcBool,
        [this, invokeTopic_funcBool](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcBool, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            bool paramBool = arguments.at(0).get<bool>();
            auto result = m_impl->funcBool(paramBool);
            return result;
        }));
}


void MqttNoPropertiesInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigVoid = interfaceName() + "/sig/sigVoid";
    connect(m_impl.get(), &AbstractNoPropertiesInterface::sigVoid, this,
        [this, topic_sigVoid]()
        {
            nlohmann::json args = {  };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigVoid, args);
        });
    const auto topic_sigBool = interfaceName() + "/sig/sigBool";
    connect(m_impl.get(), &AbstractNoPropertiesInterface::sigBool, this,
        [this, topic_sigBool](bool paramBool)
        {
            nlohmann::json args = { paramBool };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigBool, args);
        });
}

void MqttNoPropertiesInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttNoPropertiesInterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

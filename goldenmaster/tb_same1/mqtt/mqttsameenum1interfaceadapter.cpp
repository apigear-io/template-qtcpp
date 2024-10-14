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


#include "mqttsameenum1interfaceadapter.h"
#include "tb_same1/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_same1 {

namespace
{
const QString InterfaceName = "tb.same1/SameEnum1Interface";
}


MqttSameEnum1InterfaceAdapter::MqttSameEnum1InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractSameEnum1Interface> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_finishedInitialization(false)
    , m_mqttServiceAdapter(mqttServiceAdapter)
{
    if (m_mqttServiceAdapter.isReady())
    {
        subscribeForPropertiesChanges();
        subscribeForInvokeRequests();
        connectServicePropertiesChanges();
        connectServiceSignals();
    }
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, [this]()
    {
        subscribeForPropertiesChanges();
        subscribeForInvokeRequests();
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

MqttSameEnum1InterfaceAdapter::~MqttSameEnum1InterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttSameEnum1InterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttSameEnum1InterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttSameEnum1InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = interfaceName() + "/set/prop1";
    m_pendingSubscriptions.push_back(setTopic_prop1);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this, setTopic_prop1](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop1, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            Enum1::Enum1Enum prop1 = value.get<Enum1::Enum1Enum>();
            m_impl->setProp1(prop1);
        }));
}

void MqttSameEnum1InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = interfaceName() + "/rpc/func1";
    m_pendingSubscriptions.push_back(invokeTopic_func1);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this, invokeTopic_func1](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func1, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            Enum1::Enum1Enum param1 = arguments.at(0).get<Enum1::Enum1Enum>();
            auto result = m_impl->func1(param1);
            return result;
        }));
}

void MqttSameEnum1InterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = interfaceName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractSameEnum1Interface::prop1Changed,
        this, [this, publishTopic_prop1](Enum1::Enum1Enum prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });    
}

void MqttSameEnum1InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = interfaceName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractSameEnum1Interface::sig1, this,
        [this, topic_sig1](Enum1::Enum1Enum param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
}

void MqttSameEnum1InterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttSameEnum1InterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

} // namespace tb_same1

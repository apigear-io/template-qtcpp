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


#include "mqttnestedstruct2interfaceadapter.h"
#include "testbed2/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace testbed2 {

namespace
{
const QString InterfaceName = "testbed2/NestedStruct2Interface";
}


MqttNestedStruct2InterfaceAdapter::MqttNestedStruct2InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNestedStruct2Interface> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
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
    });
    
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, [this](){
    AG_LOG_DEBUG(Q_FUNC_INFO);
        m_subscribedIds.clear();
    });
}

MqttNestedStruct2InterfaceAdapter::~MqttNestedStruct2InterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

const QString& MqttNestedStruct2InterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttNestedStruct2InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = interfaceName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            NestedStruct1 prop1 = value.get<NestedStruct1>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = interfaceName() + "/set/prop2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this](const nlohmann::json& value)
        {
            NestedStruct2 prop2 = value.get<NestedStruct2>();
            m_impl->setProp2(prop2);
        }));
}

void MqttNestedStruct2InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = interfaceName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const nlohmann::json& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = interfaceName() + "/rpc/func2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this](const nlohmann::json& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            NestedStruct2 param2 = arguments.at(1).get<NestedStruct2>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
}

void MqttNestedStruct2InterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = interfaceName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractNestedStruct2Interface::prop1Changed,
        this, [this, publishTopic_prop1](const NestedStruct1& prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = interfaceName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractNestedStruct2Interface::prop2Changed,
        this, [this, publishTopic_prop2](const NestedStruct2& prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });    
}

void MqttNestedStruct2InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = interfaceName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractNestedStruct2Interface::sig1, this,
        [this, topic_sig1](const NestedStruct1& param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = interfaceName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractNestedStruct2Interface::sig2, this,
        [this, topic_sig2](const NestedStruct1& param1, const NestedStruct2& param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
}

void MqttNestedStruct2InterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

} // namespace testbed2

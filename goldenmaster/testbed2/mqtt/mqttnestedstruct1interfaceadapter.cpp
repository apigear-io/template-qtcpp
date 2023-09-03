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


#include "mqttnestedstruct1interfaceadapter.h"
#include "testbed2/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace testbed2 {

namespace
{
const QString ID = "testbed2/NestedStruct1Interface";
}


MqttNestedStruct1InterfaceAdapter::MqttNestedStruct1InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNestedStruct1Interface> impl, QObject *parent)
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
}

MqttNestedStruct1InterfaceAdapter::~MqttNestedStruct1InterfaceAdapter()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& MqttNestedStruct1InterfaceAdapter::objectName()
{
    return ID;
}

void MqttNestedStruct1InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = objectName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            NestedStruct1 prop1 = value.get<NestedStruct1>();
            m_impl->setProp1(prop1);
        }));
}

void MqttNestedStruct1InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = objectName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const auto& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            auto result = m_impl->func1(param1);
            return result;
        }));
}

void MqttNestedStruct1InterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = objectName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractNestedStruct1Interface::prop1Changed,
        this, [this, publishTopic_prop1](const NestedStruct1& prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });    
}

void MqttNestedStruct1InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = objectName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractNestedStruct1Interface::sig1, this,
        [this, topic_sig1](const NestedStruct1& param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
}

} // namespace testbed2

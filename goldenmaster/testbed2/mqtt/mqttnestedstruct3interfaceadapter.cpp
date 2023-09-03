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


#include "mqttnestedstruct3interfaceadapter.h"
#include "testbed2/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace testbed2 {

namespace
{
const QString ID = "testbed2/NestedStruct3Interface";
}


MqttNestedStruct3InterfaceAdapter::MqttNestedStruct3InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNestedStruct3Interface> impl, QObject *parent)
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

MqttNestedStruct3InterfaceAdapter::~MqttNestedStruct3InterfaceAdapter()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& MqttNestedStruct3InterfaceAdapter::objectName()
{
    return ID;
}

void MqttNestedStruct3InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = objectName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            NestedStruct1 prop1 = value.get<NestedStruct1>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = objectName() + "/set/prop2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this](const nlohmann::json& value)
        {
            NestedStruct2 prop2 = value.get<NestedStruct2>();
            m_impl->setProp2(prop2);
        }));
    const auto setTopic_prop3 = objectName() + "/set/prop3";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop3,
        [this](const nlohmann::json& value)
        {
            NestedStruct3 prop3 = value.get<NestedStruct3>();
            m_impl->setProp3(prop3);
        }));
}

void MqttNestedStruct3InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = objectName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const auto& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = objectName() + "/rpc/func2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this](const auto& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            NestedStruct2 param2 = arguments.at(1).get<NestedStruct2>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
    const auto invokeTopic_func3 = objectName() + "/rpc/func3";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func3,
        [this](const auto& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            NestedStruct2 param2 = arguments.at(1).get<NestedStruct2>();
            NestedStruct3 param3 = arguments.at(2).get<NestedStruct3>();
            auto result = m_impl->func3(param1, param2, param3);
            return result;
        }));
}

void MqttNestedStruct3InterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = objectName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractNestedStruct3Interface::prop1Changed,
        this, [this, publishTopic_prop1](const NestedStruct1& prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = objectName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractNestedStruct3Interface::prop2Changed,
        this, [this, publishTopic_prop2](const NestedStruct2& prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });
    const auto publishTopic_prop3 = objectName() + "/prop/prop3";
    connect(m_impl.get(),&AbstractNestedStruct3Interface::prop3Changed,
        this, [this, publishTopic_prop3](const NestedStruct3& prop3)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop3, prop3);
        });    
}

void MqttNestedStruct3InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = objectName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractNestedStruct3Interface::sig1, this,
        [this, topic_sig1](const NestedStruct1& param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = objectName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractNestedStruct3Interface::sig2, this,
        [this, topic_sig2](const NestedStruct1& param1, const NestedStruct2& param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
    const auto topic_sig3 = objectName() + "/sig/sig3";
    connect(m_impl.get(), &AbstractNestedStruct3Interface::sig3, this,
        [this, topic_sig3](const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
        {
            nlohmann::json args = { param1, param2, param3 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig3, args);
        });
}

} // namespace testbed2

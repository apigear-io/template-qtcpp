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


#include "mqttsamestruct2interfaceadapter.h"
#include "tb_same2/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_same2 {

namespace
{
const QString ID = "tb.same2/SameStruct2Interface";
}


MqttSameStruct2InterfaceAdapter::MqttSameStruct2InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractSameStruct2Interface> impl, QObject *parent)
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

MqttSameStruct2InterfaceAdapter::~MqttSameStruct2InterfaceAdapter()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& MqttSameStruct2InterfaceAdapter::objectName()
{
    return ID;
}

void MqttSameStruct2InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = objectName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            Struct2 prop1 = value.get<Struct2>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = objectName() + "/set/prop2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this](const nlohmann::json& value)
        {
            Struct2 prop2 = value.get<Struct2>();
            m_impl->setProp2(prop2);
        }));
}

void MqttSameStruct2InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = objectName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const auto& arguments)
        {
            Struct1 param1 = arguments.at(0).get<Struct1>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = objectName() + "/rpc/func2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this](const auto& arguments)
        {
            Struct1 param1 = arguments.at(0).get<Struct1>();
            Struct2 param2 = arguments.at(1).get<Struct2>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
}

void MqttSameStruct2InterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = objectName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractSameStruct2Interface::prop1Changed,
        this, [this, publishTopic_prop1](const Struct2& prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = objectName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractSameStruct2Interface::prop2Changed,
        this, [this, publishTopic_prop2](const Struct2& prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });    
}

void MqttSameStruct2InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = objectName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractSameStruct2Interface::sig1, this,
        [this, topic_sig1](const Struct1& param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = objectName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractSameStruct2Interface::sig2, this,
        [this, topic_sig2](const Struct1& param1, const Struct2& param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
}

} // namespace tb_same2

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


#include "mqttsameenum2interfaceadapter.h"
#include "tb_same1/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_same1 {

namespace
{
const QString ID = "tb.same1/SameEnum2Interface";
}


MqttSameEnum2InterfaceAdapter::MqttSameEnum2InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractSameEnum2Interface> impl, QObject *parent)
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

MqttSameEnum2InterfaceAdapter::~MqttSameEnum2InterfaceAdapter()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& MqttSameEnum2InterfaceAdapter::objectName()
{
    return ID;
}

void MqttSameEnum2InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = objectName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            Enum1::Enum1Enum prop1 = value.get<Enum1::Enum1Enum>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = objectName() + "/set/prop2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this](const nlohmann::json& value)
        {
            Enum2::Enum2Enum prop2 = value.get<Enum2::Enum2Enum>();
            m_impl->setProp2(prop2);
        }));
}

void MqttSameEnum2InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = objectName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const auto& arguments)
        {
            Enum1::Enum1Enum param1 = arguments.at(0).get<Enum1::Enum1Enum>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = objectName() + "/rpc/func2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this](const auto& arguments)
        {
            Enum1::Enum1Enum param1 = arguments.at(0).get<Enum1::Enum1Enum>();
            Enum2::Enum2Enum param2 = arguments.at(1).get<Enum2::Enum2Enum>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
}

void MqttSameEnum2InterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = objectName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractSameEnum2Interface::prop1Changed,
        this, [this, publishTopic_prop1](Enum1::Enum1Enum prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = objectName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractSameEnum2Interface::prop2Changed,
        this, [this, publishTopic_prop2](Enum2::Enum2Enum prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });    
}

void MqttSameEnum2InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = objectName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractSameEnum2Interface::sig1, this,
        [this, topic_sig1](Enum1::Enum1Enum param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = objectName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractSameEnum2Interface::sig2, this,
        [this, topic_sig2](Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
}

} // namespace tb_same1

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


#include "mqttenuminterfaceadapter.h"
#include "tb_enum/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_enum {

namespace
{
const QString InterfaceName = "tb.enum/EnumInterface";
}


MqttEnumInterfaceAdapter::MqttEnumInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractEnumInterface> impl, QObject *parent)
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

MqttEnumInterfaceAdapter::~MqttEnumInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

const QString& MqttEnumInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttEnumInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop0 = interfaceName() + "/set/prop0";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop0,
        [this](const nlohmann::json& value)
        {
            Enum0::Enum0Enum prop0 = value.get<Enum0::Enum0Enum>();
            m_impl->setProp0(prop0);
        }));
    const auto setTopic_prop1 = interfaceName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            Enum1::Enum1Enum prop1 = value.get<Enum1::Enum1Enum>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = interfaceName() + "/set/prop2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this](const nlohmann::json& value)
        {
            Enum2::Enum2Enum prop2 = value.get<Enum2::Enum2Enum>();
            m_impl->setProp2(prop2);
        }));
    const auto setTopic_prop3 = interfaceName() + "/set/prop3";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop3,
        [this](const nlohmann::json& value)
        {
            Enum3::Enum3Enum prop3 = value.get<Enum3::Enum3Enum>();
            m_impl->setProp3(prop3);
        }));
}

void MqttEnumInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func0 = interfaceName() + "/rpc/func0";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func0,
        [this](const nlohmann::json& arguments)
        {
            Enum0::Enum0Enum param0 = arguments.at(0).get<Enum0::Enum0Enum>();
            auto result = m_impl->func0(param0);
            return result;
        }));
    const auto invokeTopic_func1 = interfaceName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const nlohmann::json& arguments)
        {
            Enum1::Enum1Enum param1 = arguments.at(0).get<Enum1::Enum1Enum>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = interfaceName() + "/rpc/func2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this](const nlohmann::json& arguments)
        {
            Enum2::Enum2Enum param2 = arguments.at(0).get<Enum2::Enum2Enum>();
            auto result = m_impl->func2(param2);
            return result;
        }));
    const auto invokeTopic_func3 = interfaceName() + "/rpc/func3";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func3,
        [this](const nlohmann::json& arguments)
        {
            Enum3::Enum3Enum param3 = arguments.at(0).get<Enum3::Enum3Enum>();
            auto result = m_impl->func3(param3);
            return result;
        }));
}

void MqttEnumInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop0 = interfaceName() + "/prop/prop0";
    connect(m_impl.get(),&AbstractEnumInterface::prop0Changed,
        this, [this, publishTopic_prop0](Enum0::Enum0Enum prop0)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop0, prop0);
        });
    const auto publishTopic_prop1 = interfaceName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractEnumInterface::prop1Changed,
        this, [this, publishTopic_prop1](Enum1::Enum1Enum prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = interfaceName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractEnumInterface::prop2Changed,
        this, [this, publishTopic_prop2](Enum2::Enum2Enum prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });
    const auto publishTopic_prop3 = interfaceName() + "/prop/prop3";
    connect(m_impl.get(),&AbstractEnumInterface::prop3Changed,
        this, [this, publishTopic_prop3](Enum3::Enum3Enum prop3)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop3, prop3);
        });    
}

void MqttEnumInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig0 = interfaceName() + "/sig/sig0";
    connect(m_impl.get(), &AbstractEnumInterface::sig0, this,
        [this, topic_sig0](Enum0::Enum0Enum param0)
        {
            nlohmann::json args = { param0 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig0, args);
        });
    const auto topic_sig1 = interfaceName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractEnumInterface::sig1, this,
        [this, topic_sig1](Enum1::Enum1Enum param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = interfaceName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractEnumInterface::sig2, this,
        [this, topic_sig2](Enum2::Enum2Enum param2)
        {
            nlohmann::json args = { param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
    const auto topic_sig3 = interfaceName() + "/sig/sig3";
    connect(m_impl.get(), &AbstractEnumInterface::sig3, this,
        [this, topic_sig3](Enum3::Enum3Enum param3)
        {
            nlohmann::json args = { param3 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig3, args);
        });
}

void MqttEnumInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

} // namespace tb_enum

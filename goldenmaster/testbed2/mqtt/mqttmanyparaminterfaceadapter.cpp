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


#include "mqttmanyparaminterfaceadapter.h"
#include "testbed2/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace testbed2 {

namespace
{
const QString ID = "testbed2/ManyParamInterface";
}


MqttManyParamInterfaceAdapter::MqttManyParamInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractManyParamInterface> impl, QObject *parent)
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

MqttManyParamInterfaceAdapter::~MqttManyParamInterfaceAdapter()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& MqttManyParamInterfaceAdapter::objectName()
{
    return ID;
}

void MqttManyParamInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = objectName() + "/set/prop1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this](const nlohmann::json& value)
        {
            int prop1 = value.get<int>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = objectName() + "/set/prop2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this](const nlohmann::json& value)
        {
            int prop2 = value.get<int>();
            m_impl->setProp2(prop2);
        }));
    const auto setTopic_prop3 = objectName() + "/set/prop3";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop3,
        [this](const nlohmann::json& value)
        {
            int prop3 = value.get<int>();
            m_impl->setProp3(prop3);
        }));
    const auto setTopic_prop4 = objectName() + "/set/prop4";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop4,
        [this](const nlohmann::json& value)
        {
            int prop4 = value.get<int>();
            m_impl->setProp4(prop4);
        }));
}

void MqttManyParamInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = objectName() + "/rpc/func1";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this](const auto& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = objectName() + "/rpc/func2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this](const auto& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            int param2 = arguments.at(1).get<int>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
    const auto invokeTopic_func3 = objectName() + "/rpc/func3";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func3,
        [this](const auto& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            int param2 = arguments.at(1).get<int>();
            int param3 = arguments.at(2).get<int>();
            auto result = m_impl->func3(param1, param2, param3);
            return result;
        }));
    const auto invokeTopic_func4 = objectName() + "/rpc/func4";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func4,
        [this](const auto& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            int param2 = arguments.at(1).get<int>();
            int param3 = arguments.at(2).get<int>();
            int param4 = arguments.at(3).get<int>();
            auto result = m_impl->func4(param1, param2, param3, param4);
            return result;
        }));
}

void MqttManyParamInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_prop1 = objectName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractManyParamInterface::prop1Changed,
        this, [this, publishTopic_prop1](int prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = objectName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractManyParamInterface::prop2Changed,
        this, [this, publishTopic_prop2](int prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });
    const auto publishTopic_prop3 = objectName() + "/prop/prop3";
    connect(m_impl.get(),&AbstractManyParamInterface::prop3Changed,
        this, [this, publishTopic_prop3](int prop3)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop3, prop3);
        });
    const auto publishTopic_prop4 = objectName() + "/prop/prop4";
    connect(m_impl.get(),&AbstractManyParamInterface::prop4Changed,
        this, [this, publishTopic_prop4](int prop4)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop4, prop4);
        });    
}

void MqttManyParamInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = objectName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractManyParamInterface::sig1, this,
        [this, topic_sig1](int param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = objectName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractManyParamInterface::sig2, this,
        [this, topic_sig2](int param1, int param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
    const auto topic_sig3 = objectName() + "/sig/sig3";
    connect(m_impl.get(), &AbstractManyParamInterface::sig3, this,
        [this, topic_sig3](int param1, int param2, int param3)
        {
            nlohmann::json args = { param1, param2, param3 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig3, args);
        });
    const auto topic_sig4 = objectName() + "/sig/sig4";
    connect(m_impl.get(), &AbstractManyParamInterface::sig4, this,
        [this, topic_sig4](int param1, int param2, int param3, int param4)
        {
            nlohmann::json args = { param1, param2, param3, param4 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig4, args);
        });
}

} // namespace testbed2

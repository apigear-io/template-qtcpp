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


#include "mqttstructinterfaceadapter.h"
#include "testbed1/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace testbed1 {

namespace
{
const QString InterfaceName = "testbed1/StructInterface";
}


MqttStructInterfaceAdapter::MqttStructInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractStructInterface> impl, QObject *parent)
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

MqttStructInterfaceAdapter::~MqttStructInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

const QString& MqttStructInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttStructInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_propBool = interfaceName() + "/set/propBool";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propBool,
        [this](const nlohmann::json& value)
        {
            StructBool propBool = value.get<StructBool>();
            m_impl->setPropBool(propBool);
        }));
    const auto setTopic_propInt = interfaceName() + "/set/propInt";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt,
        [this](const nlohmann::json& value)
        {
            StructInt propInt = value.get<StructInt>();
            m_impl->setPropInt(propInt);
        }));
    const auto setTopic_propFloat = interfaceName() + "/set/propFloat";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat,
        [this](const nlohmann::json& value)
        {
            StructFloat propFloat = value.get<StructFloat>();
            m_impl->setPropFloat(propFloat);
        }));
    const auto setTopic_propString = interfaceName() + "/set/propString";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propString,
        [this](const nlohmann::json& value)
        {
            StructString propString = value.get<StructString>();
            m_impl->setPropString(propString);
        }));
}

void MqttStructInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_funcBool = interfaceName() + "/rpc/funcBool";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcBool,
        [this](const nlohmann::json& arguments)
        {
            StructBool paramBool = arguments.at(0).get<StructBool>();
            auto result = m_impl->funcBool(paramBool);
            return result;
        }));
    const auto invokeTopic_funcInt = interfaceName() + "/rpc/funcInt";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt,
        [this](const nlohmann::json& arguments)
        {
            StructInt paramInt = arguments.at(0).get<StructInt>();
            auto result = m_impl->funcInt(paramInt);
            return result;
        }));
    const auto invokeTopic_funcFloat = interfaceName() + "/rpc/funcFloat";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat,
        [this](const nlohmann::json& arguments)
        {
            StructFloat paramFloat = arguments.at(0).get<StructFloat>();
            auto result = m_impl->funcFloat(paramFloat);
            return result;
        }));
    const auto invokeTopic_funcString = interfaceName() + "/rpc/funcString";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcString,
        [this](const nlohmann::json& arguments)
        {
            StructString paramString = arguments.at(0).get<StructString>();
            auto result = m_impl->funcString(paramString);
            return result;
        }));
}

void MqttStructInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_propBool = interfaceName() + "/prop/propBool";
    connect(m_impl.get(),&AbstractStructInterface::propBoolChanged,
        this, [this, publishTopic_propBool](const StructBool& propBool)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propBool, propBool);
        });
    const auto publishTopic_propInt = interfaceName() + "/prop/propInt";
    connect(m_impl.get(),&AbstractStructInterface::propIntChanged,
        this, [this, publishTopic_propInt](const StructInt& propInt)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt, propInt);
        });
    const auto publishTopic_propFloat = interfaceName() + "/prop/propFloat";
    connect(m_impl.get(),&AbstractStructInterface::propFloatChanged,
        this, [this, publishTopic_propFloat](const StructFloat& propFloat)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat, propFloat);
        });
    const auto publishTopic_propString = interfaceName() + "/prop/propString";
    connect(m_impl.get(),&AbstractStructInterface::propStringChanged,
        this, [this, publishTopic_propString](const StructString& propString)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propString, propString);
        });    
}

void MqttStructInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigBool = interfaceName() + "/sig/sigBool";
    connect(m_impl.get(), &AbstractStructInterface::sigBool, this,
        [this, topic_sigBool](const StructBool& paramBool)
        {
            nlohmann::json args = { paramBool };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigBool, args);
        });
    const auto topic_sigInt = interfaceName() + "/sig/sigInt";
    connect(m_impl.get(), &AbstractStructInterface::sigInt, this,
        [this, topic_sigInt](const StructInt& paramInt)
        {
            nlohmann::json args = { paramInt };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt, args);
        });
    const auto topic_sigFloat = interfaceName() + "/sig/sigFloat";
    connect(m_impl.get(), &AbstractStructInterface::sigFloat, this,
        [this, topic_sigFloat](const StructFloat& paramFloat)
        {
            nlohmann::json args = { paramFloat };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat, args);
        });
    const auto topic_sigString = interfaceName() + "/sig/sigString";
    connect(m_impl.get(), &AbstractStructInterface::sigString, this,
        [this, topic_sigString](const StructString& paramString)
        {
            nlohmann::json args = { paramString };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigString, args);
        });
}

void MqttStructInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

} // namespace testbed1

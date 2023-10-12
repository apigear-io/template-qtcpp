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


#include "mqttnam_esadapter.h"
#include "tb_names/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_names {

namespace
{
const QString InterfaceName = "tb.names/NamEs";
}


MqttNam_EsAdapter::MqttNam_EsAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNamEs> impl, QObject *parent)
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

MqttNam_EsAdapter::~MqttNam_EsAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

const QString& MqttNam_EsAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttNam_EsAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_Switch = interfaceName() + "/set/Switch";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_Switch,
        [this](const nlohmann::json& value)
        {
            bool Switch = value.get<bool>();
            m_impl->setSwitch(Switch);
        }));
    const auto setTopic_SOME_PROPERTY = interfaceName() + "/set/SOME_PROPERTY";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_SOME_PROPERTY,
        [this](const nlohmann::json& value)
        {
            int SOME_PROPERTY = value.get<int>();
            m_impl->setSomeProperty(SOME_PROPERTY);
        }));
    const auto setTopic_Some_Poperty2 = interfaceName() + "/set/Some_Poperty2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_Some_Poperty2,
        [this](const nlohmann::json& value)
        {
            int Some_Poperty2 = value.get<int>();
            m_impl->setSomePoperty2(Some_Poperty2);
        }));
}

void MqttNam_EsAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_SOME_FUNCTION = interfaceName() + "/rpc/SOME_FUNCTION";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_SOME_FUNCTION,
        [this](const nlohmann::json& arguments)
        {
            bool SOME_PARAM = arguments.at(0).get<bool>();
            m_impl->someFunction( SOME_PARAM);
            return nlohmann::json {};
        }));
    const auto invokeTopic_Some_Function2 = interfaceName() + "/rpc/Some_Function2";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_Some_Function2,
        [this](const nlohmann::json& arguments)
        {
            bool Some_Param = arguments.at(0).get<bool>();
            m_impl->someFunction2( Some_Param);
            return nlohmann::json {};
        }));
}

void MqttNam_EsAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_Switch = interfaceName() + "/prop/Switch";
    connect(m_impl.get(),&AbstractNamEs::SwitchChanged,
        this, [this, publishTopic_Switch](bool Switch)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_Switch, Switch);
        });
    const auto publishTopic_SOME_PROPERTY = interfaceName() + "/prop/SOME_PROPERTY";
    connect(m_impl.get(),&AbstractNamEs::SOME_PROPERTYChanged,
        this, [this, publishTopic_SOME_PROPERTY](int SOME_PROPERTY)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_SOME_PROPERTY, SOME_PROPERTY);
        });
    const auto publishTopic_Some_Poperty2 = interfaceName() + "/prop/Some_Poperty2";
    connect(m_impl.get(),&AbstractNamEs::Some_Poperty2Changed,
        this, [this, publishTopic_Some_Poperty2](int Some_Poperty2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_Some_Poperty2, Some_Poperty2);
        });    
}

void MqttNam_EsAdapter::connectServiceSignals()
{
    const auto topic_someSignal = interfaceName() + "/sig/someSignal";
    connect(m_impl.get(), &AbstractNamEs::someSignal, this,
        [this, topic_someSignal](bool SOME_PARAM)
        {
            nlohmann::json args = { SOME_PARAM };
            m_mqttServiceAdapter.emitPropertyChange(topic_someSignal, args);
        });
    const auto topic_someSignal2 = interfaceName() + "/sig/someSignal2";
    connect(m_impl.get(), &AbstractNamEs::someSignal2, this,
        [this, topic_someSignal2](bool Some_Param)
        {
            nlohmann::json args = { Some_Param };
            m_mqttServiceAdapter.emitPropertyChange(topic_someSignal2, args);
        });
}

void MqttNam_EsAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

} // namespace tb_names

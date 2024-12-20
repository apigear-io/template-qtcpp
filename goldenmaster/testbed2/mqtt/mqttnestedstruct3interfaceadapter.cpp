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
const QString InterfaceName = "testbed2/NestedStruct3Interface";
}


MqttNestedStruct3InterfaceAdapter::MqttNestedStruct3InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNestedStruct3Interface> impl, QObject *parent)
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

MqttNestedStruct3InterfaceAdapter::~MqttNestedStruct3InterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttNestedStruct3InterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttNestedStruct3InterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttNestedStruct3InterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = interfaceName() + "/set/prop1";
    m_pendingSubscriptions.push_back(setTopic_prop1);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this, setTopic_prop1](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop1, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            NestedStruct1 prop1 = value.get<NestedStruct1>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = interfaceName() + "/set/prop2";
    m_pendingSubscriptions.push_back(setTopic_prop2);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this, setTopic_prop2](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop2, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            NestedStruct2 prop2 = value.get<NestedStruct2>();
            m_impl->setProp2(prop2);
        }));
    const auto setTopic_prop3 = interfaceName() + "/set/prop3";
    m_pendingSubscriptions.push_back(setTopic_prop3);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop3,
        [this, setTopic_prop3](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop3, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            NestedStruct3 prop3 = value.get<NestedStruct3>();
            m_impl->setProp3(prop3);
        }));
}

void MqttNestedStruct3InterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = interfaceName() + "/rpc/func1";
    m_pendingSubscriptions.push_back(invokeTopic_func1);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this, invokeTopic_func1](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func1, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = interfaceName() + "/rpc/func2";
    m_pendingSubscriptions.push_back(invokeTopic_func2);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this, invokeTopic_func2](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func2, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            NestedStruct1 param1 = arguments.at(0).get<NestedStruct1>();
            NestedStruct2 param2 = arguments.at(1).get<NestedStruct2>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
    const auto invokeTopic_func3 = interfaceName() + "/rpc/func3";
    m_pendingSubscriptions.push_back(invokeTopic_func3);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func3,
        [this, invokeTopic_func3](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func3, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
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
    const auto publishTopic_prop1 = interfaceName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractNestedStruct3Interface::prop1Changed,
        this, [this, publishTopic_prop1](const NestedStruct1& prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = interfaceName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractNestedStruct3Interface::prop2Changed,
        this, [this, publishTopic_prop2](const NestedStruct2& prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });
    const auto publishTopic_prop3 = interfaceName() + "/prop/prop3";
    connect(m_impl.get(),&AbstractNestedStruct3Interface::prop3Changed,
        this, [this, publishTopic_prop3](const NestedStruct3& prop3)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop3, prop3);
        });    
}

void MqttNestedStruct3InterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = interfaceName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractNestedStruct3Interface::sig1, this,
        [this, topic_sig1](const NestedStruct1& param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = interfaceName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractNestedStruct3Interface::sig2, this,
        [this, topic_sig2](const NestedStruct1& param1, const NestedStruct2& param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
    const auto topic_sig3 = interfaceName() + "/sig/sig3";
    connect(m_impl.get(), &AbstractNestedStruct3Interface::sig3, this,
        [this, topic_sig3](const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
        {
            nlohmann::json args = { param1, param2, param3 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig3, args);
        });
}

void MqttNestedStruct3InterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttNestedStruct3InterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

} // namespace testbed2

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
const QString InterfaceName = "testbed2/ManyParamInterface";
}


MqttManyParamInterfaceAdapter::MqttManyParamInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractManyParamInterface> impl, QObject *parent)
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

MqttManyParamInterfaceAdapter::~MqttManyParamInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttManyParamInterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttManyParamInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttManyParamInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_prop1 = interfaceName() + "/set/prop1";
    m_pendingSubscriptions.push_back(setTopic_prop1);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop1,
        [this, setTopic_prop1](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop1, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            int prop1 = value.get<int>();
            m_impl->setProp1(prop1);
        }));
    const auto setTopic_prop2 = interfaceName() + "/set/prop2";
    m_pendingSubscriptions.push_back(setTopic_prop2);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop2,
        [this, setTopic_prop2](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop2, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            int prop2 = value.get<int>();
            m_impl->setProp2(prop2);
        }));
    const auto setTopic_prop3 = interfaceName() + "/set/prop3";
    m_pendingSubscriptions.push_back(setTopic_prop3);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop3,
        [this, setTopic_prop3](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop3, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            int prop3 = value.get<int>();
            m_impl->setProp3(prop3);
        }));
    const auto setTopic_prop4 = interfaceName() + "/set/prop4";
    m_pendingSubscriptions.push_back(setTopic_prop4);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_prop4,
        [this, setTopic_prop4](auto id, bool hasSucceed){handleOnSubscribed(setTopic_prop4, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            int prop4 = value.get<int>();
            m_impl->setProp4(prop4);
        }));
}

void MqttManyParamInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_func1 = interfaceName() + "/rpc/func1";
    m_pendingSubscriptions.push_back(invokeTopic_func1);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func1,
        [this, invokeTopic_func1](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func1, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            auto result = m_impl->func1(param1);
            return result;
        }));
    const auto invokeTopic_func2 = interfaceName() + "/rpc/func2";
    m_pendingSubscriptions.push_back(invokeTopic_func2);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func2,
        [this, invokeTopic_func2](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func2, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            int param2 = arguments.at(1).get<int>();
            auto result = m_impl->func2(param1, param2);
            return result;
        }));
    const auto invokeTopic_func3 = interfaceName() + "/rpc/func3";
    m_pendingSubscriptions.push_back(invokeTopic_func3);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func3,
        [this, invokeTopic_func3](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func3, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            int param1 = arguments.at(0).get<int>();
            int param2 = arguments.at(1).get<int>();
            int param3 = arguments.at(2).get<int>();
            auto result = m_impl->func3(param1, param2, param3);
            return result;
        }));
    const auto invokeTopic_func4 = interfaceName() + "/rpc/func4";
    m_pendingSubscriptions.push_back(invokeTopic_func4);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_func4,
        [this, invokeTopic_func4](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_func4, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
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
    const auto publishTopic_prop1 = interfaceName() + "/prop/prop1";
    connect(m_impl.get(),&AbstractManyParamInterface::prop1Changed,
        this, [this, publishTopic_prop1](int prop1)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop1, prop1);
        });
    const auto publishTopic_prop2 = interfaceName() + "/prop/prop2";
    connect(m_impl.get(),&AbstractManyParamInterface::prop2Changed,
        this, [this, publishTopic_prop2](int prop2)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop2, prop2);
        });
    const auto publishTopic_prop3 = interfaceName() + "/prop/prop3";
    connect(m_impl.get(),&AbstractManyParamInterface::prop3Changed,
        this, [this, publishTopic_prop3](int prop3)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop3, prop3);
        });
    const auto publishTopic_prop4 = interfaceName() + "/prop/prop4";
    connect(m_impl.get(),&AbstractManyParamInterface::prop4Changed,
        this, [this, publishTopic_prop4](int prop4)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_prop4, prop4);
        });    
}

void MqttManyParamInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sig1 = interfaceName() + "/sig/sig1";
    connect(m_impl.get(), &AbstractManyParamInterface::sig1, this,
        [this, topic_sig1](int param1)
        {
            nlohmann::json args = { param1 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig1, args);
        });
    const auto topic_sig2 = interfaceName() + "/sig/sig2";
    connect(m_impl.get(), &AbstractManyParamInterface::sig2, this,
        [this, topic_sig2](int param1, int param2)
        {
            nlohmann::json args = { param1, param2 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig2, args);
        });
    const auto topic_sig3 = interfaceName() + "/sig/sig3";
    connect(m_impl.get(), &AbstractManyParamInterface::sig3, this,
        [this, topic_sig3](int param1, int param2, int param3)
        {
            nlohmann::json args = { param1, param2, param3 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig3, args);
        });
    const auto topic_sig4 = interfaceName() + "/sig/sig4";
    connect(m_impl.get(), &AbstractManyParamInterface::sig4, this,
        [this, topic_sig4](int param1, int param2, int param3, int param4)
        {
            nlohmann::json args = { param1, param2, param3, param4 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sig4, args);
        });
}

void MqttManyParamInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttManyParamInterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

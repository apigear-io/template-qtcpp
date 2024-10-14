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


#include "mqttstructarrayinterfaceadapter.h"
#include "testbed1/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace testbed1 {

namespace
{
const QString InterfaceName = "testbed1/StructArrayInterface";
}


MqttStructArrayInterfaceAdapter::MqttStructArrayInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractStructArrayInterface> impl, QObject *parent)
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

MqttStructArrayInterfaceAdapter::~MqttStructArrayInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttStructArrayInterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttStructArrayInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttStructArrayInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_propBool = interfaceName() + "/set/propBool";
    m_pendingSubscriptions.push_back(setTopic_propBool);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propBool,
        [this, setTopic_propBool](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propBool, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            QList<StructBool> propBool = value.get<QList<StructBool>>();
            m_impl->setPropBool(propBool);
        }));
    const auto setTopic_propInt = interfaceName() + "/set/propInt";
    m_pendingSubscriptions.push_back(setTopic_propInt);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt,
        [this, setTopic_propInt](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propInt, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            QList<StructInt> propInt = value.get<QList<StructInt>>();
            m_impl->setPropInt(propInt);
        }));
    const auto setTopic_propFloat = interfaceName() + "/set/propFloat";
    m_pendingSubscriptions.push_back(setTopic_propFloat);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat,
        [this, setTopic_propFloat](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propFloat, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            QList<StructFloat> propFloat = value.get<QList<StructFloat>>();
            m_impl->setPropFloat(propFloat);
        }));
    const auto setTopic_propString = interfaceName() + "/set/propString";
    m_pendingSubscriptions.push_back(setTopic_propString);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propString,
        [this, setTopic_propString](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propString, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            QList<StructString> propString = value.get<QList<StructString>>();
            m_impl->setPropString(propString);
        }));
}

void MqttStructArrayInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_funcBool = interfaceName() + "/rpc/funcBool";
    m_pendingSubscriptions.push_back(invokeTopic_funcBool);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcBool,
        [this, invokeTopic_funcBool](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcBool, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            QList<StructBool> paramBool = arguments.at(0).get<QList<StructBool>>();
            auto result = m_impl->funcBool(paramBool);
            return result;
        }));
    const auto invokeTopic_funcInt = interfaceName() + "/rpc/funcInt";
    m_pendingSubscriptions.push_back(invokeTopic_funcInt);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt,
        [this, invokeTopic_funcInt](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcInt, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            QList<StructInt> paramInt = arguments.at(0).get<QList<StructInt>>();
            auto result = m_impl->funcInt(paramInt);
            return result;
        }));
    const auto invokeTopic_funcFloat = interfaceName() + "/rpc/funcFloat";
    m_pendingSubscriptions.push_back(invokeTopic_funcFloat);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat,
        [this, invokeTopic_funcFloat](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcFloat, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            QList<StructFloat> paramFloat = arguments.at(0).get<QList<StructFloat>>();
            auto result = m_impl->funcFloat(paramFloat);
            return result;
        }));
    const auto invokeTopic_funcString = interfaceName() + "/rpc/funcString";
    m_pendingSubscriptions.push_back(invokeTopic_funcString);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcString,
        [this, invokeTopic_funcString](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcString, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            QList<StructString> paramString = arguments.at(0).get<QList<StructString>>();
            auto result = m_impl->funcString(paramString);
            return result;
        }));
}

void MqttStructArrayInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_propBool = interfaceName() + "/prop/propBool";
    connect(m_impl.get(),&AbstractStructArrayInterface::propBoolChanged,
        this, [this, publishTopic_propBool](const QList<StructBool>& propBool)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propBool, propBool);
        });
    const auto publishTopic_propInt = interfaceName() + "/prop/propInt";
    connect(m_impl.get(),&AbstractStructArrayInterface::propIntChanged,
        this, [this, publishTopic_propInt](const QList<StructInt>& propInt)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt, propInt);
        });
    const auto publishTopic_propFloat = interfaceName() + "/prop/propFloat";
    connect(m_impl.get(),&AbstractStructArrayInterface::propFloatChanged,
        this, [this, publishTopic_propFloat](const QList<StructFloat>& propFloat)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat, propFloat);
        });
    const auto publishTopic_propString = interfaceName() + "/prop/propString";
    connect(m_impl.get(),&AbstractStructArrayInterface::propStringChanged,
        this, [this, publishTopic_propString](const QList<StructString>& propString)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propString, propString);
        });    
}

void MqttStructArrayInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigBool = interfaceName() + "/sig/sigBool";
    connect(m_impl.get(), &AbstractStructArrayInterface::sigBool, this,
        [this, topic_sigBool](const QList<StructBool>& paramBool)
        {
            nlohmann::json args = { paramBool };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigBool, args);
        });
    const auto topic_sigInt = interfaceName() + "/sig/sigInt";
    connect(m_impl.get(), &AbstractStructArrayInterface::sigInt, this,
        [this, topic_sigInt](const QList<StructInt>& paramInt)
        {
            nlohmann::json args = { paramInt };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt, args);
        });
    const auto topic_sigFloat = interfaceName() + "/sig/sigFloat";
    connect(m_impl.get(), &AbstractStructArrayInterface::sigFloat, this,
        [this, topic_sigFloat](const QList<StructFloat>& paramFloat)
        {
            nlohmann::json args = { paramFloat };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat, args);
        });
    const auto topic_sigString = interfaceName() + "/sig/sigString";
    connect(m_impl.get(), &AbstractStructArrayInterface::sigString, this,
        [this, topic_sigString](const QList<StructString>& paramString)
        {
            nlohmann::json args = { paramString };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigString, args);
        });
}

void MqttStructArrayInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttStructArrayInterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

} // namespace testbed1

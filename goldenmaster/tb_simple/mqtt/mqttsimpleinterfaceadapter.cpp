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


#include "mqttsimpleinterfaceadapter.h"
#include "tb_simple/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/SimpleInterface";
}


MqttSimpleInterfaceAdapter::MqttSimpleInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractSimpleInterface> impl, QObject *parent)
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

MqttSimpleInterfaceAdapter::~MqttSimpleInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool MqttSimpleInterfaceAdapter::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& MqttSimpleInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttSimpleInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_propBool = interfaceName() + "/set/propBool";
    m_pendingSubscriptions.push_back(setTopic_propBool);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propBool,
        [this, setTopic_propBool](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propBool, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            bool propBool = value.get<bool>();
            m_impl->setPropBool(propBool);
        }));
    const auto setTopic_propInt = interfaceName() + "/set/propInt";
    m_pendingSubscriptions.push_back(setTopic_propInt);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt,
        [this, setTopic_propInt](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propInt, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            int propInt = value.get<int>();
            m_impl->setPropInt(propInt);
        }));
    const auto setTopic_propInt32 = interfaceName() + "/set/propInt32";
    m_pendingSubscriptions.push_back(setTopic_propInt32);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt32,
        [this, setTopic_propInt32](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propInt32, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            qint32 propInt32 = value.get<qint32>();
            m_impl->setPropInt32(propInt32);
        }));
    const auto setTopic_propInt64 = interfaceName() + "/set/propInt64";
    m_pendingSubscriptions.push_back(setTopic_propInt64);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt64,
        [this, setTopic_propInt64](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propInt64, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            qint64 propInt64 = value.get<qint64>();
            m_impl->setPropInt64(propInt64);
        }));
    const auto setTopic_propFloat = interfaceName() + "/set/propFloat";
    m_pendingSubscriptions.push_back(setTopic_propFloat);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat,
        [this, setTopic_propFloat](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propFloat, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            qreal propFloat = value.get<qreal>();
            m_impl->setPropFloat(propFloat);
        }));
    const auto setTopic_propFloat32 = interfaceName() + "/set/propFloat32";
    m_pendingSubscriptions.push_back(setTopic_propFloat32);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat32,
        [this, setTopic_propFloat32](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propFloat32, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            float propFloat32 = value.get<float>();
            m_impl->setPropFloat32(propFloat32);
        }));
    const auto setTopic_propFloat64 = interfaceName() + "/set/propFloat64";
    m_pendingSubscriptions.push_back(setTopic_propFloat64);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat64,
        [this, setTopic_propFloat64](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propFloat64, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            double propFloat64 = value.get<double>();
            m_impl->setPropFloat64(propFloat64);
        }));
    const auto setTopic_propString = interfaceName() + "/set/propString";
    m_pendingSubscriptions.push_back(setTopic_propString);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propString,
        [this, setTopic_propString](auto id, bool hasSucceed){handleOnSubscribed(setTopic_propString, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            QString propString = value.get<QString>();
            m_impl->setPropString(propString);
        }));
}

void MqttSimpleInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_funcNoReturnValue = interfaceName() + "/rpc/funcNoReturnValue";
    m_pendingSubscriptions.push_back(invokeTopic_funcNoReturnValue);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcNoReturnValue,
        [this, invokeTopic_funcNoReturnValue](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcNoReturnValue, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            bool paramBool = arguments.at(0).get<bool>();
            m_impl->funcNoReturnValue( paramBool);
            return nlohmann::json {};
        }));
    const auto invokeTopic_funcBool = interfaceName() + "/rpc/funcBool";
    m_pendingSubscriptions.push_back(invokeTopic_funcBool);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcBool,
        [this, invokeTopic_funcBool](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcBool, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            bool paramBool = arguments.at(0).get<bool>();
            auto result = m_impl->funcBool(paramBool);
            return result;
        }));
    const auto invokeTopic_funcInt = interfaceName() + "/rpc/funcInt";
    m_pendingSubscriptions.push_back(invokeTopic_funcInt);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt,
        [this, invokeTopic_funcInt](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcInt, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            int paramInt = arguments.at(0).get<int>();
            auto result = m_impl->funcInt(paramInt);
            return result;
        }));
    const auto invokeTopic_funcInt32 = interfaceName() + "/rpc/funcInt32";
    m_pendingSubscriptions.push_back(invokeTopic_funcInt32);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt32,
        [this, invokeTopic_funcInt32](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcInt32, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            qint32 paramInt32 = arguments.at(0).get<qint32>();
            auto result = m_impl->funcInt32(paramInt32);
            return result;
        }));
    const auto invokeTopic_funcInt64 = interfaceName() + "/rpc/funcInt64";
    m_pendingSubscriptions.push_back(invokeTopic_funcInt64);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt64,
        [this, invokeTopic_funcInt64](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcInt64, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            qint64 paramInt64 = arguments.at(0).get<qint64>();
            auto result = m_impl->funcInt64(paramInt64);
            return result;
        }));
    const auto invokeTopic_funcFloat = interfaceName() + "/rpc/funcFloat";
    m_pendingSubscriptions.push_back(invokeTopic_funcFloat);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat,
        [this, invokeTopic_funcFloat](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcFloat, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            qreal paramFloat = arguments.at(0).get<qreal>();
            auto result = m_impl->funcFloat(paramFloat);
            return result;
        }));
    const auto invokeTopic_funcFloat32 = interfaceName() + "/rpc/funcFloat32";
    m_pendingSubscriptions.push_back(invokeTopic_funcFloat32);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat32,
        [this, invokeTopic_funcFloat32](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcFloat32, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            float paramFloat32 = arguments.at(0).get<float>();
            auto result = m_impl->funcFloat32(paramFloat32);
            return result;
        }));
    const auto invokeTopic_funcFloat64 = interfaceName() + "/rpc/funcFloat64";
    m_pendingSubscriptions.push_back(invokeTopic_funcFloat64);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat64,
        [this, invokeTopic_funcFloat64](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcFloat64, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            double paramFloat = arguments.at(0).get<double>();
            auto result = m_impl->funcFloat64(paramFloat);
            return result;
        }));
    const auto invokeTopic_funcString = interfaceName() + "/rpc/funcString";
    m_pendingSubscriptions.push_back(invokeTopic_funcString);
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcString,
        [this, invokeTopic_funcString](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_funcString, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            QString paramString = arguments.at(0).get<QString>();
            auto result = m_impl->funcString(paramString);
            return result;
        }));
}

void MqttSimpleInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_propBool = interfaceName() + "/prop/propBool";
    connect(m_impl.get(),&AbstractSimpleInterface::propBoolChanged,
        this, [this, publishTopic_propBool](bool propBool)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propBool, propBool);
        });
    const auto publishTopic_propInt = interfaceName() + "/prop/propInt";
    connect(m_impl.get(),&AbstractSimpleInterface::propIntChanged,
        this, [this, publishTopic_propInt](int propInt)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt, propInt);
        });
    const auto publishTopic_propInt32 = interfaceName() + "/prop/propInt32";
    connect(m_impl.get(),&AbstractSimpleInterface::propInt32Changed,
        this, [this, publishTopic_propInt32](qint32 propInt32)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt32, propInt32);
        });
    const auto publishTopic_propInt64 = interfaceName() + "/prop/propInt64";
    connect(m_impl.get(),&AbstractSimpleInterface::propInt64Changed,
        this, [this, publishTopic_propInt64](qint64 propInt64)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt64, propInt64);
        });
    const auto publishTopic_propFloat = interfaceName() + "/prop/propFloat";
    connect(m_impl.get(),&AbstractSimpleInterface::propFloatChanged,
        this, [this, publishTopic_propFloat](qreal propFloat)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat, propFloat);
        });
    const auto publishTopic_propFloat32 = interfaceName() + "/prop/propFloat32";
    connect(m_impl.get(),&AbstractSimpleInterface::propFloat32Changed,
        this, [this, publishTopic_propFloat32](float propFloat32)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat32, propFloat32);
        });
    const auto publishTopic_propFloat64 = interfaceName() + "/prop/propFloat64";
    connect(m_impl.get(),&AbstractSimpleInterface::propFloat64Changed,
        this, [this, publishTopic_propFloat64](double propFloat64)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat64, propFloat64);
        });
    const auto publishTopic_propString = interfaceName() + "/prop/propString";
    connect(m_impl.get(),&AbstractSimpleInterface::propStringChanged,
        this, [this, publishTopic_propString](const QString& propString)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propString, propString);
        });    
}

void MqttSimpleInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigBool = interfaceName() + "/sig/sigBool";
    connect(m_impl.get(), &AbstractSimpleInterface::sigBool, this,
        [this, topic_sigBool](bool paramBool)
        {
            nlohmann::json args = { paramBool };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigBool, args);
        });
    const auto topic_sigInt = interfaceName() + "/sig/sigInt";
    connect(m_impl.get(), &AbstractSimpleInterface::sigInt, this,
        [this, topic_sigInt](int paramInt)
        {
            nlohmann::json args = { paramInt };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt, args);
        });
    const auto topic_sigInt32 = interfaceName() + "/sig/sigInt32";
    connect(m_impl.get(), &AbstractSimpleInterface::sigInt32, this,
        [this, topic_sigInt32](qint32 paramInt32)
        {
            nlohmann::json args = { paramInt32 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt32, args);
        });
    const auto topic_sigInt64 = interfaceName() + "/sig/sigInt64";
    connect(m_impl.get(), &AbstractSimpleInterface::sigInt64, this,
        [this, topic_sigInt64](qint64 paramInt64)
        {
            nlohmann::json args = { paramInt64 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt64, args);
        });
    const auto topic_sigFloat = interfaceName() + "/sig/sigFloat";
    connect(m_impl.get(), &AbstractSimpleInterface::sigFloat, this,
        [this, topic_sigFloat](qreal paramFloat)
        {
            nlohmann::json args = { paramFloat };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat, args);
        });
    const auto topic_sigFloat32 = interfaceName() + "/sig/sigFloat32";
    connect(m_impl.get(), &AbstractSimpleInterface::sigFloat32, this,
        [this, topic_sigFloat32](float paramFloat32)
        {
            nlohmann::json args = { paramFloat32 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat32, args);
        });
    const auto topic_sigFloat64 = interfaceName() + "/sig/sigFloat64";
    connect(m_impl.get(), &AbstractSimpleInterface::sigFloat64, this,
        [this, topic_sigFloat64](double paramFloat64)
        {
            nlohmann::json args = { paramFloat64 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat64, args);
        });
    const auto topic_sigString = interfaceName() + "/sig/sigString";
    connect(m_impl.get(), &AbstractSimpleInterface::sigString, this,
        [this, topic_sigString](const QString& paramString)
        {
            nlohmann::json args = { paramString };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigString, args);
        });
}

void MqttSimpleInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void MqttSimpleInterfaceAdapter::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
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

} // namespace tb_simple

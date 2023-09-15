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


#include "mqttsimplearrayinterfaceadapter.h"
#include "tb_simple/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_simple {

namespace
{
const QString ID = "tb.simple/SimpleArrayInterface";
}


MqttSimpleArrayInterfaceAdapter::MqttSimpleArrayInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractSimpleArrayInterface> impl, QObject *parent)
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

MqttSimpleArrayInterfaceAdapter::~MqttSimpleArrayInterfaceAdapter()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& MqttSimpleArrayInterfaceAdapter::objectName()
{
    return ID;
}

void MqttSimpleArrayInterfaceAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_propBool = objectName() + "/set/propBool";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propBool,
        [this](const nlohmann::json& value)
        {
            QList<bool> propBool = value.get<QList<bool>>();
            m_impl->setPropBool(propBool);
        }));
    const auto setTopic_propInt = objectName() + "/set/propInt";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt,
        [this](const nlohmann::json& value)
        {
            QList<int> propInt = value.get<QList<int>>();
            m_impl->setPropInt(propInt);
        }));
    const auto setTopic_propInt32 = objectName() + "/set/propInt32";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt32,
        [this](const nlohmann::json& value)
        {
            QList<qint32> propInt32 = value.get<QList<qint32>>();
            m_impl->setPropInt32(propInt32);
        }));
    const auto setTopic_propInt64 = objectName() + "/set/propInt64";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propInt64,
        [this](const nlohmann::json& value)
        {
            QList<qint64> propInt64 = value.get<QList<qint64>>();
            m_impl->setPropInt64(propInt64);
        }));
    const auto setTopic_propFloat = objectName() + "/set/propFloat";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat,
        [this](const nlohmann::json& value)
        {
            QList<qreal> propFloat = value.get<QList<qreal>>();
            m_impl->setPropFloat(propFloat);
        }));
    const auto setTopic_propFloat32 = objectName() + "/set/propFloat32";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat32,
        [this](const nlohmann::json& value)
        {
            QList<float> propFloat32 = value.get<QList<float>>();
            m_impl->setPropFloat32(propFloat32);
        }));
    const auto setTopic_propFloat64 = objectName() + "/set/propFloat64";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propFloat64,
        [this](const nlohmann::json& value)
        {
            QList<double> propFloat64 = value.get<QList<double>>();
            m_impl->setPropFloat64(propFloat64);
        }));
    const auto setTopic_propString = objectName() + "/set/propString";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_propString,
        [this](const nlohmann::json& value)
        {
            QList<QString> propString = value.get<QList<QString>>();
            m_impl->setPropString(propString);
        }));
}

void MqttSimpleArrayInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_funcBool = objectName() + "/rpc/funcBool";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcBool,
        [this](const nlohmann::json& arguments)
        {
            QList<bool> paramBool = arguments.at(0).get<QList<bool>>();
            auto result = m_impl->funcBool(paramBool);
            return result;
        }));
    const auto invokeTopic_funcInt = objectName() + "/rpc/funcInt";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt,
        [this](const nlohmann::json& arguments)
        {
            QList<int> paramInt = arguments.at(0).get<QList<int>>();
            auto result = m_impl->funcInt(paramInt);
            return result;
        }));
    const auto invokeTopic_funcInt32 = objectName() + "/rpc/funcInt32";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt32,
        [this](const nlohmann::json& arguments)
        {
            QList<qint32> paramInt32 = arguments.at(0).get<QList<qint32>>();
            auto result = m_impl->funcInt32(paramInt32);
            return result;
        }));
    const auto invokeTopic_funcInt64 = objectName() + "/rpc/funcInt64";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcInt64,
        [this](const nlohmann::json& arguments)
        {
            QList<qint64> paramInt64 = arguments.at(0).get<QList<qint64>>();
            auto result = m_impl->funcInt64(paramInt64);
            return result;
        }));
    const auto invokeTopic_funcFloat = objectName() + "/rpc/funcFloat";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat,
        [this](const nlohmann::json& arguments)
        {
            QList<qreal> paramFloat = arguments.at(0).get<QList<qreal>>();
            auto result = m_impl->funcFloat(paramFloat);
            return result;
        }));
    const auto invokeTopic_funcFloat32 = objectName() + "/rpc/funcFloat32";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat32,
        [this](const nlohmann::json& arguments)
        {
            QList<float> paramFloat32 = arguments.at(0).get<QList<float>>();
            auto result = m_impl->funcFloat32(paramFloat32);
            return result;
        }));
    const auto invokeTopic_funcFloat64 = objectName() + "/rpc/funcFloat64";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcFloat64,
        [this](const nlohmann::json& arguments)
        {
            QList<double> paramFloat = arguments.at(0).get<QList<double>>();
            auto result = m_impl->funcFloat64(paramFloat);
            return result;
        }));
    const auto invokeTopic_funcString = objectName() + "/rpc/funcString";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcString,
        [this](const nlohmann::json& arguments)
        {
            QList<QString> paramString = arguments.at(0).get<QList<QString>>();
            auto result = m_impl->funcString(paramString);
            return result;
        }));
}

void MqttSimpleArrayInterfaceAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_propBool = objectName() + "/prop/propBool";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propBoolChanged,
        this, [this, publishTopic_propBool](const QList<bool>& propBool)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propBool, propBool);
        });
    const auto publishTopic_propInt = objectName() + "/prop/propInt";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propIntChanged,
        this, [this, publishTopic_propInt](const QList<int>& propInt)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt, propInt);
        });
    const auto publishTopic_propInt32 = objectName() + "/prop/propInt32";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propInt32Changed,
        this, [this, publishTopic_propInt32](const QList<qint32>& propInt32)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt32, propInt32);
        });
    const auto publishTopic_propInt64 = objectName() + "/prop/propInt64";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propInt64Changed,
        this, [this, publishTopic_propInt64](const QList<qint64>& propInt64)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propInt64, propInt64);
        });
    const auto publishTopic_propFloat = objectName() + "/prop/propFloat";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propFloatChanged,
        this, [this, publishTopic_propFloat](const QList<qreal>& propFloat)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat, propFloat);
        });
    const auto publishTopic_propFloat32 = objectName() + "/prop/propFloat32";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propFloat32Changed,
        this, [this, publishTopic_propFloat32](const QList<float>& propFloat32)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat32, propFloat32);
        });
    const auto publishTopic_propFloat64 = objectName() + "/prop/propFloat64";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propFloat64Changed,
        this, [this, publishTopic_propFloat64](const QList<double>& propFloat64)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propFloat64, propFloat64);
        });
    const auto publishTopic_propString = objectName() + "/prop/propString";
    connect(m_impl.get(),&AbstractSimpleArrayInterface::propStringChanged,
        this, [this, publishTopic_propString](const QList<QString>& propString)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_propString, propString);
        });    
}

void MqttSimpleArrayInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigBool = objectName() + "/sig/sigBool";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigBool, this,
        [this, topic_sigBool](const QList<bool>& paramBool)
        {
            nlohmann::json args = { paramBool };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigBool, args);
        });
    const auto topic_sigInt = objectName() + "/sig/sigInt";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt, this,
        [this, topic_sigInt](const QList<int>& paramInt)
        {
            nlohmann::json args = { paramInt };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt, args);
        });
    const auto topic_sigInt32 = objectName() + "/sig/sigInt32";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt32, this,
        [this, topic_sigInt32](const QList<qint32>& paramInt32)
        {
            nlohmann::json args = { paramInt32 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt32, args);
        });
    const auto topic_sigInt64 = objectName() + "/sig/sigInt64";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt64, this,
        [this, topic_sigInt64](const QList<qint64>& paramInt64)
        {
            nlohmann::json args = { paramInt64 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigInt64, args);
        });
    const auto topic_sigFloat = objectName() + "/sig/sigFloat";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat, this,
        [this, topic_sigFloat](const QList<qreal>& paramFloat)
        {
            nlohmann::json args = { paramFloat };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat, args);
        });
    const auto topic_sigFloat32 = objectName() + "/sig/sigFloat32";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat32, this,
        [this, topic_sigFloat32](const QList<float>& paramFloa32)
        {
            nlohmann::json args = { paramFloa32 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat32, args);
        });
    const auto topic_sigFloat64 = objectName() + "/sig/sigFloat64";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat64, this,
        [this, topic_sigFloat64](const QList<double>& paramFloat64)
        {
            nlohmann::json args = { paramFloat64 };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigFloat64, args);
        });
    const auto topic_sigString = objectName() + "/sig/sigString";
    connect(m_impl.get(), &AbstractSimpleArrayInterface::sigString, this,
        [this, topic_sigString](const QList<QString>& paramString)
        {
            nlohmann::json args = { paramString };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigString, args);
        });
}

} // namespace tb_simple

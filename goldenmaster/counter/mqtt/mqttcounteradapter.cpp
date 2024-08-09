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


#include "mqttcounteradapter.h"
#include "counter/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace counter {

namespace
{
const QString InterfaceName = "counter/Counter";
}


MqttCounterAdapter::MqttCounterAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractCounter> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_mqttServiceAdapter(mqttServiceAdapter)
{
    if (m_mqttServiceAdapter.isReady())
    {
        subscribeForPropertiesChanges();
        subscribeForInvokeRequests();
        connectServicePropertiesChanges();
    }
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, [this]()
    {
        subscribeForPropertiesChanges();
        subscribeForInvokeRequests();
        connectServicePropertiesChanges();
    });
    
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, [this](){
    AG_LOG_DEBUG(Q_FUNC_INFO);
        m_subscribedIds.clear();
    });
}

MqttCounterAdapter::~MqttCounterAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

const QString& MqttCounterAdapter::interfaceName()
{
    return InterfaceName;
}

void MqttCounterAdapter::subscribeForPropertiesChanges()
{
    const auto setTopic_vector = interfaceName() + "/set/vector";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_vector,
        [this](const nlohmann::json& value)
        {
            custom_types::Vector3D vector = value.get<custom_types::Vector3D>();
            m_impl->setVector(vector);
        }));
    const auto setTopic_extern_vector = interfaceName() + "/set/extern_vector";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_extern_vector,
        [this](const nlohmann::json& value)
        {
            QVector3D extern_vector = value.get<QVector3D>();
            m_impl->setExternVector(extern_vector);
        }));
}

void MqttCounterAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_increment = interfaceName() + "/rpc/increment";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_increment,
        [this](const nlohmann::json& arguments)
        {
            QVector3D vec = arguments.at(0).get<QVector3D>();
            auto result = m_impl->increment(vec);
            return result;
        }));
    const auto invokeTopic_decrement = interfaceName() + "/rpc/decrement";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_decrement,
        [this](const nlohmann::json& arguments)
        {
            custom_types::Vector3D vec = arguments.at(0).get<custom_types::Vector3D>();
            auto result = m_impl->decrement(vec);
            return result;
        }));
}

void MqttCounterAdapter::connectServicePropertiesChanges()
{
    const auto publishTopic_vector = interfaceName() + "/prop/vector";
    connect(m_impl.get(),&AbstractCounter::vectorChanged,
        this, [this, publishTopic_vector](const custom_types::Vector3D& vector)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_vector, vector);
        });
    const auto publishTopic_extern_vector = interfaceName() + "/prop/extern_vector";
    connect(m_impl.get(),&AbstractCounter::extern_vectorChanged,
        this, [this, publishTopic_extern_vector](const QVector3D& extern_vector)
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_extern_vector, extern_vector);
        });    
}


void MqttCounterAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

} // namespace counter

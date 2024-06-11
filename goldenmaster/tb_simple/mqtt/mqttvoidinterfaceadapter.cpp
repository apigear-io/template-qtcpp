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


#include "mqttvoidinterfaceadapter.h"
#include "tb_simple/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace tb_simple {

namespace
{
const QString InterfaceName = "tb.simple/VoidInterface";
}


MqttVoidInterfaceAdapter::MqttVoidInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractVoidInterface> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_mqttServiceAdapter(mqttServiceAdapter)
{
    if (m_mqttServiceAdapter.isReady())
    {
        subscribeForInvokeRequests();
        connectServiceSignals();
    }
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, [this]()
    {
        subscribeForInvokeRequests();
        connectServiceSignals();
    });
    
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, [this](){
    AG_LOG_DEBUG(Q_FUNC_INFO);
        m_subscribedIds.clear();
    });
}

MqttVoidInterfaceAdapter::~MqttVoidInterfaceAdapter()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

const QString& MqttVoidInterfaceAdapter::interfaceName()
{
    return InterfaceName;
}


void MqttVoidInterfaceAdapter::subscribeForInvokeRequests()
{
    const auto invokeTopic_funcVoid = interfaceName() + "/rpc/funcVoid";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_funcVoid,
        [this](const nlohmann::json& arguments)
        {
            m_impl->funcVoid( );
            return nlohmann::json {};
        }));
}


void MqttVoidInterfaceAdapter::connectServiceSignals()
{
    const auto topic_sigVoid = interfaceName() + "/sig/sigVoid";
    connect(m_impl.get(), &AbstractVoidInterface::sigVoid, this,
        [this, topic_sigVoid]()
        {
            nlohmann::json args = {  };
            m_mqttServiceAdapter.emitPropertyChange(topic_sigVoid, args);
        });
}

void MqttVoidInterfaceAdapter::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

} // namespace tb_simple

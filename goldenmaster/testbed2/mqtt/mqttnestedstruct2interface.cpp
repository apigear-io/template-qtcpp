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

#include "mqttnestedstruct2interface.h"

#include "testbed2/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace testbed2 {

namespace
{
const QString ID = "testbed2/NestedStruct2Interface";
}

MqttNestedStruct2Interface::MqttNestedStruct2Interface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_isReady(false)
    , m_client(client)
{
    if (m_client.isReady())
    {
        subscribeForPropertiesChanges();
        subscribeForSignals();
        subscribeForInvokeResponses();
    }
     connect(&m_client, &ApiGear::Mqtt::Client::ready, [this](){
        AG_LOG_DEBUG(Q_FUNC_INFO);
            subscribeForPropertiesChanges();
            subscribeForSignals();
            subscribeForInvokeResponses();
    });
}

MqttNestedStruct2Interface::~MqttNestedStruct2Interface()
{
    for(auto id :m_subscribedIds)
    {
        m_client.unsubscribeTopic(id);
    }
    for(auto info :m_InvokeCallsInfo)
    {
        m_client.unsubscribeTopic(info.second.second);
    }
}

void MqttNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    static const QString topic = objectName() + QString("/set/prop1");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { prop1 });
}

void MqttNestedStruct2Interface::setProp1Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop1(input.get<NestedStruct1>());
    if (m_prop1 != in_prop1)
    {
        m_prop1 = in_prop1;
        emit prop1Changed(in_prop1);
    }
}

NestedStruct1 MqttNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void MqttNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    static const QString topic = objectName() + QString("/set/prop2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { prop2 });
}

void MqttNestedStruct2Interface::setProp2Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop2(input.get<NestedStruct2>());
    if (m_prop2 != in_prop2)
    {
        m_prop2 = in_prop2;
        emit prop2Changed(in_prop2);
    }
}

NestedStruct2 MqttNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 MqttNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return NestedStruct1();
    }
    NestedStruct1 value{ NestedStruct1() };
    func1Async(param1)
        .then([&](NestedStruct1 result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> MqttNestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/func1");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1 });       
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    NestedStruct1 value = arg.get<NestedStruct1>();
                    resolve(value);
                });
        }
    };
}

NestedStruct1 MqttNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return NestedStruct1();
    }
    NestedStruct1 value{ NestedStruct1() };
    func2Async(param1, param2)
        .then([&](NestedStruct1 result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> MqttNestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/func2");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1, param2 });       
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    NestedStruct1 value = arg.get<NestedStruct1>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttNestedStruct2Interface::objectName()
{
    return ID;
}
void MqttNestedStruct2Interface::subscribeForPropertiesChanges()
{
        static const QString topicprop1 = objectName() + "/prop/prop1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop1, [this](auto& input) { setProp1Local(input);}));
        static const QString topicprop2 = objectName() + "/prop/prop2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop2, [this](auto& input) { setProp2Local(input);}));
}
void MqttNestedStruct2Interface::subscribeForSignals()
{
        static const QString topicsig1 = objectName() + "/sig/sig1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig1, [this](const auto& input){
            emit sig1(input[0].get<NestedStruct1>());}));
        static const QString topicsig2 = objectName() + "/sig/sig2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig2, [this](const auto& input){
            emit sig2(input[0].get<NestedStruct1>(),input[1].get<NestedStruct2>());}));
}
void MqttNestedStruct2Interface::subscribeForInvokeResponses()
{
    // Subscribe for invokeReply and prepare invoke call info for non void functions.
    const QString topicfunc1 = objectName() + "/rpc/func1";
    const QString topicfunc1InvokeResp = objectName() + "/rpc/func1"+ m_client.clientId() + "/result";
    auto id_func1 = m_client.subscribeForInvokeResponse(topicfunc1InvokeResp);
    m_InvokeCallsInfo[topicfunc1] = std::make_pair(topicfunc1InvokeResp, id_func1);
    const QString topicfunc2 = objectName() + "/rpc/func2";
    const QString topicfunc2InvokeResp = objectName() + "/rpc/func2"+ m_client.clientId() + "/result";
    auto id_func2 = m_client.subscribeForInvokeResponse(topicfunc2InvokeResp);
    m_InvokeCallsInfo[topicfunc2] = std::make_pair(topicfunc2InvokeResp, id_func2);
}


} // namespace testbed2
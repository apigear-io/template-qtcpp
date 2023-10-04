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

#include "mqttenuminterface.h"

#include "tb_enum/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace tb_enum {

namespace
{
const QString InterfaceName = "tb.enum/EnumInterface";
}

MqttEnumInterface::MqttEnumInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractEnumInterface(parent)
    , m_prop0(Enum0::value0)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value2)
    , m_prop3(Enum3::value3)
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
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
}

MqttEnumInterface::~MqttEnumInterface()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

void MqttEnumInterface::setProp0(Enum0::Enum0Enum prop0)
{
    static const QString topic = interfaceName() + QString("/set/prop0");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop0 ));
}

void MqttEnumInterface::setProp0Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop0(value.get<Enum0::Enum0Enum>());
    if (m_prop0 != in_prop0)
    {
        m_prop0 = in_prop0;
        emit prop0Changed(in_prop0);
    }
}

Enum0::Enum0Enum MqttEnumInterface::prop0() const
{
    return m_prop0;
}

void MqttEnumInterface::setProp1(Enum1::Enum1Enum prop1)
{
    static const QString topic = interfaceName() + QString("/set/prop1");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop1 ));
}

void MqttEnumInterface::setProp1Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop1(value.get<Enum1::Enum1Enum>());
    if (m_prop1 != in_prop1)
    {
        m_prop1 = in_prop1;
        emit prop1Changed(in_prop1);
    }
}

Enum1::Enum1Enum MqttEnumInterface::prop1() const
{
    return m_prop1;
}

void MqttEnumInterface::setProp2(Enum2::Enum2Enum prop2)
{
    static const QString topic = interfaceName() + QString("/set/prop2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop2 ));
}

void MqttEnumInterface::setProp2Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop2(value.get<Enum2::Enum2Enum>());
    if (m_prop2 != in_prop2)
    {
        m_prop2 = in_prop2;
        emit prop2Changed(in_prop2);
    }
}

Enum2::Enum2Enum MqttEnumInterface::prop2() const
{
    return m_prop2;
}

void MqttEnumInterface::setProp3(Enum3::Enum3Enum prop3)
{
    static const QString topic = interfaceName() + QString("/set/prop3");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( prop3 ));
}

void MqttEnumInterface::setProp3Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop3(value.get<Enum3::Enum3Enum>());
    if (m_prop3 != in_prop3)
    {
        m_prop3 = in_prop3;
        emit prop3Changed(in_prop3);
    }
}

Enum3::Enum3Enum MqttEnumInterface::prop3() const
{
    return m_prop3;
}

Enum0::Enum0Enum MqttEnumInterface::func0(Enum0::Enum0Enum param0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return Enum0::value0;
    }
    Enum0::Enum0Enum value{ Enum0::value0 };
    func0Async(param0)
        .then([&](Enum0::Enum0Enum result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<Enum0::Enum0Enum> MqttEnumInterface::func0Async(Enum0::Enum0Enum param0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func0");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<Enum0::Enum0Enum>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<Enum0::Enum0Enum>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param0 });       
    return QtPromise::QPromise<Enum0::Enum0Enum>{[&](
        const QtPromise::QPromiseResolve<Enum0::Enum0Enum>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    Enum0::Enum0Enum value = arg.get<Enum0::Enum0Enum>();
                    resolve(value);
                });
        }
    };
}

Enum1::Enum1Enum MqttEnumInterface::func1(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return Enum1::value1;
    }
    Enum1::Enum1Enum value{ Enum1::value1 };
    func1Async(param1)
        .then([&](Enum1::Enum1Enum result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> MqttEnumInterface::func1Async(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func1");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1 });       
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    Enum1::Enum1Enum value = arg.get<Enum1::Enum1Enum>();
                    resolve(value);
                });
        }
    };
}

Enum2::Enum2Enum MqttEnumInterface::func2(Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return Enum2::value2;
    }
    Enum2::Enum2Enum value{ Enum2::value2 };
    func2Async(param2)
        .then([&](Enum2::Enum2Enum result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<Enum2::Enum2Enum> MqttEnumInterface::func2Async(Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func2");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<Enum2::Enum2Enum>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<Enum2::Enum2Enum>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param2 });       
    return QtPromise::QPromise<Enum2::Enum2Enum>{[&](
        const QtPromise::QPromiseResolve<Enum2::Enum2Enum>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    Enum2::Enum2Enum value = arg.get<Enum2::Enum2Enum>();
                    resolve(value);
                });
        }
    };
}

Enum3::Enum3Enum MqttEnumInterface::func3(Enum3::Enum3Enum param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return Enum3::value3;
    }
    Enum3::Enum3Enum value{ Enum3::value3 };
    func3Async(param3)
        .then([&](Enum3::Enum3Enum result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<Enum3::Enum3Enum> MqttEnumInterface::func3Async(Enum3::Enum3Enum param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = interfaceName() + QString("/rpc/func3");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<Enum3::Enum3Enum>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<Enum3::Enum3Enum>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param3 });       
    return QtPromise::QPromise<Enum3::Enum3Enum>{[&](
        const QtPromise::QPromiseResolve<Enum3::Enum3Enum>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const nlohmann::json& arg)
                {
                    Enum3::Enum3Enum value = arg.get<Enum3::Enum3Enum>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttEnumInterface::interfaceName()
{
    return InterfaceName;
}
void MqttEnumInterface::subscribeForPropertiesChanges()
{
        static const QString topicprop0 = interfaceName() + "/prop/prop0";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop0, [this](auto& value) { setProp0Local(value);}));
        static const QString topicprop1 = interfaceName() + "/prop/prop1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop1, [this](auto& value) { setProp1Local(value);}));
        static const QString topicprop2 = interfaceName() + "/prop/prop2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop2, [this](auto& value) { setProp2Local(value);}));
        static const QString topicprop3 = interfaceName() + "/prop/prop3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop3, [this](auto& value) { setProp3Local(value);}));
}
void MqttEnumInterface::subscribeForSignals()
{
        static const QString topicsig0 = interfaceName() + "/sig/sig0";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig0, [this](const nlohmann::json& argumentsArray){
            emit sig0(argumentsArray[0].get<Enum0::Enum0Enum>());}));
        static const QString topicsig1 = interfaceName() + "/sig/sig1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig1, [this](const nlohmann::json& argumentsArray){
            emit sig1(argumentsArray[0].get<Enum1::Enum1Enum>());}));
        static const QString topicsig2 = interfaceName() + "/sig/sig2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig2, [this](const nlohmann::json& argumentsArray){
            emit sig2(argumentsArray[0].get<Enum2::Enum2Enum>());}));
        static const QString topicsig3 = interfaceName() + "/sig/sig3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig3, [this](const nlohmann::json& argumentsArray){
            emit sig3(argumentsArray[0].get<Enum3::Enum3Enum>());}));
}
void MqttEnumInterface::subscribeForInvokeResponses()
{
    // Subscribe for invokeReply and prepare invoke call info for non void functions.
    const QString topicfunc0 = interfaceName() + "/rpc/func0";
    const QString topicfunc0InvokeResp = interfaceName() + "/rpc/func0"+ m_client.clientId() + "/result";
    auto id_func0 = m_client.subscribeForInvokeResponse(topicfunc0InvokeResp);
    m_InvokeCallsInfo[topicfunc0] = std::make_pair(topicfunc0InvokeResp, id_func0);
    const QString topicfunc1 = interfaceName() + "/rpc/func1";
    const QString topicfunc1InvokeResp = interfaceName() + "/rpc/func1"+ m_client.clientId() + "/result";
    auto id_func1 = m_client.subscribeForInvokeResponse(topicfunc1InvokeResp);
    m_InvokeCallsInfo[topicfunc1] = std::make_pair(topicfunc1InvokeResp, id_func1);
    const QString topicfunc2 = interfaceName() + "/rpc/func2";
    const QString topicfunc2InvokeResp = interfaceName() + "/rpc/func2"+ m_client.clientId() + "/result";
    auto id_func2 = m_client.subscribeForInvokeResponse(topicfunc2InvokeResp);
    m_InvokeCallsInfo[topicfunc2] = std::make_pair(topicfunc2InvokeResp, id_func2);
    const QString topicfunc3 = interfaceName() + "/rpc/func3";
    const QString topicfunc3InvokeResp = interfaceName() + "/rpc/func3"+ m_client.clientId() + "/result";
    auto id_func3 = m_client.subscribeForInvokeResponse(topicfunc3InvokeResp);
    m_InvokeCallsInfo[topicfunc3] = std::make_pair(topicfunc3InvokeResp, id_func3);
}

void MqttEnumInterface::unsubscribeAll()
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

} // namespace tb_enum

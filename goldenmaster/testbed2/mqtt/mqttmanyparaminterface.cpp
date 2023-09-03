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

#include "mqttmanyparaminterface.h"

#include "testbed2/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace testbed2 {

namespace
{
const QString ID = "testbed2/ManyParamInterface";
}

MqttManyParamInterface::MqttManyParamInterface(ApiGear::Mqtt::Client& client, QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
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

MqttManyParamInterface::~MqttManyParamInterface()
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

void MqttManyParamInterface::setProp1(int prop1)
{
    static const QString topic = objectName() + QString("/set/prop1");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { prop1 });
}

void MqttManyParamInterface::setProp1Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop1(input.get<int>());
    if (m_prop1 != in_prop1)
    {
        m_prop1 = in_prop1;
        emit prop1Changed(in_prop1);
    }
}

int MqttManyParamInterface::prop1() const
{
    return m_prop1;
}

void MqttManyParamInterface::setProp2(int prop2)
{
    static const QString topic = objectName() + QString("/set/prop2");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { prop2 });
}

void MqttManyParamInterface::setProp2Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop2(input.get<int>());
    if (m_prop2 != in_prop2)
    {
        m_prop2 = in_prop2;
        emit prop2Changed(in_prop2);
    }
}

int MqttManyParamInterface::prop2() const
{
    return m_prop2;
}

void MqttManyParamInterface::setProp3(int prop3)
{
    static const QString topic = objectName() + QString("/set/prop3");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { prop3 });
}

void MqttManyParamInterface::setProp3Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop3(input.get<int>());
    if (m_prop3 != in_prop3)
    {
        m_prop3 = in_prop3;
        emit prop3Changed(in_prop3);
    }
}

int MqttManyParamInterface::prop3() const
{
    return m_prop3;
}

void MqttManyParamInterface::setProp4(int prop4)
{
    static const QString topic = objectName() + QString("/set/prop4");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { prop4 });
}

void MqttManyParamInterface::setProp4Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_prop4(input.get<int>());
    if (m_prop4 != in_prop4)
    {
        m_prop4 = in_prop4;
        emit prop4Changed(in_prop4);
    }
}

int MqttManyParamInterface::prop4() const
{
    return m_prop4;
}

int MqttManyParamInterface::func1(int param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0;
    }
    int value{ 0 };
    func1Async(param1)
        .then([&](int result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<int> MqttManyParamInterface::func1Async(int param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/func1");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1 });       
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    int value = arg.get<int>();
                    resolve(value);
                });
        }
    };
}

int MqttManyParamInterface::func2(int param1, int param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0;
    }
    int value{ 0 };
    func2Async(param1, param2)
        .then([&](int result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<int> MqttManyParamInterface::func2Async(int param1, int param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/func2");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1, param2 });       
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    int value = arg.get<int>();
                    resolve(value);
                });
        }
    };
}

int MqttManyParamInterface::func3(int param1, int param2, int param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0;
    }
    int value{ 0 };
    func3Async(param1, param2, param3)
        .then([&](int result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<int> MqttManyParamInterface::func3Async(int param1, int param2, int param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/func3");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1, param2, param3 });       
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    int value = arg.get<int>();
                    resolve(value);
                });
        }
    };
}

int MqttManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady()) {
        return 0;
    }
    int value{ 0 };
    func4Async(param1, param2, param3, param4)
        .then([&](int result) {value = result;})
        .wait();
    return value;
}

QtPromise::QPromise<int> MqttManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/func4");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({param1, param2, param3, param4 });       
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    int value = arg.get<int>();
                    resolve(value);
                });
        }
    };
}


const QString& MqttManyParamInterface::objectName()
{
    return ID;
}
void MqttManyParamInterface::subscribeForPropertiesChanges()
{
        static const QString topicprop1 = objectName() + "/prop/prop1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop1, [this](auto& input) { setProp1Local(input);}));
        static const QString topicprop2 = objectName() + "/prop/prop2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop2, [this](auto& input) { setProp2Local(input);}));
        static const QString topicprop3 = objectName() + "/prop/prop3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop3, [this](auto& input) { setProp3Local(input);}));
        static const QString topicprop4 = objectName() + "/prop/prop4";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicprop4, [this](auto& input) { setProp4Local(input);}));
}
void MqttManyParamInterface::subscribeForSignals()
{
        static const QString topicsig1 = objectName() + "/sig/sig1";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig1, [this](const auto& input){
            emit sig1(input[0].get<int>());}));
        static const QString topicsig2 = objectName() + "/sig/sig2";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig2, [this](const auto& input){
            emit sig2(input[0].get<int>(),input[1].get<int>());}));
        static const QString topicsig3 = objectName() + "/sig/sig3";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig3, [this](const auto& input){
            emit sig3(input[0].get<int>(),input[1].get<int>(),input[2].get<int>());}));
        static const QString topicsig4 = objectName() + "/sig/sig4";
        m_subscribedIds.push_back(m_client.subscribeTopic(topicsig4, [this](const auto& input){
            emit sig4(input[0].get<int>(),input[1].get<int>(),input[2].get<int>(),input[3].get<int>());}));
}
void MqttManyParamInterface::subscribeForInvokeResponses()
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
    const QString topicfunc3 = objectName() + "/rpc/func3";
    const QString topicfunc3InvokeResp = objectName() + "/rpc/func3"+ m_client.clientId() + "/result";
    auto id_func3 = m_client.subscribeForInvokeResponse(topicfunc3InvokeResp);
    m_InvokeCallsInfo[topicfunc3] = std::make_pair(topicfunc3InvokeResp, id_func3);
    const QString topicfunc4 = objectName() + "/rpc/func4";
    const QString topicfunc4InvokeResp = objectName() + "/rpc/func4"+ m_client.clientId() + "/result";
    auto id_func4 = m_client.subscribeForInvokeResponse(topicfunc4InvokeResp);
    m_InvokeCallsInfo[topicfunc4] = std::make_pair(topicfunc4InvokeResp, id_func4);
}


} // namespace testbed2

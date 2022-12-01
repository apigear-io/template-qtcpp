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
#include "olinkmanyparaminterface.h"

#include "testbed2/api/agent.h"
#include "testbed2/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

OLinkManyParamInterface::OLinkManyParamInterface(QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkManyParamInterface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<int>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<int>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<int>());
    }
    if(fields.contains("prop4")) {
        setProp4Local(fields["prop4"].get<int>());
    }
}

void OLinkManyParamInterface::setProp1(int prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop1", prop1);
}

void OLinkManyParamInterface::setProp1Local(int prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int OLinkManyParamInterface::prop1() const
{
    return m_prop1;
}

void OLinkManyParamInterface::setProp2(int prop2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop2", prop2);
}

void OLinkManyParamInterface::setProp2Local(int prop2)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int OLinkManyParamInterface::prop2() const
{
    return m_prop2;
}

void OLinkManyParamInterface::setProp3(int prop3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop3", prop3);
}

void OLinkManyParamInterface::setProp3Local(int prop3)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int OLinkManyParamInterface::prop3() const
{
    return m_prop3;
}

void OLinkManyParamInterface::setProp4(int prop4)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop4", prop4);
}

void OLinkManyParamInterface::setProp4Local(int prop4)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int OLinkManyParamInterface::prop4() const
{
    return m_prop4;
}

int OLinkManyParamInterface::func1(int param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    int value{ 0 };
    func1Async(param1)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> OLinkManyParamInterface::func1Async(int param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}

int OLinkManyParamInterface::func2(int param1, int param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    int value{ 0 };
    func2Async(param1, param2)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> OLinkManyParamInterface::func2Async(int param1, int param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}

int OLinkManyParamInterface::func3(int param1, int param2, int param3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    int value{ 0 };
    func3Async(param1, param2, param3)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> OLinkManyParamInterface::func3Async(int param1, int param2, int param3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2,param3}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}

int OLinkManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    int value{ 0 };
    func4Async(param1, param2, param3, param4)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> OLinkManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func4");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2,param3,param4}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}


std::string OLinkManyParamInterface::olinkObjectName()
{
    return "testbed2.ManyParamInterface";
}

void OLinkManyParamInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<int>());   
        return;
    }
    if(signalName == "sig2") {
        emit sig2(args[0].get<int>(),args[1].get<int>());   
        return;
    }
    if(signalName == "sig3") {
        emit sig3(args[0].get<int>(),args[1].get<int>(),args[2].get<int>());   
        return;
    }
    if(signalName == "sig4") {
        emit sig4(args[0].get<int>(),args[1].get<int>(),args[2].get<int>(),args[3].get<int>());   
        return;
    }
}

void OLinkManyParamInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkManyParamInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkManyParamInterface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



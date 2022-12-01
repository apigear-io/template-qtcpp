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
#include "olinknestedstruct3interface.h"

#include "testbed2/api/agent.h"
#include "testbed2/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed2 {

OLinkNestedStruct3Interface::OLinkNestedStruct3Interface(QObject *parent)
    : AbstractNestedStruct3Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_prop3(NestedStruct3())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkNestedStruct3Interface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<NestedStruct3>());
    }
}

void OLinkNestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct3Interface/prop1", prop1);
}

void OLinkNestedStruct3Interface::setProp1Local(const NestedStruct1& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 OLinkNestedStruct3Interface::prop1() const
{
    return m_prop1;
}

void OLinkNestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct3Interface/prop2", prop2);
}

void OLinkNestedStruct3Interface::setProp2Local(const NestedStruct2& prop2)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}

NestedStruct2 OLinkNestedStruct3Interface::prop2() const
{
    return m_prop2;
}

void OLinkNestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct3Interface/prop3", prop3);
}

void OLinkNestedStruct3Interface::setProp3Local(const NestedStruct3& prop3)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}

NestedStruct3 OLinkNestedStruct3Interface::prop3() const
{
    return m_prop3;
}

NestedStruct1 OLinkNestedStruct3Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return NestedStruct1();
    }
    NestedStruct1 value{ NestedStruct1() };
    func1Async(param1)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct3Interface::func1Async(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}

NestedStruct1 OLinkNestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return NestedStruct1();
    }
    NestedStruct1 value{ NestedStruct1() };
    func2Async(param1, param2)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct3Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}

NestedStruct1 OLinkNestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return NestedStruct1();
    }
    NestedStruct1 value{ NestedStruct1() };
    func3Async(param1, param2, param3)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct3Interface::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2,param3}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}


std::string OLinkNestedStruct3Interface::olinkObjectName()
{
    return "testbed2.NestedStruct3Interface";
}

void OLinkNestedStruct3Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<NestedStruct1>());   
        return;
    }
    if(signalName == "sig2") {
        emit sig2(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>());   
        return;
    }
    if(signalName == "sig3") {
        emit sig3(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>(),args[2].get<NestedStruct3>());   
        return;
    }
}

void OLinkNestedStruct3Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkNestedStruct3Interface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNestedStruct3Interface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}

} //namespace testbed2

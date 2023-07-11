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
#include "olinknestedstruct2interface.h"

#include "testbed2/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed2 {

OLinkNestedStruct2Interface::OLinkNestedStruct2Interface(QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkNestedStruct2Interface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void OLinkNestedStruct2Interface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "prop1") {
        setProp1Local(value.get<NestedStruct1>());
    }
    else if ( propertyName == "prop2") {
        setProp2Local(value.get<NestedStruct2>());
    }
}

void OLinkNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop1", prop1);
}

void OLinkNestedStruct2Interface::setProp1Local(const NestedStruct1& prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

NestedStruct1 OLinkNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void OLinkNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop2", prop2);
}

void OLinkNestedStruct2Interface::setProp2Local(const NestedStruct2& prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

NestedStruct2 OLinkNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 OLinkNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
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

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            m_node->invokeRemote(operationId, nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}

NestedStruct1 OLinkNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
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

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}


std::string OLinkNestedStruct2Interface::olinkObjectName()
{
    return "testbed2.NestedStruct2Interface";
}

void OLinkNestedStruct2Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<NestedStruct1>());   
        return;
    }
    if(signalName == "sig2") {
        emit sig2(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>());   
        return;
    }
}

void OLinkNestedStruct2Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkNestedStruct2Interface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNestedStruct2Interface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace testbed2

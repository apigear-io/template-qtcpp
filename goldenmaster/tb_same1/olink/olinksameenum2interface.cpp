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
#include "olinksameenum2interface.h"

#include "tb_same1/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_same1 {

OLinkSameEnum2Interface::OLinkSameEnum2Interface(QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value1)
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkSameEnum2Interface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1::Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2::Enum2Enum>());
    }
}

void OLinkSameEnum2Interface::setProp1(Enum1::Enum1Enum prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameEnum2Interface/prop1", prop1);
}

void OLinkSameEnum2Interface::setProp1Local(Enum1::Enum1Enum prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum OLinkSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void OLinkSameEnum2Interface::setProp2(Enum2::Enum2Enum prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameEnum2Interface/prop2", prop2);
}

void OLinkSameEnum2Interface::setProp2Local(Enum2::Enum2Enum prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum OLinkSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum OLinkSameEnum2Interface::func1(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return Enum1::Value1;
    }
    Enum1::Enum1Enum value{ Enum1::Value1 };
    func1Async(param1)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> OLinkSameEnum2Interface::func1Async(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const Enum1::Enum1Enum& value = arg.value.get<Enum1::Enum1Enum>();
                resolve(value);
            });
        }
    };
}

Enum1::Enum1Enum OLinkSameEnum2Interface::func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return Enum1::Value1;
    }
    Enum1::Enum1Enum value{ Enum1::Value1 };
    func2Async(param1, param2)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> OLinkSameEnum2Interface::func2Async(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const Enum1::Enum1Enum& value = arg.value.get<Enum1::Enum1Enum>();
                resolve(value);
            });
        }
    };
}


std::string OLinkSameEnum2Interface::olinkObjectName()
{
    return "tb.same1.SameEnum2Interface";
}

void OLinkSameEnum2Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<Enum1::Enum1Enum>());   
        return;
    }
    if(signalName == "sig2") {
        emit sig2(args[0].get<Enum1::Enum1Enum>(),args[1].get<Enum2::Enum2Enum>());   
        return;
    }
}

void OLinkSameEnum2Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkSameEnum2Interface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSameEnum2Interface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_same1

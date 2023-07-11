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
#include "olinksamestruct1interface.h"

#include "tb_same1/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_same1 {

OLinkSameStruct1Interface::OLinkSameStruct1Interface(QObject *parent)
    : AbstractSameStruct1Interface(parent)
    , m_prop1(Struct1())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkSameStruct1Interface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct1>());
    }
}

void OLinkSameStruct1Interface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "prop1") {
        setProp1Local(value.get<Struct1>());
    }
}

void OLinkSameStruct1Interface::setProp1(const Struct1& prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameStruct1Interface/prop1", prop1);
}

void OLinkSameStruct1Interface::setProp1Local(const Struct1& prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Struct1 OLinkSameStruct1Interface::prop1() const
{
    return m_prop1;
}

Struct1 OLinkSameStruct1Interface::func1(const Struct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return Struct1();
    }
    Struct1 value{ Struct1() };
    func1Async(param1)
        .then([&](Struct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Struct1> OLinkSameStruct1Interface::func1Async(const Struct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<Struct1>::reject("not initialized");
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
    return QtPromise::QPromise<Struct1>{[&](
        const QtPromise::QPromiseResolve<Struct1>& resolve) {
            m_node->invokeRemote(operationId, nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const Struct1& value = arg.value.get<Struct1>();
                resolve(value);
            });
        }
    };
}


std::string OLinkSameStruct1Interface::olinkObjectName()
{
    return "tb.same1.SameStruct1Interface";
}

void OLinkSameStruct1Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<Struct1>());   
        return;
    }
}

void OLinkSameStruct1Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkSameStruct1Interface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSameStruct1Interface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_same1

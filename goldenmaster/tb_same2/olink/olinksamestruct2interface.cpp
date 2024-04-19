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
#include "olinksamestruct2interface.h"

#include "tb_same2/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_same2 {

OLinkSameStruct2Interface::OLinkSameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
    , m_prop1(Struct2())
    , m_prop2(Struct2())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkSameStruct2Interface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct2>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Struct2>());
    }
}

void OLinkSameStruct2Interface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "prop1") {
        setProp1Local(value.get<Struct2>());
    }
    else if ( propertyName == "prop2") {
        setProp2Local(value.get<Struct2>());
    }
}

void OLinkSameStruct2Interface::setProp1(const Struct2& prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameStruct2Interface/prop1", prop1);
}

void OLinkSameStruct2Interface::setProp1Local(const Struct2& prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Struct2 OLinkSameStruct2Interface::prop1() const
{
    return m_prop1;
}

void OLinkSameStruct2Interface::setProp2(const Struct2& prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameStruct2Interface/prop2", prop2);
}

void OLinkSameStruct2Interface::setProp2Local(const Struct2& prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Struct2 OLinkSameStruct2Interface::prop2() const
{
    return m_prop2;
}


Struct1 OLinkSameStruct2Interface::func1(const Struct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = func1Async(param1);
    future.waitForFinished();
    return future.result();
}

QFuture<Struct1> OLinkSameStruct2Interface::func1Async(const Struct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<Struct1>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSameStruct2Interface::func1, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(Struct1());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
    m_node->invokeRemote(operationId, nlohmann::json::array({param1}), 
            [resolve](InvokeReplyArg arg) {
                Struct1 value = arg.value.get<Struct1>();
                resolve->addResult(value);
            });
    return resolve->future();
}


Struct1 OLinkSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = func2Async(param1, param2);
    future.waitForFinished();
    return future.result();
}

QFuture<Struct1> OLinkSameStruct2Interface::func2Async(const Struct1& param1, const Struct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<Struct1>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSameStruct2Interface::func2, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(Struct1());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
    m_node->invokeRemote(operationId, nlohmann::json::array({param1,param2}), 
            [resolve](InvokeReplyArg arg) {
                Struct1 value = arg.value.get<Struct1>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkSameStruct2Interface::olinkObjectName()
{
    return "tb.same2.SameStruct2Interface";
}

void OLinkSameStruct2Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<Struct1>());   
        return;
    }
    if(signalName == "sig2") {
        emit sig2(args[0].get<Struct1>(),args[1].get<Struct2>());   
        return;
    }
}

void OLinkSameStruct2Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkSameStruct2Interface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSameStruct2Interface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_same2

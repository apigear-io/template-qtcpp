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
#include "olinkenuminterface.h"

#include "tb_enum/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_enum {

OLinkEnumInterface::OLinkEnumInterface(QObject *parent)
    : AbstractEnumInterface(parent)
    , m_prop0(Enum0::Value0)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value2)
    , m_prop3(Enum3::Value3)
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkEnumInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("prop0")) {
        setProp0Local(fields["prop0"].get<Enum0::Enum0Enum>());
    }
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1::Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2::Enum2Enum>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<Enum3::Enum3Enum>());
    }
}

void OLinkEnumInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "prop0") {
        setProp0Local(value.get<Enum0::Enum0Enum>());
    }
    else if ( propertyName == "prop1") {
        setProp1Local(value.get<Enum1::Enum1Enum>());
    }
    else if ( propertyName == "prop2") {
        setProp2Local(value.get<Enum2::Enum2Enum>());
    }
    else if ( propertyName == "prop3") {
        setProp3Local(value.get<Enum3::Enum3Enum>());
    }
}

void OLinkEnumInterface::setProp0(Enum0::Enum0Enum prop0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop0", prop0);
}

void OLinkEnumInterface::setProp0Local(Enum0::Enum0Enum prop0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop0 != prop0) {
        m_prop0 = prop0;
        emit prop0Changed(prop0);
    }
}

Enum0::Enum0Enum OLinkEnumInterface::prop0() const
{
    return m_prop0;
}

void OLinkEnumInterface::setProp1(Enum1::Enum1Enum prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop1", prop1);
}

void OLinkEnumInterface::setProp1Local(Enum1::Enum1Enum prop1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum OLinkEnumInterface::prop1() const
{
    return m_prop1;
}

void OLinkEnumInterface::setProp2(Enum2::Enum2Enum prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop2", prop2);
}

void OLinkEnumInterface::setProp2Local(Enum2::Enum2Enum prop2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum OLinkEnumInterface::prop2() const
{
    return m_prop2;
}

void OLinkEnumInterface::setProp3(Enum3::Enum3Enum prop3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop3", prop3);
}

void OLinkEnumInterface::setProp3Local(Enum3::Enum3Enum prop3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

Enum3::Enum3Enum OLinkEnumInterface::prop3() const
{
    return m_prop3;
}


Enum0::Enum0Enum OLinkEnumInterface::func0(Enum0::Enum0Enum param0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = func0Async(param0);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum0::Enum0Enum> OLinkEnumInterface::func0Async(Enum0::Enum0Enum param0)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<Enum0::Enum0Enum>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkEnumInterface::func0, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(Enum0::Value0);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func0");
    m_node->invokeRemote(operationId, nlohmann::json::array({param0}), 
            [resolve](InvokeReplyArg arg) {
                Enum0::Enum0Enum value = arg.value.get<Enum0::Enum0Enum>();
                resolve->addResult(value);
            });
    return resolve->future();
}


Enum1::Enum1Enum OLinkEnumInterface::func1(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = func1Async(param1);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum1::Enum1Enum> OLinkEnumInterface::func1Async(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<Enum1::Enum1Enum>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkEnumInterface::func1, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(Enum1::Value1);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
    m_node->invokeRemote(operationId, nlohmann::json::array({param1}), 
            [resolve](InvokeReplyArg arg) {
                Enum1::Enum1Enum value = arg.value.get<Enum1::Enum1Enum>();
                resolve->addResult(value);
            });
    return resolve->future();
}


Enum2::Enum2Enum OLinkEnumInterface::func2(Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = func2Async(param2);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum2::Enum2Enum> OLinkEnumInterface::func2Async(Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<Enum2::Enum2Enum>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkEnumInterface::func2, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(Enum2::Value2);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
    m_node->invokeRemote(operationId, nlohmann::json::array({param2}), 
            [resolve](InvokeReplyArg arg) {
                Enum2::Enum2Enum value = arg.value.get<Enum2::Enum2Enum>();
                resolve->addResult(value);
            });
    return resolve->future();
}


Enum3::Enum3Enum OLinkEnumInterface::func3(Enum3::Enum3Enum param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = func3Async(param3);
    future.waitForFinished();
    return future.result();
}

QFuture<Enum3::Enum3Enum> OLinkEnumInterface::func3Async(Enum3::Enum3Enum param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<Enum3::Enum3Enum>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkEnumInterface::func3, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(Enum3::Value3);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
    m_node->invokeRemote(operationId, nlohmann::json::array({param3}), 
            [resolve](InvokeReplyArg arg) {
                Enum3::Enum3Enum value = arg.value.get<Enum3::Enum3Enum>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkEnumInterface::olinkObjectName()
{
    return "tb.enum.EnumInterface";
}

void OLinkEnumInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig0") {
        emit sig0(args[0].get<Enum0::Enum0Enum>());   
        return;
    }
    if(signalName == "sig1") {
        emit sig1(args[0].get<Enum1::Enum1Enum>());   
        return;
    }
    if(signalName == "sig2") {
        emit sig2(args[0].get<Enum2::Enum2Enum>());   
        return;
    }
    if(signalName == "sig3") {
        emit sig3(args[0].get<Enum3::Enum3Enum>());   
        return;
    }
}

void OLinkEnumInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkEnumInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkEnumInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_enum

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
#include "olinkstructinterface.h"

#include "testbed1/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed1 {

OLinkStructInterface::OLinkStructInterface(QObject *parent)
    : AbstractStructInterface(parent)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkStructInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<StructString>());
    }
}

void OLinkStructInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "propBool") {
        setPropBoolLocal(value.get<StructBool>());
    }
    else if ( propertyName == "propInt") {
        setPropIntLocal(value.get<StructInt>());
    }
    else if ( propertyName == "propFloat") {
        setPropFloatLocal(value.get<StructFloat>());
    }
    else if ( propertyName == "propString") {
        setPropStringLocal(value.get<StructString>());
    }
}

void OLinkStructInterface::setPropBool(const StructBool& propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propBool", propBool);
}

void OLinkStructInterface::setPropBoolLocal(const StructBool& propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

StructBool OLinkStructInterface::propBool() const
{
    return m_propBool;
}

void OLinkStructInterface::setPropInt(const StructInt& propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propInt", propInt);
}

void OLinkStructInterface::setPropIntLocal(const StructInt& propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

StructInt OLinkStructInterface::propInt() const
{
    return m_propInt;
}

void OLinkStructInterface::setPropFloat(const StructFloat& propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propFloat", propFloat);
}

void OLinkStructInterface::setPropFloatLocal(const StructFloat& propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

StructFloat OLinkStructInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkStructInterface::setPropString(const StructString& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propString", propString);
}

void OLinkStructInterface::setPropStringLocal(const StructString& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

StructString OLinkStructInterface::propString() const
{
    return m_propString;
}


StructBool OLinkStructInterface::funcBool(const StructBool& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<StructBool> OLinkStructInterface::funcBoolAsync(const StructBool& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<StructBool>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructInterface::funcBool, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(StructBool());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), 
            [resolve](InvokeReplyArg arg) {
                StructBool value = arg.value.get<StructBool>();
                resolve->addResult(value);
            });
    return resolve->future();
}


StructInt OLinkStructInterface::funcInt(const StructInt& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<StructInt> OLinkStructInterface::funcIntAsync(const StructInt& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<StructInt>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructInterface::funcInt, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(StructInt());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), 
            [resolve](InvokeReplyArg arg) {
                StructInt value = arg.value.get<StructInt>();
                resolve->addResult(value);
            });
    return resolve->future();
}


StructFloat OLinkStructInterface::funcFloat(const StructFloat& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<StructFloat> OLinkStructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<StructFloat>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructInterface::funcFloat, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(StructFloat());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), 
            [resolve](InvokeReplyArg arg) {
                StructFloat value = arg.value.get<StructFloat>();
                resolve->addResult(value);
            });
    return resolve->future();
}


StructString OLinkStructInterface::funcString(const StructString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<StructString> OLinkStructInterface::funcStringAsync(const StructString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<StructString>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructInterface::funcString, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(StructString());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), 
            [resolve](InvokeReplyArg arg) {
                StructString value = arg.value.get<StructString>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkStructInterface::olinkObjectName()
{
    return "testbed1.StructInterface";
}

void OLinkStructInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<StructBool>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<StructInt>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<StructFloat>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<StructString>());   
        return;
    }
}

void OLinkStructInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkStructInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkStructInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace testbed1

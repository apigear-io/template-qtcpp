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
#include "olinkstructarrayinterface.h"

#include "testbed1/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed1 {

OLinkStructArrayInterface::OLinkStructArrayInterface(QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkStructArrayInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<QList<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<QList<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<QList<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QList<StructString>>());
    }
}

void OLinkStructArrayInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "propBool") {
        setPropBoolLocal(value.get<QList<StructBool>>());
    }
    else if ( propertyName == "propInt") {
        setPropIntLocal(value.get<QList<StructInt>>());
    }
    else if ( propertyName == "propFloat") {
        setPropFloatLocal(value.get<QList<StructFloat>>());
    }
    else if ( propertyName == "propString") {
        setPropStringLocal(value.get<QList<StructString>>());
    }
}

void OLinkStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propBool", propBool);
}

void OLinkStructArrayInterface::setPropBoolLocal(const QList<StructBool>& propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

QList<StructBool> OLinkStructArrayInterface::propBool() const
{
    return m_propBool;
}

void OLinkStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propInt", propInt);
}

void OLinkStructArrayInterface::setPropIntLocal(const QList<StructInt>& propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

QList<StructInt> OLinkStructArrayInterface::propInt() const
{
    return m_propInt;
}

void OLinkStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propFloat", propFloat);
}

void OLinkStructArrayInterface::setPropFloatLocal(const QList<StructFloat>& propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<StructFloat> OLinkStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propString", propString);
}

void OLinkStructArrayInterface::setPropStringLocal(const QList<StructString>& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<StructString> OLinkStructArrayInterface::propString() const
{
    return m_propString;
}


QList<StructBool> OLinkStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructBool>> OLinkStructArrayInterface::funcBoolAsync(const QList<StructBool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<StructBool>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructArrayInterface::funcBool, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<StructBool>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), 
            [resolve](InvokeReplyArg arg) {
                QList<StructBool> value = arg.value.get<QList<StructBool>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<StructInt> OLinkStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructInt>> OLinkStructArrayInterface::funcIntAsync(const QList<StructInt>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<StructInt>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructArrayInterface::funcInt, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<StructInt>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), 
            [resolve](InvokeReplyArg arg) {
                QList<StructInt> value = arg.value.get<QList<StructInt>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<StructFloat> OLinkStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructFloat>> OLinkStructArrayInterface::funcFloatAsync(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<StructFloat>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructArrayInterface::funcFloat, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<StructFloat>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), 
            [resolve](InvokeReplyArg arg) {
                QList<StructFloat> value = arg.value.get<QList<StructFloat>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<StructString> OLinkStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<StructString>> OLinkStructArrayInterface::funcStringAsync(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<StructString>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkStructArrayInterface::funcString, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<StructString>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), 
            [resolve](InvokeReplyArg arg) {
                QList<StructString> value = arg.value.get<QList<StructString>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkStructArrayInterface::olinkObjectName()
{
    return "testbed1.StructArrayInterface";
}

void OLinkStructArrayInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<QList<StructBool>>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<QList<StructInt>>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<QList<StructFloat>>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QList<StructString>>());   
        return;
    }
}

void OLinkStructArrayInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkStructArrayInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkStructArrayInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace testbed1

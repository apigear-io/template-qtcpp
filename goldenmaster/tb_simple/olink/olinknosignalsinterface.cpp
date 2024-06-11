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
#include "olinknosignalsinterface.h"

#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkNoSignalsInterface::OLinkNoSignalsInterface(QObject *parent)
    : AbstractNoSignalsInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkNoSignalsInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
}

void OLinkNoSignalsInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "propBool") {
        setPropBoolLocal(value.get<bool>());
    }
    else if ( propertyName == "propInt") {
        setPropIntLocal(value.get<int>());
    }
}

void OLinkNoSignalsInterface::setPropBool(bool propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.NoSignalsInterface/propBool", propBool);
}

void OLinkNoSignalsInterface::setPropBoolLocal(bool propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

bool OLinkNoSignalsInterface::propBool() const
{
    return m_propBool;
}

void OLinkNoSignalsInterface::setPropInt(int propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.NoSignalsInterface/propInt", propInt);
}

void OLinkNoSignalsInterface::setPropIntLocal(int propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int OLinkNoSignalsInterface::propInt() const
{
    return m_propInt;
}


void OLinkNoSignalsInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcVoidAsync();
    future.waitForFinished();
    return;
}

QFuture<void> OLinkNoSignalsInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<void>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkNoSignalsInterface::funcVoid, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->finish();
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcVoid");
    m_node->invokeRemote(operationId, nlohmann::json::array({}), 
            [resolve](InvokeReplyArg arg) {
                resolve->finish();
            });
    return resolve->future();
}


bool OLinkNoSignalsInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<bool> OLinkNoSignalsInterface::funcBoolAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<bool>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkNoSignalsInterface::funcBool, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(false);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), 
            [resolve](InvokeReplyArg arg) {
                bool value = arg.value.get<bool>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkNoSignalsInterface::olinkObjectName()
{
    return "tb.simple.NoSignalsInterface";
}

void OLinkNoSignalsInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
}

void OLinkNoSignalsInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkNoSignalsInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNoSignalsInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple

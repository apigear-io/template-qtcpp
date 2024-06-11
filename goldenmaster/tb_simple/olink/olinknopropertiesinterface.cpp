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
#include "olinknopropertiesinterface.h"

#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkNoPropertiesInterface::OLinkNoPropertiesInterface(QObject *parent)
    : AbstractNoPropertiesInterface(parent)
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkNoPropertiesInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkNoPropertiesInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{// no properties to apply state
    (void) propertyName;
    (void) value;
}


void OLinkNoPropertiesInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcVoidAsync();
    future.waitForFinished();
    return;
}

QFuture<void> OLinkNoPropertiesInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<void>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkNoPropertiesInterface::funcVoid, client is not connected. Try reconnecting the client.";
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


bool OLinkNoPropertiesInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<bool> OLinkNoPropertiesInterface::funcBoolAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<bool>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkNoPropertiesInterface::funcBool, client is not connected. Try reconnecting the client.";
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


std::string OLinkNoPropertiesInterface::olinkObjectName()
{
    return "tb.simple.NoPropertiesInterface";
}

void OLinkNoPropertiesInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigVoid") {
        emit sigVoid();   
        return;
    }
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<bool>());   
        return;
    }
}

void OLinkNoPropertiesInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkNoPropertiesInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNoPropertiesInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple

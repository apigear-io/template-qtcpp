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
#include "olinkvoidinterface.h"

#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkVoidInterface::OLinkVoidInterface(QObject *parent)
    : AbstractVoidInterface(parent)
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkVoidInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkVoidInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{// no properties to apply state
    (void) propertyName;
    (void) value;
}


void OLinkVoidInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcVoidAsync();
    future.waitForFinished();
    return;
}

QFuture<void> OLinkVoidInterface::funcVoidAsync()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<void>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkVoidInterface::funcVoid, client is not connected. Try reconnecting the client.";
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


std::string OLinkVoidInterface::olinkObjectName()
{
    return "tb.simple.VoidInterface";
}

void OLinkVoidInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigVoid") {
        emit sigVoid();   
        return;
    }
}

void OLinkVoidInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkVoidInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkVoidInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple

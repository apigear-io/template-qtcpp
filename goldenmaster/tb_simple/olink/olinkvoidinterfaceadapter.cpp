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



#include "olinkvoidinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "tb_simple/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace tb_simple {

OLinkVoidInterfaceAdapter::OLinkVoidInterfaceAdapter(RemoteRegistry& registry, AbstractVoidInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
        connect(m_impl, &AbstractVoidInterface::sigVoid, this,
            [=]() {
                const nlohmann::json& args = {  };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigVoid");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
}

json OLinkVoidInterfaceAdapter::captureState()
{
    return json::object({
    });
}

void OLinkVoidInterfaceAdapter::applyState(const json& state)
{
}


std::string OLinkVoidInterfaceAdapter::olinkObjectName() {
    return "tb.simple.VoidInterface";
}

json OLinkVoidInterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "funcVoid") {
        m_impl->funcVoid( );
        return json{};
    }
    return json();
}

void OLinkVoidInterfaceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string path = Name::getMemberName(propertyId);    
}

void OLinkVoidInterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

void OLinkVoidInterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

json OLinkVoidInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace tb_simple

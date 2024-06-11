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



#include "olinknosignalsinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "tb_simple/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace tb_simple {

OLinkNoSignalsInterfaceAdapter::OLinkNoSignalsInterfaceAdapter(RemoteRegistry& registry, AbstractNoSignalsInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractNoSignalsInterface::propBoolChanged, this,
        [=](bool propBool) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propBool);
            }
        }
    });
    connect(m_impl, &AbstractNoSignalsInterface::propIntChanged, this,
        [=](int propInt) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propInt);
            }
        }
    });
}

json OLinkNoSignalsInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() }
    });
}

void OLinkNoSignalsInterfaceAdapter::applyState(const json& state)
{
    if(state.contains("propBool")) {
        m_impl->setPropBool(state["propBool"]);
    }
    if(state.contains("propInt")) {
        m_impl->setPropInt(state["propInt"]);
    }
}


std::string OLinkNoSignalsInterfaceAdapter::olinkObjectName() {
    return "tb.simple.NoSignalsInterface";
}

json OLinkNoSignalsInterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "funcVoid") {
        m_impl->funcVoid( );
        return json{};
    }
    if(path == "funcBool") {
        const bool& paramBool = args.at(0);
        bool result = m_impl->funcBool(paramBool);
        return result;
    }
    return json();
}

void OLinkNoSignalsInterfaceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "propBool") {
        bool propBool = value.get<bool>();
        m_impl->setPropBool(propBool);
    }
    if(path == "propInt") {
        int propInt = value.get<int>();
        m_impl->setPropInt(propInt);
    }    
}

void OLinkNoSignalsInterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

void OLinkNoSignalsInterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

json OLinkNoSignalsInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace tb_simple

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



#include "olinknam_esadapter.h"

#include <nlohmann/json.hpp>
#include "tb_names/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace tb_names {

OLinkNam_EsAdapter::OLinkNam_EsAdapter(RemoteRegistry& registry, AbstractNamEs* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractNamEs::SwitchChanged, this,
        [=](bool Switch) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "Switch");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, Switch);
            }
        }
    });
    connect(m_impl, &AbstractNamEs::SOME_PROPERTYChanged, this,
        [=](int SOME_PROPERTY) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "SOME_PROPERTY");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, SOME_PROPERTY);
            }
        }
    });
    connect(m_impl, &AbstractNamEs::Some_Poperty2Changed, this,
        [=](int Some_Poperty2) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "Some_Poperty2");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, Some_Poperty2);
            }
        }
    });
        connect(m_impl, &AbstractNamEs::someSignal, this,
            [=](bool SOME_PARAM) {
                const nlohmann::json& args = { SOME_PARAM };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "SOME_SIGNAL");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractNamEs::someSignal2, this,
            [=](bool Some_Param) {
                const nlohmann::json& args = { Some_Param };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "Some_Signal2");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
}

json OLinkNam_EsAdapter::captureState()
{
    return json::object({
        { "Switch", m_impl->Switch() },
        { "SOME_PROPERTY", m_impl->SOME_PROPERTY() },
        { "Some_Poperty2", m_impl->Some_Poperty2() }
    });
}

void OLinkNam_EsAdapter::applyState(const json& state)
{
    if(state.contains("Switch")) {
        m_impl->setSwitch(state["Switch"]);
    }
    if(state.contains("SOME_PROPERTY")) {
        m_impl->setSomeProperty(state["SOME_PROPERTY"]);
    }
    if(state.contains("Some_Poperty2")) {
        m_impl->setSomePoperty2(state["Some_Poperty2"]);
    }
}


std::string OLinkNam_EsAdapter::olinkObjectName() {
    return "tb.names.Nam_Es";
}

json OLinkNam_EsAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "SOME_FUNCTION") {
        const bool& SOME_PARAM = args.at(0);
        m_impl->someFunction( SOME_PARAM);
        return json{};
    }
    if(path == "Some_Function2") {
        const bool& Some_Param = args.at(0);
        m_impl->someFunction2( Some_Param);
        return json{};
    }
    return json();
}

void OLinkNam_EsAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "Switch") {
        bool Switch = value.get<bool>();
        m_impl->setSwitch(Switch);
    }
    if(path == "SOME_PROPERTY") {
        int SOME_PROPERTY = value.get<int>();
        m_impl->setSomeProperty(SOME_PROPERTY);
    }
    if(path == "Some_Poperty2") {
        int Some_Poperty2 = value.get<int>();
        m_impl->setSomePoperty2(Some_Poperty2);
    }    
}

void OLinkNam_EsAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

void OLinkNam_EsAdapter::olinkUnlinked(const std::string& objectId)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

json OLinkNam_EsAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace tb_names

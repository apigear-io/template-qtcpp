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



#include "olinkcounteradapter.h"

#include <nlohmann/json.hpp>
#include "counter/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace counter {

OLinkCounterAdapter::OLinkCounterAdapter(RemoteRegistry& registry, AbstractCounter* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractCounter::vectorChanged, this,
        [=](const custom_types::Vector3D& vector) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "vector");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, vector);
            }
        }
    });
    connect(m_impl, &AbstractCounter::extern_vectorChanged, this,
        [=](const QVector3D& extern_vector) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "extern_vector");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, extern_vector);
            }
        }
    });
}

json OLinkCounterAdapter::captureState()
{
    return json::object({
        { "vector", m_impl->vector() },
        { "extern_vector", m_impl->extern_vector() }
    });
}

void OLinkCounterAdapter::applyState(const json& state)
{
    if(state.contains("vector")) {
        m_impl->setVector(state["vector"]);
    }
    if(state.contains("extern_vector")) {
        m_impl->setExternVector(state["extern_vector"]);
    }
}


std::string OLinkCounterAdapter::olinkObjectName() {
    return "counter.Counter";
}

json OLinkCounterAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "increment") {
        const QVector3D& vec = args.at(0);
        QVector3D result = m_impl->increment(vec);
        return result;
    }
    if(path == "decrement") {
        const custom_types::Vector3D& vec = args.at(0);
        custom_types::Vector3D result = m_impl->decrement(vec);
        return result;
    }
    return json();
}

void OLinkCounterAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "vector") {
        custom_types::Vector3D vector = value.get<custom_types::Vector3D>();
        m_impl->setVector(vector);
    }
    if(path == "extern_vector") {
        QVector3D extern_vector = value.get<QVector3D>();
        m_impl->setExternVector(extern_vector);
    }    
}

void OLinkCounterAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

void OLinkCounterAdapter::olinkUnlinked(const std::string& objectId)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

json OLinkCounterAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace counter

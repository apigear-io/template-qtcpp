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



#include "olinknestedstruct2interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "testbed2/api/agent.h"
#include "testbed2/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace testbed2 {

OLinkNestedStruct2InterfaceAdapter::OLinkNestedStruct2InterfaceAdapter(RemoteRegistry& registry, AbstractNestedStruct2Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractNestedStruct2Interface::prop1Changed, this,
        [=](const NestedStruct1& prop1) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, prop1);
            }
        }
    });
    connect(m_impl, &AbstractNestedStruct2Interface::prop2Changed, this,
        [=](const NestedStruct2& prop2) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, prop2);
            }
        }
    });
        connect(m_impl, &AbstractNestedStruct2Interface::sig1, this,
            [=](const NestedStruct1& param1) {
                const nlohmann::json& args = { param1 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractNestedStruct2Interface::sig2, this,
            [=](const NestedStruct1& param1, const NestedStruct2& param2) {
                const nlohmann::json& args = { param1, param2 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
}

json OLinkNestedStruct2InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void OLinkNestedStruct2InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}


std::string OLinkNestedStruct2InterfaceAdapter::olinkObjectName() {
    return "testbed2.NestedStruct2Interface";
}

json OLinkNestedStruct2InterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "func1") {
        const NestedStruct1& param1 = args.at(0);
        NestedStruct1 result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const NestedStruct1& param1 = args.at(0);
        const NestedStruct2& param2 = args.at(1);
        NestedStruct1 result = m_impl->func2(param1, param2);
        return result;
    }
    return json();
}

void OLinkNestedStruct2InterfaceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_impl->setProp2(prop2);
    }    
}

void OLinkNestedStruct2InterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

void OLinkNestedStruct2InterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

json OLinkNestedStruct2InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace testbed2

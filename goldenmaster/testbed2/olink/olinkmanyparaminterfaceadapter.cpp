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



#include "olinkmanyparaminterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "testbed2/api/agent.h"
#include "testbed2/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace testbed2 {

OLinkManyParamInterfaceAdapter::OLinkManyParamInterfaceAdapter(RemoteRegistry& registry, AbstractManyParamInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractManyParamInterface::prop1Changed, this,
        [=](int prop1) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, prop1);
            }
        }
    });
    connect(m_impl, &AbstractManyParamInterface::prop2Changed, this,
        [=](int prop2) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, prop2);
            }
        }
    });
    connect(m_impl, &AbstractManyParamInterface::prop3Changed, this,
        [=](int prop3) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, prop3);
            }
        }
    });
    connect(m_impl, &AbstractManyParamInterface::prop4Changed, this,
        [=](int prop4) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop4)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, prop4);
            }
        }
    });
        connect(m_impl, &AbstractManyParamInterface::sig1, this,
            [=](int param1) {
                const nlohmann::json& args = { param1 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractManyParamInterface::sig2, this,
            [=](int param1, int param2) {
                const nlohmann::json& args = { param1, param2 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractManyParamInterface::sig3, this,
            [=](int param1, int param2, int param3) {
                const nlohmann::json& args = { param1, param2, param3 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractManyParamInterface::sig4, this,
            [=](int param1, int param2, int param3, int param4) {
                const nlohmann::json& args = { param1, param2, param3, param4 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig4)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
}

json OLinkManyParamInterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() },
        { "prop4", m_impl->prop4() }
    });
}

void OLinkManyParamInterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
    if(state.contains("prop3")) {
        m_impl->setProp3(state["prop3"]);
    }
    if(state.contains("prop4")) {
        m_impl->setProp4(state["prop4"]);
    }
}


std::string OLinkManyParamInterfaceAdapter::olinkObjectName() {
    return "testbed2.ManyParamInterface";
}

json OLinkManyParamInterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "func1") {
        const int& param1 = args.at(0);
        int result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const int& param1 = args.at(0);
        const int& param2 = args.at(1);
        int result = m_impl->func2(param1, param2);
        return result;
    }
    if(path == "func3") {
        const int& param1 = args.at(0);
        const int& param2 = args.at(1);
        const int& param3 = args.at(2);
        int result = m_impl->func3(param1, param2, param3);
        return result;
    }
    if(path == "func4") {
        const int& param1 = args.at(0);
        const int& param2 = args.at(1);
        const int& param3 = args.at(2);
        const int& param4 = args.at(3);
        int result = m_impl->func4(param1, param2, param3, param4);
        return result;
    }
    return json();
}

void OLinkManyParamInterfaceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "prop1") {
        int prop1 = value.get<int>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        int prop2 = value.get<int>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        int prop3 = value.get<int>();
        m_impl->setProp3(prop3);
    }
    if(path == "prop4") {
        int prop4 = value.get<int>();
        m_impl->setProp4(prop4);
    }    
}

void OLinkManyParamInterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

void OLinkManyParamInterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

json OLinkManyParamInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace testbed2

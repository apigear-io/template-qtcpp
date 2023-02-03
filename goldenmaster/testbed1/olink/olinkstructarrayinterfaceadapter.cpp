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



#include "olinkstructarrayinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "testbed1/api/agent.h"
#include "testbed1/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace testbed1 {

OLinkStructArrayInterfaceAdapter::OLinkStructArrayInterfaceAdapter(RemoteRegistry& registry, AbstractStructArrayInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractStructArrayInterface::propBoolChanged, this,
        [=](const QList<StructBool>& propBool) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propBool);
            }
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::propIntChanged, this,
        [=](const QList<StructInt>& propInt) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propInt);
            }
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::propFloatChanged, this,
        [=](const QList<StructFloat>& propFloat) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propFloat);
            }
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::propStringChanged, this,
        [=](const QList<StructString>& propString) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propString);
            }
        }
    });
        connect(m_impl, &AbstractStructArrayInterface::sigBool, this,
            [=](const QList<StructBool>& paramBool) {
                const nlohmann::json& args = { paramBool };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractStructArrayInterface::sigInt, this,
            [=](const QList<StructInt>& paramInt) {
                const nlohmann::json& args = { paramInt };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractStructArrayInterface::sigFloat, this,
            [=](const QList<StructFloat>& paramFloat) {
                const nlohmann::json& args = { paramFloat };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractStructArrayInterface::sigString, this,
            [=](const QList<StructString>& paramString) {
                const nlohmann::json& args = { paramString };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
}

json OLinkStructArrayInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkStructArrayInterfaceAdapter::applyState(const json& state)
{
    if(state.contains("propBool")) {
        m_impl->setPropBool(state["propBool"]);
    }
    if(state.contains("propInt")) {
        m_impl->setPropInt(state["propInt"]);
    }
    if(state.contains("propFloat")) {
        m_impl->setPropFloat(state["propFloat"]);
    }
    if(state.contains("propString")) {
        m_impl->setPropString(state["propString"]);
    }
}


std::string OLinkStructArrayInterfaceAdapter::olinkObjectName() {
    return "testbed1.StructArrayInterface";
}

json OLinkStructArrayInterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "funcBool") {
        const QList<StructBool>& paramBool = args.at(0);
        StructBool result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const QList<StructInt>& paramInt = args.at(0);
        StructBool result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const QList<StructFloat>& paramFloat = args.at(0);
        StructBool result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const QList<StructString>& paramString = args.at(0);
        StructBool result = m_impl->funcString(paramString);
        return result;
    }
    return json();
}

void OLinkStructArrayInterfaceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "propBool") {
        QList<StructBool> propBool = value.get<QList<StructBool>>();
        m_impl->setPropBool(propBool);
    }
    if(path == "propInt") {
        QList<StructInt> propInt = value.get<QList<StructInt>>();
        m_impl->setPropInt(propInt);
    }
    if(path == "propFloat") {
        QList<StructFloat> propFloat = value.get<QList<StructFloat>>();
        m_impl->setPropFloat(propFloat);
    }
    if(path == "propString") {
        QList<StructString> propString = value.get<QList<StructString>>();
        m_impl->setPropString(propString);
    }    
}

void OLinkStructArrayInterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

void OLinkStructArrayInterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

json OLinkStructArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace testbed1

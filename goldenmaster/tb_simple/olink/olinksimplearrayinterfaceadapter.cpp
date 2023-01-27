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



#include "olinksimplearrayinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "tb_simple/api/agent.h"
#include "tb_simple/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace tb_simple {

OLinkSimpleArrayInterfaceAdapter::OLinkSimpleArrayInterfaceAdapter(RemoteRegistry& registry, AbstractSimpleArrayInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
    connect(m_impl, &AbstractSimpleArrayInterface::propBoolChanged, this,
        [=](const QList<bool>& propBool) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propBool);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propIntChanged, this,
        [=](const QList<int>& propInt) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propInt);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propFloatChanged, this,
        [=](const QList<qreal>& propFloat) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propFloat);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propStringChanged, this,
        [=](const QList<QString>& propString) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString)");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propString);
            }
        }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigBool, this,
            [=](const QList<bool>& paramBool) {
                const nlohmann::json& args = { paramBool };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigInt, this,
            [=](const QList<int>& paramInt) {
                const nlohmann::json& args = { paramInt };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigFloat, this,
            [=](const QList<qreal>& paramFloat) {
                const nlohmann::json& args = { paramFloat };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat)");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigString, this,
            [=](const QList<QString>& paramString) {
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

json OLinkSimpleArrayInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkSimpleArrayInterfaceAdapter::applyState(const json& state)
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


std::string OLinkSimpleArrayInterfaceAdapter::olinkObjectName() {
    return "tb.simple.SimpleArrayInterface";
}

json OLinkSimpleArrayInterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(methodId);
    std::string path = Name::getMemberName(methodId);
    if(path == "funcBool") {
        const QList<bool>& paramBool = args.at(0);
        QList<bool> result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const QList<int>& paramInt = args.at(0);
        QList<int> result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const QList<qreal>& paramFloat = args.at(0);
        QList<qreal> result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const QList<QString>& paramString = args.at(0);
        QList<QString> result = m_impl->funcString(paramString);
        return result;
    }
    return json();
}

void OLinkSimpleArrayInterfaceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "propBool") {
        QList<bool> propBool = value.get<QList<bool>>();
        m_impl->setPropBool(propBool);
    }
    if(path == "propInt") {
        QList<int> propInt = value.get<QList<int>>();
        m_impl->setPropInt(propInt);
    }
    if(path == "propFloat") {
        QList<qreal> propFloat = value.get<QList<qreal>>();
        m_impl->setPropFloat(propFloat);
    }
    if(path == "propString") {
        QList<QString> propString = value.get<QList<QString>>();
        m_impl->setPropString(propString);
    }    
}

void OLinkSimpleArrayInterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

void OLinkSimpleArrayInterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
}

json OLinkSimpleArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace tb_simple

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
#include "tb_simple/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"
#include "utilities/logger.h"

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
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propBool);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propIntChanged, this,
        [=](const QList<int>& propInt) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propInt);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propInt32Changed, this,
        [=](const QList<qint32>& propInt32) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propInt32);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propInt64Changed, this,
        [=](const QList<qint64>& propInt64) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propInt64);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propFloatChanged, this,
        [=](const QList<qreal>& propFloat) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propFloat);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propFloat32Changed, this,
        [=](const QList<float>& propFloat32) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propFloat32);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propFloat64Changed, this,
        [=](const QList<double>& propFloat64) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propFloat64);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propStringChanged, this,
        [=](const QList<QString>& propString) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propString);
            }
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propReadOnlyStringChanged, this,
        [=](const QString& propReadOnlyString) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propReadOnlyString");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, propReadOnlyString);
            }
        }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigBool, this,
            [=](const QList<bool>& paramBool) {
                const nlohmann::json& args = { paramBool };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
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
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigInt32, this,
            [=](const QList<qint32>& paramInt32) {
                const nlohmann::json& args = { paramInt32 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt32");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigInt64, this,
            [=](const QList<qint64>& paramInt64) {
                const nlohmann::json& args = { paramInt64 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt64");
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
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigFloat32, this,
            [=](const QList<float>& paramFloa32) {
                const nlohmann::json& args = { paramFloa32 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat32");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
        connect(m_impl, &AbstractSimpleArrayInterface::sigFloat64, this,
            [=](const QList<double>& paramFloat64) {
                const nlohmann::json& args = { paramFloat64 };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat64");
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
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
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
        { "propInt32", m_impl->propInt32() },
        { "propInt64", m_impl->propInt64() },
        { "propFloat", m_impl->propFloat() },
        { "propFloat32", m_impl->propFloat32() },
        { "propFloat64", m_impl->propFloat64() },
        { "propString", m_impl->propString() },
        { "propReadOnlyString", m_impl->propReadOnlyString() }
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
    if(state.contains("propInt32")) {
        m_impl->setPropInt32(state["propInt32"]);
    }
    if(state.contains("propInt64")) {
        m_impl->setPropInt64(state["propInt64"]);
    }
    if(state.contains("propFloat")) {
        m_impl->setPropFloat(state["propFloat"]);
    }
    if(state.contains("propFloat32")) {
        m_impl->setPropFloat32(state["propFloat32"]);
    }
    if(state.contains("propFloat64")) {
        m_impl->setPropFloat64(state["propFloat64"]);
    }
    if(state.contains("propString")) {
        m_impl->setPropString(state["propString"]);
    }
    if(state.contains("propReadOnlyString")) {
        m_impl->setPropReadOnlyString(state["propReadOnlyString"]);
    }
}


std::string OLinkSimpleArrayInterfaceAdapter::olinkObjectName() {
    return "tb.simple.SimpleArrayInterface";
}

json OLinkSimpleArrayInterfaceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(methodId);
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
    if(path == "funcInt32") {
        const QList<qint32>& paramInt32 = args.at(0);
        QList<qint32> result = m_impl->funcInt32(paramInt32);
        return result;
    }
    if(path == "funcInt64") {
        const QList<qint64>& paramInt64 = args.at(0);
        QList<qint64> result = m_impl->funcInt64(paramInt64);
        return result;
    }
    if(path == "funcFloat") {
        const QList<qreal>& paramFloat = args.at(0);
        QList<qreal> result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcFloat32") {
        const QList<float>& paramFloat32 = args.at(0);
        QList<float> result = m_impl->funcFloat32(paramFloat32);
        return result;
    }
    if(path == "funcFloat64") {
        const QList<double>& paramFloat = args.at(0);
        QList<double> result = m_impl->funcFloat64(paramFloat);
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
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string path = Name::getMemberName(propertyId);
    if(path == "propBool") {
        QList<bool> propBool = value.get<QList<bool>>();
        m_impl->setPropBool(propBool);
    }
    if(path == "propInt") {
        QList<int> propInt = value.get<QList<int>>();
        m_impl->setPropInt(propInt);
    }
    if(path == "propInt32") {
        QList<qint32> propInt32 = value.get<QList<qint32>>();
        m_impl->setPropInt32(propInt32);
    }
    if(path == "propInt64") {
        QList<qint64> propInt64 = value.get<QList<qint64>>();
        m_impl->setPropInt64(propInt64);
    }
    if(path == "propFloat") {
        QList<qreal> propFloat = value.get<QList<qreal>>();
        m_impl->setPropFloat(propFloat);
    }
    if(path == "propFloat32") {
        QList<float> propFloat32 = value.get<QList<float>>();
        m_impl->setPropFloat32(propFloat32);
    }
    if(path == "propFloat64") {
        QList<double> propFloat64 = value.get<QList<double>>();
        m_impl->setPropFloat64(propFloat64);
    }
    if(path == "propString") {
        QList<QString> propString = value.get<QList<QString>>();
        m_impl->setPropString(propString);
    }
    if(path == "propReadOnlyString") {
        QString propReadOnlyString = value.get<QString>();
        m_impl->setPropReadOnlyString(propReadOnlyString);
    }    
}

void OLinkSimpleArrayInterfaceAdapter::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

void OLinkSimpleArrayInterfaceAdapter::olinkUnlinked(const std::string& objectId)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

json OLinkSimpleArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}

} // namespace tb_simple

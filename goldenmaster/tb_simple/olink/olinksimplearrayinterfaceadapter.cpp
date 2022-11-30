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
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkSimpleArrayInterfaceAdapter::OLinkSimpleArrayInterfaceAdapter(RemoteRegistry& registry, AbstractSimpleArrayInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractSimpleArrayInterface::propBoolChanged, this, [=](const QList<bool>& propBool) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propBool", propBool);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propIntChanged, this, [=](const QList<int>& propInt) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propInt", propInt);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propFloatChanged, this, [=](const QList<qreal>& propFloat) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propFloat", propFloat);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::propStringChanged, this, [=](const QList<QString>& propString) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propString", propString);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::sigBool, this, [=](const QList<bool>& paramBool) {
        if(m_node) {
            const json& args = { paramBool };
            m_node->notifySignal("tb.simple.SimpleArrayInterface/sigBool", args);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::sigInt, this, [=](const QList<int>& paramInt) {
        if(m_node) {
            const json& args = { paramInt };
            m_node->notifySignal("tb.simple.SimpleArrayInterface/sigInt", args);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::sigFloat, this, [=](const QList<qreal>& paramFloat) {
        if(m_node) {
            const json& args = { paramFloat };
            m_node->notifySignal("tb.simple.SimpleArrayInterface/sigFloat", args);
        }
    });
    connect(m_impl, &AbstractSimpleArrayInterface::sigString, this, [=](const QList<QString>& paramString) {
        if(m_node) {
            const json& args = { paramString };
            m_node->notifySignal("tb.simple.SimpleArrayInterface/sigString", args);
        }
    });
}

OLinkSimpleArrayInterfaceAdapter::~OLinkSimpleArrayInterfaceAdapter()
{
    m_registry.removeObjectSource(this);
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

json OLinkSimpleArrayInterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
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

void OLinkSimpleArrayInterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
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

void OLinkSimpleArrayInterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkSimpleArrayInterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkSimpleArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





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
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkStructArrayInterfaceAdapter::OLinkStructArrayInterfaceAdapter(AbstractStructArrayInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_node(nullptr)
{
    RemoteRegistry::get().addObjectSource(this);
    connect(m_impl, &AbstractStructArrayInterface::propBoolChanged, this, [=](const QList<StructBool>& propBool) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructArrayInterface/propBool", propBool);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::propIntChanged, this, [=](const QList<StructInt>& propInt) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructArrayInterface/propInt", propInt);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::propFloatChanged, this, [=](const QList<StructFloat>& propFloat) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructArrayInterface/propFloat", propFloat);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::propStringChanged, this, [=](const QList<StructString>& propString) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructArrayInterface/propString", propString);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::sigBool, this, [=](const QList<StructBool>& paramBool) {
        if(m_node) {
            const json& args = { paramBool };
            m_node->notifySignal("testbed1.StructArrayInterface/sigBool", args);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::sigInt, this, [=](const QList<StructInt>& paramInt) {
        if(m_node) {
            const json& args = { paramInt };
            m_node->notifySignal("testbed1.StructArrayInterface/sigInt", args);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::sigFloat, this, [=](const QList<StructFloat>& paramFloat) {
        if(m_node) {
            const json& args = { paramFloat };
            m_node->notifySignal("testbed1.StructArrayInterface/sigFloat", args);
        }
    });
    connect(m_impl, &AbstractStructArrayInterface::sigString, this, [=](const QList<StructString>& paramString) {
        if(m_node) {
            const json& args = { paramString };
            m_node->notifySignal("testbed1.StructArrayInterface/sigString", args);
        }
    });
}

OLinkStructArrayInterfaceAdapter::~OLinkStructArrayInterfaceAdapter()
{
    RemoteRegistry::get().removeObjectSource(this);
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

json OLinkStructArrayInterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
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

void OLinkStructArrayInterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
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

void OLinkStructArrayInterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkStructArrayInterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkStructArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





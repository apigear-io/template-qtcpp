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



#include "olinkstructinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkStructInterfaceAdapter::OLinkStructInterfaceAdapter(AbstractStructInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_node(nullptr)
{
    RemoteRegistry::get().addObjectSource(this);
    connect(m_impl, &AbstractStructInterface::propBoolChanged, this, [=](const StructBool& propBool) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructInterface/propBool", propBool);
        }
    });
    connect(m_impl, &AbstractStructInterface::propIntChanged, this, [=](const StructInt& propInt) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructInterface/propInt", propInt);
        }
    });
    connect(m_impl, &AbstractStructInterface::propFloatChanged, this, [=](const StructFloat& propFloat) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructInterface/propFloat", propFloat);
        }
    });
    connect(m_impl, &AbstractStructInterface::propStringChanged, this, [=](const StructString& propString) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed1.StructInterface/propString", propString);
        }
    });
    connect(m_impl, &AbstractStructInterface::sigBool, this, [=](const StructBool& paramBool) {
        if(m_node) {
            const json& args = { paramBool };
            m_node->notifySignal("testbed1.StructInterface/sigBool", args);
        }
    });
    connect(m_impl, &AbstractStructInterface::sigInt, this, [=](const StructInt& paramInt) {
        if(m_node) {
            const json& args = { paramInt };
            m_node->notifySignal("testbed1.StructInterface/sigInt", args);
        }
    });
    connect(m_impl, &AbstractStructInterface::sigFloat, this, [=](const StructFloat& paramFloat) {
        if(m_node) {
            const json& args = { paramFloat };
            m_node->notifySignal("testbed1.StructInterface/sigFloat", args);
        }
    });
    connect(m_impl, &AbstractStructInterface::sigString, this, [=](const StructString& paramString) {
        if(m_node) {
            const json& args = { paramString };
            m_node->notifySignal("testbed1.StructInterface/sigString", args);
        }
    });
}

OLinkStructInterfaceAdapter::~OLinkStructInterfaceAdapter()
{
    RemoteRegistry::get().removeObjectSource(this);
}

json OLinkStructInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkStructInterfaceAdapter::applyState(const json& state)
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


std::string OLinkStructInterfaceAdapter::olinkObjectName() {
    return "testbed1.StructInterface";
}

json OLinkStructInterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "funcBool") {
        const StructBool& paramBool = args.at(0);
        StructBool result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const StructInt& paramInt = args.at(0);
        StructBool result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const StructFloat& paramFloat = args.at(0);
        StructFloat result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const StructString& paramString = args.at(0);
        StructString result = m_impl->funcString(paramString);
        return result;
    }
    return json();
}

void OLinkStructInterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "propBool") {
        StructBool propBool = value.get<StructBool>();
        m_impl->setPropBool(propBool);
    }
    if(path == "propInt") {
        StructInt propInt = value.get<StructInt>();
        m_impl->setPropInt(propInt);
    }
    if(path == "propFloat") {
        StructFloat propFloat = value.get<StructFloat>();
        m_impl->setPropFloat(propFloat);
    }
    if(path == "propString") {
        StructString propString = value.get<StructString>();
        m_impl->setPropString(propString);
    }    
}

void OLinkStructInterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkStructInterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkStructInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





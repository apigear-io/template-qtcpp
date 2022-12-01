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



#include "olinksimpleinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "tb_simple/api/agent.h"
#include "tb_simple/api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkSimpleInterfaceAdapter::OLinkSimpleInterfaceAdapter(RemoteRegistry& registry, AbstractSimpleInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractSimpleInterface::propBoolChanged, this, [=](bool propBool) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleInterface/propBool", propBool);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::propIntChanged, this, [=](int propInt) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleInterface/propInt", propInt);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::propFloatChanged, this, [=](qreal propFloat) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleInterface/propFloat", propFloat);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::propStringChanged, this, [=](const QString& propString) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.simple.SimpleInterface/propString", propString);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::sigBool, this, [=](bool paramBool) {
        if(m_node) {
            const json& args = { paramBool };
            m_node->notifySignal("tb.simple.SimpleInterface/sigBool", args);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::sigInt, this, [=](int paramInt) {
        if(m_node) {
            const json& args = { paramInt };
            m_node->notifySignal("tb.simple.SimpleInterface/sigInt", args);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::sigFloat, this, [=](qreal paramFloat) {
        if(m_node) {
            const json& args = { paramFloat };
            m_node->notifySignal("tb.simple.SimpleInterface/sigFloat", args);
        }
    });
    connect(m_impl, &AbstractSimpleInterface::sigString, this, [=](const QString& paramString) {
        if(m_node) {
            const json& args = { paramString };
            m_node->notifySignal("tb.simple.SimpleInterface/sigString", args);
        }
    });
}

OLinkSimpleInterfaceAdapter::~OLinkSimpleInterfaceAdapter()
{
    m_registry.removeObjectSource(this);
}

json OLinkSimpleInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkSimpleInterfaceAdapter::applyState(const json& state)
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


std::string OLinkSimpleInterfaceAdapter::olinkObjectName() {
    return "tb.simple.SimpleInterface";
}

json OLinkSimpleInterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "funcBool") {
        const bool& paramBool = args.at(0);
        bool result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const int& paramInt = args.at(0);
        int result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const qreal& paramFloat = args.at(0);
        qreal result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const QString& paramString = args.at(0);
        QString result = m_impl->funcString(paramString);
        return result;
    }
    return json();
}

void OLinkSimpleInterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "propBool") {
        bool propBool = value.get<bool>();
        m_impl->setPropBool(propBool);
    }
    if(path == "propInt") {
        int propInt = value.get<int>();
        m_impl->setPropInt(propInt);
    }
    if(path == "propFloat") {
        qreal propFloat = value.get<qreal>();
        m_impl->setPropFloat(propFloat);
    }
    if(path == "propString") {
        QString propString = value.get<QString>();
        m_impl->setPropString(propString);
    }    
}

void OLinkSimpleInterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkSimpleInterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkSimpleInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





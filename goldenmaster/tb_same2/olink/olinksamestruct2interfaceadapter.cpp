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



#include "olinksamestruct2interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkSameStruct2InterfaceAdapter::OLinkSameStruct2InterfaceAdapter(RemoteRegistry& registry, AbstractSameStruct2Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractSameStruct2Interface::prop1Changed, this, [=](const Struct2& prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.same2.SameStruct2Interface/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractSameStruct2Interface::prop2Changed, this, [=](const Struct2& prop2) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.same2.SameStruct2Interface/prop2", prop2);
        }
    });
    connect(m_impl, &AbstractSameStruct2Interface::sig1, this, [=](const Struct1& param1) {
        if(m_node) {
            const json& args = { param1 };
            m_node->notifySignal("tb.same2.SameStruct2Interface/sig1", args);
        }
    });
    connect(m_impl, &AbstractSameStruct2Interface::sig2, this, [=](const Struct1& param1, const Struct2& param2) {
        if(m_node) {
            const json& args = { param1, param2 };
            m_node->notifySignal("tb.same2.SameStruct2Interface/sig2", args);
        }
    });
}

OLinkSameStruct2InterfaceAdapter::~OLinkSameStruct2InterfaceAdapter()
{
    m_registry.removeObjectSource(this);
}

json OLinkSameStruct2InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void OLinkSameStruct2InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}


std::string OLinkSameStruct2InterfaceAdapter::olinkObjectName() {
    return "tb.same2.SameStruct2Interface";
}

json OLinkSameStruct2InterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "func1") {
        const Struct1& param1 = args.at(0);
        Struct1 result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const Struct1& param1 = args.at(0);
        const Struct2& param2 = args.at(1);
        Struct1 result = m_impl->func2(param1, param2);
        return result;
    }
    return json();
}

void OLinkSameStruct2InterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop1") {
        Struct2 prop1 = value.get<Struct2>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        Struct2 prop2 = value.get<Struct2>();
        m_impl->setProp2(prop2);
    }    
}

void OLinkSameStruct2InterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkSameStruct2InterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkSameStruct2InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





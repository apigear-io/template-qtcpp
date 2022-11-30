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



#include "olinksameenum2interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkSameEnum2InterfaceAdapter::OLinkSameEnum2InterfaceAdapter(RemoteRegistry& registry, AbstractSameEnum2Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractSameEnum2Interface::prop1Changed, this, [=](const Enum1::Enum1Enum prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.same1.SameEnum2Interface/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractSameEnum2Interface::prop2Changed, this, [=](const Enum2::Enum2Enum prop2) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.same1.SameEnum2Interface/prop2", prop2);
        }
    });
    connect(m_impl, &AbstractSameEnum2Interface::sig1, this, [=](const Enum1::Enum1Enum param1) {
        if(m_node) {
            const json& args = { param1 };
            m_node->notifySignal("tb.same1.SameEnum2Interface/sig1", args);
        }
    });
    connect(m_impl, &AbstractSameEnum2Interface::sig2, this, [=](const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2) {
        if(m_node) {
            const json& args = { param1, param2 };
            m_node->notifySignal("tb.same1.SameEnum2Interface/sig2", args);
        }
    });
}

OLinkSameEnum2InterfaceAdapter::~OLinkSameEnum2InterfaceAdapter()
{
    m_registry.removeObjectSource(this);
}

json OLinkSameEnum2InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void OLinkSameEnum2InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}


std::string OLinkSameEnum2InterfaceAdapter::olinkObjectName() {
    return "tb.same1.SameEnum2Interface";
}

json OLinkSameEnum2InterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "func1") {
        const Enum1::Enum1Enum& param1 = args.at(0);
        Enum1::Enum1Enum result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const Enum1::Enum1Enum& param1 = args.at(0);
        const Enum2::Enum2Enum& param2 = args.at(1);
        Enum1::Enum1Enum result = m_impl->func2(param1, param2);
        return result;
    }
    return json();
}

void OLinkSameEnum2InterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop1") {
        Enum1::Enum1Enum prop1 = value.get<Enum1::Enum1Enum>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        Enum2::Enum2Enum prop2 = value.get<Enum2::Enum2Enum>();
        m_impl->setProp2(prop2);
    }    
}

void OLinkSameEnum2InterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkSameEnum2InterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkSameEnum2InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





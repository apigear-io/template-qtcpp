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



#include "olinknestedstruct1interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkNestedStruct1InterfaceAdapter::OLinkNestedStruct1InterfaceAdapter(RemoteRegistry& registry, AbstractNestedStruct1Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractNestedStruct1Interface::prop1Changed, this, [=](const NestedStruct1& prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed2.NestedStruct1Interface/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractNestedStruct1Interface::sig1, this, [=](const NestedStruct1& param1) {
        if(m_node) {
            const json& args = { param1 };
            m_node->notifySignal("testbed2.NestedStruct1Interface/sig1", args);
        }
    });
}

OLinkNestedStruct1InterfaceAdapter::~OLinkNestedStruct1InterfaceAdapter()
{
    m_registry.removeObjectSource(this);
}

json OLinkNestedStruct1InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() }
    });
}

void OLinkNestedStruct1InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
}


std::string OLinkNestedStruct1InterfaceAdapter::olinkObjectName() {
    return "testbed2.NestedStruct1Interface";
}

json OLinkNestedStruct1InterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "func1") {
        const NestedStruct1& param1 = args.at(0);
        NestedStruct1 result = m_impl->func1(param1);
        return result;
    }
    return json();
}

void OLinkNestedStruct1InterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_impl->setProp1(prop1);
    }    
}

void OLinkNestedStruct1InterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkNestedStruct1InterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkNestedStruct1InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





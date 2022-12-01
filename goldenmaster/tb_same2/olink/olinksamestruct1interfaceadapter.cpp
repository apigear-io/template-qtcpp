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



#include "olinksamestruct1interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "tb_same2/api/agent.h"
#include "tb_same2/api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkSameStruct1InterfaceAdapter::OLinkSameStruct1InterfaceAdapter(RemoteRegistry& registry, AbstractSameStruct1Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractSameStruct1Interface::prop1Changed, this, [=](const Struct1& prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.same2.SameStruct1Interface/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractSameStruct1Interface::sig1, this, [=](const Struct1& param1) {
        if(m_node) {
            const json& args = { param1 };
            m_node->notifySignal("tb.same2.SameStruct1Interface/sig1", args);
        }
    });
}

OLinkSameStruct1InterfaceAdapter::~OLinkSameStruct1InterfaceAdapter()
{
    m_registry.removeObjectSource(this);
}

json OLinkSameStruct1InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() }
    });
}

void OLinkSameStruct1InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
}


std::string OLinkSameStruct1InterfaceAdapter::olinkObjectName() {
    return "tb.same2.SameStruct1Interface";
}

json OLinkSameStruct1InterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "func1") {
        const Struct1& param1 = args.at(0);
        Struct1 result = m_impl->func1(param1);
        return result;
    }
    return json();
}

void OLinkSameStruct1InterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop1") {
        Struct1 prop1 = value.get<Struct1>();
        m_impl->setProp1(prop1);
    }    
}

void OLinkSameStruct1InterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkSameStruct1InterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkSameStruct1InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





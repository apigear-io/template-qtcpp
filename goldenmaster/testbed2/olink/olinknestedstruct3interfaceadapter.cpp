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



#include "olinknestedstruct3interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "testbed2/api/agent.h"
#include "testbed2/api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkNestedStruct3InterfaceAdapter::OLinkNestedStruct3InterfaceAdapter(RemoteRegistry& registry, AbstractNestedStruct3Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    connect(m_impl, &AbstractNestedStruct3Interface::prop1Changed, this, [=](const NestedStruct1& prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed2.NestedStruct3Interface/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractNestedStruct3Interface::prop2Changed, this, [=](const NestedStruct2& prop2) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed2.NestedStruct3Interface/prop2", prop2);
        }
    });
    connect(m_impl, &AbstractNestedStruct3Interface::prop3Changed, this, [=](const NestedStruct3& prop3) {
        if(m_node) {
            m_node->notifyPropertyChange("testbed2.NestedStruct3Interface/prop3", prop3);
        }
    });
    connect(m_impl, &AbstractNestedStruct3Interface::sig1, this, [=](const NestedStruct1& param1) {
        if(m_node) {
            const json& args = { param1 };
            m_node->notifySignal("testbed2.NestedStruct3Interface/sig1", args);
        }
    });
    connect(m_impl, &AbstractNestedStruct3Interface::sig2, this, [=](const NestedStruct1& param1, const NestedStruct2& param2) {
        if(m_node) {
            const json& args = { param1, param2 };
            m_node->notifySignal("testbed2.NestedStruct3Interface/sig2", args);
        }
    });
    connect(m_impl, &AbstractNestedStruct3Interface::sig3, this, [=](const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) {
        if(m_node) {
            const json& args = { param1, param2, param3 };
            m_node->notifySignal("testbed2.NestedStruct3Interface/sig3", args);
        }
    });
}

OLinkNestedStruct3InterfaceAdapter::~OLinkNestedStruct3InterfaceAdapter()
{
    m_registry.removeObjectSource(this);
}

json OLinkNestedStruct3InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() }
    });
}

void OLinkNestedStruct3InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
    if(state.contains("prop3")) {
        m_impl->setProp3(state["prop3"]);
    }
}


std::string OLinkNestedStruct3InterfaceAdapter::olinkObjectName() {
    return "testbed2.NestedStruct3Interface";
}

json OLinkNestedStruct3InterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "func1") {
        const NestedStruct1& param1 = args.at(0);
        NestedStruct1 result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const NestedStruct1& param1 = args.at(0);
        const NestedStruct2& param2 = args.at(1);
        NestedStruct1 result = m_impl->func2(param1, param2);
        return result;
    }
    if(path == "func3") {
        const NestedStruct1& param1 = args.at(0);
        const NestedStruct2& param2 = args.at(1);
        const NestedStruct3& param3 = args.at(2);
        NestedStruct1 result = m_impl->func3(param1, param2, param3);
        return result;
    }
    return json();
}

void OLinkNestedStruct3InterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        NestedStruct3 prop3 = value.get<NestedStruct3>();
        m_impl->setProp3(prop3);
    }    
}

void OLinkNestedStruct3InterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkNestedStruct3InterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkNestedStruct3InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





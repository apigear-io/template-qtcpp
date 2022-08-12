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



#include "olinkenuminterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkEnumInterfaceAdapter::OLinkEnumInterfaceAdapter(AbstractEnumInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_node(nullptr)
{
    RemoteRegistry::get().addObjectSource(this);
    connect(m_impl, &AbstractEnumInterface::prop0Changed, this, [=](const Enum0::Enum0Enum prop0) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.enum.EnumInterface/prop0", prop0);
        }
    });
    connect(m_impl, &AbstractEnumInterface::prop1Changed, this, [=](const Enum1::Enum1Enum prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.enum.EnumInterface/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractEnumInterface::prop2Changed, this, [=](const Enum2::Enum2Enum prop2) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.enum.EnumInterface/prop2", prop2);
        }
    });
    connect(m_impl, &AbstractEnumInterface::prop3Changed, this, [=](const Enum3::Enum3Enum prop3) {
        if(m_node) {
            m_node->notifyPropertyChange("tb.enum.EnumInterface/prop3", prop3);
        }
    });
    connect(m_impl, &AbstractEnumInterface::sig0, this, [=](const Enum0::Enum0Enum param0) {
        if(m_node) {
            const json& args = { param0 };
            m_node->notifySignal("tb.enum.EnumInterface/sig0", args);
        }
    });
    connect(m_impl, &AbstractEnumInterface::sig1, this, [=](const Enum1::Enum1Enum param1) {
        if(m_node) {
            const json& args = { param1 };
            m_node->notifySignal("tb.enum.EnumInterface/sig1", args);
        }
    });
    connect(m_impl, &AbstractEnumInterface::sig2, this, [=](const Enum2::Enum2Enum param2) {
        if(m_node) {
            const json& args = { param2 };
            m_node->notifySignal("tb.enum.EnumInterface/sig2", args);
        }
    });
    connect(m_impl, &AbstractEnumInterface::sig3, this, [=](const Enum3::Enum3Enum param3) {
        if(m_node) {
            const json& args = { param3 };
            m_node->notifySignal("tb.enum.EnumInterface/sig3", args);
        }
    });
}

OLinkEnumInterfaceAdapter::~OLinkEnumInterfaceAdapter()
{
    RemoteRegistry::get().removeObjectSource(this);
}

json OLinkEnumInterfaceAdapter::captureState()
{
    return json::object({
        { "prop0", m_impl->prop0() },
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() }
    });
}

void OLinkEnumInterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop0")) {
        m_impl->setProp0(state["prop0"]);
    }
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


std::string OLinkEnumInterfaceAdapter::olinkObjectName() {
    return "tb.enum.EnumInterface";
}

json OLinkEnumInterfaceAdapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "func0") {
        const Enum0::Enum0Enum& param0 = args.at(0);
        Enum0::Enum0Enum result = m_impl->func0(param0);
        return result;
    }
    if(path == "func1") {
        const Enum1::Enum1Enum& param1 = args.at(0);
        Enum1::Enum1Enum result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const Enum2::Enum2Enum& param2 = args.at(0);
        Enum2::Enum2Enum result = m_impl->func2(param2);
        return result;
    }
    if(path == "func3") {
        const Enum3::Enum3Enum& param3 = args.at(0);
        Enum3::Enum3Enum result = m_impl->func3(param3);
        return result;
    }
    return json();
}

void OLinkEnumInterfaceAdapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop0") {
        Enum0::Enum0Enum prop0 = value.get<Enum0::Enum0Enum>();
        m_impl->setProp0(prop0);
    }
    if(path == "prop1") {
        Enum1::Enum1Enum prop1 = value.get<Enum1::Enum1Enum>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        Enum2::Enum2Enum prop2 = value.get<Enum2::Enum2Enum>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        Enum3::Enum3Enum prop3 = value.get<Enum3::Enum3Enum>();
        m_impl->setProp3(prop3);
    }    
}

void OLinkEnumInterfaceAdapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkEnumInterfaceAdapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkEnumInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}





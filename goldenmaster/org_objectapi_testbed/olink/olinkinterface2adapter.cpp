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



#include "olinkinterface2adapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkInterface2Adapter::OLinkInterface2Adapter(AbstractInterface2* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_node(nullptr)
{
    RemoteRegistry::get().addObjectSource(this);
    connect(m_impl, &AbstractInterface2::prop200Changed, this, [=](int prop200) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop200", prop200);
        }
    });
    connect(m_impl, &AbstractInterface2::prop201Changed, this, [=](int prop201) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop201", prop201);
        }
    });
    connect(m_impl, &AbstractInterface2::prop202Changed, this, [=](int prop202) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop202", prop202);
        }
    });
    connect(m_impl, &AbstractInterface2::prop203Changed, this, [=](qreal prop203) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop203", prop203);
        }
    });
    connect(m_impl, &AbstractInterface2::prop204Changed, this, [=](qreal prop204) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop204", prop204);
        }
    });
    connect(m_impl, &AbstractInterface2::prop205Changed, this, [=](const QString& prop205) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop205", prop205);
        }
    });
}

OLinkInterface2Adapter::~OLinkInterface2Adapter()
{
    RemoteRegistry::get().removeObjectSource(this);
}

json OLinkInterface2Adapter::captureState()
{
    return json::object({
        { "prop200", m_impl->prop200() },
        { "prop201", m_impl->prop201() },
        { "prop202", m_impl->prop202() },
        { "prop203", m_impl->prop203() },
        { "prop204", m_impl->prop204() },
        { "prop205", m_impl->prop205() }
    });
}

void OLinkInterface2Adapter::applyState(const json& state)
{
    if(state.contains("prop200")) {
        m_impl->setProp200(state["prop200"]);
    }
    if(state.contains("prop201")) {
        m_impl->setProp201(state["prop201"]);
    }
    if(state.contains("prop202")) {
        m_impl->setProp202(state["prop202"]);
    }
    if(state.contains("prop203")) {
        m_impl->setProp203(state["prop203"]);
    }
    if(state.contains("prop204")) {
        m_impl->setProp204(state["prop204"]);
    }
    if(state.contains("prop205")) {
        m_impl->setProp205(state["prop205"]);
    }
}


std::string OLinkInterface2Adapter::olinkObjectName() {
    return "org.objectapi.testbed.Interface2";
}

json OLinkInterface2Adapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    return json();
}

void OLinkInterface2Adapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop200") {
        int prop200 = value.get<int>();
        m_impl->setProp200(prop200);
    }
    if(path == "prop201") {
        int prop201 = value.get<int>();
        m_impl->setProp201(prop201);
    }
    if(path == "prop202") {
        int prop202 = value.get<int>();
        m_impl->setProp202(prop202);
    }
    if(path == "prop203") {
        qreal prop203 = value.get<qreal>();
        m_impl->setProp203(prop203);
    }
    if(path == "prop204") {
        qreal prop204 = value.get<qreal>();
        m_impl->setProp204(prop204);
    }
    if(path == "prop205") {
        QString prop205 = value.get<QString>();
        m_impl->setProp205(prop205);
    }    
}

void OLinkInterface2Adapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkInterface2Adapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkInterface2Adapter::olinkCollectProperties()
{
    return captureState();
}





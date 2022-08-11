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



#include "olinkinterface1adapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

OLinkInterface1Adapter::OLinkInterface1Adapter(AbstractInterface1* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_node(nullptr)
{
    RemoteRegistry::get().addObjectSource(this);
    connect(m_impl, &AbstractInterface1::prop1Changed, this, [=](bool prop1) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop1", prop1);
        }
    });
    connect(m_impl, &AbstractInterface1::prop2Changed, this, [=](int prop2) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop2", prop2);
        }
    });
    connect(m_impl, &AbstractInterface1::prop3Changed, this, [=](qreal prop3) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop3", prop3);
        }
    });
    connect(m_impl, &AbstractInterface1::prop4Changed, this, [=](const QString& prop4) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop4", prop4);
        }
    });
    connect(m_impl, &AbstractInterface1::prop5Changed, this, [=](const QList<int>& prop5) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop5", prop5);
        }
    });
    connect(m_impl, &AbstractInterface1::prop6Changed, this, [=](const Struct1& prop6) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop6", prop6);
        }
    });
    connect(m_impl, &AbstractInterface1::prop7Changed, this, [=](int prop7) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop7", prop7);
        }
    });
    connect(m_impl, &AbstractInterface1::prop10Changed, this, [=](const QList<int>& prop10) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop10", prop10);
        }
    });
    connect(m_impl, &AbstractInterface1::prop11Changed, this, [=](const QList<Struct1>& prop11) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop11", prop11);
        }
    });
    connect(m_impl, &AbstractInterface1::prop12Changed, this, [=](const QList<Enum1::Enum1Enum>& prop12) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop12", prop12);
        }
    });
    connect(m_impl, &AbstractInterface1::prop14Changed, this, [=](const QList<Struct1>& prop14) {
        if(m_node) {
            m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop14", prop14);
        }
    });
    connect(m_impl, &AbstractInterface1::sig1, this, [=]() {
        if(m_node) {
            const json& args = {  };
            m_node->notifySignal("org.objectapi.testbed.Interface1/sig1", args);
        }
    });
    connect(m_impl, &AbstractInterface1::sig2, this, [=](int step) {
        if(m_node) {
            const json& args = { step };
            m_node->notifySignal("org.objectapi.testbed.Interface1/sig2", args);
        }
    });
    connect(m_impl, &AbstractInterface1::sig3, this, [=]() {
        if(m_node) {
            const json& args = {  };
            m_node->notifySignal("org.objectapi.testbed.Interface1/sig3", args);
        }
    });
}

OLinkInterface1Adapter::~OLinkInterface1Adapter()
{
    RemoteRegistry::get().removeObjectSource(this);
}

json OLinkInterface1Adapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() },
        { "prop4", m_impl->prop4() },
        { "prop5", m_impl->prop5() },
        { "prop6", m_impl->prop6() },
        { "prop7", m_impl->prop7() },
        { "prop10", m_impl->prop10() },
        { "prop11", m_impl->prop11() },
        { "prop12", m_impl->prop12() },
        { "prop14", m_impl->prop14() }
    });
}

void OLinkInterface1Adapter::applyState(const json& state)
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
    if(state.contains("prop4")) {
        m_impl->setProp4(state["prop4"]);
    }
    if(state.contains("prop5")) {
        m_impl->setProp5(state["prop5"]);
    }
    if(state.contains("prop6")) {
        m_impl->setProp6(state["prop6"]);
    }
    if(state.contains("prop7")) {
        m_impl->setProp7(state["prop7"]);
    }
    if(state.contains("prop10")) {
        m_impl->setProp10(state["prop10"]);
    }
    if(state.contains("prop11")) {
        m_impl->setProp11(state["prop11"]);
    }
    if(state.contains("prop12")) {
        m_impl->setProp12(state["prop12"]);
    }
    if(state.contains("prop14")) {
        m_impl->setProp14(state["prop14"]);
    }
}


std::string OLinkInterface1Adapter::olinkObjectName() {
    return "org.objectapi.testbed.Interface1";
}

json OLinkInterface1Adapter::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "op1") {
        m_impl->op1();
        return json{};
    }
    if(path == "op2") {
        const int& step = args.at(0);
        m_impl->op2(step);
        return json{};
    }
    if(path == "op3") {
        int result = m_impl->op3();
        return result;
    }
    return json();
}

void OLinkInterface1Adapter::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "prop1") {
        bool prop1 = value.get<bool>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        int prop2 = value.get<int>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        qreal prop3 = value.get<qreal>();
        m_impl->setProp3(prop3);
    }
    if(path == "prop4") {
        QString prop4 = value.get<QString>();
        m_impl->setProp4(prop4);
    }
    if(path == "prop5") {
        QList<int> prop5 = value.get<QList<int>>();
        m_impl->setProp5(prop5);
    }
    if(path == "prop6") {
        Struct1 prop6 = value.get<Struct1>();
        m_impl->setProp6(prop6);
    }
    if(path == "prop7") {
        int prop7 = value.get<int>();
        m_impl->setProp7(prop7);
    }
    if(path == "prop10") {
        QList<int> prop10 = value.get<QList<int>>();
        m_impl->setProp10(prop10);
    }
    if(path == "prop11") {
        QList<Struct1> prop11 = value.get<QList<Struct1>>();
        m_impl->setProp11(prop11);
    }
    if(path == "prop12") {
        QList<Enum1::Enum1Enum> prop12 = value.get<QList<Enum1::Enum1Enum>>();
        m_impl->setProp12(prop12);
    }
    if(path == "prop14") {
        QList<Struct1> prop14 = value.get<QList<Struct1>>();
        m_impl->setProp14(prop14);
    }    
}

void OLinkInterface1Adapter::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void OLinkInterface1Adapter::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json OLinkInterface1Adapter::olinkCollectProperties()
{
    return captureState();
}





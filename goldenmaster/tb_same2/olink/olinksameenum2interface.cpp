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
#include "olinksameenum2interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkSameEnum2Interface::OLinkSameEnum2Interface(QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value1)
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkSameEnum2Interface::~OLinkSameEnum2Interface()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkSameEnum2Interface::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1::Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2::Enum2Enum>());
    }
}

void OLinkSameEnum2Interface::setProp1(const Enum1::Enum1Enum prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameEnum2Interface/prop1", prop1);
}

void OLinkSameEnum2Interface::setProp1Local(const Enum1::Enum1Enum prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameEnum2InterfaceAgent::trace_state(this);
    }
}

Enum1::Enum1Enum OLinkSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void OLinkSameEnum2Interface::setProp2(const Enum2::Enum2Enum prop2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameEnum2Interface/prop2", prop2);
}

void OLinkSameEnum2Interface::setProp2Local(const Enum2::Enum2Enum prop2)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        SameEnum2InterfaceAgent::trace_state(this);
    }
}

Enum2::Enum2Enum OLinkSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum OLinkSameEnum2Interface::func1(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return Enum1::value1;
    }
    Enum1::Enum1Enum value(Enum1::value1);
    func1Async(param1)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> OLinkSameEnum2Interface::func1Async(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            m_node->invokeRemote("tb.same2.SameEnum2Interface/func1", json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const Enum1::Enum1Enum& value = arg.value.get<Enum1::Enum1Enum>();
                resolve(value);
            });
        }
    };
}

Enum1::Enum1Enum OLinkSameEnum2Interface::func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return Enum1::value1;
    }
    Enum1::Enum1Enum value(Enum1::value1);
    func2Async(param1, param2)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> OLinkSameEnum2Interface::func2Async(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            m_node->invokeRemote("tb.same2.SameEnum2Interface/func2", json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const Enum1::Enum1Enum& value = arg.value.get<Enum1::Enum1Enum>();
                resolve(value);
            });
        }
    };
}


std::string OLinkSameEnum2Interface::olinkObjectName()
{
    return "tb.same2.SameEnum2Interface";
}

void OLinkSameEnum2Interface::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sig1") {
        emit sig1(args[0].get<Enum1::Enum1Enum>());   
        return;
    }
    if(path == "sig2") {
        emit sig2(args[0].get<Enum1::Enum1Enum>(),args[1].get<Enum2::Enum2Enum>());   
        return;
    }
}

void OLinkSameEnum2Interface::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameEnum2Interface::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSameEnum2Interface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



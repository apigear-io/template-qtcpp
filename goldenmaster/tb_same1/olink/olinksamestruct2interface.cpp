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
#include "olinksamestruct2interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkSameStruct2Interface::OLinkSameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
    , m_prop1(Struct2())
    , m_prop2(Struct2())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkSameStruct2Interface::~OLinkSameStruct2Interface()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkSameStruct2Interface::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct2>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Struct2>());
    }
}

void OLinkSameStruct2Interface::setProp1(const Struct2& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameStruct2Interface/prop1", prop1);
}

void OLinkSameStruct2Interface::setProp1Local(const Struct2& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameStruct2InterfaceAgent::trace_state(this);
    }
}

Struct2 OLinkSameStruct2Interface::prop1() const
{
    return m_prop1;
}

void OLinkSameStruct2Interface::setProp2(const Struct2& prop2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameStruct2Interface/prop2", prop2);
}

void OLinkSameStruct2Interface::setProp2Local(const Struct2& prop2)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        SameStruct2InterfaceAgent::trace_state(this);
    }
}

Struct2 OLinkSameStruct2Interface::prop2() const
{
    return m_prop2;
}

Struct1 OLinkSameStruct2Interface::func1(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return Struct1();
    }
    Struct1 value(Struct1());
    func1Async(param1)
        .then([&](Struct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Struct1> OLinkSameStruct2Interface::func1Async(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<Struct1>::reject("not initialized");
    }
    return QtPromise::QPromise<Struct1>{[&](
        const QtPromise::QPromiseResolve<Struct1>& resolve) {
            m_node->invokeRemote("tb.same1.SameStruct2Interface/func1", json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const Struct1& value = arg.value.get<Struct1>();
                resolve(value);
            });
        }
    };
}

Struct1 OLinkSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return Struct1();
    }
    Struct1 value(Struct1());
    func2Async(param1, param2)
        .then([&](Struct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Struct1> OLinkSameStruct2Interface::func2Async(const Struct1& param1, const Struct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<Struct1>::reject("not initialized");
    }
    return QtPromise::QPromise<Struct1>{[&](
        const QtPromise::QPromiseResolve<Struct1>& resolve) {
            m_node->invokeRemote("tb.same1.SameStruct2Interface/func2", json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const Struct1& value = arg.value.get<Struct1>();
                resolve(value);
            });
        }
    };
}


std::string OLinkSameStruct2Interface::olinkObjectName()
{
    return "tb.same1.SameStruct2Interface";
}

void OLinkSameStruct2Interface::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sig1") {
        emit sig1(args[0].get<Struct1>());   
        return;
    }
    if(path == "sig2") {
        emit sig2(args[0].get<Struct1>(),args[1].get<Struct2>());   
        return;
    }
}

void OLinkSameStruct2Interface::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameStruct2Interface::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSameStruct2Interface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



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
#include "olinknestedstruct2interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkNestedStruct2Interface::OLinkNestedStruct2Interface(QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkNestedStruct2Interface::~OLinkNestedStruct2Interface()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkNestedStruct2Interface::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void OLinkNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop1", prop1);
}

void OLinkNestedStruct2Interface::setProp1Local(const NestedStruct1& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 OLinkNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void OLinkNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop2", prop2);
}

void OLinkNestedStruct2Interface::setProp2Local(const NestedStruct2& prop2)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}

NestedStruct2 OLinkNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 OLinkNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return NestedStruct1();
    }
    NestedStruct1 value(NestedStruct1());
    func1Async(param1)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            m_node->invokeRemote("testbed2.NestedStruct2Interface/func1", json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}

NestedStruct1 OLinkNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return NestedStruct1();
    }
    NestedStruct1 value(NestedStruct1());
    func2Async(param1, param2)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            m_node->invokeRemote("testbed2.NestedStruct2Interface/func2", json::array({param1,param2}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}


std::string OLinkNestedStruct2Interface::olinkObjectName()
{
    return "testbed2.NestedStruct2Interface";
}

void OLinkNestedStruct2Interface::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sig1") {
        emit sig1(args[0].get<NestedStruct1>());   
        return;
    }
    if(path == "sig2") {
        emit sig2(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>());   
        return;
    }
}

void OLinkNestedStruct2Interface::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkNestedStruct2Interface::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNestedStruct2Interface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



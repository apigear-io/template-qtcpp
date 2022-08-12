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
#include "wampnestedstruct2interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampNestedStruct2Interface::WampNestedStruct2Interface(QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
{    
    // get initial state from service
    WampClient::instance()->doCall("testbed2.NestedStruct2Interface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("testbed2.NestedStruct2Interface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("testbed2.NestedStruct2Interface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("testbed2.NestedStruct2Interface.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
}

WampNestedStruct2Interface::~WampNestedStruct2Interface()
{
}

void WampNestedStruct2Interface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void WampNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("testbed2.NestedStruct2Interface._set", json::array(), fields);
}

void WampNestedStruct2Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}


NestedStruct1 WampNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void WampNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("testbed2.NestedStruct2Interface._set", json::array(), fields);
}

void WampNestedStruct2Interface::setProp2Local(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}


NestedStruct2 WampNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 WampNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct1 value{ NestedStruct1() };
    func1Async(param1)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> WampNestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            WampClient::instance()->doCall("testbed2.NestedStruct2Interface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const NestedStruct1& result = arg.args[0].get<NestedStruct1>();
                resolve(result);
            });
        }
    };
}

NestedStruct1 WampNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct1 value{ NestedStruct1() };
    func2Async(param1, param2)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> WampNestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            WampClient::instance()->doCall("testbed2.NestedStruct2Interface.func2", json::array({param1,param2}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const NestedStruct1& result = arg.args[0].get<NestedStruct1>();
                resolve(result);
            });
        }
    };
}

void WampNestedStruct2Interface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<NestedStruct1>());
}

void WampNestedStruct2Interface::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<NestedStruct1>(),arg.args[1].get<NestedStruct2>());
}


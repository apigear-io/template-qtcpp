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
#include "wampsamestruct2interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampSameStruct2Interface::WampSameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
    , m_prop1(Struct2())
    , m_prop2(Struct2())
{    
    // get initial state from service
    WampClient::instance()->doCall("tb.same2.SameStruct2Interface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("tb.same2.SameStruct2Interface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("tb.same2.SameStruct2Interface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("tb.same2.SameStruct2Interface.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
}

WampSameStruct2Interface::~WampSameStruct2Interface()
{
}

void WampSameStruct2Interface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct2>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Struct2>());
    }
}

void WampSameStruct2Interface::setProp1(const Struct2& prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("tb.same2.SameStruct2Interface._set", json::array(), fields);
}

void WampSameStruct2Interface::setProp1Local(const Struct2& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameStruct2InterfaceAgent::trace_state(this);
    }
}


Struct2 WampSameStruct2Interface::prop1() const
{
    return m_prop1;
}

void WampSameStruct2Interface::setProp2(const Struct2& prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("tb.same2.SameStruct2Interface._set", json::array(), fields);
}

void WampSameStruct2Interface::setProp2Local(const Struct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        SameStruct2InterfaceAgent::trace_state(this);
    }
}


Struct2 WampSameStruct2Interface::prop2() const
{
    return m_prop2;
}

Struct1 WampSameStruct2Interface::func1(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    Struct1 value{ Struct1() };
    func1Async(param1)
        .then([&](Struct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Struct1> WampSameStruct2Interface::func1Async(const Struct1& param1)
{
    return QtPromise::QPromise<Struct1>{[&](
        const QtPromise::QPromiseResolve<Struct1>& resolve) {
            WampClient::instance()->doCall("tb.same2.SameStruct2Interface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Struct1& result = arg.args[0].get<Struct1>();
                resolve(result);
            });
        }
    };
}

Struct1 WampSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    Struct1 value{ Struct1() };
    func2Async(param1, param2)
        .then([&](Struct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Struct1> WampSameStruct2Interface::func2Async(const Struct1& param1, const Struct2& param2)
{
    return QtPromise::QPromise<Struct1>{[&](
        const QtPromise::QPromiseResolve<Struct1>& resolve) {
            WampClient::instance()->doCall("tb.same2.SameStruct2Interface.func2", json::array({param1,param2}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Struct1& result = arg.args[0].get<Struct1>();
                resolve(result);
            });
        }
    };
}

void WampSameStruct2Interface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<Struct1>());
}

void WampSameStruct2Interface::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<Struct1>(),arg.args[1].get<Struct2>());
}


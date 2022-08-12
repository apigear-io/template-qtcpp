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
#include "wampsameenum2interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampSameEnum2Interface::WampSameEnum2Interface(QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value1)
{    
    // get initial state from service
    WampClient::instance()->doCall("tb.same2.SameEnum2Interface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("tb.same2.SameEnum2Interface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("tb.same2.SameEnum2Interface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("tb.same2.SameEnum2Interface.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
}

WampSameEnum2Interface::~WampSameEnum2Interface()
{
}

void WampSameEnum2Interface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1::Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2::Enum2Enum>());
    }
}

void WampSameEnum2Interface::setProp1(const Enum1::Enum1Enum prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("tb.same2.SameEnum2Interface._set", json::array(), fields);
}

void WampSameEnum2Interface::setProp1Local(const Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameEnum2InterfaceAgent::trace_state(this);
    }
}


Enum1::Enum1Enum WampSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void WampSameEnum2Interface::setProp2(const Enum2::Enum2Enum prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("tb.same2.SameEnum2Interface._set", json::array(), fields);
}

void WampSameEnum2Interface::setProp2Local(const Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        SameEnum2InterfaceAgent::trace_state(this);
    }
}


Enum2::Enum2Enum WampSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum WampSameEnum2Interface::func1(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    Enum1::Enum1Enum value(Enum1::value1);
    func1Async(param1)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> WampSameEnum2Interface::func1Async(const Enum1::Enum1Enum param1)
{
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            WampClient::instance()->doCall("tb.same2.SameEnum2Interface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Enum1::Enum1Enum& result = arg.args[0].get<Enum1::Enum1Enum>();
                resolve(result);
            });
        }
    };
}

Enum1::Enum1Enum WampSameEnum2Interface::func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;
    Enum1::Enum1Enum value(Enum1::value1);
    func2Async(param1, param2)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> WampSameEnum2Interface::func2Async(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            WampClient::instance()->doCall("tb.same2.SameEnum2Interface.func2", json::array({param1,param2}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Enum1::Enum1Enum& result = arg.args[0].get<Enum1::Enum1Enum>();
                resolve(result);
            });
        }
    };
}

void WampSameEnum2Interface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<Enum1::Enum1Enum>());
}

void WampSameEnum2Interface::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<Enum1::Enum1Enum>(),arg.args[1].get<Enum2::Enum2Enum>());
}


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
#include "wampsamestruct1interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampSameStruct1Interface::WampSameStruct1Interface(QObject *parent)
    : AbstractSameStruct1Interface(parent)
    , m_prop1(Struct1())
{    
    // get initial state from service
    WampClient::instance()->doCall("tb.same2.SameStruct1Interface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("tb.same2.SameStruct1Interface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("tb.same2.SameStruct1Interface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
}

WampSameStruct1Interface::~WampSameStruct1Interface()
{
}

void WampSameStruct1Interface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct1>());
    }
}

void WampSameStruct1Interface::setProp1(const Struct1& prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("tb.same2.SameStruct1Interface._set", json::array(), fields);
}

void WampSameStruct1Interface::setProp1Local(const Struct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameStruct1InterfaceAgent::trace_state(this);
    }
}


Struct1 WampSameStruct1Interface::prop1() const
{
    return m_prop1;
}

Struct1 WampSameStruct1Interface::func1(const Struct1& param1)
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

QtPromise::QPromise<Struct1> WampSameStruct1Interface::func1Async(const Struct1& param1)
{
    return QtPromise::QPromise<Struct1>{[&](
        const QtPromise::QPromiseResolve<Struct1>& resolve) {
            WampClient::instance()->doCall("tb.same2.SameStruct1Interface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Struct1& result = arg.args[0].get<Struct1>();
                resolve(result);
            });
        }
    };
}

void WampSameStruct1Interface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<Struct1>());
}


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
#include "wampnestedstruct1interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampNestedStruct1Interface::WampNestedStruct1Interface(QObject *parent)
    : AbstractNestedStruct1Interface(parent)
    , m_prop1(NestedStruct1())
{    
    // get initial state from service
    WampClient::instance()->doCall("testbed2.NestedStruct1Interface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("testbed2.NestedStruct1Interface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("testbed2.NestedStruct1Interface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
}

WampNestedStruct1Interface::~WampNestedStruct1Interface()
{
}

void WampNestedStruct1Interface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
}

void WampNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("testbed2.NestedStruct1Interface._set", json::array(), fields);
}

void WampNestedStruct1Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct1InterfaceAgent::trace_state(this);
    }
}


NestedStruct1 WampNestedStruct1Interface::prop1() const
{
    return m_prop1;
}

NestedStruct1 WampNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct1 value(NestedStruct1());
    func1Async(param1)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> WampNestedStruct1Interface::func1Async(const NestedStruct1& param1)
{
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            WampClient::instance()->doCall("testbed2.NestedStruct1Interface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const NestedStruct1& result = arg.args[0].get<NestedStruct1>();
                resolve(result);
            });
        }
    };
}

void WampNestedStruct1Interface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<NestedStruct1>());
}


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
#include "wampnestedstruct3interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampNestedStruct3Interface::WampNestedStruct3Interface(QObject *parent)
    : AbstractNestedStruct3Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_prop3(NestedStruct3())
{    
    // get initial state from service
    WampClient::instance()->doCall("testbed2.NestedStruct3Interface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("testbed2.NestedStruct3Interface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("testbed2.NestedStruct3Interface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("testbed2.NestedStruct3Interface.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
    // subscribe to signal sig3
    WampClient::instance()->doSubscribe("testbed2.NestedStruct3Interface.sig3", [this](WAMP::EventArg arg) {
        this->notifySig3(arg);
    });
}

WampNestedStruct3Interface::~WampNestedStruct3Interface()
{
}

void WampNestedStruct3Interface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<NestedStruct3>());
    }
}

void WampNestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("testbed2.NestedStruct3Interface._set", json::array(), fields);
}

void WampNestedStruct3Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}


NestedStruct1 WampNestedStruct3Interface::prop1() const
{
    return m_prop1;
}

void WampNestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("testbed2.NestedStruct3Interface._set", json::array(), fields);
}

void WampNestedStruct3Interface::setProp2Local(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}


NestedStruct2 WampNestedStruct3Interface::prop2() const
{
    return m_prop2;
}

void WampNestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    const json &fields = json::object({
        { "prop3", prop3 }
    });
    WampClient::instance()->doCall("testbed2.NestedStruct3Interface._set", json::array(), fields);
}

void WampNestedStruct3Interface::setProp3Local(const NestedStruct3& prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}


NestedStruct3 WampNestedStruct3Interface::prop3() const
{
    return m_prop3;
}

NestedStruct1 WampNestedStruct3Interface::func1(const NestedStruct1& param1)
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

QtPromise::QPromise<NestedStruct1> WampNestedStruct3Interface::func1Async(const NestedStruct1& param1)
{
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            WampClient::instance()->doCall("testbed2.NestedStruct3Interface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const NestedStruct1& result = arg.args[0].get<NestedStruct1>();
                resolve(result);
            });
        }
    };
}

NestedStruct1 WampNestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct1 value(NestedStruct1());
    func2Async(param1, param2)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> WampNestedStruct3Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            WampClient::instance()->doCall("testbed2.NestedStruct3Interface.func2", json::array({param1,param2}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const NestedStruct1& result = arg.args[0].get<NestedStruct1>();
                resolve(result);
            });
        }
    };
}

NestedStruct1 WampNestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct1 value(NestedStruct1());
    func3Async(param1, param2, param3)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> WampNestedStruct3Interface::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            WampClient::instance()->doCall("testbed2.NestedStruct3Interface.func3", json::array({param1,param2,param3}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const NestedStruct1& result = arg.args[0].get<NestedStruct1>();
                resolve(result);
            });
        }
    };
}

void WampNestedStruct3Interface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<NestedStruct1>());
}

void WampNestedStruct3Interface::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<NestedStruct1>(),arg.args[1].get<NestedStruct2>());
}

void WampNestedStruct3Interface::notifySig3(WAMP::EventArg arg)
{
    emit sig3(arg.args[0].get<NestedStruct1>(),arg.args[1].get<NestedStruct2>(),arg.args[2].get<NestedStruct3>());
}


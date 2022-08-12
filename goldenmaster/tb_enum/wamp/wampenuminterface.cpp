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
#include "wampenuminterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampEnumInterface::WampEnumInterface(QObject *parent)
    : AbstractEnumInterface(parent)
    , m_prop0(Enum0::value0)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value2)
    , m_prop3(Enum3::value3)
{    
    // get initial state from service
    WampClient::instance()->doCall("tb.enum.EnumInterface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("tb.enum.EnumInterface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig0
    WampClient::instance()->doSubscribe("tb.enum.EnumInterface.sig0", [this](WAMP::EventArg arg) {
        this->notifySig0(arg);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("tb.enum.EnumInterface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("tb.enum.EnumInterface.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
    // subscribe to signal sig3
    WampClient::instance()->doSubscribe("tb.enum.EnumInterface.sig3", [this](WAMP::EventArg arg) {
        this->notifySig3(arg);
    });
}

WampEnumInterface::~WampEnumInterface()
{
}

void WampEnumInterface::applyState(const json& fields) 
{
    if(fields.contains("prop0")) {
        setProp0Local(fields["prop0"].get<Enum0::Enum0Enum>());
    }
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1::Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2::Enum2Enum>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<Enum3::Enum3Enum>());
    }
}

void WampEnumInterface::setProp0(const Enum0::Enum0Enum prop0)
{
    const json &fields = json::object({
        { "prop0", prop0 }
    });
    WampClient::instance()->doCall("tb.enum.EnumInterface._set", json::array(), fields);
}

void WampEnumInterface::setProp0Local(const Enum0::Enum0Enum prop0)
{
    if (m_prop0 != prop0) {
        m_prop0 = prop0;
        emit prop0Changed(prop0);
        EnumInterfaceAgent::trace_state(this);
    }
}


Enum0::Enum0Enum WampEnumInterface::prop0() const
{
    return m_prop0;
}

void WampEnumInterface::setProp1(const Enum1::Enum1Enum prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("tb.enum.EnumInterface._set", json::array(), fields);
}

void WampEnumInterface::setProp1Local(const Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        EnumInterfaceAgent::trace_state(this);
    }
}


Enum1::Enum1Enum WampEnumInterface::prop1() const
{
    return m_prop1;
}

void WampEnumInterface::setProp2(const Enum2::Enum2Enum prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("tb.enum.EnumInterface._set", json::array(), fields);
}

void WampEnumInterface::setProp2Local(const Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        EnumInterfaceAgent::trace_state(this);
    }
}


Enum2::Enum2Enum WampEnumInterface::prop2() const
{
    return m_prop2;
}

void WampEnumInterface::setProp3(const Enum3::Enum3Enum prop3)
{
    const json &fields = json::object({
        { "prop3", prop3 }
    });
    WampClient::instance()->doCall("tb.enum.EnumInterface._set", json::array(), fields);
}

void WampEnumInterface::setProp3Local(const Enum3::Enum3Enum prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        EnumInterfaceAgent::trace_state(this);
    }
}


Enum3::Enum3Enum WampEnumInterface::prop3() const
{
    return m_prop3;
}

Enum0::Enum0Enum WampEnumInterface::func0(const Enum0::Enum0Enum param0)
{
    qDebug() << Q_FUNC_INFO;
    Enum0::Enum0Enum value(Enum0::value0);
    func0Async(param0)
        .then([&](Enum0::Enum0Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum0::Enum0Enum> WampEnumInterface::func0Async(const Enum0::Enum0Enum param0)
{
    return QtPromise::QPromise<Enum0::Enum0Enum>{[&](
        const QtPromise::QPromiseResolve<Enum0::Enum0Enum>& resolve) {
            WampClient::instance()->doCall("tb.enum.EnumInterface.func0", json::array({param0}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Enum0::Enum0Enum& result = arg.args[0].get<Enum0::Enum0Enum>();
                resolve(result);
            });
        }
    };
}

Enum1::Enum1Enum WampEnumInterface::func1(const Enum1::Enum1Enum param1)
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

QtPromise::QPromise<Enum1::Enum1Enum> WampEnumInterface::func1Async(const Enum1::Enum1Enum param1)
{
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            WampClient::instance()->doCall("tb.enum.EnumInterface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Enum1::Enum1Enum& result = arg.args[0].get<Enum1::Enum1Enum>();
                resolve(result);
            });
        }
    };
}

Enum2::Enum2Enum WampEnumInterface::func2(const Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;
    Enum2::Enum2Enum value(Enum2::value2);
    func2Async(param2)
        .then([&](Enum2::Enum2Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum2::Enum2Enum> WampEnumInterface::func2Async(const Enum2::Enum2Enum param2)
{
    return QtPromise::QPromise<Enum2::Enum2Enum>{[&](
        const QtPromise::QPromiseResolve<Enum2::Enum2Enum>& resolve) {
            WampClient::instance()->doCall("tb.enum.EnumInterface.func2", json::array({param2}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Enum2::Enum2Enum& result = arg.args[0].get<Enum2::Enum2Enum>();
                resolve(result);
            });
        }
    };
}

Enum3::Enum3Enum WampEnumInterface::func3(const Enum3::Enum3Enum param3)
{
    qDebug() << Q_FUNC_INFO;
    Enum3::Enum3Enum value(Enum3::value3);
    func3Async(param3)
        .then([&](Enum3::Enum3Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum3::Enum3Enum> WampEnumInterface::func3Async(const Enum3::Enum3Enum param3)
{
    return QtPromise::QPromise<Enum3::Enum3Enum>{[&](
        const QtPromise::QPromiseResolve<Enum3::Enum3Enum>& resolve) {
            WampClient::instance()->doCall("tb.enum.EnumInterface.func3", json::array({param3}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const Enum3::Enum3Enum& result = arg.args[0].get<Enum3::Enum3Enum>();
                resolve(result);
            });
        }
    };
}

void WampEnumInterface::notifySig0(WAMP::EventArg arg)
{
    emit sig0(arg.args[0].get<Enum0::Enum0Enum>());
}

void WampEnumInterface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<Enum1::Enum1Enum>());
}

void WampEnumInterface::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<Enum2::Enum2Enum>());
}

void WampEnumInterface::notifySig3(WAMP::EventArg arg)
{
    emit sig3(arg.args[0].get<Enum3::Enum3Enum>());
}


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
#include "wampstructinterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampStructInterface::WampStructInterface(QObject *parent)
    : AbstractStructInterface(parent)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
{    
    // get initial state from service
    WampClient::instance()->doCall("testbed1.StructInterface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("testbed1.StructInterface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sigBool
    WampClient::instance()->doSubscribe("testbed1.StructInterface.sigBool", [this](WAMP::EventArg arg) {
        this->notifySigBool(arg);
    });
    // subscribe to signal sigInt
    WampClient::instance()->doSubscribe("testbed1.StructInterface.sigInt", [this](WAMP::EventArg arg) {
        this->notifySigInt(arg);
    });
    // subscribe to signal sigFloat
    WampClient::instance()->doSubscribe("testbed1.StructInterface.sigFloat", [this](WAMP::EventArg arg) {
        this->notifySigFloat(arg);
    });
    // subscribe to signal sigString
    WampClient::instance()->doSubscribe("testbed1.StructInterface.sigString", [this](WAMP::EventArg arg) {
        this->notifySigString(arg);
    });
}

WampStructInterface::~WampStructInterface()
{
}

void WampStructInterface::applyState(const json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<StructString>());
    }
}

void WampStructInterface::setPropBool(const StructBool& propBool)
{
    const json &fields = json::object({
        { "propBool", propBool }
    });
    WampClient::instance()->doCall("testbed1.StructInterface._set", json::array(), fields);
}

void WampStructInterface::setPropBoolLocal(const StructBool& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        StructInterfaceAgent::trace_state(this);
    }
}


StructBool WampStructInterface::propBool() const
{
    return m_propBool;
}

void WampStructInterface::setPropInt(const StructInt& propInt)
{
    const json &fields = json::object({
        { "propInt", propInt }
    });
    WampClient::instance()->doCall("testbed1.StructInterface._set", json::array(), fields);
}

void WampStructInterface::setPropIntLocal(const StructInt& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        StructInterfaceAgent::trace_state(this);
    }
}


StructInt WampStructInterface::propInt() const
{
    return m_propInt;
}

void WampStructInterface::setPropFloat(const StructFloat& propFloat)
{
    const json &fields = json::object({
        { "propFloat", propFloat }
    });
    WampClient::instance()->doCall("testbed1.StructInterface._set", json::array(), fields);
}

void WampStructInterface::setPropFloatLocal(const StructFloat& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        StructInterfaceAgent::trace_state(this);
    }
}


StructFloat WampStructInterface::propFloat() const
{
    return m_propFloat;
}

void WampStructInterface::setPropString(const StructString& propString)
{
    const json &fields = json::object({
        { "propString", propString }
    });
    WampClient::instance()->doCall("testbed1.StructInterface._set", json::array(), fields);
}

void WampStructInterface::setPropStringLocal(const StructString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        StructInterfaceAgent::trace_state(this);
    }
}


StructString WampStructInterface::propString() const
{
    return m_propString;
}

StructBool WampStructInterface::funcBool(const StructBool& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    StructBool value{ StructBool() };
    funcBoolAsync(paramBool)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> WampStructInterface::funcBoolAsync(const StructBool& paramBool)
{
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            WampClient::instance()->doCall("testbed1.StructInterface.funcBool", json::array({paramBool}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructBool& result = arg.args[0].get<StructBool>();
                resolve(result);
            });
        }
    };
}

StructBool WampStructInterface::funcInt(const StructInt& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    StructBool value{ StructBool() };
    funcIntAsync(paramInt)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> WampStructInterface::funcIntAsync(const StructInt& paramInt)
{
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            WampClient::instance()->doCall("testbed1.StructInterface.funcInt", json::array({paramInt}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructBool& result = arg.args[0].get<StructBool>();
                resolve(result);
            });
        }
    };
}

StructFloat WampStructInterface::funcFloat(const StructFloat& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    StructFloat value{ StructFloat() };
    funcFloatAsync(paramFloat)
        .then([&](StructFloat result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructFloat> WampStructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    return QtPromise::QPromise<StructFloat>{[&](
        const QtPromise::QPromiseResolve<StructFloat>& resolve) {
            WampClient::instance()->doCall("testbed1.StructInterface.funcFloat", json::array({paramFloat}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructFloat& result = arg.args[0].get<StructFloat>();
                resolve(result);
            });
        }
    };
}

StructString WampStructInterface::funcString(const StructString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    StructString value{ StructString() };
    funcStringAsync(paramString)
        .then([&](StructString result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructString> WampStructInterface::funcStringAsync(const StructString& paramString)
{
    return QtPromise::QPromise<StructString>{[&](
        const QtPromise::QPromiseResolve<StructString>& resolve) {
            WampClient::instance()->doCall("testbed1.StructInterface.funcString", json::array({paramString}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructString& result = arg.args[0].get<StructString>();
                resolve(result);
            });
        }
    };
}

void WampStructInterface::notifySigBool(WAMP::EventArg arg)
{
    emit sigBool(arg.args[0].get<StructBool>());
}

void WampStructInterface::notifySigInt(WAMP::EventArg arg)
{
    emit sigInt(arg.args[0].get<StructInt>());
}

void WampStructInterface::notifySigFloat(WAMP::EventArg arg)
{
    emit sigFloat(arg.args[0].get<StructFloat>());
}

void WampStructInterface::notifySigString(WAMP::EventArg arg)
{
    emit sigString(arg.args[0].get<StructString>());
}


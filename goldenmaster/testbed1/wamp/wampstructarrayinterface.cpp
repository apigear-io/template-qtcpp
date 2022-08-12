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
#include "wampstructarrayinterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampStructArrayInterface::WampStructArrayInterface(QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
{    
    // get initial state from service
    WampClient::instance()->doCall("testbed1.StructArrayInterface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("testbed1.StructArrayInterface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sigBool
    WampClient::instance()->doSubscribe("testbed1.StructArrayInterface.sigBool", [this](WAMP::EventArg arg) {
        this->notifySigBool(arg);
    });
    // subscribe to signal sigInt
    WampClient::instance()->doSubscribe("testbed1.StructArrayInterface.sigInt", [this](WAMP::EventArg arg) {
        this->notifySigInt(arg);
    });
    // subscribe to signal sigFloat
    WampClient::instance()->doSubscribe("testbed1.StructArrayInterface.sigFloat", [this](WAMP::EventArg arg) {
        this->notifySigFloat(arg);
    });
    // subscribe to signal sigString
    WampClient::instance()->doSubscribe("testbed1.StructArrayInterface.sigString", [this](WAMP::EventArg arg) {
        this->notifySigString(arg);
    });
}

WampStructArrayInterface::~WampStructArrayInterface()
{
}

void WampStructArrayInterface::applyState(const json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<QList<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<QList<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<QList<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<QList<StructString>>());
    }
}

void WampStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    const json &fields = json::object({
        { "propBool", propBool }
    });
    WampClient::instance()->doCall("testbed1.StructArrayInterface._set", json::array(), fields);
}

void WampStructArrayInterface::setPropBoolLocal(const QList<StructBool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        StructArrayInterfaceAgent::trace_state(this);
    }
}


QList<StructBool> WampStructArrayInterface::propBool() const
{
    return m_propBool;
}

void WampStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    const json &fields = json::object({
        { "propInt", propInt }
    });
    WampClient::instance()->doCall("testbed1.StructArrayInterface._set", json::array(), fields);
}

void WampStructArrayInterface::setPropIntLocal(const QList<StructInt>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        StructArrayInterfaceAgent::trace_state(this);
    }
}


QList<StructInt> WampStructArrayInterface::propInt() const
{
    return m_propInt;
}

void WampStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    const json &fields = json::object({
        { "propFloat", propFloat }
    });
    WampClient::instance()->doCall("testbed1.StructArrayInterface._set", json::array(), fields);
}

void WampStructArrayInterface::setPropFloatLocal(const QList<StructFloat>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        StructArrayInterfaceAgent::trace_state(this);
    }
}


QList<StructFloat> WampStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void WampStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    const json &fields = json::object({
        { "propString", propString }
    });
    WampClient::instance()->doCall("testbed1.StructArrayInterface._set", json::array(), fields);
}

void WampStructArrayInterface::setPropStringLocal(const QList<StructString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        StructArrayInterfaceAgent::trace_state(this);
    }
}


QList<StructString> WampStructArrayInterface::propString() const
{
    return m_propString;
}

StructBool WampStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    StructBool value(StructBool());
    funcBoolAsync(paramBool)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> WampStructArrayInterface::funcBoolAsync(const QList<StructBool>& paramBool)
{
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            WampClient::instance()->doCall("testbed1.StructArrayInterface.funcBool", json::array({paramBool}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructBool& result = arg.args[0].get<StructBool>();
                resolve(result);
            });
        }
    };
}

StructBool WampStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    StructBool value(StructBool());
    funcIntAsync(paramInt)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> WampStructArrayInterface::funcIntAsync(const QList<StructInt>& paramInt)
{
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            WampClient::instance()->doCall("testbed1.StructArrayInterface.funcInt", json::array({paramInt}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructBool& result = arg.args[0].get<StructBool>();
                resolve(result);
            });
        }
    };
}

StructBool WampStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    StructBool value(StructBool());
    funcFloatAsync(paramFloat)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> WampStructArrayInterface::funcFloatAsync(const QList<StructFloat>& paramFloat)
{
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            WampClient::instance()->doCall("testbed1.StructArrayInterface.funcFloat", json::array({paramFloat}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructBool& result = arg.args[0].get<StructBool>();
                resolve(result);
            });
        }
    };
}

StructBool WampStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    StructBool value(StructBool());
    funcStringAsync(paramString)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> WampStructArrayInterface::funcStringAsync(const QList<StructString>& paramString)
{
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            WampClient::instance()->doCall("testbed1.StructArrayInterface.funcString", json::array({paramString}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const StructBool& result = arg.args[0].get<StructBool>();
                resolve(result);
            });
        }
    };
}

void WampStructArrayInterface::notifySigBool(WAMP::EventArg arg)
{
    emit sigBool(arg.args[0].get<QList<StructBool>>());
}

void WampStructArrayInterface::notifySigInt(WAMP::EventArg arg)
{
    emit sigInt(arg.args[0].get<QList<StructInt>>());
}

void WampStructArrayInterface::notifySigFloat(WAMP::EventArg arg)
{
    emit sigFloat(arg.args[0].get<QList<StructFloat>>());
}

void WampStructArrayInterface::notifySigString(WAMP::EventArg arg)
{
    emit sigString(arg.args[0].get<QList<StructString>>());
}


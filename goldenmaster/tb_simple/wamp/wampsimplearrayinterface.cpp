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
#include "wampsimplearrayinterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampSimpleArrayInterface::WampSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propFloat(QList<qreal>())
    , m_propString(QList<QString>())
{    
    // get initial state from service
    WampClient::instance()->doCall("tb.simple.SimpleArrayInterface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("tb.simple.SimpleArrayInterface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sigBool
    WampClient::instance()->doSubscribe("tb.simple.SimpleArrayInterface.sigBool", [this](WAMP::EventArg arg) {
        this->notifySigBool(arg);
    });
    // subscribe to signal sigInt
    WampClient::instance()->doSubscribe("tb.simple.SimpleArrayInterface.sigInt", [this](WAMP::EventArg arg) {
        this->notifySigInt(arg);
    });
    // subscribe to signal sigFloat
    WampClient::instance()->doSubscribe("tb.simple.SimpleArrayInterface.sigFloat", [this](WAMP::EventArg arg) {
        this->notifySigFloat(arg);
    });
    // subscribe to signal sigString
    WampClient::instance()->doSubscribe("tb.simple.SimpleArrayInterface.sigString", [this](WAMP::EventArg arg) {
        this->notifySigString(arg);
    });
}

WampSimpleArrayInterface::~WampSimpleArrayInterface()
{
}

void WampSimpleArrayInterface::applyState(const json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<QList<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<QList<int>>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<QList<qreal>>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<QList<QString>>());
    }
}

void WampSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    const json &fields = json::object({
        { "propBool", propBool }
    });
    WampClient::instance()->doCall("tb.simple.SimpleArrayInterface._set", json::array(), fields);
}

void WampSimpleArrayInterface::setPropBoolLocal(const QList<bool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}


QList<bool> WampSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void WampSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    const json &fields = json::object({
        { "propInt", propInt }
    });
    WampClient::instance()->doCall("tb.simple.SimpleArrayInterface._set", json::array(), fields);
}

void WampSimpleArrayInterface::setPropIntLocal(const QList<int>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}


QList<int> WampSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void WampSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    const json &fields = json::object({
        { "propFloat", propFloat }
    });
    WampClient::instance()->doCall("tb.simple.SimpleArrayInterface._set", json::array(), fields);
}

void WampSimpleArrayInterface::setPropFloatLocal(const QList<qreal>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}


QList<qreal> WampSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void WampSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    const json &fields = json::object({
        { "propString", propString }
    });
    WampClient::instance()->doCall("tb.simple.SimpleArrayInterface._set", json::array(), fields);
}

void WampSimpleArrayInterface::setPropStringLocal(const QList<QString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}


QList<QString> WampSimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> WampSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    QList<bool> value{ QList<bool>() };
    funcBoolAsync(paramBool)
        .then([&](QList<bool> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<bool>> WampSimpleArrayInterface::funcBoolAsync(const QList<bool>& paramBool)
{
    return QtPromise::QPromise<QList<bool>>{[&](
        const QtPromise::QPromiseResolve<QList<bool>>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleArrayInterface.funcBool", json::array({paramBool}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const QList<bool>& result = arg.args[0].get<QList<bool>>();
                resolve(result);
            });
        }
    };
}

QList<int> WampSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    QList<int> value{ QList<int>() };
    funcIntAsync(paramInt)
        .then([&](QList<int> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<int>> WampSimpleArrayInterface::funcIntAsync(const QList<int>& paramInt)
{
    return QtPromise::QPromise<QList<int>>{[&](
        const QtPromise::QPromiseResolve<QList<int>>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleArrayInterface.funcInt", json::array({paramInt}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const QList<int>& result = arg.args[0].get<QList<int>>();
                resolve(result);
            });
        }
    };
}

QList<qreal> WampSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    QList<qreal> value{ QList<qreal>() };
    funcFloatAsync(paramFloat)
        .then([&](QList<qreal> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<qreal>> WampSimpleArrayInterface::funcFloatAsync(const QList<qreal>& paramFloat)
{
    return QtPromise::QPromise<QList<qreal>>{[&](
        const QtPromise::QPromiseResolve<QList<qreal>>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleArrayInterface.funcFloat", json::array({paramFloat}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const QList<qreal>& result = arg.args[0].get<QList<qreal>>();
                resolve(result);
            });
        }
    };
}

QList<QString> WampSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    QList<QString> value{ QList<QString>() };
    funcStringAsync(paramString)
        .then([&](QList<QString> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<QString>> WampSimpleArrayInterface::funcStringAsync(const QList<QString>& paramString)
{
    return QtPromise::QPromise<QList<QString>>{[&](
        const QtPromise::QPromiseResolve<QList<QString>>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleArrayInterface.funcString", json::array({paramString}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const QList<QString>& result = arg.args[0].get<QList<QString>>();
                resolve(result);
            });
        }
    };
}

void WampSimpleArrayInterface::notifySigBool(WAMP::EventArg arg)
{
    emit sigBool(arg.args[0].get<QList<bool>>());
}

void WampSimpleArrayInterface::notifySigInt(WAMP::EventArg arg)
{
    emit sigInt(arg.args[0].get<QList<int>>());
}

void WampSimpleArrayInterface::notifySigFloat(WAMP::EventArg arg)
{
    emit sigFloat(arg.args[0].get<QList<qreal>>());
}

void WampSimpleArrayInterface::notifySigString(WAMP::EventArg arg)
{
    emit sigString(arg.args[0].get<QList<QString>>());
}


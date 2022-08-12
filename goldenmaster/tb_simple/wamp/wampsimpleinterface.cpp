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
#include "wampsimpleinterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampSimpleInterface::WampSimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propFloat(0.0)
    , m_propString(QString())
{    
    // get initial state from service
    WampClient::instance()->doCall("tb.simple.SimpleInterface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("tb.simple.SimpleInterface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sigBool
    WampClient::instance()->doSubscribe("tb.simple.SimpleInterface.sigBool", [this](WAMP::EventArg arg) {
        this->notifySigBool(arg);
    });
    // subscribe to signal sigInt
    WampClient::instance()->doSubscribe("tb.simple.SimpleInterface.sigInt", [this](WAMP::EventArg arg) {
        this->notifySigInt(arg);
    });
    // subscribe to signal sigFloat
    WampClient::instance()->doSubscribe("tb.simple.SimpleInterface.sigFloat", [this](WAMP::EventArg arg) {
        this->notifySigFloat(arg);
    });
    // subscribe to signal sigString
    WampClient::instance()->doSubscribe("tb.simple.SimpleInterface.sigString", [this](WAMP::EventArg arg) {
        this->notifySigString(arg);
    });
}

WampSimpleInterface::~WampSimpleInterface()
{
}

void WampSimpleInterface::applyState(const json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<qreal>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QString>());
    }
}

void WampSimpleInterface::setPropBool(bool propBool)
{
    const json &fields = json::object({
        { "propBool", propBool }
    });
    WampClient::instance()->doCall("tb.simple.SimpleInterface._set", json::array(), fields);
}

void WampSimpleInterface::setPropBoolLocal(bool propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleInterfaceAgent::trace_state(this);
    }
}


bool WampSimpleInterface::propBool() const
{
    return m_propBool;
}

void WampSimpleInterface::setPropInt(int propInt)
{
    const json &fields = json::object({
        { "propInt", propInt }
    });
    WampClient::instance()->doCall("tb.simple.SimpleInterface._set", json::array(), fields);
}

void WampSimpleInterface::setPropIntLocal(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleInterfaceAgent::trace_state(this);
    }
}


int WampSimpleInterface::propInt() const
{
    return m_propInt;
}

void WampSimpleInterface::setPropFloat(qreal propFloat)
{
    const json &fields = json::object({
        { "propFloat", propFloat }
    });
    WampClient::instance()->doCall("tb.simple.SimpleInterface._set", json::array(), fields);
}

void WampSimpleInterface::setPropFloatLocal(qreal propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleInterfaceAgent::trace_state(this);
    }
}


qreal WampSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void WampSimpleInterface::setPropString(const QString& propString)
{
    const json &fields = json::object({
        { "propString", propString }
    });
    WampClient::instance()->doCall("tb.simple.SimpleInterface._set", json::array(), fields);
}

void WampSimpleInterface::setPropStringLocal(const QString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleInterfaceAgent::trace_state(this);
    }
}


QString WampSimpleInterface::propString() const
{
    return m_propString;
}

bool WampSimpleInterface::funcBool(bool paramBool)
{
    qDebug() << Q_FUNC_INFO;
    bool value{ false };
    funcBoolAsync(paramBool)
        .then([&](bool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<bool> WampSimpleInterface::funcBoolAsync(bool paramBool)
{
    return QtPromise::QPromise<bool>{[&](
        const QtPromise::QPromiseResolve<bool>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleInterface.funcBool", json::array({paramBool}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const bool& result = arg.args[0].get<bool>();
                resolve(result);
            });
        }
    };
}

int WampSimpleInterface::funcInt(int paramInt)
{
    qDebug() << Q_FUNC_INFO;
    int value{ 0 };
    funcIntAsync(paramInt)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> WampSimpleInterface::funcIntAsync(int paramInt)
{
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleInterface.funcInt", json::array({paramInt}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const int& result = arg.args[0].get<int>();
                resolve(result);
            });
        }
    };
}

qreal WampSimpleInterface::funcFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    qreal value{ 0.0 };
    funcFloatAsync(paramFloat)
        .then([&](qreal result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<qreal> WampSimpleInterface::funcFloatAsync(qreal paramFloat)
{
    return QtPromise::QPromise<qreal>{[&](
        const QtPromise::QPromiseResolve<qreal>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleInterface.funcFloat", json::array({paramFloat}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const qreal& result = arg.args[0].get<qreal>();
                resolve(result);
            });
        }
    };
}

QString WampSimpleInterface::funcString(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    QString value{ QString() };
    funcStringAsync(paramString)
        .then([&](QString result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QString> WampSimpleInterface::funcStringAsync(const QString& paramString)
{
    return QtPromise::QPromise<QString>{[&](
        const QtPromise::QPromiseResolve<QString>& resolve) {
            WampClient::instance()->doCall("tb.simple.SimpleInterface.funcString", json::array({paramString}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const QString& result = arg.args[0].get<QString>();
                resolve(result);
            });
        }
    };
}

void WampSimpleInterface::notifySigBool(WAMP::EventArg arg)
{
    emit sigBool(arg.args[0].get<bool>());
}

void WampSimpleInterface::notifySigInt(WAMP::EventArg arg)
{
    emit sigInt(arg.args[0].get<int>());
}

void WampSimpleInterface::notifySigFloat(WAMP::EventArg arg)
{
    emit sigFloat(arg.args[0].get<qreal>());
}

void WampSimpleInterface::notifySigString(WAMP::EventArg arg)
{
    emit sigString(arg.args[0].get<QString>());
}


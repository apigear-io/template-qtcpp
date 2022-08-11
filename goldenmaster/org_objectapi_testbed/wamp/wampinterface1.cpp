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
#include "wampinterface1.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampInterface1::WampInterface1(QObject *parent)
    : AbstractInterface1(parent)
    , m_prop1(false)
    , m_prop2(0)
    , m_prop3(0.0)
    , m_prop4(QString())
    , m_prop5(QList<int>())
    , m_prop6(Struct1())
    , m_prop7(0)
    , m_prop10(QList<int>())
    , m_prop11(QList<Struct1>())
    , m_prop12(QList<Enum1::Enum1Enum>())
    , m_prop14(QList<Struct1>())
{    
    // get initial state from service
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("org.objectapi.testbed.Interface1", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("org.objectapi.testbed.Interface1.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("org.objectapi.testbed.Interface1.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
    // subscribe to signal sig3
    WampClient::instance()->doSubscribe("org.objectapi.testbed.Interface1.sig3", [this](WAMP::EventArg arg) {
        this->notifySig3(arg);
    });
}

WampInterface1::~WampInterface1()
{
}

void WampInterface1::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<bool>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<int>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<qreal>());
    }
    if(fields.contains("prop4")) {
        setProp4Local(fields["prop4"].get<QString>());
    }
    if(fields.contains("prop5")) {
        setProp5Local(fields["prop5"].get<QList<int>>());
    }
    if(fields.contains("prop6")) {
        setProp6Local(fields["prop6"].get<Struct1>());
    }
    if(fields.contains("prop7")) {
        setProp7Local(fields["prop7"].get<int>());
    }
    if(fields.contains("prop10")) {
        setProp10Local(fields["prop10"].get<QList<int>>());
    }
    if(fields.contains("prop11")) {
        setProp11Local(fields["prop11"].get<QList<Struct1>>());
    }
    if(fields.contains("prop12")) {
        setProp12Local(fields["prop12"].get<QList<Enum1::Enum1Enum>>());
    }
    if(fields.contains("prop14")) {
        setProp14Local(fields["prop14"].get<QList<Struct1>>());
    }
}

void WampInterface1::setProp1(bool prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp1Local(bool prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        Interface1Agent::trace_state(this);
    }
}


bool WampInterface1::prop1() const
{
    return m_prop1;
}

void WampInterface1::setProp2(int prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp2Local(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        Interface1Agent::trace_state(this);
    }
}


int WampInterface1::prop2() const
{
    return m_prop2;
}

void WampInterface1::setProp3(qreal prop3)
{
    const json &fields = json::object({
        { "prop3", prop3 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp3Local(qreal prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        Interface1Agent::trace_state(this);
    }
}


qreal WampInterface1::prop3() const
{
    return m_prop3;
}

void WampInterface1::setProp4(const QString& prop4)
{
    const json &fields = json::object({
        { "prop4", prop4 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp4Local(const QString& prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        Interface1Agent::trace_state(this);
    }
}


QString WampInterface1::prop4() const
{
    return m_prop4;
}

void WampInterface1::setProp5(const QList<int>& prop5)
{
    const json &fields = json::object({
        { "prop5", prop5 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp5Local(const QList<int>& prop5)
{
    if (m_prop5 != prop5) {
        m_prop5 = prop5;
        emit prop5Changed(prop5);
        Interface1Agent::trace_state(this);
    }
}


QList<int> WampInterface1::prop5() const
{
    return m_prop5;
}

void WampInterface1::setProp6(const Struct1& prop6)
{
    const json &fields = json::object({
        { "prop6", prop6 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp6Local(const Struct1& prop6)
{
    if (m_prop6 != prop6) {
        m_prop6 = prop6;
        emit prop6Changed(prop6);
        Interface1Agent::trace_state(this);
    }
}


Struct1 WampInterface1::prop6() const
{
    return m_prop6;
}

void WampInterface1::setProp7(int prop7)
{
    const json &fields = json::object({
        { "prop7", prop7 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp7Local(int prop7)
{
    if (m_prop7 != prop7) {
        m_prop7 = prop7;
        emit prop7Changed(prop7);
        Interface1Agent::trace_state(this);
    }
}


int WampInterface1::prop7() const
{
    return m_prop7;
}

void WampInterface1::setProp10(const QList<int>& prop10)
{
    const json &fields = json::object({
        { "prop10", prop10 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp10Local(const QList<int>& prop10)
{
    if (m_prop10 != prop10) {
        m_prop10 = prop10;
        emit prop10Changed(prop10);
        Interface1Agent::trace_state(this);
    }
}


QList<int> WampInterface1::prop10() const
{
    return m_prop10;
}

void WampInterface1::setProp11(const QList<Struct1>& prop11)
{
    const json &fields = json::object({
        { "prop11", prop11 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp11Local(const QList<Struct1>& prop11)
{
    if (m_prop11 != prop11) {
        m_prop11 = prop11;
        emit prop11Changed(prop11);
        Interface1Agent::trace_state(this);
    }
}


QList<Struct1> WampInterface1::prop11() const
{
    return m_prop11;
}

void WampInterface1::setProp12(const QList<Enum1::Enum1Enum>& prop12)
{
    const json &fields = json::object({
        { "prop12", prop12 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp12Local(const QList<Enum1::Enum1Enum>& prop12)
{
    if (m_prop12 != prop12) {
        m_prop12 = prop12;
        emit prop12Changed(prop12);
        Interface1Agent::trace_state(this);
    }
}


QList<Enum1::Enum1Enum> WampInterface1::prop12() const
{
    return m_prop12;
}

void WampInterface1::setProp14(const QList<Struct1>& prop14)
{
    const json &fields = json::object({
        { "prop14", prop14 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1._set", json::array(), fields);
}

void WampInterface1::setProp14Local(const QList<Struct1>& prop14)
{
    if (m_prop14 != prop14) {
        m_prop14 = prop14;
        emit prop14Changed(prop14);
        Interface1Agent::trace_state(this);
    }
}


QList<Struct1> WampInterface1::prop14() const
{
    return m_prop14;
}

void WampInterface1::op1()
{
    qDebug() << Q_FUNC_INFO;
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1.op1", json::array({}), json::object());
}

QtPromise::QPromise<void> WampInterface1::op1Async()
{
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1.op1", json::array({}), json::object());
    return QtPromise::QPromise<void>::resolve();
}

void WampInterface1::op2(int step)
{
    qDebug() << Q_FUNC_INFO;
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1.op2", json::array({step}), json::object());
}

QtPromise::QPromise<void> WampInterface1::op2Async(int step)
{
    WampClient::instance()->doCall("org.objectapi.testbed.Interface1.op2", json::array({step}), json::object());
    return QtPromise::QPromise<void>::resolve();
}

int WampInterface1::op3()
{
    qDebug() << Q_FUNC_INFO;
    int value(0);
    op3Async()
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> WampInterface1::op3Async()
{
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            WampClient::instance()->doCall("org.objectapi.testbed.Interface1.op3", json::array({}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const int& result = arg.args[0].get<int>();
                resolve(result);
            });
        }
    };
}

void WampInterface1::notifySig1(WAMP::EventArg arg)
{
    emit sig1();
}

void WampInterface1::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<int>());
}

void WampInterface1::notifySig3(WAMP::EventArg arg)
{
    emit sig3();
}


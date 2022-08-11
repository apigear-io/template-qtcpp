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
#include "olinkinterface1.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkInterface1::OLinkInterface1(QObject *parent)
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
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkInterface1::~OLinkInterface1()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkInterface1::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
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

void OLinkInterface1::setProp1(bool prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop1", prop1);
}

void OLinkInterface1::setProp1Local(bool prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        Interface1Agent::trace_state(this);
    }
}

bool OLinkInterface1::prop1() const
{
    return m_prop1;
}

void OLinkInterface1::setProp2(int prop2)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop2", prop2);
}

void OLinkInterface1::setProp2Local(int prop2)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        Interface1Agent::trace_state(this);
    }
}

int OLinkInterface1::prop2() const
{
    return m_prop2;
}

void OLinkInterface1::setProp3(qreal prop3)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop3", prop3);
}

void OLinkInterface1::setProp3Local(qreal prop3)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        Interface1Agent::trace_state(this);
    }
}

qreal OLinkInterface1::prop3() const
{
    return m_prop3;
}

void OLinkInterface1::setProp4(const QString& prop4)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop4", prop4);
}

void OLinkInterface1::setProp4Local(const QString& prop4)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        Interface1Agent::trace_state(this);
    }
}

QString OLinkInterface1::prop4() const
{
    return m_prop4;
}

void OLinkInterface1::setProp5(const QList<int>& prop5)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop5", prop5);
}

void OLinkInterface1::setProp5Local(const QList<int>& prop5)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop5 != prop5) {
        m_prop5 = prop5;
        emit prop5Changed(prop5);
        Interface1Agent::trace_state(this);
    }
}

QList<int> OLinkInterface1::prop5() const
{
    return m_prop5;
}

void OLinkInterface1::setProp6(const Struct1& prop6)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop6", prop6);
}

void OLinkInterface1::setProp6Local(const Struct1& prop6)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop6 != prop6) {
        m_prop6 = prop6;
        emit prop6Changed(prop6);
        Interface1Agent::trace_state(this);
    }
}

Struct1 OLinkInterface1::prop6() const
{
    return m_prop6;
}

void OLinkInterface1::setProp7(int prop7)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop7", prop7);
}

void OLinkInterface1::setProp7Local(int prop7)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop7 != prop7) {
        m_prop7 = prop7;
        emit prop7Changed(prop7);
        Interface1Agent::trace_state(this);
    }
}

int OLinkInterface1::prop7() const
{
    return m_prop7;
}

void OLinkInterface1::setProp10(const QList<int>& prop10)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop10", prop10);
}

void OLinkInterface1::setProp10Local(const QList<int>& prop10)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop10 != prop10) {
        m_prop10 = prop10;
        emit prop10Changed(prop10);
        Interface1Agent::trace_state(this);
    }
}

QList<int> OLinkInterface1::prop10() const
{
    return m_prop10;
}

void OLinkInterface1::setProp11(const QList<Struct1>& prop11)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop11", prop11);
}

void OLinkInterface1::setProp11Local(const QList<Struct1>& prop11)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop11 != prop11) {
        m_prop11 = prop11;
        emit prop11Changed(prop11);
        Interface1Agent::trace_state(this);
    }
}

QList<Struct1> OLinkInterface1::prop11() const
{
    return m_prop11;
}

void OLinkInterface1::setProp12(const QList<Enum1::Enum1Enum>& prop12)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop12", prop12);
}

void OLinkInterface1::setProp12Local(const QList<Enum1::Enum1Enum>& prop12)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop12 != prop12) {
        m_prop12 = prop12;
        emit prop12Changed(prop12);
        Interface1Agent::trace_state(this);
    }
}

QList<Enum1::Enum1Enum> OLinkInterface1::prop12() const
{
    return m_prop12;
}

void OLinkInterface1::setProp14(const QList<Struct1>& prop14)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop14", prop14);
}

void OLinkInterface1::setProp14Local(const QList<Struct1>& prop14)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop14 != prop14) {
        m_prop14 = prop14;
        emit prop14Changed(prop14);
        Interface1Agent::trace_state(this);
    }
}

QList<Struct1> OLinkInterface1::prop14() const
{
    return m_prop14;
}

void OLinkInterface1::op1()
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return ;
    }
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const json &args = json::array({
        
    });
    m_node->invokeRemote("org_objectapi_testbed.Interface1/op1", args, func);
}

QtPromise::QPromise<void> OLinkInterface1::op1Async()
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    m_node->invokeRemote("org.objectapi.testbed.Interface1/op1", json::array({}));
    return QtPromise::QPromise<void>::resolve();
}

void OLinkInterface1::op2(int step)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return ;
    }
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const json &args = json::array({
        step
    });
    m_node->invokeRemote("org_objectapi_testbed.Interface1/op2", args, func);
}

QtPromise::QPromise<void> OLinkInterface1::op2Async(int step)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    m_node->invokeRemote("org.objectapi.testbed.Interface1/op2", json::array({step}));
    return QtPromise::QPromise<void>::resolve();
}

int OLinkInterface1::op3()
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    int value(0);
    op3Async()
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> OLinkInterface1::op3Async()
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            m_node->invokeRemote("org.objectapi.testbed.Interface1/op3", json::array({}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}


std::string OLinkInterface1::olinkObjectName()
{
    return "org.objectapi.testbed.Interface1";
}

void OLinkInterface1::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sig1") {
        emit sig1();   
        return;
    }
    if(path == "sig2") {
        emit sig2(args[0].get<int>());   
        return;
    }
    if(path == "sig3") {
        emit sig3();   
        return;
    }
}

void OLinkInterface1::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkInterface1::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkInterface1::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



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


#include "qmlinterface1.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

QmlInterface1::QmlInterface1(QObject *parent)
    : AbstractInterface1(parent)
{
    m_obj = ApiFactory::get()->createInterface1(this);
    connect(m_obj, &AbstractInterface1::prop1Changed, this, &QmlInterface1::prop1Changed);
    connect(m_obj, &AbstractInterface1::prop1Changed, this, &AbstractInterface1::prop1Changed);
    connect(m_obj, &AbstractInterface1::prop2Changed, this, &QmlInterface1::prop2Changed);
    connect(m_obj, &AbstractInterface1::prop2Changed, this, &AbstractInterface1::prop2Changed);
    connect(m_obj, &AbstractInterface1::prop3Changed, this, &QmlInterface1::prop3Changed);
    connect(m_obj, &AbstractInterface1::prop3Changed, this, &AbstractInterface1::prop3Changed);
    connect(m_obj, &AbstractInterface1::prop4Changed, this, &QmlInterface1::prop4Changed);
    connect(m_obj, &AbstractInterface1::prop4Changed, this, &AbstractInterface1::prop4Changed);
    connect(m_obj, &AbstractInterface1::prop5Changed, this, &QmlInterface1::prop5Changed);
    connect(m_obj, &AbstractInterface1::prop5Changed, this, &AbstractInterface1::prop5Changed);
    connect(m_obj, &AbstractInterface1::prop6Changed, this, &QmlInterface1::prop6Changed);
    connect(m_obj, &AbstractInterface1::prop6Changed, this, &AbstractInterface1::prop6Changed);
    connect(m_obj, &AbstractInterface1::prop7Changed, this, &QmlInterface1::prop7Changed);
    connect(m_obj, &AbstractInterface1::prop7Changed, this, &AbstractInterface1::prop7Changed);
    connect(m_obj, &AbstractInterface1::prop10Changed, this, &QmlInterface1::prop10Changed);
    connect(m_obj, &AbstractInterface1::prop10Changed, this, &AbstractInterface1::prop10Changed);
    connect(m_obj, &AbstractInterface1::prop11Changed, this, &QmlInterface1::prop11Changed);
    connect(m_obj, &AbstractInterface1::prop11Changed, this, &AbstractInterface1::prop11Changed);
    connect(m_obj, &AbstractInterface1::prop12Changed, this, &QmlInterface1::prop12Changed);
    connect(m_obj, &AbstractInterface1::prop12Changed, this, &AbstractInterface1::prop12Changed);
    connect(m_obj, &AbstractInterface1::prop14Changed, this, &QmlInterface1::prop14Changed);
    connect(m_obj, &AbstractInterface1::prop14Changed, this, &AbstractInterface1::prop14Changed);
    connect(m_obj, &AbstractInterface1::sig1, this, &QmlInterface1::sig1);
    connect(m_obj, &AbstractInterface1::sig1, this, &AbstractInterface1::sig1);
    connect(m_obj, &AbstractInterface1::sig2, this, &QmlInterface1::sig2);
    connect(m_obj, &AbstractInterface1::sig2, this, &AbstractInterface1::sig2);
    connect(m_obj, &AbstractInterface1::sig3, this, &QmlInterface1::sig3);
    connect(m_obj, &AbstractInterface1::sig3, this, &AbstractInterface1::sig3);
}

QmlInterface1::~QmlInterface1()
{
}

bool QmlInterface1::prop1() const
{
    return m_obj->prop1();
}

void QmlInterface1::setProp1(bool prop1)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp1(prop1);
}

int QmlInterface1::prop2() const
{
    return m_obj->prop2();
}

void QmlInterface1::setProp2(int prop2)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp2(prop2);
}

qreal QmlInterface1::prop3() const
{
    return m_obj->prop3();
}

void QmlInterface1::setProp3(qreal prop3)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp3(prop3);
}

QString QmlInterface1::prop4() const
{
    return m_obj->prop4();
}

void QmlInterface1::setProp4(const QString& prop4)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp4(prop4);
}

QList<int> QmlInterface1::prop5() const
{
    return m_obj->prop5();
}

void QmlInterface1::setProp5(const QList<int>& prop5)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp5(prop5);
}

Struct1 QmlInterface1::prop6() const
{
    return m_obj->prop6();
}

void QmlInterface1::setProp6(const Struct1& prop6)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp6(prop6);
}

int QmlInterface1::prop7() const
{
    return m_obj->prop7();
}

void QmlInterface1::setProp7(int prop7)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp7(prop7);
}

QList<int> QmlInterface1::prop10() const
{
    return m_obj->prop10();
}

void QmlInterface1::setProp10(const QList<int>& prop10)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp10(prop10);
}

QList<Struct1> QmlInterface1::prop11() const
{
    return m_obj->prop11();
}

void QmlInterface1::setProp11(const QList<Struct1>& prop11)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp11(prop11);
}

QList<Enum1::Enum1Enum> QmlInterface1::prop12() const
{
    return m_obj->prop12();
}

void QmlInterface1::setProp12(const QList<Enum1::Enum1Enum>& prop12)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp12(prop12);
}

QList<Struct1> QmlInterface1::prop14() const
{
    return m_obj->prop14();
}

void QmlInterface1::setProp14(const QList<Struct1>& prop14)
{
    Interface1Agent::capture_state(this);
    return m_obj->setProp14(prop14);
}

void QmlInterface1::op1()
{
    Interface1Agent::trace_op1(this);
	
    return m_obj->op1();
}

void QmlInterface1::op2(int step)
{
    Interface1Agent::trace_op2(this, step);
	
    return m_obj->op2(step);
}

int QmlInterface1::op3()
{
    Interface1Agent::trace_op3(this);
	
    return m_obj->op3();
}

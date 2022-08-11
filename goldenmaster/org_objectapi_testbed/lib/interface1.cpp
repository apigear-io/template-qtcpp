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


#include "interface1.h"

#include <QtQml>

#include "../api/agent.h"

Interface1::Interface1(QObject *parent)
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
}

Interface1::~Interface1()
{
}

void Interface1::setProp1(bool prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        Interface1Agent::trace_state(this);
    }
}

bool Interface1::prop1() const
{
    return m_prop1;
}

void Interface1::setProp2(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        Interface1Agent::trace_state(this);
    }
}

int Interface1::prop2() const
{
    return m_prop2;
}

void Interface1::setProp3(qreal prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        Interface1Agent::trace_state(this);
    }
}

qreal Interface1::prop3() const
{
    return m_prop3;
}

void Interface1::setProp4(const QString& prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        Interface1Agent::trace_state(this);
    }
}

QString Interface1::prop4() const
{
    return m_prop4;
}

void Interface1::setProp5(const QList<int>& prop5)
{
    if (m_prop5 != prop5) {
        m_prop5 = prop5;
        emit prop5Changed(prop5);
        Interface1Agent::trace_state(this);
    }
}

QList<int> Interface1::prop5() const
{
    return m_prop5;
}

void Interface1::setProp6(const Struct1& prop6)
{
    if (m_prop6 != prop6) {
        m_prop6 = prop6;
        emit prop6Changed(prop6);
        Interface1Agent::trace_state(this);
    }
}

Struct1 Interface1::prop6() const
{
    return m_prop6;
}

void Interface1::setProp7(int prop7)
{
    if (m_prop7 != prop7) {
        m_prop7 = prop7;
        emit prop7Changed(prop7);
        Interface1Agent::trace_state(this);
    }
}

int Interface1::prop7() const
{
    return m_prop7;
}

void Interface1::setProp10(const QList<int>& prop10)
{
    if (m_prop10 != prop10) {
        m_prop10 = prop10;
        emit prop10Changed(prop10);
        Interface1Agent::trace_state(this);
    }
}

QList<int> Interface1::prop10() const
{
    return m_prop10;
}

void Interface1::setProp11(const QList<Struct1>& prop11)
{
    if (m_prop11 != prop11) {
        m_prop11 = prop11;
        emit prop11Changed(prop11);
        Interface1Agent::trace_state(this);
    }
}

QList<Struct1> Interface1::prop11() const
{
    return m_prop11;
}

void Interface1::setProp12(const QList<Enum1::Enum1Enum>& prop12)
{
    if (m_prop12 != prop12) {
        m_prop12 = prop12;
        emit prop12Changed(prop12);
        Interface1Agent::trace_state(this);
    }
}

QList<Enum1::Enum1Enum> Interface1::prop12() const
{
    return m_prop12;
}

void Interface1::setProp14(const QList<Struct1>& prop14)
{
    if (m_prop14 != prop14) {
        m_prop14 = prop14;
        emit prop14Changed(prop14);
        Interface1Agent::trace_state(this);
    }
}

QList<Struct1> Interface1::prop14() const
{
    return m_prop14;
}

void Interface1::op1()
{
    qDebug() << Q_FUNC_INFO;
    Interface1Agent::trace_op1(this);
    return ;
}

void Interface1::op2(int step)
{
    qDebug() << Q_FUNC_INFO;
    Interface1Agent::trace_op2(this, step);
    return ;
}

int Interface1::op3()
{
    qDebug() << Q_FUNC_INFO;
    Interface1Agent::trace_op3(this);
    return 0;
}

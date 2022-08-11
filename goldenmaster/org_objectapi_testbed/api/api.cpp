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
#include "api.h"
// ********************************************************************
// Enumeration Enum1
// ********************************************************************
Enum1::Enum1Enum Enum1::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 0: return Enum1::Member1;
        case 1: return Enum1::Member2;
        case 2: return Enum1::Member3;
        case 3: return Enum1::Member4;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum1::Member1;
    }
}
// ********************************************************************
// Enumeration Enum2
// ********************************************************************
Enum2::Enum2Enum Enum2::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 0: return Enum2::Member1;
        case 1: return Enum2::Member2;
        case 2: return Enum2::Member3;
        case 3: return Enum2::Member4;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum2::Member1;
    }
}
// ********************************************************************
// Struct Struct1
// ********************************************************************

Struct1::Struct1()
    : m_field1(false)    , m_field2(0)    , m_field3(0.0)    , m_field4(QString())
{
}

void Struct1::setField1(bool field1)
{
  m_field1 = field1;
}

bool Struct1::field1() const
{
  return m_field1;
}

void Struct1::setField2(int field2)
{
  m_field2 = field2;
}

int Struct1::field2() const
{
  return m_field2;
}

void Struct1::setField3(qreal field3)
{
  m_field3 = field3;
}

qreal Struct1::field3() const
{
  return m_field3;
}

void Struct1::setField4(const QString& field4)
{
  m_field4 = field4;
}

QString Struct1::field4() const
{
  return m_field4;
}

bool Struct1::operator==(const Struct1 &other) const
{
    return (
        field1() == other.field1() &&
        field2() == other.field2() &&
        field3() == other.field3() &&
        field4() == other.field4()
    );
}

bool Struct1::operator!=(const Struct1 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Struct1 &obj)
{
    stream << obj.field1();
    stream << obj.field2();
    stream << obj.field3();
    stream << obj.field4();

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Struct1 &obj)
{
    bool field1Value;
    stream >> field1Value;
    obj.setField1(field1Value);
    int field2Value;
    stream >> field2Value;
    obj.setField2(field2Value);
    qreal field3Value;
    stream >> field3Value;
    obj.setField3(field3Value);
    QString field4Value;
    stream >> field4Value;
    obj.setField4(field4Value);
    return stream;
}

// ********************************************************************
// Struct Factory Struct1
// ********************************************************************

Struct1 Struct1Factory::create()
{
    return Struct1();
}

// ********************************************************************
// AbstractInterface1 abstract interface
// ********************************************************************

AbstractInterface1::AbstractInterface1(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractInterface2 abstract interface
// ********************************************************************

AbstractInterface2::AbstractInterface2(QObject *parent)
    : QObject(parent)
{
}

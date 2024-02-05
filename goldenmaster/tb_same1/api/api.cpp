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

namespace tb_same1 {
// ********************************************************************
// Enumeration Enum1
// ********************************************************************
Enum1::Enum1Enum Enum1::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 1: return Enum1::Value1;
        case 2: return Enum1::Value2;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum1::Value1;
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
        case 1: return Enum2::Value1;
        case 2: return Enum2::Value2;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum2::Value1;
    }
}
// ********************************************************************
// Struct Struct1
// ********************************************************************

Struct1::Struct1()
    : m_field1(0)    , m_field2(0)    , m_field3(0)
{
}

bool Struct1::operator==(const Struct1 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2 &&
        m_field3 == other.m_field3
    );
}

bool Struct1::operator!=(const Struct1 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Struct1 &obj)
{
    stream << obj.m_field1;
    stream << obj.m_field2;
    stream << obj.m_field3;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Struct1 &obj)
{
    int field1Value;
    stream >> field1Value;
    obj.m_field1 = field1Value;
    int field2Value;
    stream >> field2Value;
    obj.m_field2 = field2Value;
    int field3Value;
    stream >> field3Value;
    obj.m_field3 = field3Value;
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
// Struct Struct2
// ********************************************************************

Struct2::Struct2()
    : m_field1(0)    , m_field2(0)    , m_field3(0)
{
}

bool Struct2::operator==(const Struct2 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2 &&
        m_field3 == other.m_field3
    );
}

bool Struct2::operator!=(const Struct2 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Struct2 &obj)
{
    stream << obj.m_field1;
    stream << obj.m_field2;
    stream << obj.m_field3;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Struct2 &obj)
{
    int field1Value;
    stream >> field1Value;
    obj.m_field1 = field1Value;
    int field2Value;
    stream >> field2Value;
    obj.m_field2 = field2Value;
    int field3Value;
    stream >> field3Value;
    obj.m_field3 = field3Value;
    return stream;
}

// ********************************************************************
// Struct Factory Struct2
// ********************************************************************

Struct2 Struct2Factory::create()
{
    return Struct2();
}

// ********************************************************************
// AbstractSameStruct1Interface abstract interface
// ********************************************************************

AbstractSameStruct1Interface::AbstractSameStruct1Interface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractSameStruct2Interface abstract interface
// ********************************************************************

AbstractSameStruct2Interface::AbstractSameStruct2Interface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractSameEnum1Interface abstract interface
// ********************************************************************

AbstractSameEnum1Interface::AbstractSameEnum1Interface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractSameEnum2Interface abstract interface
// ********************************************************************

AbstractSameEnum2Interface::AbstractSameEnum2Interface(QObject *parent)
    : QObject(parent)
{
}

} // namespace tb_same1

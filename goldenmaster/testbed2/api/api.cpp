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

namespace testbed2 {
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
        case 3: return Enum1::Value3;
        case 4: return Enum1::Value4;
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
        case 3: return Enum2::Value3;
        case 4: return Enum2::Value4;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum2::Value1;
    }
}
// ********************************************************************
// Enumeration Enum3
// ********************************************************************
Enum3::Enum3Enum Enum3::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 1: return Enum3::Value1;
        case 2: return Enum3::Value2;
        case 3: return Enum3::Value3;
        case 4: return Enum3::Value4;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum3::Value1;
    }
}
// ********************************************************************
// Struct Struct1
// ********************************************************************

Struct1::Struct1()
    : m_field1(0)
{
}

bool Struct1::operator==(const Struct1 &other) const
{
    return (
        m_field1 == other.m_field1
    );
}

bool Struct1::operator!=(const Struct1 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Struct1 &obj)
{
    stream << obj.m_field1;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Struct1 &obj)
{
    int field1Value;
    stream >> field1Value;
    obj.m_field1 = field1Value;
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
    : m_field1(0)    , m_field2(0)
{
}

bool Struct2::operator==(const Struct2 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2
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
// Struct Struct3
// ********************************************************************

Struct3::Struct3()
    : m_field1(0)    , m_field2(0)    , m_field3(0)
{
}

bool Struct3::operator==(const Struct3 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2 &&
        m_field3 == other.m_field3
    );
}

bool Struct3::operator!=(const Struct3 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Struct3 &obj)
{
    stream << obj.m_field1;
    stream << obj.m_field2;
    stream << obj.m_field3;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Struct3 &obj)
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
// Struct Factory Struct3
// ********************************************************************

Struct3 Struct3Factory::create()
{
    return Struct3();
}
// ********************************************************************
// Struct Struct4
// ********************************************************************

Struct4::Struct4()
    : m_field1(0)    , m_field2(0)    , m_field3(0)    , m_field4(0)
{
}

bool Struct4::operator==(const Struct4 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2 &&
        m_field3 == other.m_field3 &&
        m_field4 == other.m_field4
    );
}

bool Struct4::operator!=(const Struct4 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Struct4 &obj)
{
    stream << obj.m_field1;
    stream << obj.m_field2;
    stream << obj.m_field3;
    stream << obj.m_field4;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Struct4 &obj)
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
    int field4Value;
    stream >> field4Value;
    obj.m_field4 = field4Value;
    return stream;
}

// ********************************************************************
// Struct Factory Struct4
// ********************************************************************

Struct4 Struct4Factory::create()
{
    return Struct4();
}
// ********************************************************************
// Struct NestedStruct1
// ********************************************************************

NestedStruct1::NestedStruct1()
    : m_field1(Struct1())
{
}

bool NestedStruct1::operator==(const NestedStruct1 &other) const
{
    return (
        m_field1 == other.m_field1
    );
}

bool NestedStruct1::operator!=(const NestedStruct1 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const NestedStruct1 &obj)
{
    stream << obj.m_field1;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, NestedStruct1 &obj)
{
    Struct1 field1Value;
    stream >> field1Value;
    obj.m_field1 = field1Value;
    return stream;
}

// ********************************************************************
// Struct Factory NestedStruct1
// ********************************************************************

NestedStruct1 NestedStruct1Factory::create()
{
    return NestedStruct1();
}
// ********************************************************************
// Struct NestedStruct2
// ********************************************************************

NestedStruct2::NestedStruct2()
    : m_field1(Struct1())    , m_field2(Struct2())
{
}

bool NestedStruct2::operator==(const NestedStruct2 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2
    );
}

bool NestedStruct2::operator!=(const NestedStruct2 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const NestedStruct2 &obj)
{
    stream << obj.m_field1;
    stream << obj.m_field2;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, NestedStruct2 &obj)
{
    Struct1 field1Value;
    stream >> field1Value;
    obj.m_field1 = field1Value;
    Struct2 field2Value;
    stream >> field2Value;
    obj.m_field2 = field2Value;
    return stream;
}

// ********************************************************************
// Struct Factory NestedStruct2
// ********************************************************************

NestedStruct2 NestedStruct2Factory::create()
{
    return NestedStruct2();
}
// ********************************************************************
// Struct NestedStruct3
// ********************************************************************

NestedStruct3::NestedStruct3()
    : m_field1(Struct1())    , m_field2(Struct2())    , m_field3(Struct3())
{
}

bool NestedStruct3::operator==(const NestedStruct3 &other) const
{
    return (
        m_field1 == other.m_field1 &&
        m_field2 == other.m_field2 &&
        m_field3 == other.m_field3
    );
}

bool NestedStruct3::operator!=(const NestedStruct3 &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const NestedStruct3 &obj)
{
    stream << obj.m_field1;
    stream << obj.m_field2;
    stream << obj.m_field3;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, NestedStruct3 &obj)
{
    Struct1 field1Value;
    stream >> field1Value;
    obj.m_field1 = field1Value;
    Struct2 field2Value;
    stream >> field2Value;
    obj.m_field2 = field2Value;
    Struct3 field3Value;
    stream >> field3Value;
    obj.m_field3 = field3Value;
    return stream;
}

// ********************************************************************
// Struct Factory NestedStruct3
// ********************************************************************

NestedStruct3 NestedStruct3Factory::create()
{
    return NestedStruct3();
}

// ********************************************************************
// AbstractManyParamInterface abstract interface
// ********************************************************************

AbstractManyParamInterface::AbstractManyParamInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractNestedStruct1Interface abstract interface
// ********************************************************************

AbstractNestedStruct1Interface::AbstractNestedStruct1Interface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractNestedStruct2Interface abstract interface
// ********************************************************************

AbstractNestedStruct2Interface::AbstractNestedStruct2Interface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractNestedStruct3Interface abstract interface
// ********************************************************************

AbstractNestedStruct3Interface::AbstractNestedStruct3Interface(QObject *parent)
    : QObject(parent)
{
}

} // namespace testbed2

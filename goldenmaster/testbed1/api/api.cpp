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

namespace testbed1 {
// ********************************************************************
// Struct StructBool
// ********************************************************************

StructBool::StructBool()
    : m_fieldBool(false)
{
}

bool StructBool::operator==(const StructBool &other) const
{
    return (
        m_fieldBool == other.m_fieldBool
    );
}

bool StructBool::operator!=(const StructBool &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructBool &obj)
{
    stream << obj.m_fieldBool;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructBool &obj)
{
    bool fieldBoolValue;
    stream >> fieldBoolValue;
    obj.m_fieldBool = fieldBoolValue;
    return stream;
}

// ********************************************************************
// Struct Factory StructBool
// ********************************************************************

StructBool StructBoolFactory::create()
{
    return StructBool();
}
// ********************************************************************
// Struct StructInt
// ********************************************************************

StructInt::StructInt()
    : m_fieldInt(0)
{
}

bool StructInt::operator==(const StructInt &other) const
{
    return (
        m_fieldInt == other.m_fieldInt
    );
}

bool StructInt::operator!=(const StructInt &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructInt &obj)
{
    stream << obj.m_fieldInt;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructInt &obj)
{
    int fieldIntValue;
    stream >> fieldIntValue;
    obj.m_fieldInt = fieldIntValue;
    return stream;
}

// ********************************************************************
// Struct Factory StructInt
// ********************************************************************

StructInt StructIntFactory::create()
{
    return StructInt();
}
// ********************************************************************
// Struct StructFloat
// ********************************************************************

StructFloat::StructFloat()
    : m_fieldFloat(0.0)
{
}

bool StructFloat::operator==(const StructFloat &other) const
{
    return (
        m_fieldFloat == other.m_fieldFloat
    );
}

bool StructFloat::operator!=(const StructFloat &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructFloat &obj)
{
    stream << obj.m_fieldFloat;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructFloat &obj)
{
    qreal fieldFloatValue;
    stream >> fieldFloatValue;
    obj.m_fieldFloat = fieldFloatValue;
    return stream;
}

// ********************************************************************
// Struct Factory StructFloat
// ********************************************************************

StructFloat StructFloatFactory::create()
{
    return StructFloat();
}
// ********************************************************************
// Struct StructString
// ********************************************************************

StructString::StructString()
    : m_fieldString(QString())
{
}

bool StructString::operator==(const StructString &other) const
{
    return (
        m_fieldString == other.m_fieldString
    );
}

bool StructString::operator!=(const StructString &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructString &obj)
{
    stream << obj.m_fieldString;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructString &obj)
{
    QString fieldStringValue;
    stream >> fieldStringValue;
    obj.m_fieldString = fieldStringValue;
    return stream;
}

// ********************************************************************
// Struct Factory StructString
// ********************************************************************

StructString StructStringFactory::create()
{
    return StructString();
}

// ********************************************************************
// AbstractStructInterface abstract interface
// ********************************************************************

AbstractStructInterface::AbstractStructInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractStructArrayInterface abstract interface
// ********************************************************************

AbstractStructArrayInterface::AbstractStructArrayInterface(QObject *parent)
    : QObject(parent)
{
}

} // namespace testbed1

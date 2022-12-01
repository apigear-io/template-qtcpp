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

void StructBool::setFieldBool(bool fieldBool)
{
  m_fieldBool = fieldBool;
}

bool StructBool::fieldBool() const
{
  return m_fieldBool;
}

bool StructBool::operator==(const StructBool &other) const
{
    return (
        fieldBool() == other.fieldBool()
    );
}

bool StructBool::operator!=(const StructBool &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructBool &obj)
{
    stream << obj.fieldBool();

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructBool &obj)
{
    bool fieldBoolValue;
    stream >> fieldBoolValue;
    obj.setFieldBool(fieldBoolValue);
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

void StructInt::setFieldInt(int fieldInt)
{
  m_fieldInt = fieldInt;
}

int StructInt::fieldInt() const
{
  return m_fieldInt;
}

bool StructInt::operator==(const StructInt &other) const
{
    return (
        fieldInt() == other.fieldInt()
    );
}

bool StructInt::operator!=(const StructInt &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructInt &obj)
{
    stream << obj.fieldInt();

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructInt &obj)
{
    int fieldIntValue;
    stream >> fieldIntValue;
    obj.setFieldInt(fieldIntValue);
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

void StructFloat::setFieldFloat(qreal fieldFloat)
{
  m_fieldFloat = fieldFloat;
}

qreal StructFloat::fieldFloat() const
{
  return m_fieldFloat;
}

bool StructFloat::operator==(const StructFloat &other) const
{
    return (
        fieldFloat() == other.fieldFloat()
    );
}

bool StructFloat::operator!=(const StructFloat &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructFloat &obj)
{
    stream << obj.fieldFloat();

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructFloat &obj)
{
    qreal fieldFloatValue;
    stream >> fieldFloatValue;
    obj.setFieldFloat(fieldFloatValue);
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

void StructString::setFieldString(const QString& fieldString)
{
  m_fieldString = fieldString;
}

QString StructString::fieldString() const
{
  return m_fieldString;
}

bool StructString::operator==(const StructString &other) const
{
    return (
        fieldString() == other.fieldString()
    );
}

bool StructString::operator!=(const StructString &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const StructString &obj)
{
    stream << obj.fieldString();

    return stream;
}

QDataStream &operator>>(QDataStream &stream, StructString &obj)
{
    QString fieldStringValue;
    stream >> fieldStringValue;
    obj.setFieldString(fieldStringValue);
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

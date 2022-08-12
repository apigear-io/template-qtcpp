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


#include "structarrayinterface.h"

#include <QtQml>

#include "../api/agent.h"

StructArrayInterface::StructArrayInterface(QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
{
}

StructArrayInterface::~StructArrayInterface()
{
}

void StructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructBool> StructArrayInterface::propBool() const
{
    return m_propBool;
}

void StructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructInt> StructArrayInterface::propInt() const
{
    return m_propInt;
}

void StructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructFloat> StructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void StructArrayInterface::setPropString(const QList<StructString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructString> StructArrayInterface::propString() const
{
    return m_propString;
}

StructBool StructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    StructArrayInterfaceAgent::trace_funcBool(this, paramBool);
    return StructBool();
}

StructBool StructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    StructArrayInterfaceAgent::trace_funcInt(this, paramInt);
    return StructBool();
}

StructBool StructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    StructArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
    return StructBool();
}

StructBool StructArrayInterface::funcString(const QList<StructString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    StructArrayInterfaceAgent::trace_funcString(this, paramString);
    return StructBool();
}

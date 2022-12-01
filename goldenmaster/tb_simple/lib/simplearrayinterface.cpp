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


#include "simplearrayinterface.h"

#include <QtQml>

#include "tb_simple/api/agent.h"

SimpleArrayInterface::SimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propFloat(QList<qreal>())
    , m_propString(QList<QString>())
{
}

SimpleArrayInterface::~SimpleArrayInterface()
{
}

void SimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<bool> SimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void SimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<int> SimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void SimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<qreal> SimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void SimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<QString> SimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> SimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    SimpleArrayInterfaceAgent::trace_funcBool(this, paramBool);
    return QList<bool>();
}

QList<int> SimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    SimpleArrayInterfaceAgent::trace_funcInt(this, paramInt);
    return QList<int>();
}

QList<qreal> SimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    SimpleArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
    return QList<qreal>();
}

QList<QString> SimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    SimpleArrayInterfaceAgent::trace_funcString(this, paramString);
    return QList<QString>();
}

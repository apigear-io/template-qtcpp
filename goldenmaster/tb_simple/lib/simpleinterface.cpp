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


#include "simpleinterface.h"

#include <QtQml>

#include "tb_simple/api/agent.h"

SimpleInterface::SimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propFloat(0.0)
    , m_propString(QString())
{
}

SimpleInterface::~SimpleInterface()
{
}

void SimpleInterface::setPropBool(bool propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleInterfaceAgent::trace_state(this);
    }
}

bool SimpleInterface::propBool() const
{
    return m_propBool;
}

void SimpleInterface::setPropInt(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleInterfaceAgent::trace_state(this);
    }
}

int SimpleInterface::propInt() const
{
    return m_propInt;
}

void SimpleInterface::setPropFloat(qreal propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleInterfaceAgent::trace_state(this);
    }
}

qreal SimpleInterface::propFloat() const
{
    return m_propFloat;
}

void SimpleInterface::setPropString(const QString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleInterfaceAgent::trace_state(this);
    }
}

QString SimpleInterface::propString() const
{
    return m_propString;
}

bool SimpleInterface::funcBool(bool paramBool)
{
    qDebug() << Q_FUNC_INFO;
    SimpleInterfaceAgent::trace_funcBool(this, paramBool);
    return false;
}

int SimpleInterface::funcInt(int paramInt)
{
    qDebug() << Q_FUNC_INFO;
    SimpleInterfaceAgent::trace_funcInt(this, paramInt);
    return 0;
}

qreal SimpleInterface::funcFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    SimpleInterfaceAgent::trace_funcFloat(this, paramFloat);
    return 0.0;
}

QString SimpleInterface::funcString(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    SimpleInterfaceAgent::trace_funcString(this, paramString);
    return QString();
}

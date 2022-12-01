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


#include "qmlsimplearrayinterface.h"
#include "tb_simple/api/apifactory.h"
#include "tb_simple/api/agent.h"

#include <QtQml>

QmlSimpleArrayInterface::QmlSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
{
    m_obj = ApiFactory::get()->createSimpleArrayInterface(this);
    connect(m_obj, &AbstractSimpleArrayInterface::propBoolChanged, this, &QmlSimpleArrayInterface::propBoolChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propBoolChanged, this, &AbstractSimpleArrayInterface::propBoolChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propIntChanged, this, &QmlSimpleArrayInterface::propIntChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propIntChanged, this, &AbstractSimpleArrayInterface::propIntChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propFloatChanged, this, &QmlSimpleArrayInterface::propFloatChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propFloatChanged, this, &AbstractSimpleArrayInterface::propFloatChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propStringChanged, this, &QmlSimpleArrayInterface::propStringChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::propStringChanged, this, &AbstractSimpleArrayInterface::propStringChanged);
    connect(m_obj, &AbstractSimpleArrayInterface::sigBool, this, &QmlSimpleArrayInterface::sigBool);
    connect(m_obj, &AbstractSimpleArrayInterface::sigBool, this, &AbstractSimpleArrayInterface::sigBool);
    connect(m_obj, &AbstractSimpleArrayInterface::sigInt, this, &QmlSimpleArrayInterface::sigInt);
    connect(m_obj, &AbstractSimpleArrayInterface::sigInt, this, &AbstractSimpleArrayInterface::sigInt);
    connect(m_obj, &AbstractSimpleArrayInterface::sigFloat, this, &QmlSimpleArrayInterface::sigFloat);
    connect(m_obj, &AbstractSimpleArrayInterface::sigFloat, this, &AbstractSimpleArrayInterface::sigFloat);
    connect(m_obj, &AbstractSimpleArrayInterface::sigString, this, &QmlSimpleArrayInterface::sigString);
    connect(m_obj, &AbstractSimpleArrayInterface::sigString, this, &AbstractSimpleArrayInterface::sigString);
}

QmlSimpleArrayInterface::~QmlSimpleArrayInterface()
{
}

QList<bool> QmlSimpleArrayInterface::propBool() const
{
    return m_obj->propBool();
}

void QmlSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    SimpleArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropBool(propBool);
}

QList<int> QmlSimpleArrayInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    SimpleArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropInt(propInt);
}

QList<qreal> QmlSimpleArrayInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    SimpleArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropFloat(propFloat);
}

QList<QString> QmlSimpleArrayInterface::propString() const
{
    return m_obj->propString();
}

void QmlSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    SimpleArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropString(propString);
}

QList<bool> QmlSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    SimpleArrayInterfaceAgent::trace_funcBool(this, paramBool);
	
    return m_obj->funcBool(paramBool);
}

QList<int> QmlSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    SimpleArrayInterfaceAgent::trace_funcInt(this, paramInt);
	
    return m_obj->funcInt(paramInt);
}

QList<qreal> QmlSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    SimpleArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
	
    return m_obj->funcFloat(paramFloat);
}

QList<QString> QmlSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    SimpleArrayInterfaceAgent::trace_funcString(this, paramString);
	
    return m_obj->funcString(paramString);
}
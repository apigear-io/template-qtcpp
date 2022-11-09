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


#include "qmlstructinterface.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

QmlStructInterface::QmlStructInterface(QObject *parent)
    : AbstractStructInterface(parent)
{
    m_obj = ApiFactory::get()->createStructInterface(this);
    connect(m_obj, &AbstractStructInterface::propBoolChanged, this, &QmlStructInterface::propBoolChanged);
    connect(m_obj, &AbstractStructInterface::propBoolChanged, this, &AbstractStructInterface::propBoolChanged);
    connect(m_obj, &AbstractStructInterface::propIntChanged, this, &QmlStructInterface::propIntChanged);
    connect(m_obj, &AbstractStructInterface::propIntChanged, this, &AbstractStructInterface::propIntChanged);
    connect(m_obj, &AbstractStructInterface::propFloatChanged, this, &QmlStructInterface::propFloatChanged);
    connect(m_obj, &AbstractStructInterface::propFloatChanged, this, &AbstractStructInterface::propFloatChanged);
    connect(m_obj, &AbstractStructInterface::propStringChanged, this, &QmlStructInterface::propStringChanged);
    connect(m_obj, &AbstractStructInterface::propStringChanged, this, &AbstractStructInterface::propStringChanged);
    connect(m_obj, &AbstractStructInterface::sigBool, this, &QmlStructInterface::sigBool);
    connect(m_obj, &AbstractStructInterface::sigBool, this, &AbstractStructInterface::sigBool);
    connect(m_obj, &AbstractStructInterface::sigInt, this, &QmlStructInterface::sigInt);
    connect(m_obj, &AbstractStructInterface::sigInt, this, &AbstractStructInterface::sigInt);
    connect(m_obj, &AbstractStructInterface::sigFloat, this, &QmlStructInterface::sigFloat);
    connect(m_obj, &AbstractStructInterface::sigFloat, this, &AbstractStructInterface::sigFloat);
    connect(m_obj, &AbstractStructInterface::sigString, this, &QmlStructInterface::sigString);
    connect(m_obj, &AbstractStructInterface::sigString, this, &AbstractStructInterface::sigString);
}

QmlStructInterface::~QmlStructInterface()
{
}

StructBool QmlStructInterface::propBool() const
{
    return m_obj->propBool();
}

void QmlStructInterface::setPropBool(const StructBool& propBool)
{
    StructInterfaceAgent::capture_state(this);
    return m_obj->setPropBool(propBool);
}

StructInt QmlStructInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlStructInterface::setPropInt(const StructInt& propInt)
{
    StructInterfaceAgent::capture_state(this);
    return m_obj->setPropInt(propInt);
}

StructFloat QmlStructInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlStructInterface::setPropFloat(const StructFloat& propFloat)
{
    StructInterfaceAgent::capture_state(this);
    return m_obj->setPropFloat(propFloat);
}

StructString QmlStructInterface::propString() const
{
    return m_obj->propString();
}

void QmlStructInterface::setPropString(const StructString& propString)
{
    StructInterfaceAgent::capture_state(this);
    return m_obj->setPropString(propString);
}

StructBool QmlStructInterface::funcBool(const StructBool& paramBool)
{
    StructInterfaceAgent::trace_funcBool(this, paramBool);
	
    return m_obj->funcBool(paramBool);
}

StructBool QmlStructInterface::funcInt(const StructInt& paramInt)
{
    StructInterfaceAgent::trace_funcInt(this, paramInt);
	
    return m_obj->funcInt(paramInt);
}

StructFloat QmlStructInterface::funcFloat(const StructFloat& paramFloat)
{
    StructInterfaceAgent::trace_funcFloat(this, paramFloat);
	
    return m_obj->funcFloat(paramFloat);
}

StructString QmlStructInterface::funcString(const StructString& paramString)
{
    StructInterfaceAgent::trace_funcString(this, paramString);
	
    return m_obj->funcString(paramString);
}
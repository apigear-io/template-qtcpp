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


#include "qmlstructarrayinterface.h"
#include "testbed1/api/apifactory.h"
#include "testbed1/api/agent.h"

#include <QtQml>

namespace testbed1 {

QmlStructArrayInterface::QmlStructArrayInterface(QObject *parent)
    : AbstractStructArrayInterface(parent)
{
    m_obj = ApiFactory::get()->createStructArrayInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlStructArrayInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractStructArrayInterface::Property Changed signal
    // for usage, where QmlStructArrayInterface is used by the AbstractTuner interface and for connections with AbstractStructArrayInterface::Property Changed signal
    connect(m_obj.get(), &AbstractStructArrayInterface::propBoolChanged, this, &QmlStructArrayInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propBoolChanged, this, &AbstractStructArrayInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propIntChanged, this, &QmlStructArrayInterface::propIntChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propIntChanged, this, &AbstractStructArrayInterface::propIntChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propFloatChanged, this, &QmlStructArrayInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propFloatChanged, this, &AbstractStructArrayInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propStringChanged, this, &QmlStructArrayInterface::propStringChanged);
    connect(m_obj.get(), &AbstractStructArrayInterface::propStringChanged, this, &AbstractStructArrayInterface::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlStructArrayInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlStructArrayInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractStructArrayInterface::sigBool, this, &AbstractStructArrayInterface::sigBool);
    connect(m_obj.get(), &AbstractStructArrayInterface::sigInt, this, &AbstractStructArrayInterface::sigInt);
    connect(m_obj.get(), &AbstractStructArrayInterface::sigFloat, this, &AbstractStructArrayInterface::sigFloat);
    connect(m_obj.get(), &AbstractStructArrayInterface::sigString, this, &AbstractStructArrayInterface::sigString);
}

QmlStructArrayInterface::~QmlStructArrayInterface()
{
}

QList<StructBool> QmlStructArrayInterface::propBool() const
{
    return m_obj->propBool();
}

void QmlStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    StructArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropBool(propBool);
}

QList<StructInt> QmlStructArrayInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    StructArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropInt(propInt);
}

QList<StructFloat> QmlStructArrayInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    StructArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropFloat(propFloat);
}

QList<StructString> QmlStructArrayInterface::propString() const
{
    return m_obj->propString();
}

void QmlStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    StructArrayInterfaceAgent::capture_state(this);
    return m_obj->setPropString(propString);
}

StructBool QmlStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    StructArrayInterfaceAgent::trace_funcBool(this, paramBool);
	
    return m_obj->funcBool(paramBool);
}

StructBool QmlStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    StructArrayInterfaceAgent::trace_funcInt(this, paramInt);
	
    return m_obj->funcInt(paramInt);
}

StructBool QmlStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    StructArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
	
    return m_obj->funcFloat(paramFloat);
}

StructBool QmlStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    StructArrayInterfaceAgent::trace_funcString(this, paramString);
	
    return m_obj->funcString(paramString);
}

} //namespace testbed1

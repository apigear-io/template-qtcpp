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


#include "qmlsimpleinterface.h"
#include "tb_simple/api/apifactory.h"
#include "tb_simple/api/agent.h"

#include <QtQml>

namespace tb_simple {

QmlSimpleInterface::QmlSimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
{
    m_obj = ApiFactory::get()->createSimpleInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlSimpleInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractSimpleInterface::Property Changed signal
    // for usage, where QmlSimpleInterface is used by the AbstractTuner interface and for connections with AbstractSimpleInterface::Property Changed signal
    connect(m_obj.get(), &AbstractSimpleInterface::propBoolChanged, this, &QmlSimpleInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propBoolChanged, this, &AbstractSimpleInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propIntChanged, this, &QmlSimpleInterface::propIntChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propIntChanged, this, &AbstractSimpleInterface::propIntChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloatChanged, this, &QmlSimpleInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloatChanged, this, &AbstractSimpleInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propStringChanged, this, &QmlSimpleInterface::propStringChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propStringChanged, this, &AbstractSimpleInterface::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlSimpleInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlSimpleInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractSimpleInterface::sigBool, this, &AbstractSimpleInterface::sigBool);
    connect(m_obj.get(), &AbstractSimpleInterface::sigInt, this, &AbstractSimpleInterface::sigInt);
    connect(m_obj.get(), &AbstractSimpleInterface::sigFloat, this, &AbstractSimpleInterface::sigFloat);
    connect(m_obj.get(), &AbstractSimpleInterface::sigString, this, &AbstractSimpleInterface::sigString);
}

QmlSimpleInterface::~QmlSimpleInterface()
{
}

bool QmlSimpleInterface::propBool() const
{
    return m_obj->propBool();
}

void QmlSimpleInterface::setPropBool(bool propBool)
{
    SimpleInterfaceAgent::capture_state(this);
    return m_obj->setPropBool(propBool);
}

int QmlSimpleInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlSimpleInterface::setPropInt(int propInt)
{
    SimpleInterfaceAgent::capture_state(this);
    return m_obj->setPropInt(propInt);
}

qreal QmlSimpleInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlSimpleInterface::setPropFloat(qreal propFloat)
{
    SimpleInterfaceAgent::capture_state(this);
    return m_obj->setPropFloat(propFloat);
}

QString QmlSimpleInterface::propString() const
{
    return m_obj->propString();
}

void QmlSimpleInterface::setPropString(const QString& propString)
{
    SimpleInterfaceAgent::capture_state(this);
    return m_obj->setPropString(propString);
}

bool QmlSimpleInterface::funcBool(bool paramBool)
{
    SimpleInterfaceAgent::trace_funcBool(this, paramBool);
	
    return m_obj->funcBool(paramBool);
}

int QmlSimpleInterface::funcInt(int paramInt)
{
    SimpleInterfaceAgent::trace_funcInt(this, paramInt);
	
    return m_obj->funcInt(paramInt);
}

qreal QmlSimpleInterface::funcFloat(qreal paramFloat)
{
    SimpleInterfaceAgent::trace_funcFloat(this, paramFloat);
	
    return m_obj->funcFloat(paramFloat);
}

QString QmlSimpleInterface::funcString(const QString& paramString)
{
    SimpleInterfaceAgent::trace_funcString(this, paramString);
	
    return m_obj->funcString(paramString);
}

} //namespace tb_simple

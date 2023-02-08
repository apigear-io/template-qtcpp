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
#include "testbed1/api/apifactory.h"

#include <QtQml>

namespace testbed1 {

QmlStructInterface::QmlStructInterface(QObject *parent)
    : AbstractStructInterface(parent)
{
    m_obj = ApiFactory::get()->createStructInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlStructInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractStructInterface::Property Changed signal
    // for usage, where QmlStructInterface is used by the AbstractTuner interface and for connections with AbstractStructInterface::Property Changed signal
    connect(m_obj.get(), &AbstractStructInterface::propBoolChanged, this, &QmlStructInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractStructInterface::propBoolChanged, this, &AbstractStructInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractStructInterface::propIntChanged, this, &QmlStructInterface::propIntChanged);
    connect(m_obj.get(), &AbstractStructInterface::propIntChanged, this, &AbstractStructInterface::propIntChanged);
    connect(m_obj.get(), &AbstractStructInterface::propFloatChanged, this, &QmlStructInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractStructInterface::propFloatChanged, this, &AbstractStructInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractStructInterface::propStringChanged, this, &QmlStructInterface::propStringChanged);
    connect(m_obj.get(), &AbstractStructInterface::propStringChanged, this, &AbstractStructInterface::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlStructInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlStructInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractStructInterface::sigBool, this, &AbstractStructInterface::sigBool);
    connect(m_obj.get(), &AbstractStructInterface::sigInt, this, &AbstractStructInterface::sigInt);
    connect(m_obj.get(), &AbstractStructInterface::sigFloat, this, &AbstractStructInterface::sigFloat);
    connect(m_obj.get(), &AbstractStructInterface::sigString, this, &AbstractStructInterface::sigString);
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
    return m_obj->setPropBool(propBool);
}

StructInt QmlStructInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlStructInterface::setPropInt(const StructInt& propInt)
{
    return m_obj->setPropInt(propInt);
}

StructFloat QmlStructInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlStructInterface::setPropFloat(const StructFloat& propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

StructString QmlStructInterface::propString() const
{
    return m_obj->propString();
}

void QmlStructInterface::setPropString(const StructString& propString)
{
    return m_obj->setPropString(propString);
}

StructBool QmlStructInterface::funcBool(const StructBool& paramBool)
{
    return m_obj->funcBool(paramBool);
}

StructBool QmlStructInterface::funcInt(const StructInt& paramInt)
{
    return m_obj->funcInt(paramInt);
}

StructFloat QmlStructInterface::funcFloat(const StructFloat& paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

StructString QmlStructInterface::funcString(const StructString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace testbed1

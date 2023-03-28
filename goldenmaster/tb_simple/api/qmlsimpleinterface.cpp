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
#include "apifactory.h"

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
    connect(m_obj.get(), &AbstractSimpleInterface::propInt32Changed, this, &QmlSimpleInterface::propInt32Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propInt32Changed, this, &AbstractSimpleInterface::propInt32Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propInt64Changed, this, &QmlSimpleInterface::propInt64Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propInt64Changed, this, &AbstractSimpleInterface::propInt64Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloatChanged, this, &QmlSimpleInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloatChanged, this, &AbstractSimpleInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloat32Changed, this, &QmlSimpleInterface::propFloat32Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloat32Changed, this, &AbstractSimpleInterface::propFloat32Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloat64Changed, this, &QmlSimpleInterface::propFloat64Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propFloat64Changed, this, &AbstractSimpleInterface::propFloat64Changed);
    connect(m_obj.get(), &AbstractSimpleInterface::propStringChanged, this, &QmlSimpleInterface::propStringChanged);
    connect(m_obj.get(), &AbstractSimpleInterface::propStringChanged, this, &AbstractSimpleInterface::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlSimpleInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlSimpleInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractSimpleInterface::sigVoid, this, &AbstractSimpleInterface::sigVoid);
    connect(m_obj.get(), &AbstractSimpleInterface::sigBool, this, &AbstractSimpleInterface::sigBool);
    connect(m_obj.get(), &AbstractSimpleInterface::sigInt, this, &AbstractSimpleInterface::sigInt);
    connect(m_obj.get(), &AbstractSimpleInterface::sigInt32, this, &AbstractSimpleInterface::sigInt32);
    connect(m_obj.get(), &AbstractSimpleInterface::sigInt64, this, &AbstractSimpleInterface::sigInt64);
    connect(m_obj.get(), &AbstractSimpleInterface::sigFloat, this, &AbstractSimpleInterface::sigFloat);
    connect(m_obj.get(), &AbstractSimpleInterface::sigFloat32, this, &AbstractSimpleInterface::sigFloat32);
    connect(m_obj.get(), &AbstractSimpleInterface::sigFloat64, this, &AbstractSimpleInterface::sigFloat64);
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
    return m_obj->setPropBool(propBool);
}

int QmlSimpleInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlSimpleInterface::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qint32 QmlSimpleInterface::propInt32() const
{
    return m_obj->propInt32();
}

void QmlSimpleInterface::setPropInt32(qint32 propInt32)
{
    return m_obj->setPropInt32(propInt32);
}

qint64 QmlSimpleInterface::propInt64() const
{
    return m_obj->propInt64();
}

void QmlSimpleInterface::setPropInt64(qint64 propInt64)
{
    return m_obj->setPropInt64(propInt64);
}

qreal QmlSimpleInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlSimpleInterface::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

float QmlSimpleInterface::propFloat32() const
{
    return m_obj->propFloat32();
}

void QmlSimpleInterface::setPropFloat32(float propFloat32)
{
    return m_obj->setPropFloat32(propFloat32);
}

double QmlSimpleInterface::propFloat64() const
{
    return m_obj->propFloat64();
}

void QmlSimpleInterface::setPropFloat64(double propFloat64)
{
    return m_obj->setPropFloat64(propFloat64);
}

QString QmlSimpleInterface::propString() const
{
    return m_obj->propString();
}

void QmlSimpleInterface::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

void QmlSimpleInterface::funcVoid()
{
    return m_obj->funcVoid();
}

bool QmlSimpleInterface::funcBool(bool paramBool)
{
    return m_obj->funcBool(paramBool);
}

int QmlSimpleInterface::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qint32 QmlSimpleInterface::funcInt32(qint32 paramInt32)
{
    return m_obj->funcInt32(paramInt32);
}

qint64 QmlSimpleInterface::funcInt64(qint64 paramInt64)
{
    return m_obj->funcInt64(paramInt64);
}

qreal QmlSimpleInterface::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

float QmlSimpleInterface::funcFloat32(float paramFloat32)
{
    return m_obj->funcFloat32(paramFloat32);
}

double QmlSimpleInterface::funcFloat64(double paramFloat)
{
    return m_obj->funcFloat64(paramFloat);
}

QString QmlSimpleInterface::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace tb_simple

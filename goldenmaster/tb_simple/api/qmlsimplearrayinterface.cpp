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
#include "apifactory.h"

#include <QtQml>

namespace tb_simple {

QmlSimpleArrayInterface::QmlSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
{
    m_obj = ApiFactory::get()->createSimpleArrayInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlSimpleArrayInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractSimpleArrayInterface::Property Changed signal
    // for usage, where QmlSimpleArrayInterface is used by the AbstractTuner interface and for connections with AbstractSimpleArrayInterface::Property Changed signal
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propBoolChanged, this, &QmlSimpleArrayInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propBoolChanged, this, &AbstractSimpleArrayInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propIntChanged, this, &QmlSimpleArrayInterface::propIntChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propIntChanged, this, &AbstractSimpleArrayInterface::propIntChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propInt32Changed, this, &QmlSimpleArrayInterface::propInt32Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propInt32Changed, this, &AbstractSimpleArrayInterface::propInt32Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propInt64Changed, this, &QmlSimpleArrayInterface::propInt64Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propInt64Changed, this, &AbstractSimpleArrayInterface::propInt64Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propFloatChanged, this, &QmlSimpleArrayInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propFloatChanged, this, &AbstractSimpleArrayInterface::propFloatChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propFloat32Changed, this, &QmlSimpleArrayInterface::propFloat32Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propFloat32Changed, this, &AbstractSimpleArrayInterface::propFloat32Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propFloat64Changed, this, &QmlSimpleArrayInterface::propFloat64Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propFloat64Changed, this, &AbstractSimpleArrayInterface::propFloat64Changed);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propStringChanged, this, &QmlSimpleArrayInterface::propStringChanged);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::propStringChanged, this, &AbstractSimpleArrayInterface::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlSimpleArrayInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlSimpleArrayInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigBool, this, &AbstractSimpleArrayInterface::sigBool);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigInt, this, &AbstractSimpleArrayInterface::sigInt);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigInt32, this, &AbstractSimpleArrayInterface::sigInt32);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigInt64, this, &AbstractSimpleArrayInterface::sigInt64);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigFloat, this, &AbstractSimpleArrayInterface::sigFloat);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigFloat32, this, &AbstractSimpleArrayInterface::sigFloat32);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigFloat64, this, &AbstractSimpleArrayInterface::sigFloat64);
    connect(m_obj.get(), &AbstractSimpleArrayInterface::sigString, this, &AbstractSimpleArrayInterface::sigString);
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
    return m_obj->setPropBool(propBool);
}

QList<int> QmlSimpleArrayInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    return m_obj->setPropInt(propInt);
}

QList<qint32> QmlSimpleArrayInterface::propInt32() const
{
    return m_obj->propInt32();
}

void QmlSimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    return m_obj->setPropInt32(propInt32);
}

QList<qint64> QmlSimpleArrayInterface::propInt64() const
{
    return m_obj->propInt64();
}

void QmlSimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    return m_obj->setPropInt64(propInt64);
}

QList<qreal> QmlSimpleArrayInterface::propFloat() const
{
    return m_obj->propFloat();
}

void QmlSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QList<float> QmlSimpleArrayInterface::propFloat32() const
{
    return m_obj->propFloat32();
}

void QmlSimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    return m_obj->setPropFloat32(propFloat32);
}

QList<double> QmlSimpleArrayInterface::propFloat64() const
{
    return m_obj->propFloat64();
}

void QmlSimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    return m_obj->setPropFloat64(propFloat64);
}

QList<QString> QmlSimpleArrayInterface::propString() const
{
    return m_obj->propString();
}

void QmlSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    return m_obj->setPropString(propString);
}

QList<bool> QmlSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    return m_obj->funcBool(paramBool);
}

QList<int> QmlSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    return m_obj->funcInt(paramInt);
}

QList<qint32> QmlSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    return m_obj->funcInt32(paramInt32);
}

QList<qint64> QmlSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    return m_obj->funcInt64(paramInt64);
}

QList<qreal> QmlSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QList<float> QmlSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    return m_obj->funcFloat32(paramFloat32);
}

QList<double> QmlSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    return m_obj->funcFloat64(paramFloat);
}

QList<QString> QmlSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace tb_simple

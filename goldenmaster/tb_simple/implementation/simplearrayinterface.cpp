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

namespace tb_simple {

SimpleArrayInterface::SimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propInt32(QList<qint32>())
    , m_propInt64(QList<qint64>())
    , m_propFloat(QList<qreal>())
    , m_propFloat32(QList<float>())
    , m_propFloat64(QList<double>())
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
    }
}

QList<int> SimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void SimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

QList<qint32> SimpleArrayInterface::propInt32() const
{
    return m_propInt32;
}

void SimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

QList<qint64> SimpleArrayInterface::propInt64() const
{
    return m_propInt64;
}

void SimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<qreal> SimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void SimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

QList<float> SimpleArrayInterface::propFloat32() const
{
    return m_propFloat32;
}

void SimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

QList<double> SimpleArrayInterface::propFloat64() const
{
    return m_propFloat64;
}

void SimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<QString> SimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> SimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    return QList<bool>();
}

QList<int> SimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    return QList<int>();
}

QList<qint32> SimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    qDebug() << Q_FUNC_INFO;
    return QList<qint32>();
}

QList<qint64> SimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    qDebug() << Q_FUNC_INFO;
    return QList<qint64>();
}

QList<qreal> SimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    return QList<qreal>();
}

QList<float> SimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    qDebug() << Q_FUNC_INFO;
    return QList<float>();
}

QList<double> SimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    return QList<double>();
}

QList<QString> SimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    return QList<QString>();
}
} //namespace tb_simple

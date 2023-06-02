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


#include "qmltestapi64.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi64::QmlTestApi64(QObject *parent)
    : AbstractTestApi64(parent)
{
    m_obj = ApiFactory::get()->createTestApi64();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi64::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi64::Property Changed signal
    // for usage, where QmlTestApi64 is used by the AbstractTuner interface and for connections with AbstractTestApi64::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi64::propIntChanged, this, &QmlTestApi64::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi64::propIntChanged, this, &AbstractTestApi64::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi64::propFloatChanged, this, &QmlTestApi64::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi64::propFloatChanged, this, &AbstractTestApi64::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi64::propStringChanged, this, &QmlTestApi64::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi64::propStringChanged, this, &AbstractTestApi64::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi64 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi64 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi64::sigInt, this, &AbstractTestApi64::sigInt);
    connect(m_obj.get(), &AbstractTestApi64::sigFloat, this, &AbstractTestApi64::sigFloat);
    connect(m_obj.get(), &AbstractTestApi64::sigString, this, &AbstractTestApi64::sigString);
}

QmlTestApi64::~QmlTestApi64()
{
}

int QmlTestApi64::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi64::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi64::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi64::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi64::propString() const
{
    return m_obj->propString();
}

void QmlTestApi64::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi64::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi64::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi64::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

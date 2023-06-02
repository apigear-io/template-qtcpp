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


#include "qmltestapi20.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi20::QmlTestApi20(QObject *parent)
    : AbstractTestApi20(parent)
{
    m_obj = ApiFactory::get()->createTestApi20();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi20::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi20::Property Changed signal
    // for usage, where QmlTestApi20 is used by the AbstractTuner interface and for connections with AbstractTestApi20::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi20::propIntChanged, this, &QmlTestApi20::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi20::propIntChanged, this, &AbstractTestApi20::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi20::propFloatChanged, this, &QmlTestApi20::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi20::propFloatChanged, this, &AbstractTestApi20::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi20::propStringChanged, this, &QmlTestApi20::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi20::propStringChanged, this, &AbstractTestApi20::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi20 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi20 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi20::sigInt, this, &AbstractTestApi20::sigInt);
    connect(m_obj.get(), &AbstractTestApi20::sigFloat, this, &AbstractTestApi20::sigFloat);
    connect(m_obj.get(), &AbstractTestApi20::sigString, this, &AbstractTestApi20::sigString);
}

QmlTestApi20::~QmlTestApi20()
{
}

int QmlTestApi20::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi20::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi20::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi20::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi20::propString() const
{
    return m_obj->propString();
}

void QmlTestApi20::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi20::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi20::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi20::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

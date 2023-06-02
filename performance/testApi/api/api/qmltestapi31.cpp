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


#include "qmltestapi31.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi31::QmlTestApi31(QObject *parent)
    : AbstractTestApi31(parent)
{
    m_obj = ApiFactory::get()->createTestApi31();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi31::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi31::Property Changed signal
    // for usage, where QmlTestApi31 is used by the AbstractTuner interface and for connections with AbstractTestApi31::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi31::propIntChanged, this, &QmlTestApi31::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi31::propIntChanged, this, &AbstractTestApi31::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi31::propFloatChanged, this, &QmlTestApi31::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi31::propFloatChanged, this, &AbstractTestApi31::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi31::propStringChanged, this, &QmlTestApi31::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi31::propStringChanged, this, &AbstractTestApi31::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi31 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi31 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi31::sigInt, this, &AbstractTestApi31::sigInt);
    connect(m_obj.get(), &AbstractTestApi31::sigFloat, this, &AbstractTestApi31::sigFloat);
    connect(m_obj.get(), &AbstractTestApi31::sigString, this, &AbstractTestApi31::sigString);
}

QmlTestApi31::~QmlTestApi31()
{
}

int QmlTestApi31::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi31::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi31::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi31::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi31::propString() const
{
    return m_obj->propString();
}

void QmlTestApi31::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi31::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi31::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi31::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

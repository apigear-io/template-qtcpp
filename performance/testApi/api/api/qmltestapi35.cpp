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


#include "qmltestapi35.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi35::QmlTestApi35(QObject *parent)
    : AbstractTestApi35(parent)
{
    m_obj = ApiFactory::get()->createTestApi35();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi35::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi35::Property Changed signal
    // for usage, where QmlTestApi35 is used by the AbstractTuner interface and for connections with AbstractTestApi35::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi35::propIntChanged, this, &QmlTestApi35::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi35::propIntChanged, this, &AbstractTestApi35::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi35::propFloatChanged, this, &QmlTestApi35::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi35::propFloatChanged, this, &AbstractTestApi35::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi35::propStringChanged, this, &QmlTestApi35::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi35::propStringChanged, this, &AbstractTestApi35::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi35 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi35 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi35::sigInt, this, &AbstractTestApi35::sigInt);
    connect(m_obj.get(), &AbstractTestApi35::sigFloat, this, &AbstractTestApi35::sigFloat);
    connect(m_obj.get(), &AbstractTestApi35::sigString, this, &AbstractTestApi35::sigString);
}

QmlTestApi35::~QmlTestApi35()
{
}

int QmlTestApi35::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi35::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi35::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi35::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi35::propString() const
{
    return m_obj->propString();
}

void QmlTestApi35::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi35::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi35::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi35::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

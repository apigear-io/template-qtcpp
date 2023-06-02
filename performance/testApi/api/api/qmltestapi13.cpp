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


#include "qmltestapi13.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi13::QmlTestApi13(QObject *parent)
    : AbstractTestApi13(parent)
{
    m_obj = ApiFactory::get()->createTestApi13();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi13::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi13::Property Changed signal
    // for usage, where QmlTestApi13 is used by the AbstractTuner interface and for connections with AbstractTestApi13::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi13::propIntChanged, this, &QmlTestApi13::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi13::propIntChanged, this, &AbstractTestApi13::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi13::propFloatChanged, this, &QmlTestApi13::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi13::propFloatChanged, this, &AbstractTestApi13::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi13::propStringChanged, this, &QmlTestApi13::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi13::propStringChanged, this, &AbstractTestApi13::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi13 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi13 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi13::sigInt, this, &AbstractTestApi13::sigInt);
    connect(m_obj.get(), &AbstractTestApi13::sigFloat, this, &AbstractTestApi13::sigFloat);
    connect(m_obj.get(), &AbstractTestApi13::sigString, this, &AbstractTestApi13::sigString);
}

QmlTestApi13::~QmlTestApi13()
{
}

int QmlTestApi13::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi13::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi13::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi13::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi13::propString() const
{
    return m_obj->propString();
}

void QmlTestApi13::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi13::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi13::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi13::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

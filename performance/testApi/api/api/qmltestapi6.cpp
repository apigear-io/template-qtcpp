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


#include "qmltestapi6.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi6::QmlTestApi6(QObject *parent)
    : AbstractTestApi6(parent)
{
    m_obj = ApiFactory::get()->createTestApi6();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi6::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi6::Property Changed signal
    // for usage, where QmlTestApi6 is used by the AbstractTuner interface and for connections with AbstractTestApi6::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi6::propIntChanged, this, &QmlTestApi6::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi6::propIntChanged, this, &AbstractTestApi6::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi6::propFloatChanged, this, &QmlTestApi6::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi6::propFloatChanged, this, &AbstractTestApi6::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi6::propStringChanged, this, &QmlTestApi6::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi6::propStringChanged, this, &AbstractTestApi6::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi6 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi6 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi6::sigInt, this, &AbstractTestApi6::sigInt);
    connect(m_obj.get(), &AbstractTestApi6::sigFloat, this, &AbstractTestApi6::sigFloat);
    connect(m_obj.get(), &AbstractTestApi6::sigString, this, &AbstractTestApi6::sigString);
}

QmlTestApi6::~QmlTestApi6()
{
}

int QmlTestApi6::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi6::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi6::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi6::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi6::propString() const
{
    return m_obj->propString();
}

void QmlTestApi6::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi6::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi6::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi6::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

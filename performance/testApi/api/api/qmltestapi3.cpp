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


#include "qmltestapi3.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi3::QmlTestApi3(QObject *parent)
    : AbstractTestApi3(parent)
{
    m_obj = ApiFactory::get()->createTestApi3();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi3::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi3::Property Changed signal
    // for usage, where QmlTestApi3 is used by the AbstractTuner interface and for connections with AbstractTestApi3::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi3::propIntChanged, this, &QmlTestApi3::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi3::propIntChanged, this, &AbstractTestApi3::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi3::propFloatChanged, this, &QmlTestApi3::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi3::propFloatChanged, this, &AbstractTestApi3::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi3::propStringChanged, this, &QmlTestApi3::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi3::propStringChanged, this, &AbstractTestApi3::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi3 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi3 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi3::sigInt, this, &AbstractTestApi3::sigInt);
    connect(m_obj.get(), &AbstractTestApi3::sigFloat, this, &AbstractTestApi3::sigFloat);
    connect(m_obj.get(), &AbstractTestApi3::sigString, this, &AbstractTestApi3::sigString);
}

QmlTestApi3::~QmlTestApi3()
{
}

int QmlTestApi3::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi3::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi3::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi3::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi3::propString() const
{
    return m_obj->propString();
}

void QmlTestApi3::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi3::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi3::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi3::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

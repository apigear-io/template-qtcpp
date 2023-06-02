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


#include "qmltestapi2.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi2::QmlTestApi2(QObject *parent)
    : AbstractTestApi2(parent)
{
    m_obj = ApiFactory::get()->createTestApi2();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi2::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi2::Property Changed signal
    // for usage, where QmlTestApi2 is used by the AbstractTuner interface and for connections with AbstractTestApi2::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi2::propIntChanged, this, &QmlTestApi2::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi2::propIntChanged, this, &AbstractTestApi2::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi2::propFloatChanged, this, &QmlTestApi2::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi2::propFloatChanged, this, &AbstractTestApi2::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi2::propStringChanged, this, &QmlTestApi2::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi2::propStringChanged, this, &AbstractTestApi2::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi2 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi2 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi2::sigInt, this, &AbstractTestApi2::sigInt);
    connect(m_obj.get(), &AbstractTestApi2::sigFloat, this, &AbstractTestApi2::sigFloat);
    connect(m_obj.get(), &AbstractTestApi2::sigString, this, &AbstractTestApi2::sigString);
}

QmlTestApi2::~QmlTestApi2()
{
}

int QmlTestApi2::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi2::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi2::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi2::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi2::propString() const
{
    return m_obj->propString();
}

void QmlTestApi2::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi2::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi2::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi2::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

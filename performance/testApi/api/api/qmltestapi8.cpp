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


#include "qmltestapi8.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi8::QmlTestApi8(QObject *parent)
    : AbstractTestApi8(parent)
{
    m_obj = ApiFactory::get()->createTestApi8();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi8::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi8::Property Changed signal
    // for usage, where QmlTestApi8 is used by the AbstractTuner interface and for connections with AbstractTestApi8::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi8::propIntChanged, this, &QmlTestApi8::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi8::propIntChanged, this, &AbstractTestApi8::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi8::propFloatChanged, this, &QmlTestApi8::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi8::propFloatChanged, this, &AbstractTestApi8::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi8::propStringChanged, this, &QmlTestApi8::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi8::propStringChanged, this, &AbstractTestApi8::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi8 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi8 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi8::sigInt, this, &AbstractTestApi8::sigInt);
    connect(m_obj.get(), &AbstractTestApi8::sigFloat, this, &AbstractTestApi8::sigFloat);
    connect(m_obj.get(), &AbstractTestApi8::sigString, this, &AbstractTestApi8::sigString);
}

QmlTestApi8::~QmlTestApi8()
{
}

int QmlTestApi8::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi8::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi8::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi8::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi8::propString() const
{
    return m_obj->propString();
}

void QmlTestApi8::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi8::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi8::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi8::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

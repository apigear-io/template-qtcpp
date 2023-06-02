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


#include "qmltestapi52.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi52::QmlTestApi52(QObject *parent)
    : AbstractTestApi52(parent)
{
    m_obj = ApiFactory::get()->createTestApi52();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi52::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi52::Property Changed signal
    // for usage, where QmlTestApi52 is used by the AbstractTuner interface and for connections with AbstractTestApi52::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi52::propIntChanged, this, &QmlTestApi52::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi52::propIntChanged, this, &AbstractTestApi52::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi52::propFloatChanged, this, &QmlTestApi52::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi52::propFloatChanged, this, &AbstractTestApi52::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi52::propStringChanged, this, &QmlTestApi52::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi52::propStringChanged, this, &AbstractTestApi52::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi52 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi52 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi52::sigInt, this, &AbstractTestApi52::sigInt);
    connect(m_obj.get(), &AbstractTestApi52::sigFloat, this, &AbstractTestApi52::sigFloat);
    connect(m_obj.get(), &AbstractTestApi52::sigString, this, &AbstractTestApi52::sigString);
}

QmlTestApi52::~QmlTestApi52()
{
}

int QmlTestApi52::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi52::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi52::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi52::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi52::propString() const
{
    return m_obj->propString();
}

void QmlTestApi52::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi52::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi52::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi52::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

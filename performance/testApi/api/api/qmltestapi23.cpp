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


#include "qmltestapi23.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi23::QmlTestApi23(QObject *parent)
    : AbstractTestApi23(parent)
{
    m_obj = ApiFactory::get()->createTestApi23();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi23::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi23::Property Changed signal
    // for usage, where QmlTestApi23 is used by the AbstractTuner interface and for connections with AbstractTestApi23::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi23::propIntChanged, this, &QmlTestApi23::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi23::propIntChanged, this, &AbstractTestApi23::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi23::propFloatChanged, this, &QmlTestApi23::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi23::propFloatChanged, this, &AbstractTestApi23::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi23::propStringChanged, this, &QmlTestApi23::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi23::propStringChanged, this, &AbstractTestApi23::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi23 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi23 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi23::sigInt, this, &AbstractTestApi23::sigInt);
    connect(m_obj.get(), &AbstractTestApi23::sigFloat, this, &AbstractTestApi23::sigFloat);
    connect(m_obj.get(), &AbstractTestApi23::sigString, this, &AbstractTestApi23::sigString);
}

QmlTestApi23::~QmlTestApi23()
{
}

int QmlTestApi23::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi23::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi23::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi23::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi23::propString() const
{
    return m_obj->propString();
}

void QmlTestApi23::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi23::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi23::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi23::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

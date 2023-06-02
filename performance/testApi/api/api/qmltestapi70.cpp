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


#include "qmltestapi70.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi70::QmlTestApi70(QObject *parent)
    : AbstractTestApi70(parent)
{
    m_obj = ApiFactory::get()->createTestApi70();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi70::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi70::Property Changed signal
    // for usage, where QmlTestApi70 is used by the AbstractTuner interface and for connections with AbstractTestApi70::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi70::propIntChanged, this, &QmlTestApi70::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi70::propIntChanged, this, &AbstractTestApi70::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi70::propFloatChanged, this, &QmlTestApi70::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi70::propFloatChanged, this, &AbstractTestApi70::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi70::propStringChanged, this, &QmlTestApi70::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi70::propStringChanged, this, &AbstractTestApi70::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi70 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi70 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi70::sigInt, this, &AbstractTestApi70::sigInt);
    connect(m_obj.get(), &AbstractTestApi70::sigFloat, this, &AbstractTestApi70::sigFloat);
    connect(m_obj.get(), &AbstractTestApi70::sigString, this, &AbstractTestApi70::sigString);
}

QmlTestApi70::~QmlTestApi70()
{
}

int QmlTestApi70::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi70::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi70::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi70::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi70::propString() const
{
    return m_obj->propString();
}

void QmlTestApi70::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi70::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi70::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi70::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

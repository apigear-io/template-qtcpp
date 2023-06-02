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


#include "qmltestapi17.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi17::QmlTestApi17(QObject *parent)
    : AbstractTestApi17(parent)
{
    m_obj = ApiFactory::get()->createTestApi17();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi17::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi17::Property Changed signal
    // for usage, where QmlTestApi17 is used by the AbstractTuner interface and for connections with AbstractTestApi17::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi17::propIntChanged, this, &QmlTestApi17::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi17::propIntChanged, this, &AbstractTestApi17::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi17::propFloatChanged, this, &QmlTestApi17::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi17::propFloatChanged, this, &AbstractTestApi17::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi17::propStringChanged, this, &QmlTestApi17::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi17::propStringChanged, this, &AbstractTestApi17::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi17 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi17 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi17::sigInt, this, &AbstractTestApi17::sigInt);
    connect(m_obj.get(), &AbstractTestApi17::sigFloat, this, &AbstractTestApi17::sigFloat);
    connect(m_obj.get(), &AbstractTestApi17::sigString, this, &AbstractTestApi17::sigString);
}

QmlTestApi17::~QmlTestApi17()
{
}

int QmlTestApi17::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi17::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi17::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi17::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi17::propString() const
{
    return m_obj->propString();
}

void QmlTestApi17::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi17::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi17::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi17::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

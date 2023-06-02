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


#include "qmltestapi71.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi71::QmlTestApi71(QObject *parent)
    : AbstractTestApi71(parent)
{
    m_obj = ApiFactory::get()->createTestApi71();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi71::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi71::Property Changed signal
    // for usage, where QmlTestApi71 is used by the AbstractTuner interface and for connections with AbstractTestApi71::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi71::propIntChanged, this, &QmlTestApi71::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi71::propIntChanged, this, &AbstractTestApi71::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi71::propFloatChanged, this, &QmlTestApi71::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi71::propFloatChanged, this, &AbstractTestApi71::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi71::propStringChanged, this, &QmlTestApi71::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi71::propStringChanged, this, &AbstractTestApi71::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi71 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi71 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi71::sigInt, this, &AbstractTestApi71::sigInt);
    connect(m_obj.get(), &AbstractTestApi71::sigFloat, this, &AbstractTestApi71::sigFloat);
    connect(m_obj.get(), &AbstractTestApi71::sigString, this, &AbstractTestApi71::sigString);
}

QmlTestApi71::~QmlTestApi71()
{
}

int QmlTestApi71::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi71::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi71::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi71::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi71::propString() const
{
    return m_obj->propString();
}

void QmlTestApi71::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi71::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi71::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi71::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

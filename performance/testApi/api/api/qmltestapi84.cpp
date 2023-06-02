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


#include "qmltestapi84.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi84::QmlTestApi84(QObject *parent)
    : AbstractTestApi84(parent)
{
    m_obj = ApiFactory::get()->createTestApi84();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi84::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi84::Property Changed signal
    // for usage, where QmlTestApi84 is used by the AbstractTuner interface and for connections with AbstractTestApi84::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi84::propIntChanged, this, &QmlTestApi84::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi84::propIntChanged, this, &AbstractTestApi84::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi84::propFloatChanged, this, &QmlTestApi84::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi84::propFloatChanged, this, &AbstractTestApi84::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi84::propStringChanged, this, &QmlTestApi84::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi84::propStringChanged, this, &AbstractTestApi84::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi84 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi84 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi84::sigInt, this, &AbstractTestApi84::sigInt);
    connect(m_obj.get(), &AbstractTestApi84::sigFloat, this, &AbstractTestApi84::sigFloat);
    connect(m_obj.get(), &AbstractTestApi84::sigString, this, &AbstractTestApi84::sigString);
}

QmlTestApi84::~QmlTestApi84()
{
}

int QmlTestApi84::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi84::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi84::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi84::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi84::propString() const
{
    return m_obj->propString();
}

void QmlTestApi84::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi84::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi84::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi84::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

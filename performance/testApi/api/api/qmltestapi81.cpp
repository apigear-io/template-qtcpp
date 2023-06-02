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


#include "qmltestapi81.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi81::QmlTestApi81(QObject *parent)
    : AbstractTestApi81(parent)
{
    m_obj = ApiFactory::get()->createTestApi81();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi81::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi81::Property Changed signal
    // for usage, where QmlTestApi81 is used by the AbstractTuner interface and for connections with AbstractTestApi81::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi81::propIntChanged, this, &QmlTestApi81::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi81::propIntChanged, this, &AbstractTestApi81::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi81::propFloatChanged, this, &QmlTestApi81::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi81::propFloatChanged, this, &AbstractTestApi81::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi81::propStringChanged, this, &QmlTestApi81::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi81::propStringChanged, this, &AbstractTestApi81::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi81 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi81 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi81::sigInt, this, &AbstractTestApi81::sigInt);
    connect(m_obj.get(), &AbstractTestApi81::sigFloat, this, &AbstractTestApi81::sigFloat);
    connect(m_obj.get(), &AbstractTestApi81::sigString, this, &AbstractTestApi81::sigString);
}

QmlTestApi81::~QmlTestApi81()
{
}

int QmlTestApi81::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi81::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi81::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi81::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi81::propString() const
{
    return m_obj->propString();
}

void QmlTestApi81::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi81::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi81::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi81::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

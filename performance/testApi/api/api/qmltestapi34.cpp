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


#include "qmltestapi34.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi34::QmlTestApi34(QObject *parent)
    : AbstractTestApi34(parent)
{
    m_obj = ApiFactory::get()->createTestApi34();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi34::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi34::Property Changed signal
    // for usage, where QmlTestApi34 is used by the AbstractTuner interface and for connections with AbstractTestApi34::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi34::propIntChanged, this, &QmlTestApi34::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi34::propIntChanged, this, &AbstractTestApi34::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi34::propFloatChanged, this, &QmlTestApi34::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi34::propFloatChanged, this, &AbstractTestApi34::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi34::propStringChanged, this, &QmlTestApi34::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi34::propStringChanged, this, &AbstractTestApi34::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi34 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi34 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi34::sigInt, this, &AbstractTestApi34::sigInt);
    connect(m_obj.get(), &AbstractTestApi34::sigFloat, this, &AbstractTestApi34::sigFloat);
    connect(m_obj.get(), &AbstractTestApi34::sigString, this, &AbstractTestApi34::sigString);
}

QmlTestApi34::~QmlTestApi34()
{
}

int QmlTestApi34::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi34::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi34::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi34::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi34::propString() const
{
    return m_obj->propString();
}

void QmlTestApi34::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi34::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi34::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi34::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

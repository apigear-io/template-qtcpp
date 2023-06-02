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


#include "qmltestapi65.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi65::QmlTestApi65(QObject *parent)
    : AbstractTestApi65(parent)
{
    m_obj = ApiFactory::get()->createTestApi65();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi65::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi65::Property Changed signal
    // for usage, where QmlTestApi65 is used by the AbstractTuner interface and for connections with AbstractTestApi65::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi65::propIntChanged, this, &QmlTestApi65::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi65::propIntChanged, this, &AbstractTestApi65::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi65::propFloatChanged, this, &QmlTestApi65::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi65::propFloatChanged, this, &AbstractTestApi65::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi65::propStringChanged, this, &QmlTestApi65::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi65::propStringChanged, this, &AbstractTestApi65::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi65 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi65 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi65::sigInt, this, &AbstractTestApi65::sigInt);
    connect(m_obj.get(), &AbstractTestApi65::sigFloat, this, &AbstractTestApi65::sigFloat);
    connect(m_obj.get(), &AbstractTestApi65::sigString, this, &AbstractTestApi65::sigString);
}

QmlTestApi65::~QmlTestApi65()
{
}

int QmlTestApi65::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi65::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi65::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi65::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi65::propString() const
{
    return m_obj->propString();
}

void QmlTestApi65::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi65::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi65::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi65::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

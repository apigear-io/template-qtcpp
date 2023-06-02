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


#include "qmltestapi83.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi83::QmlTestApi83(QObject *parent)
    : AbstractTestApi83(parent)
{
    m_obj = ApiFactory::get()->createTestApi83();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi83::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi83::Property Changed signal
    // for usage, where QmlTestApi83 is used by the AbstractTuner interface and for connections with AbstractTestApi83::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi83::propIntChanged, this, &QmlTestApi83::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi83::propIntChanged, this, &AbstractTestApi83::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi83::propFloatChanged, this, &QmlTestApi83::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi83::propFloatChanged, this, &AbstractTestApi83::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi83::propStringChanged, this, &QmlTestApi83::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi83::propStringChanged, this, &AbstractTestApi83::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi83 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi83 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi83::sigInt, this, &AbstractTestApi83::sigInt);
    connect(m_obj.get(), &AbstractTestApi83::sigFloat, this, &AbstractTestApi83::sigFloat);
    connect(m_obj.get(), &AbstractTestApi83::sigString, this, &AbstractTestApi83::sigString);
}

QmlTestApi83::~QmlTestApi83()
{
}

int QmlTestApi83::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi83::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi83::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi83::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi83::propString() const
{
    return m_obj->propString();
}

void QmlTestApi83::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi83::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi83::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi83::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

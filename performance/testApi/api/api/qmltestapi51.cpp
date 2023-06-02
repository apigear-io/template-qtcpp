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


#include "qmltestapi51.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi51::QmlTestApi51(QObject *parent)
    : AbstractTestApi51(parent)
{
    m_obj = ApiFactory::get()->createTestApi51();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi51::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi51::Property Changed signal
    // for usage, where QmlTestApi51 is used by the AbstractTuner interface and for connections with AbstractTestApi51::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi51::propIntChanged, this, &QmlTestApi51::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi51::propIntChanged, this, &AbstractTestApi51::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi51::propFloatChanged, this, &QmlTestApi51::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi51::propFloatChanged, this, &AbstractTestApi51::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi51::propStringChanged, this, &QmlTestApi51::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi51::propStringChanged, this, &AbstractTestApi51::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi51 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi51 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi51::sigInt, this, &AbstractTestApi51::sigInt);
    connect(m_obj.get(), &AbstractTestApi51::sigFloat, this, &AbstractTestApi51::sigFloat);
    connect(m_obj.get(), &AbstractTestApi51::sigString, this, &AbstractTestApi51::sigString);
}

QmlTestApi51::~QmlTestApi51()
{
}

int QmlTestApi51::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi51::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi51::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi51::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi51::propString() const
{
    return m_obj->propString();
}

void QmlTestApi51::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi51::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi51::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi51::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi57.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi57::QmlTestApi57(QObject *parent)
    : AbstractTestApi57(parent)
{
    m_obj = ApiFactory::get()->createTestApi57();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi57::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi57::Property Changed signal
    // for usage, where QmlTestApi57 is used by the AbstractTuner interface and for connections with AbstractTestApi57::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi57::propIntChanged, this, &QmlTestApi57::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi57::propIntChanged, this, &AbstractTestApi57::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi57::propFloatChanged, this, &QmlTestApi57::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi57::propFloatChanged, this, &AbstractTestApi57::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi57::propStringChanged, this, &QmlTestApi57::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi57::propStringChanged, this, &AbstractTestApi57::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi57 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi57 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi57::sigInt, this, &AbstractTestApi57::sigInt);
    connect(m_obj.get(), &AbstractTestApi57::sigFloat, this, &AbstractTestApi57::sigFloat);
    connect(m_obj.get(), &AbstractTestApi57::sigString, this, &AbstractTestApi57::sigString);
}

QmlTestApi57::~QmlTestApi57()
{
}

int QmlTestApi57::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi57::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi57::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi57::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi57::propString() const
{
    return m_obj->propString();
}

void QmlTestApi57::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi57::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi57::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi57::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi0.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi0::QmlTestApi0(QObject *parent)
    : AbstractTestApi0(parent)
{
    m_obj = ApiFactory::get()->createTestApi0();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi0::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi0::Property Changed signal
    // for usage, where QmlTestApi0 is used by the AbstractTuner interface and for connections with AbstractTestApi0::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi0::propIntChanged, this, &QmlTestApi0::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi0::propIntChanged, this, &AbstractTestApi0::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi0::propFloatChanged, this, &QmlTestApi0::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi0::propFloatChanged, this, &AbstractTestApi0::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi0::propStringChanged, this, &QmlTestApi0::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi0::propStringChanged, this, &AbstractTestApi0::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi0 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi0 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi0::sigInt, this, &AbstractTestApi0::sigInt);
    connect(m_obj.get(), &AbstractTestApi0::sigFloat, this, &AbstractTestApi0::sigFloat);
    connect(m_obj.get(), &AbstractTestApi0::sigString, this, &AbstractTestApi0::sigString);
}

QmlTestApi0::~QmlTestApi0()
{
}

int QmlTestApi0::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi0::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi0::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi0::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi0::propString() const
{
    return m_obj->propString();
}

void QmlTestApi0::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi0::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi0::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi0::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

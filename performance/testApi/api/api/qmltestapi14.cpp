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


#include "qmltestapi14.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi14::QmlTestApi14(QObject *parent)
    : AbstractTestApi14(parent)
{
    m_obj = ApiFactory::get()->createTestApi14();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi14::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi14::Property Changed signal
    // for usage, where QmlTestApi14 is used by the AbstractTuner interface and for connections with AbstractTestApi14::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi14::propIntChanged, this, &QmlTestApi14::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi14::propIntChanged, this, &AbstractTestApi14::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi14::propFloatChanged, this, &QmlTestApi14::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi14::propFloatChanged, this, &AbstractTestApi14::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi14::propStringChanged, this, &QmlTestApi14::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi14::propStringChanged, this, &AbstractTestApi14::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi14 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi14 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi14::sigInt, this, &AbstractTestApi14::sigInt);
    connect(m_obj.get(), &AbstractTestApi14::sigFloat, this, &AbstractTestApi14::sigFloat);
    connect(m_obj.get(), &AbstractTestApi14::sigString, this, &AbstractTestApi14::sigString);
}

QmlTestApi14::~QmlTestApi14()
{
}

int QmlTestApi14::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi14::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi14::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi14::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi14::propString() const
{
    return m_obj->propString();
}

void QmlTestApi14::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi14::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi14::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi14::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

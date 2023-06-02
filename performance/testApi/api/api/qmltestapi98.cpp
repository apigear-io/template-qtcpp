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


#include "qmltestapi98.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi98::QmlTestApi98(QObject *parent)
    : AbstractTestApi98(parent)
{
    m_obj = ApiFactory::get()->createTestApi98();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi98::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi98::Property Changed signal
    // for usage, where QmlTestApi98 is used by the AbstractTuner interface and for connections with AbstractTestApi98::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi98::propIntChanged, this, &QmlTestApi98::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi98::propIntChanged, this, &AbstractTestApi98::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi98::propFloatChanged, this, &QmlTestApi98::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi98::propFloatChanged, this, &AbstractTestApi98::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi98::propStringChanged, this, &QmlTestApi98::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi98::propStringChanged, this, &AbstractTestApi98::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi98 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi98 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi98::sigInt, this, &AbstractTestApi98::sigInt);
    connect(m_obj.get(), &AbstractTestApi98::sigFloat, this, &AbstractTestApi98::sigFloat);
    connect(m_obj.get(), &AbstractTestApi98::sigString, this, &AbstractTestApi98::sigString);
}

QmlTestApi98::~QmlTestApi98()
{
}

int QmlTestApi98::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi98::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi98::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi98::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi98::propString() const
{
    return m_obj->propString();
}

void QmlTestApi98::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi98::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi98::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi98::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

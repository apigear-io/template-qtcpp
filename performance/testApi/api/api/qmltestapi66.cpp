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


#include "qmltestapi66.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi66::QmlTestApi66(QObject *parent)
    : AbstractTestApi66(parent)
{
    m_obj = ApiFactory::get()->createTestApi66();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi66::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi66::Property Changed signal
    // for usage, where QmlTestApi66 is used by the AbstractTuner interface and for connections with AbstractTestApi66::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi66::propIntChanged, this, &QmlTestApi66::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi66::propIntChanged, this, &AbstractTestApi66::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi66::propFloatChanged, this, &QmlTestApi66::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi66::propFloatChanged, this, &AbstractTestApi66::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi66::propStringChanged, this, &QmlTestApi66::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi66::propStringChanged, this, &AbstractTestApi66::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi66 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi66 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi66::sigInt, this, &AbstractTestApi66::sigInt);
    connect(m_obj.get(), &AbstractTestApi66::sigFloat, this, &AbstractTestApi66::sigFloat);
    connect(m_obj.get(), &AbstractTestApi66::sigString, this, &AbstractTestApi66::sigString);
}

QmlTestApi66::~QmlTestApi66()
{
}

int QmlTestApi66::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi66::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi66::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi66::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi66::propString() const
{
    return m_obj->propString();
}

void QmlTestApi66::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi66::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi66::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi66::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

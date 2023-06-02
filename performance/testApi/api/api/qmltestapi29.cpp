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


#include "qmltestapi29.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi29::QmlTestApi29(QObject *parent)
    : AbstractTestApi29(parent)
{
    m_obj = ApiFactory::get()->createTestApi29();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi29::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi29::Property Changed signal
    // for usage, where QmlTestApi29 is used by the AbstractTuner interface and for connections with AbstractTestApi29::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi29::propIntChanged, this, &QmlTestApi29::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi29::propIntChanged, this, &AbstractTestApi29::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi29::propFloatChanged, this, &QmlTestApi29::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi29::propFloatChanged, this, &AbstractTestApi29::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi29::propStringChanged, this, &QmlTestApi29::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi29::propStringChanged, this, &AbstractTestApi29::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi29 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi29 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi29::sigInt, this, &AbstractTestApi29::sigInt);
    connect(m_obj.get(), &AbstractTestApi29::sigFloat, this, &AbstractTestApi29::sigFloat);
    connect(m_obj.get(), &AbstractTestApi29::sigString, this, &AbstractTestApi29::sigString);
}

QmlTestApi29::~QmlTestApi29()
{
}

int QmlTestApi29::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi29::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi29::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi29::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi29::propString() const
{
    return m_obj->propString();
}

void QmlTestApi29::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi29::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi29::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi29::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

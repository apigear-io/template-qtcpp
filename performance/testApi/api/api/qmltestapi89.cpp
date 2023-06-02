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


#include "qmltestapi89.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi89::QmlTestApi89(QObject *parent)
    : AbstractTestApi89(parent)
{
    m_obj = ApiFactory::get()->createTestApi89();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi89::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi89::Property Changed signal
    // for usage, where QmlTestApi89 is used by the AbstractTuner interface and for connections with AbstractTestApi89::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi89::propIntChanged, this, &QmlTestApi89::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi89::propIntChanged, this, &AbstractTestApi89::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi89::propFloatChanged, this, &QmlTestApi89::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi89::propFloatChanged, this, &AbstractTestApi89::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi89::propStringChanged, this, &QmlTestApi89::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi89::propStringChanged, this, &AbstractTestApi89::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi89 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi89 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi89::sigInt, this, &AbstractTestApi89::sigInt);
    connect(m_obj.get(), &AbstractTestApi89::sigFloat, this, &AbstractTestApi89::sigFloat);
    connect(m_obj.get(), &AbstractTestApi89::sigString, this, &AbstractTestApi89::sigString);
}

QmlTestApi89::~QmlTestApi89()
{
}

int QmlTestApi89::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi89::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi89::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi89::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi89::propString() const
{
    return m_obj->propString();
}

void QmlTestApi89::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi89::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi89::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi89::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

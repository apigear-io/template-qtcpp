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


#include "qmltestapi87.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi87::QmlTestApi87(QObject *parent)
    : AbstractTestApi87(parent)
{
    m_obj = ApiFactory::get()->createTestApi87();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi87::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi87::Property Changed signal
    // for usage, where QmlTestApi87 is used by the AbstractTuner interface and for connections with AbstractTestApi87::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi87::propIntChanged, this, &QmlTestApi87::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi87::propIntChanged, this, &AbstractTestApi87::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi87::propFloatChanged, this, &QmlTestApi87::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi87::propFloatChanged, this, &AbstractTestApi87::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi87::propStringChanged, this, &QmlTestApi87::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi87::propStringChanged, this, &AbstractTestApi87::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi87 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi87 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi87::sigInt, this, &AbstractTestApi87::sigInt);
    connect(m_obj.get(), &AbstractTestApi87::sigFloat, this, &AbstractTestApi87::sigFloat);
    connect(m_obj.get(), &AbstractTestApi87::sigString, this, &AbstractTestApi87::sigString);
}

QmlTestApi87::~QmlTestApi87()
{
}

int QmlTestApi87::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi87::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi87::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi87::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi87::propString() const
{
    return m_obj->propString();
}

void QmlTestApi87::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi87::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi87::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi87::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

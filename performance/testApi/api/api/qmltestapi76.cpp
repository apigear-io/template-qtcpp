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


#include "qmltestapi76.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi76::QmlTestApi76(QObject *parent)
    : AbstractTestApi76(parent)
{
    m_obj = ApiFactory::get()->createTestApi76();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi76::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi76::Property Changed signal
    // for usage, where QmlTestApi76 is used by the AbstractTuner interface and for connections with AbstractTestApi76::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi76::propIntChanged, this, &QmlTestApi76::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi76::propIntChanged, this, &AbstractTestApi76::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi76::propFloatChanged, this, &QmlTestApi76::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi76::propFloatChanged, this, &AbstractTestApi76::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi76::propStringChanged, this, &QmlTestApi76::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi76::propStringChanged, this, &AbstractTestApi76::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi76 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi76 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi76::sigInt, this, &AbstractTestApi76::sigInt);
    connect(m_obj.get(), &AbstractTestApi76::sigFloat, this, &AbstractTestApi76::sigFloat);
    connect(m_obj.get(), &AbstractTestApi76::sigString, this, &AbstractTestApi76::sigString);
}

QmlTestApi76::~QmlTestApi76()
{
}

int QmlTestApi76::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi76::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi76::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi76::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi76::propString() const
{
    return m_obj->propString();
}

void QmlTestApi76::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi76::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi76::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi76::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

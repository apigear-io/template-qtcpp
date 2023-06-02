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


#include "qmltestapi50.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi50::QmlTestApi50(QObject *parent)
    : AbstractTestApi50(parent)
{
    m_obj = ApiFactory::get()->createTestApi50();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi50::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi50::Property Changed signal
    // for usage, where QmlTestApi50 is used by the AbstractTuner interface and for connections with AbstractTestApi50::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi50::propIntChanged, this, &QmlTestApi50::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi50::propIntChanged, this, &AbstractTestApi50::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi50::propFloatChanged, this, &QmlTestApi50::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi50::propFloatChanged, this, &AbstractTestApi50::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi50::propStringChanged, this, &QmlTestApi50::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi50::propStringChanged, this, &AbstractTestApi50::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi50 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi50 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi50::sigInt, this, &AbstractTestApi50::sigInt);
    connect(m_obj.get(), &AbstractTestApi50::sigFloat, this, &AbstractTestApi50::sigFloat);
    connect(m_obj.get(), &AbstractTestApi50::sigString, this, &AbstractTestApi50::sigString);
}

QmlTestApi50::~QmlTestApi50()
{
}

int QmlTestApi50::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi50::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi50::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi50::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi50::propString() const
{
    return m_obj->propString();
}

void QmlTestApi50::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi50::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi50::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi50::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

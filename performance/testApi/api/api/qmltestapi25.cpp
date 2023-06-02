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


#include "qmltestapi25.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi25::QmlTestApi25(QObject *parent)
    : AbstractTestApi25(parent)
{
    m_obj = ApiFactory::get()->createTestApi25();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi25::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi25::Property Changed signal
    // for usage, where QmlTestApi25 is used by the AbstractTuner interface and for connections with AbstractTestApi25::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi25::propIntChanged, this, &QmlTestApi25::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi25::propIntChanged, this, &AbstractTestApi25::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi25::propFloatChanged, this, &QmlTestApi25::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi25::propFloatChanged, this, &AbstractTestApi25::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi25::propStringChanged, this, &QmlTestApi25::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi25::propStringChanged, this, &AbstractTestApi25::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi25 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi25 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi25::sigInt, this, &AbstractTestApi25::sigInt);
    connect(m_obj.get(), &AbstractTestApi25::sigFloat, this, &AbstractTestApi25::sigFloat);
    connect(m_obj.get(), &AbstractTestApi25::sigString, this, &AbstractTestApi25::sigString);
}

QmlTestApi25::~QmlTestApi25()
{
}

int QmlTestApi25::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi25::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi25::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi25::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi25::propString() const
{
    return m_obj->propString();
}

void QmlTestApi25::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi25::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi25::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi25::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

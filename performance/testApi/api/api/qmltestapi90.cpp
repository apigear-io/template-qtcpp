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


#include "qmltestapi90.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi90::QmlTestApi90(QObject *parent)
    : AbstractTestApi90(parent)
{
    m_obj = ApiFactory::get()->createTestApi90();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi90::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi90::Property Changed signal
    // for usage, where QmlTestApi90 is used by the AbstractTuner interface and for connections with AbstractTestApi90::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi90::propIntChanged, this, &QmlTestApi90::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi90::propIntChanged, this, &AbstractTestApi90::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi90::propFloatChanged, this, &QmlTestApi90::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi90::propFloatChanged, this, &AbstractTestApi90::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi90::propStringChanged, this, &QmlTestApi90::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi90::propStringChanged, this, &AbstractTestApi90::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi90 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi90 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi90::sigInt, this, &AbstractTestApi90::sigInt);
    connect(m_obj.get(), &AbstractTestApi90::sigFloat, this, &AbstractTestApi90::sigFloat);
    connect(m_obj.get(), &AbstractTestApi90::sigString, this, &AbstractTestApi90::sigString);
}

QmlTestApi90::~QmlTestApi90()
{
}

int QmlTestApi90::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi90::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi90::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi90::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi90::propString() const
{
    return m_obj->propString();
}

void QmlTestApi90::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi90::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi90::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi90::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

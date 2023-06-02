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


#include "qmltestapi49.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi49::QmlTestApi49(QObject *parent)
    : AbstractTestApi49(parent)
{
    m_obj = ApiFactory::get()->createTestApi49();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi49::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi49::Property Changed signal
    // for usage, where QmlTestApi49 is used by the AbstractTuner interface and for connections with AbstractTestApi49::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi49::propIntChanged, this, &QmlTestApi49::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi49::propIntChanged, this, &AbstractTestApi49::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi49::propFloatChanged, this, &QmlTestApi49::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi49::propFloatChanged, this, &AbstractTestApi49::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi49::propStringChanged, this, &QmlTestApi49::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi49::propStringChanged, this, &AbstractTestApi49::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi49 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi49 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi49::sigInt, this, &AbstractTestApi49::sigInt);
    connect(m_obj.get(), &AbstractTestApi49::sigFloat, this, &AbstractTestApi49::sigFloat);
    connect(m_obj.get(), &AbstractTestApi49::sigString, this, &AbstractTestApi49::sigString);
}

QmlTestApi49::~QmlTestApi49()
{
}

int QmlTestApi49::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi49::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi49::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi49::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi49::propString() const
{
    return m_obj->propString();
}

void QmlTestApi49::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi49::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi49::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi49::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

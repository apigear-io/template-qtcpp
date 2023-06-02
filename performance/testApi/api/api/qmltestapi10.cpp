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


#include "qmltestapi10.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi10::QmlTestApi10(QObject *parent)
    : AbstractTestApi10(parent)
{
    m_obj = ApiFactory::get()->createTestApi10();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi10::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi10::Property Changed signal
    // for usage, where QmlTestApi10 is used by the AbstractTuner interface and for connections with AbstractTestApi10::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi10::propIntChanged, this, &QmlTestApi10::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi10::propIntChanged, this, &AbstractTestApi10::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi10::propFloatChanged, this, &QmlTestApi10::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi10::propFloatChanged, this, &AbstractTestApi10::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi10::propStringChanged, this, &QmlTestApi10::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi10::propStringChanged, this, &AbstractTestApi10::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi10 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi10 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi10::sigInt, this, &AbstractTestApi10::sigInt);
    connect(m_obj.get(), &AbstractTestApi10::sigFloat, this, &AbstractTestApi10::sigFloat);
    connect(m_obj.get(), &AbstractTestApi10::sigString, this, &AbstractTestApi10::sigString);
}

QmlTestApi10::~QmlTestApi10()
{
}

int QmlTestApi10::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi10::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi10::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi10::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi10::propString() const
{
    return m_obj->propString();
}

void QmlTestApi10::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi10::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi10::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi10::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

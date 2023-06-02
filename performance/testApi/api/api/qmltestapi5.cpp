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


#include "qmltestapi5.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi5::QmlTestApi5(QObject *parent)
    : AbstractTestApi5(parent)
{
    m_obj = ApiFactory::get()->createTestApi5();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi5::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi5::Property Changed signal
    // for usage, where QmlTestApi5 is used by the AbstractTuner interface and for connections with AbstractTestApi5::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi5::propIntChanged, this, &QmlTestApi5::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi5::propIntChanged, this, &AbstractTestApi5::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi5::propFloatChanged, this, &QmlTestApi5::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi5::propFloatChanged, this, &AbstractTestApi5::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi5::propStringChanged, this, &QmlTestApi5::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi5::propStringChanged, this, &AbstractTestApi5::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi5 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi5 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi5::sigInt, this, &AbstractTestApi5::sigInt);
    connect(m_obj.get(), &AbstractTestApi5::sigFloat, this, &AbstractTestApi5::sigFloat);
    connect(m_obj.get(), &AbstractTestApi5::sigString, this, &AbstractTestApi5::sigString);
}

QmlTestApi5::~QmlTestApi5()
{
}

int QmlTestApi5::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi5::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi5::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi5::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi5::propString() const
{
    return m_obj->propString();
}

void QmlTestApi5::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi5::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi5::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi5::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

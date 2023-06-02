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


#include "qmltestapi1.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi1::QmlTestApi1(QObject *parent)
    : AbstractTestApi1(parent)
{
    m_obj = ApiFactory::get()->createTestApi1();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi1::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi1::Property Changed signal
    // for usage, where QmlTestApi1 is used by the AbstractTuner interface and for connections with AbstractTestApi1::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi1::propIntChanged, this, &QmlTestApi1::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi1::propIntChanged, this, &AbstractTestApi1::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi1::propFloatChanged, this, &QmlTestApi1::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi1::propFloatChanged, this, &AbstractTestApi1::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi1::propStringChanged, this, &QmlTestApi1::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi1::propStringChanged, this, &AbstractTestApi1::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi1 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi1 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi1::sigInt, this, &AbstractTestApi1::sigInt);
    connect(m_obj.get(), &AbstractTestApi1::sigFloat, this, &AbstractTestApi1::sigFloat);
    connect(m_obj.get(), &AbstractTestApi1::sigString, this, &AbstractTestApi1::sigString);
}

QmlTestApi1::~QmlTestApi1()
{
}

int QmlTestApi1::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi1::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi1::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi1::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi1::propString() const
{
    return m_obj->propString();
}

void QmlTestApi1::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi1::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi1::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi1::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi46.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi46::QmlTestApi46(QObject *parent)
    : AbstractTestApi46(parent)
{
    m_obj = ApiFactory::get()->createTestApi46();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi46::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi46::Property Changed signal
    // for usage, where QmlTestApi46 is used by the AbstractTuner interface and for connections with AbstractTestApi46::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi46::propIntChanged, this, &QmlTestApi46::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi46::propIntChanged, this, &AbstractTestApi46::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi46::propFloatChanged, this, &QmlTestApi46::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi46::propFloatChanged, this, &AbstractTestApi46::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi46::propStringChanged, this, &QmlTestApi46::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi46::propStringChanged, this, &AbstractTestApi46::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi46 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi46 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi46::sigInt, this, &AbstractTestApi46::sigInt);
    connect(m_obj.get(), &AbstractTestApi46::sigFloat, this, &AbstractTestApi46::sigFloat);
    connect(m_obj.get(), &AbstractTestApi46::sigString, this, &AbstractTestApi46::sigString);
}

QmlTestApi46::~QmlTestApi46()
{
}

int QmlTestApi46::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi46::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi46::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi46::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi46::propString() const
{
    return m_obj->propString();
}

void QmlTestApi46::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi46::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi46::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi46::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

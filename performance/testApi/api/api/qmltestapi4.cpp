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


#include "qmltestapi4.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi4::QmlTestApi4(QObject *parent)
    : AbstractTestApi4(parent)
{
    m_obj = ApiFactory::get()->createTestApi4();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi4::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi4::Property Changed signal
    // for usage, where QmlTestApi4 is used by the AbstractTuner interface and for connections with AbstractTestApi4::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi4::propIntChanged, this, &QmlTestApi4::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi4::propIntChanged, this, &AbstractTestApi4::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi4::propFloatChanged, this, &QmlTestApi4::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi4::propFloatChanged, this, &AbstractTestApi4::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi4::propStringChanged, this, &QmlTestApi4::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi4::propStringChanged, this, &AbstractTestApi4::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi4 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi4 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi4::sigInt, this, &AbstractTestApi4::sigInt);
    connect(m_obj.get(), &AbstractTestApi4::sigFloat, this, &AbstractTestApi4::sigFloat);
    connect(m_obj.get(), &AbstractTestApi4::sigString, this, &AbstractTestApi4::sigString);
}

QmlTestApi4::~QmlTestApi4()
{
}

int QmlTestApi4::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi4::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi4::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi4::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi4::propString() const
{
    return m_obj->propString();
}

void QmlTestApi4::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi4::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi4::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi4::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

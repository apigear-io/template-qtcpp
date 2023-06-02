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


#include "qmltestapi47.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi47::QmlTestApi47(QObject *parent)
    : AbstractTestApi47(parent)
{
    m_obj = ApiFactory::get()->createTestApi47();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi47::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi47::Property Changed signal
    // for usage, where QmlTestApi47 is used by the AbstractTuner interface and for connections with AbstractTestApi47::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi47::propIntChanged, this, &QmlTestApi47::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi47::propIntChanged, this, &AbstractTestApi47::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi47::propFloatChanged, this, &QmlTestApi47::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi47::propFloatChanged, this, &AbstractTestApi47::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi47::propStringChanged, this, &QmlTestApi47::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi47::propStringChanged, this, &AbstractTestApi47::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi47 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi47 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi47::sigInt, this, &AbstractTestApi47::sigInt);
    connect(m_obj.get(), &AbstractTestApi47::sigFloat, this, &AbstractTestApi47::sigFloat);
    connect(m_obj.get(), &AbstractTestApi47::sigString, this, &AbstractTestApi47::sigString);
}

QmlTestApi47::~QmlTestApi47()
{
}

int QmlTestApi47::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi47::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi47::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi47::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi47::propString() const
{
    return m_obj->propString();
}

void QmlTestApi47::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi47::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi47::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi47::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

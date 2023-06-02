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


#include "qmltestapi33.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi33::QmlTestApi33(QObject *parent)
    : AbstractTestApi33(parent)
{
    m_obj = ApiFactory::get()->createTestApi33();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi33::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi33::Property Changed signal
    // for usage, where QmlTestApi33 is used by the AbstractTuner interface and for connections with AbstractTestApi33::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi33::propIntChanged, this, &QmlTestApi33::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi33::propIntChanged, this, &AbstractTestApi33::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi33::propFloatChanged, this, &QmlTestApi33::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi33::propFloatChanged, this, &AbstractTestApi33::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi33::propStringChanged, this, &QmlTestApi33::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi33::propStringChanged, this, &AbstractTestApi33::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi33 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi33 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi33::sigInt, this, &AbstractTestApi33::sigInt);
    connect(m_obj.get(), &AbstractTestApi33::sigFloat, this, &AbstractTestApi33::sigFloat);
    connect(m_obj.get(), &AbstractTestApi33::sigString, this, &AbstractTestApi33::sigString);
}

QmlTestApi33::~QmlTestApi33()
{
}

int QmlTestApi33::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi33::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi33::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi33::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi33::propString() const
{
    return m_obj->propString();
}

void QmlTestApi33::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi33::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi33::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi33::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

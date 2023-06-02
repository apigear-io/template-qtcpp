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


#include "qmltestapi19.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi19::QmlTestApi19(QObject *parent)
    : AbstractTestApi19(parent)
{
    m_obj = ApiFactory::get()->createTestApi19();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi19::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi19::Property Changed signal
    // for usage, where QmlTestApi19 is used by the AbstractTuner interface and for connections with AbstractTestApi19::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi19::propIntChanged, this, &QmlTestApi19::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi19::propIntChanged, this, &AbstractTestApi19::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi19::propFloatChanged, this, &QmlTestApi19::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi19::propFloatChanged, this, &AbstractTestApi19::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi19::propStringChanged, this, &QmlTestApi19::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi19::propStringChanged, this, &AbstractTestApi19::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi19 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi19 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi19::sigInt, this, &AbstractTestApi19::sigInt);
    connect(m_obj.get(), &AbstractTestApi19::sigFloat, this, &AbstractTestApi19::sigFloat);
    connect(m_obj.get(), &AbstractTestApi19::sigString, this, &AbstractTestApi19::sigString);
}

QmlTestApi19::~QmlTestApi19()
{
}

int QmlTestApi19::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi19::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi19::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi19::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi19::propString() const
{
    return m_obj->propString();
}

void QmlTestApi19::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi19::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi19::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi19::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

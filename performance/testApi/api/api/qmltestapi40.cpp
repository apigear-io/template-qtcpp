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


#include "qmltestapi40.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi40::QmlTestApi40(QObject *parent)
    : AbstractTestApi40(parent)
{
    m_obj = ApiFactory::get()->createTestApi40();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi40::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi40::Property Changed signal
    // for usage, where QmlTestApi40 is used by the AbstractTuner interface and for connections with AbstractTestApi40::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi40::propIntChanged, this, &QmlTestApi40::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi40::propIntChanged, this, &AbstractTestApi40::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi40::propFloatChanged, this, &QmlTestApi40::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi40::propFloatChanged, this, &AbstractTestApi40::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi40::propStringChanged, this, &QmlTestApi40::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi40::propStringChanged, this, &AbstractTestApi40::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi40 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi40 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi40::sigInt, this, &AbstractTestApi40::sigInt);
    connect(m_obj.get(), &AbstractTestApi40::sigFloat, this, &AbstractTestApi40::sigFloat);
    connect(m_obj.get(), &AbstractTestApi40::sigString, this, &AbstractTestApi40::sigString);
}

QmlTestApi40::~QmlTestApi40()
{
}

int QmlTestApi40::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi40::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi40::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi40::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi40::propString() const
{
    return m_obj->propString();
}

void QmlTestApi40::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi40::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi40::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi40::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

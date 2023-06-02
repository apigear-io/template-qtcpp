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


#include "qmltestapi15.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi15::QmlTestApi15(QObject *parent)
    : AbstractTestApi15(parent)
{
    m_obj = ApiFactory::get()->createTestApi15();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi15::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi15::Property Changed signal
    // for usage, where QmlTestApi15 is used by the AbstractTuner interface and for connections with AbstractTestApi15::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi15::propIntChanged, this, &QmlTestApi15::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi15::propIntChanged, this, &AbstractTestApi15::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi15::propFloatChanged, this, &QmlTestApi15::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi15::propFloatChanged, this, &AbstractTestApi15::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi15::propStringChanged, this, &QmlTestApi15::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi15::propStringChanged, this, &AbstractTestApi15::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi15 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi15 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi15::sigInt, this, &AbstractTestApi15::sigInt);
    connect(m_obj.get(), &AbstractTestApi15::sigFloat, this, &AbstractTestApi15::sigFloat);
    connect(m_obj.get(), &AbstractTestApi15::sigString, this, &AbstractTestApi15::sigString);
}

QmlTestApi15::~QmlTestApi15()
{
}

int QmlTestApi15::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi15::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi15::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi15::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi15::propString() const
{
    return m_obj->propString();
}

void QmlTestApi15::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi15::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi15::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi15::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

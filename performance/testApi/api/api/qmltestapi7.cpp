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


#include "qmltestapi7.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi7::QmlTestApi7(QObject *parent)
    : AbstractTestApi7(parent)
{
    m_obj = ApiFactory::get()->createTestApi7();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi7::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi7::Property Changed signal
    // for usage, where QmlTestApi7 is used by the AbstractTuner interface and for connections with AbstractTestApi7::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi7::propIntChanged, this, &QmlTestApi7::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi7::propIntChanged, this, &AbstractTestApi7::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi7::propFloatChanged, this, &QmlTestApi7::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi7::propFloatChanged, this, &AbstractTestApi7::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi7::propStringChanged, this, &QmlTestApi7::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi7::propStringChanged, this, &AbstractTestApi7::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi7 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi7 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi7::sigInt, this, &AbstractTestApi7::sigInt);
    connect(m_obj.get(), &AbstractTestApi7::sigFloat, this, &AbstractTestApi7::sigFloat);
    connect(m_obj.get(), &AbstractTestApi7::sigString, this, &AbstractTestApi7::sigString);
}

QmlTestApi7::~QmlTestApi7()
{
}

int QmlTestApi7::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi7::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi7::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi7::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi7::propString() const
{
    return m_obj->propString();
}

void QmlTestApi7::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi7::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi7::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi7::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi80.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi80::QmlTestApi80(QObject *parent)
    : AbstractTestApi80(parent)
{
    m_obj = ApiFactory::get()->createTestApi80();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi80::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi80::Property Changed signal
    // for usage, where QmlTestApi80 is used by the AbstractTuner interface and for connections with AbstractTestApi80::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi80::propIntChanged, this, &QmlTestApi80::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi80::propIntChanged, this, &AbstractTestApi80::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi80::propFloatChanged, this, &QmlTestApi80::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi80::propFloatChanged, this, &AbstractTestApi80::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi80::propStringChanged, this, &QmlTestApi80::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi80::propStringChanged, this, &AbstractTestApi80::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi80 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi80 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi80::sigInt, this, &AbstractTestApi80::sigInt);
    connect(m_obj.get(), &AbstractTestApi80::sigFloat, this, &AbstractTestApi80::sigFloat);
    connect(m_obj.get(), &AbstractTestApi80::sigString, this, &AbstractTestApi80::sigString);
}

QmlTestApi80::~QmlTestApi80()
{
}

int QmlTestApi80::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi80::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi80::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi80::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi80::propString() const
{
    return m_obj->propString();
}

void QmlTestApi80::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi80::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi80::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi80::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

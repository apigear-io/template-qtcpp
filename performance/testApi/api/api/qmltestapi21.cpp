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


#include "qmltestapi21.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi21::QmlTestApi21(QObject *parent)
    : AbstractTestApi21(parent)
{
    m_obj = ApiFactory::get()->createTestApi21();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi21::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi21::Property Changed signal
    // for usage, where QmlTestApi21 is used by the AbstractTuner interface and for connections with AbstractTestApi21::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi21::propIntChanged, this, &QmlTestApi21::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi21::propIntChanged, this, &AbstractTestApi21::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi21::propFloatChanged, this, &QmlTestApi21::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi21::propFloatChanged, this, &AbstractTestApi21::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi21::propStringChanged, this, &QmlTestApi21::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi21::propStringChanged, this, &AbstractTestApi21::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi21 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi21 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi21::sigInt, this, &AbstractTestApi21::sigInt);
    connect(m_obj.get(), &AbstractTestApi21::sigFloat, this, &AbstractTestApi21::sigFloat);
    connect(m_obj.get(), &AbstractTestApi21::sigString, this, &AbstractTestApi21::sigString);
}

QmlTestApi21::~QmlTestApi21()
{
}

int QmlTestApi21::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi21::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi21::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi21::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi21::propString() const
{
    return m_obj->propString();
}

void QmlTestApi21::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi21::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi21::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi21::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

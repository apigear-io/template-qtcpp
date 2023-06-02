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


#include "qmltestapi12.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi12::QmlTestApi12(QObject *parent)
    : AbstractTestApi12(parent)
{
    m_obj = ApiFactory::get()->createTestApi12();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi12::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi12::Property Changed signal
    // for usage, where QmlTestApi12 is used by the AbstractTuner interface and for connections with AbstractTestApi12::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi12::propIntChanged, this, &QmlTestApi12::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi12::propIntChanged, this, &AbstractTestApi12::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi12::propFloatChanged, this, &QmlTestApi12::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi12::propFloatChanged, this, &AbstractTestApi12::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi12::propStringChanged, this, &QmlTestApi12::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi12::propStringChanged, this, &AbstractTestApi12::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi12 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi12 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi12::sigInt, this, &AbstractTestApi12::sigInt);
    connect(m_obj.get(), &AbstractTestApi12::sigFloat, this, &AbstractTestApi12::sigFloat);
    connect(m_obj.get(), &AbstractTestApi12::sigString, this, &AbstractTestApi12::sigString);
}

QmlTestApi12::~QmlTestApi12()
{
}

int QmlTestApi12::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi12::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi12::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi12::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi12::propString() const
{
    return m_obj->propString();
}

void QmlTestApi12::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi12::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi12::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi12::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

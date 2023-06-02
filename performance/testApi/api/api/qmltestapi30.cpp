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


#include "qmltestapi30.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi30::QmlTestApi30(QObject *parent)
    : AbstractTestApi30(parent)
{
    m_obj = ApiFactory::get()->createTestApi30();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi30::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi30::Property Changed signal
    // for usage, where QmlTestApi30 is used by the AbstractTuner interface and for connections with AbstractTestApi30::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi30::propIntChanged, this, &QmlTestApi30::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi30::propIntChanged, this, &AbstractTestApi30::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi30::propFloatChanged, this, &QmlTestApi30::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi30::propFloatChanged, this, &AbstractTestApi30::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi30::propStringChanged, this, &QmlTestApi30::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi30::propStringChanged, this, &AbstractTestApi30::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi30 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi30 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi30::sigInt, this, &AbstractTestApi30::sigInt);
    connect(m_obj.get(), &AbstractTestApi30::sigFloat, this, &AbstractTestApi30::sigFloat);
    connect(m_obj.get(), &AbstractTestApi30::sigString, this, &AbstractTestApi30::sigString);
}

QmlTestApi30::~QmlTestApi30()
{
}

int QmlTestApi30::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi30::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi30::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi30::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi30::propString() const
{
    return m_obj->propString();
}

void QmlTestApi30::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi30::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi30::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi30::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

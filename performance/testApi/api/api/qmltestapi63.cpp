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


#include "qmltestapi63.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi63::QmlTestApi63(QObject *parent)
    : AbstractTestApi63(parent)
{
    m_obj = ApiFactory::get()->createTestApi63();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi63::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi63::Property Changed signal
    // for usage, where QmlTestApi63 is used by the AbstractTuner interface and for connections with AbstractTestApi63::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi63::propIntChanged, this, &QmlTestApi63::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi63::propIntChanged, this, &AbstractTestApi63::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi63::propFloatChanged, this, &QmlTestApi63::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi63::propFloatChanged, this, &AbstractTestApi63::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi63::propStringChanged, this, &QmlTestApi63::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi63::propStringChanged, this, &AbstractTestApi63::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi63 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi63 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi63::sigInt, this, &AbstractTestApi63::sigInt);
    connect(m_obj.get(), &AbstractTestApi63::sigFloat, this, &AbstractTestApi63::sigFloat);
    connect(m_obj.get(), &AbstractTestApi63::sigString, this, &AbstractTestApi63::sigString);
}

QmlTestApi63::~QmlTestApi63()
{
}

int QmlTestApi63::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi63::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi63::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi63::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi63::propString() const
{
    return m_obj->propString();
}

void QmlTestApi63::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi63::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi63::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi63::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi58.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi58::QmlTestApi58(QObject *parent)
    : AbstractTestApi58(parent)
{
    m_obj = ApiFactory::get()->createTestApi58();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi58::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi58::Property Changed signal
    // for usage, where QmlTestApi58 is used by the AbstractTuner interface and for connections with AbstractTestApi58::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi58::propIntChanged, this, &QmlTestApi58::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi58::propIntChanged, this, &AbstractTestApi58::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi58::propFloatChanged, this, &QmlTestApi58::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi58::propFloatChanged, this, &AbstractTestApi58::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi58::propStringChanged, this, &QmlTestApi58::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi58::propStringChanged, this, &AbstractTestApi58::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi58 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi58 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi58::sigInt, this, &AbstractTestApi58::sigInt);
    connect(m_obj.get(), &AbstractTestApi58::sigFloat, this, &AbstractTestApi58::sigFloat);
    connect(m_obj.get(), &AbstractTestApi58::sigString, this, &AbstractTestApi58::sigString);
}

QmlTestApi58::~QmlTestApi58()
{
}

int QmlTestApi58::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi58::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi58::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi58::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi58::propString() const
{
    return m_obj->propString();
}

void QmlTestApi58::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi58::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi58::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi58::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

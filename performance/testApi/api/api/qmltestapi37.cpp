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


#include "qmltestapi37.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi37::QmlTestApi37(QObject *parent)
    : AbstractTestApi37(parent)
{
    m_obj = ApiFactory::get()->createTestApi37();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi37::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi37::Property Changed signal
    // for usage, where QmlTestApi37 is used by the AbstractTuner interface and for connections with AbstractTestApi37::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi37::propIntChanged, this, &QmlTestApi37::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi37::propIntChanged, this, &AbstractTestApi37::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi37::propFloatChanged, this, &QmlTestApi37::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi37::propFloatChanged, this, &AbstractTestApi37::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi37::propStringChanged, this, &QmlTestApi37::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi37::propStringChanged, this, &AbstractTestApi37::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi37 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi37 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi37::sigInt, this, &AbstractTestApi37::sigInt);
    connect(m_obj.get(), &AbstractTestApi37::sigFloat, this, &AbstractTestApi37::sigFloat);
    connect(m_obj.get(), &AbstractTestApi37::sigString, this, &AbstractTestApi37::sigString);
}

QmlTestApi37::~QmlTestApi37()
{
}

int QmlTestApi37::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi37::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi37::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi37::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi37::propString() const
{
    return m_obj->propString();
}

void QmlTestApi37::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi37::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi37::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi37::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

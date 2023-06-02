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


#include "qmltestapi74.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi74::QmlTestApi74(QObject *parent)
    : AbstractTestApi74(parent)
{
    m_obj = ApiFactory::get()->createTestApi74();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi74::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi74::Property Changed signal
    // for usage, where QmlTestApi74 is used by the AbstractTuner interface and for connections with AbstractTestApi74::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi74::propIntChanged, this, &QmlTestApi74::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi74::propIntChanged, this, &AbstractTestApi74::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi74::propFloatChanged, this, &QmlTestApi74::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi74::propFloatChanged, this, &AbstractTestApi74::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi74::propStringChanged, this, &QmlTestApi74::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi74::propStringChanged, this, &AbstractTestApi74::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi74 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi74 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi74::sigInt, this, &AbstractTestApi74::sigInt);
    connect(m_obj.get(), &AbstractTestApi74::sigFloat, this, &AbstractTestApi74::sigFloat);
    connect(m_obj.get(), &AbstractTestApi74::sigString, this, &AbstractTestApi74::sigString);
}

QmlTestApi74::~QmlTestApi74()
{
}

int QmlTestApi74::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi74::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi74::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi74::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi74::propString() const
{
    return m_obj->propString();
}

void QmlTestApi74::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi74::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi74::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi74::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

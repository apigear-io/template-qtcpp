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


#include "qmltestapi78.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi78::QmlTestApi78(QObject *parent)
    : AbstractTestApi78(parent)
{
    m_obj = ApiFactory::get()->createTestApi78();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi78::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi78::Property Changed signal
    // for usage, where QmlTestApi78 is used by the AbstractTuner interface and for connections with AbstractTestApi78::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi78::propIntChanged, this, &QmlTestApi78::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi78::propIntChanged, this, &AbstractTestApi78::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi78::propFloatChanged, this, &QmlTestApi78::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi78::propFloatChanged, this, &AbstractTestApi78::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi78::propStringChanged, this, &QmlTestApi78::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi78::propStringChanged, this, &AbstractTestApi78::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi78 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi78 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi78::sigInt, this, &AbstractTestApi78::sigInt);
    connect(m_obj.get(), &AbstractTestApi78::sigFloat, this, &AbstractTestApi78::sigFloat);
    connect(m_obj.get(), &AbstractTestApi78::sigString, this, &AbstractTestApi78::sigString);
}

QmlTestApi78::~QmlTestApi78()
{
}

int QmlTestApi78::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi78::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi78::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi78::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi78::propString() const
{
    return m_obj->propString();
}

void QmlTestApi78::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi78::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi78::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi78::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

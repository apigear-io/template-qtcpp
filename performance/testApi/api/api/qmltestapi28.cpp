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


#include "qmltestapi28.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi28::QmlTestApi28(QObject *parent)
    : AbstractTestApi28(parent)
{
    m_obj = ApiFactory::get()->createTestApi28();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi28::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi28::Property Changed signal
    // for usage, where QmlTestApi28 is used by the AbstractTuner interface and for connections with AbstractTestApi28::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi28::propIntChanged, this, &QmlTestApi28::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi28::propIntChanged, this, &AbstractTestApi28::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi28::propFloatChanged, this, &QmlTestApi28::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi28::propFloatChanged, this, &AbstractTestApi28::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi28::propStringChanged, this, &QmlTestApi28::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi28::propStringChanged, this, &AbstractTestApi28::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi28 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi28 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi28::sigInt, this, &AbstractTestApi28::sigInt);
    connect(m_obj.get(), &AbstractTestApi28::sigFloat, this, &AbstractTestApi28::sigFloat);
    connect(m_obj.get(), &AbstractTestApi28::sigString, this, &AbstractTestApi28::sigString);
}

QmlTestApi28::~QmlTestApi28()
{
}

int QmlTestApi28::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi28::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi28::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi28::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi28::propString() const
{
    return m_obj->propString();
}

void QmlTestApi28::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi28::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi28::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi28::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

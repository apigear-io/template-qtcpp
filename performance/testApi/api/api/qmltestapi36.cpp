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


#include "qmltestapi36.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi36::QmlTestApi36(QObject *parent)
    : AbstractTestApi36(parent)
{
    m_obj = ApiFactory::get()->createTestApi36();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi36::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi36::Property Changed signal
    // for usage, where QmlTestApi36 is used by the AbstractTuner interface and for connections with AbstractTestApi36::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi36::propIntChanged, this, &QmlTestApi36::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi36::propIntChanged, this, &AbstractTestApi36::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi36::propFloatChanged, this, &QmlTestApi36::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi36::propFloatChanged, this, &AbstractTestApi36::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi36::propStringChanged, this, &QmlTestApi36::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi36::propStringChanged, this, &AbstractTestApi36::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi36 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi36 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi36::sigInt, this, &AbstractTestApi36::sigInt);
    connect(m_obj.get(), &AbstractTestApi36::sigFloat, this, &AbstractTestApi36::sigFloat);
    connect(m_obj.get(), &AbstractTestApi36::sigString, this, &AbstractTestApi36::sigString);
}

QmlTestApi36::~QmlTestApi36()
{
}

int QmlTestApi36::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi36::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi36::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi36::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi36::propString() const
{
    return m_obj->propString();
}

void QmlTestApi36::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi36::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi36::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi36::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

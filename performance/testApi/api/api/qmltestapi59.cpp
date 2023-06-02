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


#include "qmltestapi59.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi59::QmlTestApi59(QObject *parent)
    : AbstractTestApi59(parent)
{
    m_obj = ApiFactory::get()->createTestApi59();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi59::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi59::Property Changed signal
    // for usage, where QmlTestApi59 is used by the AbstractTuner interface and for connections with AbstractTestApi59::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi59::propIntChanged, this, &QmlTestApi59::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi59::propIntChanged, this, &AbstractTestApi59::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi59::propFloatChanged, this, &QmlTestApi59::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi59::propFloatChanged, this, &AbstractTestApi59::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi59::propStringChanged, this, &QmlTestApi59::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi59::propStringChanged, this, &AbstractTestApi59::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi59 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi59 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi59::sigInt, this, &AbstractTestApi59::sigInt);
    connect(m_obj.get(), &AbstractTestApi59::sigFloat, this, &AbstractTestApi59::sigFloat);
    connect(m_obj.get(), &AbstractTestApi59::sigString, this, &AbstractTestApi59::sigString);
}

QmlTestApi59::~QmlTestApi59()
{
}

int QmlTestApi59::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi59::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi59::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi59::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi59::propString() const
{
    return m_obj->propString();
}

void QmlTestApi59::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi59::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi59::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi59::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

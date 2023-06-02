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


#include "qmltestapi96.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi96::QmlTestApi96(QObject *parent)
    : AbstractTestApi96(parent)
{
    m_obj = ApiFactory::get()->createTestApi96();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi96::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi96::Property Changed signal
    // for usage, where QmlTestApi96 is used by the AbstractTuner interface and for connections with AbstractTestApi96::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi96::propIntChanged, this, &QmlTestApi96::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi96::propIntChanged, this, &AbstractTestApi96::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi96::propFloatChanged, this, &QmlTestApi96::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi96::propFloatChanged, this, &AbstractTestApi96::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi96::propStringChanged, this, &QmlTestApi96::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi96::propStringChanged, this, &AbstractTestApi96::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi96 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi96 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi96::sigInt, this, &AbstractTestApi96::sigInt);
    connect(m_obj.get(), &AbstractTestApi96::sigFloat, this, &AbstractTestApi96::sigFloat);
    connect(m_obj.get(), &AbstractTestApi96::sigString, this, &AbstractTestApi96::sigString);
}

QmlTestApi96::~QmlTestApi96()
{
}

int QmlTestApi96::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi96::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi96::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi96::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi96::propString() const
{
    return m_obj->propString();
}

void QmlTestApi96::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi96::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi96::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi96::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

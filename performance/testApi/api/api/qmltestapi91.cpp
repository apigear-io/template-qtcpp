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


#include "qmltestapi91.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi91::QmlTestApi91(QObject *parent)
    : AbstractTestApi91(parent)
{
    m_obj = ApiFactory::get()->createTestApi91();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi91::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi91::Property Changed signal
    // for usage, where QmlTestApi91 is used by the AbstractTuner interface and for connections with AbstractTestApi91::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi91::propIntChanged, this, &QmlTestApi91::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi91::propIntChanged, this, &AbstractTestApi91::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi91::propFloatChanged, this, &QmlTestApi91::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi91::propFloatChanged, this, &AbstractTestApi91::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi91::propStringChanged, this, &QmlTestApi91::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi91::propStringChanged, this, &AbstractTestApi91::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi91 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi91 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi91::sigInt, this, &AbstractTestApi91::sigInt);
    connect(m_obj.get(), &AbstractTestApi91::sigFloat, this, &AbstractTestApi91::sigFloat);
    connect(m_obj.get(), &AbstractTestApi91::sigString, this, &AbstractTestApi91::sigString);
}

QmlTestApi91::~QmlTestApi91()
{
}

int QmlTestApi91::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi91::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi91::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi91::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi91::propString() const
{
    return m_obj->propString();
}

void QmlTestApi91::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi91::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi91::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi91::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

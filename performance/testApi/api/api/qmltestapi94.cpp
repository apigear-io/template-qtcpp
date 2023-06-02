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


#include "qmltestapi94.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi94::QmlTestApi94(QObject *parent)
    : AbstractTestApi94(parent)
{
    m_obj = ApiFactory::get()->createTestApi94();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi94::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi94::Property Changed signal
    // for usage, where QmlTestApi94 is used by the AbstractTuner interface and for connections with AbstractTestApi94::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi94::propIntChanged, this, &QmlTestApi94::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi94::propIntChanged, this, &AbstractTestApi94::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi94::propFloatChanged, this, &QmlTestApi94::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi94::propFloatChanged, this, &AbstractTestApi94::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi94::propStringChanged, this, &QmlTestApi94::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi94::propStringChanged, this, &AbstractTestApi94::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi94 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi94 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi94::sigInt, this, &AbstractTestApi94::sigInt);
    connect(m_obj.get(), &AbstractTestApi94::sigFloat, this, &AbstractTestApi94::sigFloat);
    connect(m_obj.get(), &AbstractTestApi94::sigString, this, &AbstractTestApi94::sigString);
}

QmlTestApi94::~QmlTestApi94()
{
}

int QmlTestApi94::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi94::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi94::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi94::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi94::propString() const
{
    return m_obj->propString();
}

void QmlTestApi94::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi94::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi94::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi94::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

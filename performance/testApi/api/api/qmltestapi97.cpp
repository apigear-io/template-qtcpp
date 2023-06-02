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


#include "qmltestapi97.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi97::QmlTestApi97(QObject *parent)
    : AbstractTestApi97(parent)
{
    m_obj = ApiFactory::get()->createTestApi97();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi97::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi97::Property Changed signal
    // for usage, where QmlTestApi97 is used by the AbstractTuner interface and for connections with AbstractTestApi97::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi97::propIntChanged, this, &QmlTestApi97::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi97::propIntChanged, this, &AbstractTestApi97::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi97::propFloatChanged, this, &QmlTestApi97::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi97::propFloatChanged, this, &AbstractTestApi97::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi97::propStringChanged, this, &QmlTestApi97::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi97::propStringChanged, this, &AbstractTestApi97::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi97 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi97 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi97::sigInt, this, &AbstractTestApi97::sigInt);
    connect(m_obj.get(), &AbstractTestApi97::sigFloat, this, &AbstractTestApi97::sigFloat);
    connect(m_obj.get(), &AbstractTestApi97::sigString, this, &AbstractTestApi97::sigString);
}

QmlTestApi97::~QmlTestApi97()
{
}

int QmlTestApi97::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi97::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi97::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi97::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi97::propString() const
{
    return m_obj->propString();
}

void QmlTestApi97::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi97::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi97::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi97::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi75.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi75::QmlTestApi75(QObject *parent)
    : AbstractTestApi75(parent)
{
    m_obj = ApiFactory::get()->createTestApi75();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi75::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi75::Property Changed signal
    // for usage, where QmlTestApi75 is used by the AbstractTuner interface and for connections with AbstractTestApi75::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi75::propIntChanged, this, &QmlTestApi75::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi75::propIntChanged, this, &AbstractTestApi75::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi75::propFloatChanged, this, &QmlTestApi75::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi75::propFloatChanged, this, &AbstractTestApi75::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi75::propStringChanged, this, &QmlTestApi75::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi75::propStringChanged, this, &AbstractTestApi75::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi75 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi75 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi75::sigInt, this, &AbstractTestApi75::sigInt);
    connect(m_obj.get(), &AbstractTestApi75::sigFloat, this, &AbstractTestApi75::sigFloat);
    connect(m_obj.get(), &AbstractTestApi75::sigString, this, &AbstractTestApi75::sigString);
}

QmlTestApi75::~QmlTestApi75()
{
}

int QmlTestApi75::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi75::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi75::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi75::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi75::propString() const
{
    return m_obj->propString();
}

void QmlTestApi75::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi75::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi75::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi75::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

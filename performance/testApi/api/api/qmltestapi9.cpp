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


#include "qmltestapi9.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi9::QmlTestApi9(QObject *parent)
    : AbstractTestApi9(parent)
{
    m_obj = ApiFactory::get()->createTestApi9();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi9::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi9::Property Changed signal
    // for usage, where QmlTestApi9 is used by the AbstractTuner interface and for connections with AbstractTestApi9::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi9::propIntChanged, this, &QmlTestApi9::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi9::propIntChanged, this, &AbstractTestApi9::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi9::propFloatChanged, this, &QmlTestApi9::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi9::propFloatChanged, this, &AbstractTestApi9::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi9::propStringChanged, this, &QmlTestApi9::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi9::propStringChanged, this, &AbstractTestApi9::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi9 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi9 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi9::sigInt, this, &AbstractTestApi9::sigInt);
    connect(m_obj.get(), &AbstractTestApi9::sigFloat, this, &AbstractTestApi9::sigFloat);
    connect(m_obj.get(), &AbstractTestApi9::sigString, this, &AbstractTestApi9::sigString);
}

QmlTestApi9::~QmlTestApi9()
{
}

int QmlTestApi9::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi9::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi9::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi9::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi9::propString() const
{
    return m_obj->propString();
}

void QmlTestApi9::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi9::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi9::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi9::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

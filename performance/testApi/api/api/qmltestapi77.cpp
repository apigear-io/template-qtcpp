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


#include "qmltestapi77.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi77::QmlTestApi77(QObject *parent)
    : AbstractTestApi77(parent)
{
    m_obj = ApiFactory::get()->createTestApi77();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi77::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi77::Property Changed signal
    // for usage, where QmlTestApi77 is used by the AbstractTuner interface and for connections with AbstractTestApi77::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi77::propIntChanged, this, &QmlTestApi77::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi77::propIntChanged, this, &AbstractTestApi77::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi77::propFloatChanged, this, &QmlTestApi77::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi77::propFloatChanged, this, &AbstractTestApi77::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi77::propStringChanged, this, &QmlTestApi77::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi77::propStringChanged, this, &AbstractTestApi77::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi77 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi77 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi77::sigInt, this, &AbstractTestApi77::sigInt);
    connect(m_obj.get(), &AbstractTestApi77::sigFloat, this, &AbstractTestApi77::sigFloat);
    connect(m_obj.get(), &AbstractTestApi77::sigString, this, &AbstractTestApi77::sigString);
}

QmlTestApi77::~QmlTestApi77()
{
}

int QmlTestApi77::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi77::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi77::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi77::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi77::propString() const
{
    return m_obj->propString();
}

void QmlTestApi77::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi77::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi77::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi77::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

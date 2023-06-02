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


#include "qmltestapi93.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi93::QmlTestApi93(QObject *parent)
    : AbstractTestApi93(parent)
{
    m_obj = ApiFactory::get()->createTestApi93();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi93::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi93::Property Changed signal
    // for usage, where QmlTestApi93 is used by the AbstractTuner interface and for connections with AbstractTestApi93::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi93::propIntChanged, this, &QmlTestApi93::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi93::propIntChanged, this, &AbstractTestApi93::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi93::propFloatChanged, this, &QmlTestApi93::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi93::propFloatChanged, this, &AbstractTestApi93::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi93::propStringChanged, this, &QmlTestApi93::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi93::propStringChanged, this, &AbstractTestApi93::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi93 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi93 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi93::sigInt, this, &AbstractTestApi93::sigInt);
    connect(m_obj.get(), &AbstractTestApi93::sigFloat, this, &AbstractTestApi93::sigFloat);
    connect(m_obj.get(), &AbstractTestApi93::sigString, this, &AbstractTestApi93::sigString);
}

QmlTestApi93::~QmlTestApi93()
{
}

int QmlTestApi93::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi93::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi93::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi93::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi93::propString() const
{
    return m_obj->propString();
}

void QmlTestApi93::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi93::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi93::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi93::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

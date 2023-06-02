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


#include "qmltestapi68.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi68::QmlTestApi68(QObject *parent)
    : AbstractTestApi68(parent)
{
    m_obj = ApiFactory::get()->createTestApi68();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi68::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi68::Property Changed signal
    // for usage, where QmlTestApi68 is used by the AbstractTuner interface and for connections with AbstractTestApi68::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi68::propIntChanged, this, &QmlTestApi68::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi68::propIntChanged, this, &AbstractTestApi68::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi68::propFloatChanged, this, &QmlTestApi68::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi68::propFloatChanged, this, &AbstractTestApi68::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi68::propStringChanged, this, &QmlTestApi68::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi68::propStringChanged, this, &AbstractTestApi68::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi68 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi68 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi68::sigInt, this, &AbstractTestApi68::sigInt);
    connect(m_obj.get(), &AbstractTestApi68::sigFloat, this, &AbstractTestApi68::sigFloat);
    connect(m_obj.get(), &AbstractTestApi68::sigString, this, &AbstractTestApi68::sigString);
}

QmlTestApi68::~QmlTestApi68()
{
}

int QmlTestApi68::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi68::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi68::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi68::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi68::propString() const
{
    return m_obj->propString();
}

void QmlTestApi68::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi68::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi68::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi68::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

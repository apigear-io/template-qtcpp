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


#include "qmltestapi92.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi92::QmlTestApi92(QObject *parent)
    : AbstractTestApi92(parent)
{
    m_obj = ApiFactory::get()->createTestApi92();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi92::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi92::Property Changed signal
    // for usage, where QmlTestApi92 is used by the AbstractTuner interface and for connections with AbstractTestApi92::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi92::propIntChanged, this, &QmlTestApi92::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi92::propIntChanged, this, &AbstractTestApi92::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi92::propFloatChanged, this, &QmlTestApi92::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi92::propFloatChanged, this, &AbstractTestApi92::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi92::propStringChanged, this, &QmlTestApi92::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi92::propStringChanged, this, &AbstractTestApi92::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi92 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi92 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi92::sigInt, this, &AbstractTestApi92::sigInt);
    connect(m_obj.get(), &AbstractTestApi92::sigFloat, this, &AbstractTestApi92::sigFloat);
    connect(m_obj.get(), &AbstractTestApi92::sigString, this, &AbstractTestApi92::sigString);
}

QmlTestApi92::~QmlTestApi92()
{
}

int QmlTestApi92::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi92::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi92::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi92::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi92::propString() const
{
    return m_obj->propString();
}

void QmlTestApi92::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi92::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi92::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi92::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

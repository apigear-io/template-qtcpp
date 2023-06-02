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


#include "qmltestapi69.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi69::QmlTestApi69(QObject *parent)
    : AbstractTestApi69(parent)
{
    m_obj = ApiFactory::get()->createTestApi69();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi69::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi69::Property Changed signal
    // for usage, where QmlTestApi69 is used by the AbstractTuner interface and for connections with AbstractTestApi69::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi69::propIntChanged, this, &QmlTestApi69::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi69::propIntChanged, this, &AbstractTestApi69::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi69::propFloatChanged, this, &QmlTestApi69::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi69::propFloatChanged, this, &AbstractTestApi69::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi69::propStringChanged, this, &QmlTestApi69::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi69::propStringChanged, this, &AbstractTestApi69::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi69 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi69 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi69::sigInt, this, &AbstractTestApi69::sigInt);
    connect(m_obj.get(), &AbstractTestApi69::sigFloat, this, &AbstractTestApi69::sigFloat);
    connect(m_obj.get(), &AbstractTestApi69::sigString, this, &AbstractTestApi69::sigString);
}

QmlTestApi69::~QmlTestApi69()
{
}

int QmlTestApi69::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi69::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi69::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi69::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi69::propString() const
{
    return m_obj->propString();
}

void QmlTestApi69::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi69::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi69::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi69::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

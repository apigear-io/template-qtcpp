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


#include "qmltestapi41.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi41::QmlTestApi41(QObject *parent)
    : AbstractTestApi41(parent)
{
    m_obj = ApiFactory::get()->createTestApi41();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi41::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi41::Property Changed signal
    // for usage, where QmlTestApi41 is used by the AbstractTuner interface and for connections with AbstractTestApi41::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi41::propIntChanged, this, &QmlTestApi41::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi41::propIntChanged, this, &AbstractTestApi41::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi41::propFloatChanged, this, &QmlTestApi41::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi41::propFloatChanged, this, &AbstractTestApi41::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi41::propStringChanged, this, &QmlTestApi41::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi41::propStringChanged, this, &AbstractTestApi41::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi41 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi41 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi41::sigInt, this, &AbstractTestApi41::sigInt);
    connect(m_obj.get(), &AbstractTestApi41::sigFloat, this, &AbstractTestApi41::sigFloat);
    connect(m_obj.get(), &AbstractTestApi41::sigString, this, &AbstractTestApi41::sigString);
}

QmlTestApi41::~QmlTestApi41()
{
}

int QmlTestApi41::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi41::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi41::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi41::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi41::propString() const
{
    return m_obj->propString();
}

void QmlTestApi41::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi41::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi41::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi41::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

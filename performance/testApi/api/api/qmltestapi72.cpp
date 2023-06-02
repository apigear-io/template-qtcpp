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


#include "qmltestapi72.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi72::QmlTestApi72(QObject *parent)
    : AbstractTestApi72(parent)
{
    m_obj = ApiFactory::get()->createTestApi72();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi72::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi72::Property Changed signal
    // for usage, where QmlTestApi72 is used by the AbstractTuner interface and for connections with AbstractTestApi72::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi72::propIntChanged, this, &QmlTestApi72::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi72::propIntChanged, this, &AbstractTestApi72::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi72::propFloatChanged, this, &QmlTestApi72::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi72::propFloatChanged, this, &AbstractTestApi72::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi72::propStringChanged, this, &QmlTestApi72::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi72::propStringChanged, this, &AbstractTestApi72::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi72 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi72 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi72::sigInt, this, &AbstractTestApi72::sigInt);
    connect(m_obj.get(), &AbstractTestApi72::sigFloat, this, &AbstractTestApi72::sigFloat);
    connect(m_obj.get(), &AbstractTestApi72::sigString, this, &AbstractTestApi72::sigString);
}

QmlTestApi72::~QmlTestApi72()
{
}

int QmlTestApi72::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi72::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi72::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi72::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi72::propString() const
{
    return m_obj->propString();
}

void QmlTestApi72::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi72::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi72::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi72::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

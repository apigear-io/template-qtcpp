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


#include "qmltestapi39.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi39::QmlTestApi39(QObject *parent)
    : AbstractTestApi39(parent)
{
    m_obj = ApiFactory::get()->createTestApi39();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi39::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi39::Property Changed signal
    // for usage, where QmlTestApi39 is used by the AbstractTuner interface and for connections with AbstractTestApi39::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi39::propIntChanged, this, &QmlTestApi39::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi39::propIntChanged, this, &AbstractTestApi39::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi39::propFloatChanged, this, &QmlTestApi39::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi39::propFloatChanged, this, &AbstractTestApi39::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi39::propStringChanged, this, &QmlTestApi39::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi39::propStringChanged, this, &AbstractTestApi39::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi39 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi39 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi39::sigInt, this, &AbstractTestApi39::sigInt);
    connect(m_obj.get(), &AbstractTestApi39::sigFloat, this, &AbstractTestApi39::sigFloat);
    connect(m_obj.get(), &AbstractTestApi39::sigString, this, &AbstractTestApi39::sigString);
}

QmlTestApi39::~QmlTestApi39()
{
}

int QmlTestApi39::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi39::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi39::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi39::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi39::propString() const
{
    return m_obj->propString();
}

void QmlTestApi39::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi39::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi39::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi39::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

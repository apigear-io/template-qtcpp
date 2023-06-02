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


#include "qmltestapi53.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi53::QmlTestApi53(QObject *parent)
    : AbstractTestApi53(parent)
{
    m_obj = ApiFactory::get()->createTestApi53();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi53::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi53::Property Changed signal
    // for usage, where QmlTestApi53 is used by the AbstractTuner interface and for connections with AbstractTestApi53::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi53::propIntChanged, this, &QmlTestApi53::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi53::propIntChanged, this, &AbstractTestApi53::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi53::propFloatChanged, this, &QmlTestApi53::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi53::propFloatChanged, this, &AbstractTestApi53::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi53::propStringChanged, this, &QmlTestApi53::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi53::propStringChanged, this, &AbstractTestApi53::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi53 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi53 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi53::sigInt, this, &AbstractTestApi53::sigInt);
    connect(m_obj.get(), &AbstractTestApi53::sigFloat, this, &AbstractTestApi53::sigFloat);
    connect(m_obj.get(), &AbstractTestApi53::sigString, this, &AbstractTestApi53::sigString);
}

QmlTestApi53::~QmlTestApi53()
{
}

int QmlTestApi53::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi53::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi53::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi53::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi53::propString() const
{
    return m_obj->propString();
}

void QmlTestApi53::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi53::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi53::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi53::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

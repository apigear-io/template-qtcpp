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


#include "qmltestapi99.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi99::QmlTestApi99(QObject *parent)
    : AbstractTestApi99(parent)
{
    m_obj = ApiFactory::get()->createTestApi99();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi99::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi99::Property Changed signal
    // for usage, where QmlTestApi99 is used by the AbstractTuner interface and for connections with AbstractTestApi99::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi99::propIntChanged, this, &QmlTestApi99::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi99::propIntChanged, this, &AbstractTestApi99::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi99::propFloatChanged, this, &QmlTestApi99::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi99::propFloatChanged, this, &AbstractTestApi99::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi99::propStringChanged, this, &QmlTestApi99::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi99::propStringChanged, this, &AbstractTestApi99::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi99 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi99 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi99::sigInt, this, &AbstractTestApi99::sigInt);
    connect(m_obj.get(), &AbstractTestApi99::sigFloat, this, &AbstractTestApi99::sigFloat);
    connect(m_obj.get(), &AbstractTestApi99::sigString, this, &AbstractTestApi99::sigString);
}

QmlTestApi99::~QmlTestApi99()
{
}

int QmlTestApi99::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi99::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi99::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi99::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi99::propString() const
{
    return m_obj->propString();
}

void QmlTestApi99::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi99::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi99::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi99::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

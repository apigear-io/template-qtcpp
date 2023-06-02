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


#include "qmltestapi56.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi56::QmlTestApi56(QObject *parent)
    : AbstractTestApi56(parent)
{
    m_obj = ApiFactory::get()->createTestApi56();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi56::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi56::Property Changed signal
    // for usage, where QmlTestApi56 is used by the AbstractTuner interface and for connections with AbstractTestApi56::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi56::propIntChanged, this, &QmlTestApi56::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi56::propIntChanged, this, &AbstractTestApi56::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi56::propFloatChanged, this, &QmlTestApi56::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi56::propFloatChanged, this, &AbstractTestApi56::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi56::propStringChanged, this, &QmlTestApi56::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi56::propStringChanged, this, &AbstractTestApi56::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi56 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi56 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi56::sigInt, this, &AbstractTestApi56::sigInt);
    connect(m_obj.get(), &AbstractTestApi56::sigFloat, this, &AbstractTestApi56::sigFloat);
    connect(m_obj.get(), &AbstractTestApi56::sigString, this, &AbstractTestApi56::sigString);
}

QmlTestApi56::~QmlTestApi56()
{
}

int QmlTestApi56::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi56::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi56::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi56::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi56::propString() const
{
    return m_obj->propString();
}

void QmlTestApi56::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi56::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi56::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi56::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi73.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi73::QmlTestApi73(QObject *parent)
    : AbstractTestApi73(parent)
{
    m_obj = ApiFactory::get()->createTestApi73();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi73::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi73::Property Changed signal
    // for usage, where QmlTestApi73 is used by the AbstractTuner interface and for connections with AbstractTestApi73::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi73::propIntChanged, this, &QmlTestApi73::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi73::propIntChanged, this, &AbstractTestApi73::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi73::propFloatChanged, this, &QmlTestApi73::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi73::propFloatChanged, this, &AbstractTestApi73::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi73::propStringChanged, this, &QmlTestApi73::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi73::propStringChanged, this, &AbstractTestApi73::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi73 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi73 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi73::sigInt, this, &AbstractTestApi73::sigInt);
    connect(m_obj.get(), &AbstractTestApi73::sigFloat, this, &AbstractTestApi73::sigFloat);
    connect(m_obj.get(), &AbstractTestApi73::sigString, this, &AbstractTestApi73::sigString);
}

QmlTestApi73::~QmlTestApi73()
{
}

int QmlTestApi73::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi73::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi73::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi73::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi73::propString() const
{
    return m_obj->propString();
}

void QmlTestApi73::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi73::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi73::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi73::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

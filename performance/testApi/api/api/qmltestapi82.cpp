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


#include "qmltestapi82.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi82::QmlTestApi82(QObject *parent)
    : AbstractTestApi82(parent)
{
    m_obj = ApiFactory::get()->createTestApi82();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi82::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi82::Property Changed signal
    // for usage, where QmlTestApi82 is used by the AbstractTuner interface and for connections with AbstractTestApi82::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi82::propIntChanged, this, &QmlTestApi82::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi82::propIntChanged, this, &AbstractTestApi82::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi82::propFloatChanged, this, &QmlTestApi82::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi82::propFloatChanged, this, &AbstractTestApi82::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi82::propStringChanged, this, &QmlTestApi82::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi82::propStringChanged, this, &AbstractTestApi82::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi82 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi82 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi82::sigInt, this, &AbstractTestApi82::sigInt);
    connect(m_obj.get(), &AbstractTestApi82::sigFloat, this, &AbstractTestApi82::sigFloat);
    connect(m_obj.get(), &AbstractTestApi82::sigString, this, &AbstractTestApi82::sigString);
}

QmlTestApi82::~QmlTestApi82()
{
}

int QmlTestApi82::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi82::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi82::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi82::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi82::propString() const
{
    return m_obj->propString();
}

void QmlTestApi82::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi82::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi82::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi82::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

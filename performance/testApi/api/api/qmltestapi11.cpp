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


#include "qmltestapi11.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi11::QmlTestApi11(QObject *parent)
    : AbstractTestApi11(parent)
{
    m_obj = ApiFactory::get()->createTestApi11();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi11::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi11::Property Changed signal
    // for usage, where QmlTestApi11 is used by the AbstractTuner interface and for connections with AbstractTestApi11::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi11::propIntChanged, this, &QmlTestApi11::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi11::propIntChanged, this, &AbstractTestApi11::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi11::propFloatChanged, this, &QmlTestApi11::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi11::propFloatChanged, this, &AbstractTestApi11::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi11::propStringChanged, this, &QmlTestApi11::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi11::propStringChanged, this, &AbstractTestApi11::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi11 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi11 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi11::sigInt, this, &AbstractTestApi11::sigInt);
    connect(m_obj.get(), &AbstractTestApi11::sigFloat, this, &AbstractTestApi11::sigFloat);
    connect(m_obj.get(), &AbstractTestApi11::sigString, this, &AbstractTestApi11::sigString);
}

QmlTestApi11::~QmlTestApi11()
{
}

int QmlTestApi11::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi11::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi11::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi11::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi11::propString() const
{
    return m_obj->propString();
}

void QmlTestApi11::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi11::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi11::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi11::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

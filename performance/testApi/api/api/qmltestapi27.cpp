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


#include "qmltestapi27.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi27::QmlTestApi27(QObject *parent)
    : AbstractTestApi27(parent)
{
    m_obj = ApiFactory::get()->createTestApi27();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi27::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi27::Property Changed signal
    // for usage, where QmlTestApi27 is used by the AbstractTuner interface and for connections with AbstractTestApi27::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi27::propIntChanged, this, &QmlTestApi27::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi27::propIntChanged, this, &AbstractTestApi27::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi27::propFloatChanged, this, &QmlTestApi27::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi27::propFloatChanged, this, &AbstractTestApi27::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi27::propStringChanged, this, &QmlTestApi27::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi27::propStringChanged, this, &AbstractTestApi27::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi27 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi27 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi27::sigInt, this, &AbstractTestApi27::sigInt);
    connect(m_obj.get(), &AbstractTestApi27::sigFloat, this, &AbstractTestApi27::sigFloat);
    connect(m_obj.get(), &AbstractTestApi27::sigString, this, &AbstractTestApi27::sigString);
}

QmlTestApi27::~QmlTestApi27()
{
}

int QmlTestApi27::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi27::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi27::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi27::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi27::propString() const
{
    return m_obj->propString();
}

void QmlTestApi27::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi27::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi27::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi27::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

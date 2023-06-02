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


#include "qmltestapi88.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi88::QmlTestApi88(QObject *parent)
    : AbstractTestApi88(parent)
{
    m_obj = ApiFactory::get()->createTestApi88();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi88::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi88::Property Changed signal
    // for usage, where QmlTestApi88 is used by the AbstractTuner interface and for connections with AbstractTestApi88::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi88::propIntChanged, this, &QmlTestApi88::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi88::propIntChanged, this, &AbstractTestApi88::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi88::propFloatChanged, this, &QmlTestApi88::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi88::propFloatChanged, this, &AbstractTestApi88::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi88::propStringChanged, this, &QmlTestApi88::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi88::propStringChanged, this, &AbstractTestApi88::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi88 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi88 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi88::sigInt, this, &AbstractTestApi88::sigInt);
    connect(m_obj.get(), &AbstractTestApi88::sigFloat, this, &AbstractTestApi88::sigFloat);
    connect(m_obj.get(), &AbstractTestApi88::sigString, this, &AbstractTestApi88::sigString);
}

QmlTestApi88::~QmlTestApi88()
{
}

int QmlTestApi88::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi88::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi88::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi88::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi88::propString() const
{
    return m_obj->propString();
}

void QmlTestApi88::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi88::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi88::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi88::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmltestapi54.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi54::QmlTestApi54(QObject *parent)
    : AbstractTestApi54(parent)
{
    m_obj = ApiFactory::get()->createTestApi54();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi54::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi54::Property Changed signal
    // for usage, where QmlTestApi54 is used by the AbstractTuner interface and for connections with AbstractTestApi54::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi54::propIntChanged, this, &QmlTestApi54::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi54::propIntChanged, this, &AbstractTestApi54::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi54::propFloatChanged, this, &QmlTestApi54::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi54::propFloatChanged, this, &AbstractTestApi54::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi54::propStringChanged, this, &QmlTestApi54::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi54::propStringChanged, this, &AbstractTestApi54::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi54 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi54 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi54::sigInt, this, &AbstractTestApi54::sigInt);
    connect(m_obj.get(), &AbstractTestApi54::sigFloat, this, &AbstractTestApi54::sigFloat);
    connect(m_obj.get(), &AbstractTestApi54::sigString, this, &AbstractTestApi54::sigString);
}

QmlTestApi54::~QmlTestApi54()
{
}

int QmlTestApi54::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi54::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi54::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi54::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi54::propString() const
{
    return m_obj->propString();
}

void QmlTestApi54::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi54::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi54::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi54::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

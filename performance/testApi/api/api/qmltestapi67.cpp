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


#include "qmltestapi67.h"
#include "apifactory.h"

#include <QtQml>

namespace api {

QmlTestApi67::QmlTestApi67(QObject *parent)
    : AbstractTestApi67(parent)
{
    m_obj = ApiFactory::get()->createTestApi67();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlTestApi67::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractTestApi67::Property Changed signal
    // for usage, where QmlTestApi67 is used by the AbstractTuner interface and for connections with AbstractTestApi67::Property Changed signal
    connect(m_obj.get(), &AbstractTestApi67::propIntChanged, this, &QmlTestApi67::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi67::propIntChanged, this, &AbstractTestApi67::propIntChanged);
    connect(m_obj.get(), &AbstractTestApi67::propFloatChanged, this, &QmlTestApi67::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi67::propFloatChanged, this, &AbstractTestApi67::propFloatChanged);
    connect(m_obj.get(), &AbstractTestApi67::propStringChanged, this, &QmlTestApi67::propStringChanged);
    connect(m_obj.get(), &AbstractTestApi67::propStringChanged, this, &AbstractTestApi67::propStringChanged);

    // Forward the singals emitted by backend implementation to QmlTestApi67 wrapper.
    //  Have in mind that there is no forwarding from the QmlTestApi67 wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractTestApi67::sigInt, this, &AbstractTestApi67::sigInt);
    connect(m_obj.get(), &AbstractTestApi67::sigFloat, this, &AbstractTestApi67::sigFloat);
    connect(m_obj.get(), &AbstractTestApi67::sigString, this, &AbstractTestApi67::sigString);
}

QmlTestApi67::~QmlTestApi67()
{
}

int QmlTestApi67::propInt() const
{
    return m_obj->propInt();
}

void QmlTestApi67::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

qreal QmlTestApi67::propFloat() const
{
    return m_obj->propFloat();
}

void QmlTestApi67::setPropFloat(qreal propFloat)
{
    return m_obj->setPropFloat(propFloat);
}

QString QmlTestApi67::propString() const
{
    return m_obj->propString();
}

void QmlTestApi67::setPropString(const QString& propString)
{
    return m_obj->setPropString(propString);
}

int QmlTestApi67::funcInt(int paramInt)
{
    return m_obj->funcInt(paramInt);
}

qreal QmlTestApi67::funcFloat(qreal paramFloat)
{
    return m_obj->funcFloat(paramFloat);
}

QString QmlTestApi67::funcString(const QString& paramString)
{
    return m_obj->funcString(paramString);
}

} //namespace api

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


#include "qmlnam_es.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_names {

QmlNamEs::QmlNamEs(QObject *parent)
    : AbstractNamEs(parent)
{
    m_obj = ApiFactory::get()->createNamEs();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlNamEs::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractNamEs::Property Changed signal
    // for usage, where QmlNamEs is used by the AbstractTuner interface and for connections with AbstractNamEs::Property Changed signal
    connect(m_obj.get(), &AbstractNamEs::SwitchChanged, this, &QmlNamEs::SwitchChanged);
    connect(m_obj.get(), &AbstractNamEs::SwitchChanged, this, &AbstractNamEs::SwitchChanged);
    connect(m_obj.get(), &AbstractNamEs::SOME_PROPERTYChanged, this, &QmlNamEs::SOME_PROPERTYChanged);
    connect(m_obj.get(), &AbstractNamEs::SOME_PROPERTYChanged, this, &AbstractNamEs::SOME_PROPERTYChanged);
    connect(m_obj.get(), &AbstractNamEs::Some_Poperty2Changed, this, &QmlNamEs::Some_Poperty2Changed);
    connect(m_obj.get(), &AbstractNamEs::Some_Poperty2Changed, this, &AbstractNamEs::Some_Poperty2Changed);

    // Forward the singals emitted by backend implementation to QmlNamEs wrapper.
    //  Have in mind that there is no forwarding from the QmlNamEs wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractNamEs::someSignal, this, &AbstractNamEs::someSignal);
    connect(m_obj.get(), &AbstractNamEs::someSignal2, this, &AbstractNamEs::someSignal2);
}

QmlNamEs::~QmlNamEs()
{
}

bool QmlNamEs::Switch() const
{
    return m_obj->Switch();
}

void QmlNamEs::setSwitch(bool Switch)
{
    return m_obj->setSwitch(Switch);
}

int QmlNamEs::SOME_PROPERTY() const
{
    return m_obj->SOME_PROPERTY();
}

void QmlNamEs::setSomeProperty(int SOME_PROPERTY)
{
    return m_obj->setSomeProperty(SOME_PROPERTY);
}

int QmlNamEs::Some_Poperty2() const
{
    return m_obj->Some_Poperty2();
}

void QmlNamEs::setSomePoperty2(int Some_Poperty2)
{
    return m_obj->setSomePoperty2(Some_Poperty2);
}

void QmlNamEs::someFunction(bool SOME_PARAM)
{
    return m_obj->someFunction(SOME_PARAM);
}

void QmlNamEs::someFunction2(bool Some_Param)
{
    return m_obj->someFunction2(Some_Param);
}

} //namespace tb_names

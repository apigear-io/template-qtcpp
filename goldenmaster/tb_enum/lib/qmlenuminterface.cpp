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


#include "qmlenuminterface.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

QmlEnumInterface::QmlEnumInterface(QObject *parent)
    : AbstractEnumInterface(parent)
{
    m_obj = ApiFactory::get()->createEnumInterface(this);
    connect(m_obj, &AbstractEnumInterface::prop0Changed, this, &QmlEnumInterface::prop0Changed);
    connect(m_obj, &AbstractEnumInterface::prop0Changed, this, &AbstractEnumInterface::prop0Changed);
    connect(m_obj, &AbstractEnumInterface::prop1Changed, this, &QmlEnumInterface::prop1Changed);
    connect(m_obj, &AbstractEnumInterface::prop1Changed, this, &AbstractEnumInterface::prop1Changed);
    connect(m_obj, &AbstractEnumInterface::prop2Changed, this, &QmlEnumInterface::prop2Changed);
    connect(m_obj, &AbstractEnumInterface::prop2Changed, this, &AbstractEnumInterface::prop2Changed);
    connect(m_obj, &AbstractEnumInterface::prop3Changed, this, &QmlEnumInterface::prop3Changed);
    connect(m_obj, &AbstractEnumInterface::prop3Changed, this, &AbstractEnumInterface::prop3Changed);
    connect(m_obj, &AbstractEnumInterface::sig0, this, &QmlEnumInterface::sig0);
    connect(m_obj, &AbstractEnumInterface::sig0, this, &AbstractEnumInterface::sig0);
    connect(m_obj, &AbstractEnumInterface::sig1, this, &QmlEnumInterface::sig1);
    connect(m_obj, &AbstractEnumInterface::sig1, this, &AbstractEnumInterface::sig1);
    connect(m_obj, &AbstractEnumInterface::sig2, this, &QmlEnumInterface::sig2);
    connect(m_obj, &AbstractEnumInterface::sig2, this, &AbstractEnumInterface::sig2);
    connect(m_obj, &AbstractEnumInterface::sig3, this, &QmlEnumInterface::sig3);
    connect(m_obj, &AbstractEnumInterface::sig3, this, &AbstractEnumInterface::sig3);
}

QmlEnumInterface::~QmlEnumInterface()
{
}

Enum0::Enum0Enum QmlEnumInterface::prop0() const
{
    return m_obj->prop0();
}

void QmlEnumInterface::setProp0(const Enum0::Enum0Enum prop0)
{
    EnumInterfaceAgent::capture_state(this);
    return m_obj->setProp0(prop0);
}

Enum1::Enum1Enum QmlEnumInterface::prop1() const
{
    return m_obj->prop1();
}

void QmlEnumInterface::setProp1(const Enum1::Enum1Enum prop1)
{
    EnumInterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

Enum2::Enum2Enum QmlEnumInterface::prop2() const
{
    return m_obj->prop2();
}

void QmlEnumInterface::setProp2(const Enum2::Enum2Enum prop2)
{
    EnumInterfaceAgent::capture_state(this);
    return m_obj->setProp2(prop2);
}

Enum3::Enum3Enum QmlEnumInterface::prop3() const
{
    return m_obj->prop3();
}

void QmlEnumInterface::setProp3(const Enum3::Enum3Enum prop3)
{
    EnumInterfaceAgent::capture_state(this);
    return m_obj->setProp3(prop3);
}

Enum0::Enum0Enum QmlEnumInterface::func0(const Enum0::Enum0Enum param0)
{
    EnumInterfaceAgent::trace_func0(this, param0);
	
    return m_obj->func0(param0);
}

Enum1::Enum1Enum QmlEnumInterface::func1(const Enum1::Enum1Enum param1)
{
    EnumInterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

Enum2::Enum2Enum QmlEnumInterface::func2(const Enum2::Enum2Enum param2)
{
    EnumInterfaceAgent::trace_func2(this, param2);
	
    return m_obj->func2(param2);
}

Enum3::Enum3Enum QmlEnumInterface::func3(const Enum3::Enum3Enum param3)
{
    EnumInterfaceAgent::trace_func3(this, param3);
	
    return m_obj->func3(param3);
}
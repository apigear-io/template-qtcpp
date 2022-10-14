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


#include "qmlnestedstruct2interface.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

QmlNestedStruct2Interface::QmlNestedStruct2Interface(QObject *parent)
    : AbstractNestedStruct2Interface(parent)
{
    m_obj = ApiFactory::get()->createNestedStruct2Interface(this);
    connect(m_obj, &AbstractNestedStruct2Interface::prop1Changed, this, &QmlNestedStruct2Interface::prop1Changed);
    connect(m_obj, &AbstractNestedStruct2Interface::prop1Changed, this, &AbstractNestedStruct2Interface::prop1Changed);
    connect(m_obj, &AbstractNestedStruct2Interface::prop2Changed, this, &QmlNestedStruct2Interface::prop2Changed);
    connect(m_obj, &AbstractNestedStruct2Interface::prop2Changed, this, &AbstractNestedStruct2Interface::prop2Changed);
    connect(m_obj, &AbstractNestedStruct2Interface::sig1, this, &QmlNestedStruct2Interface::sig1);
    connect(m_obj, &AbstractNestedStruct2Interface::sig1, this, &AbstractNestedStruct2Interface::sig1);
    connect(m_obj, &AbstractNestedStruct2Interface::sig2, this, &QmlNestedStruct2Interface::sig2);
    connect(m_obj, &AbstractNestedStruct2Interface::sig2, this, &AbstractNestedStruct2Interface::sig2);
}

QmlNestedStruct2Interface::~QmlNestedStruct2Interface()
{
}

NestedStruct1 QmlNestedStruct2Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    NestedStruct2InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

NestedStruct2 QmlNestedStruct2Interface::prop2() const
{
    return m_obj->prop2();
}

void QmlNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    NestedStruct2InterfaceAgent::capture_state(this);
    return m_obj->setProp2(prop2);
}

NestedStruct1 QmlNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    NestedStruct2InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

NestedStruct1 QmlNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    NestedStruct2InterfaceAgent::trace_func2(this, param1, param2);
	
    return m_obj->func2(param1,param2);
}
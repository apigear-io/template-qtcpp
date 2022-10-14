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


#include "qmlnestedstruct1interface.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

QmlNestedStruct1Interface::QmlNestedStruct1Interface(QObject *parent)
    : AbstractNestedStruct1Interface(parent)
{
    m_obj = ApiFactory::get()->createNestedStruct1Interface(this);
    connect(m_obj, &AbstractNestedStruct1Interface::prop1Changed, this, &QmlNestedStruct1Interface::prop1Changed);
    connect(m_obj, &AbstractNestedStruct1Interface::prop1Changed, this, &AbstractNestedStruct1Interface::prop1Changed);
    connect(m_obj, &AbstractNestedStruct1Interface::sig1, this, &QmlNestedStruct1Interface::sig1);
    connect(m_obj, &AbstractNestedStruct1Interface::sig1, this, &AbstractNestedStruct1Interface::sig1);
}

QmlNestedStruct1Interface::~QmlNestedStruct1Interface()
{
}

NestedStruct1 QmlNestedStruct1Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    NestedStruct1InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

NestedStruct1 QmlNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    NestedStruct1InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}
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


#include "qmlsamestruct1interface.h"
#include "tb_same2/api/apifactory.h"
#include "tb_same2/api/agent.h"

#include <QtQml>

QmlSameStruct1Interface::QmlSameStruct1Interface(QObject *parent)
    : AbstractSameStruct1Interface(parent)
{
    m_obj = ApiFactory::get()->createSameStruct1Interface(this);
    connect(m_obj, &AbstractSameStruct1Interface::prop1Changed, this, &QmlSameStruct1Interface::prop1Changed);
    connect(m_obj, &AbstractSameStruct1Interface::prop1Changed, this, &AbstractSameStruct1Interface::prop1Changed);
    connect(m_obj, &AbstractSameStruct1Interface::sig1, this, &QmlSameStruct1Interface::sig1);
    connect(m_obj, &AbstractSameStruct1Interface::sig1, this, &AbstractSameStruct1Interface::sig1);
}

QmlSameStruct1Interface::~QmlSameStruct1Interface()
{
}

Struct1 QmlSameStruct1Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlSameStruct1Interface::setProp1(const Struct1& prop1)
{
    SameStruct1InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

Struct1 QmlSameStruct1Interface::func1(const Struct1& param1)
{
    SameStruct1InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}
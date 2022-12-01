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


#include "qmlsamestruct2interface.h"
#include "tb_same1/api/apifactory.h"
#include "tb_same1/api/agent.h"

#include <QtQml>

QmlSameStruct2Interface::QmlSameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
{
    m_obj = ApiFactory::get()->createSameStruct2Interface(this);
    connect(m_obj, &AbstractSameStruct2Interface::prop1Changed, this, &QmlSameStruct2Interface::prop1Changed);
    connect(m_obj, &AbstractSameStruct2Interface::prop1Changed, this, &AbstractSameStruct2Interface::prop1Changed);
    connect(m_obj, &AbstractSameStruct2Interface::prop2Changed, this, &QmlSameStruct2Interface::prop2Changed);
    connect(m_obj, &AbstractSameStruct2Interface::prop2Changed, this, &AbstractSameStruct2Interface::prop2Changed);
    connect(m_obj, &AbstractSameStruct2Interface::sig1, this, &QmlSameStruct2Interface::sig1);
    connect(m_obj, &AbstractSameStruct2Interface::sig1, this, &AbstractSameStruct2Interface::sig1);
    connect(m_obj, &AbstractSameStruct2Interface::sig2, this, &QmlSameStruct2Interface::sig2);
    connect(m_obj, &AbstractSameStruct2Interface::sig2, this, &AbstractSameStruct2Interface::sig2);
}

QmlSameStruct2Interface::~QmlSameStruct2Interface()
{
}

Struct2 QmlSameStruct2Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlSameStruct2Interface::setProp1(const Struct2& prop1)
{
    SameStruct2InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

Struct2 QmlSameStruct2Interface::prop2() const
{
    return m_obj->prop2();
}

void QmlSameStruct2Interface::setProp2(const Struct2& prop2)
{
    SameStruct2InterfaceAgent::capture_state(this);
    return m_obj->setProp2(prop2);
}

Struct1 QmlSameStruct2Interface::func1(const Struct1& param1)
{
    SameStruct2InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

Struct1 QmlSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    SameStruct2InterfaceAgent::trace_func2(this, param1, param2);
	
    return m_obj->func2(param1,param2);
}
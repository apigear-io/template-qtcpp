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


#include "qmlsameenum2interface.h"
#include "tb_same1/api/apifactory.h"
#include "tb_same1/api/agent.h"

#include <QtQml>

QmlSameEnum2Interface::QmlSameEnum2Interface(QObject *parent)
    : AbstractSameEnum2Interface(parent)
{
    m_obj = ApiFactory::get()->createSameEnum2Interface(this);
    connect(m_obj, &AbstractSameEnum2Interface::prop1Changed, this, &QmlSameEnum2Interface::prop1Changed);
    connect(m_obj, &AbstractSameEnum2Interface::prop1Changed, this, &AbstractSameEnum2Interface::prop1Changed);
    connect(m_obj, &AbstractSameEnum2Interface::prop2Changed, this, &QmlSameEnum2Interface::prop2Changed);
    connect(m_obj, &AbstractSameEnum2Interface::prop2Changed, this, &AbstractSameEnum2Interface::prop2Changed);
    connect(m_obj, &AbstractSameEnum2Interface::sig1, this, &QmlSameEnum2Interface::sig1);
    connect(m_obj, &AbstractSameEnum2Interface::sig1, this, &AbstractSameEnum2Interface::sig1);
    connect(m_obj, &AbstractSameEnum2Interface::sig2, this, &QmlSameEnum2Interface::sig2);
    connect(m_obj, &AbstractSameEnum2Interface::sig2, this, &AbstractSameEnum2Interface::sig2);
}

QmlSameEnum2Interface::~QmlSameEnum2Interface()
{
}

Enum1::Enum1Enum QmlSameEnum2Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlSameEnum2Interface::setProp1(const Enum1::Enum1Enum prop1)
{
    SameEnum2InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

Enum2::Enum2Enum QmlSameEnum2Interface::prop2() const
{
    return m_obj->prop2();
}

void QmlSameEnum2Interface::setProp2(const Enum2::Enum2Enum prop2)
{
    SameEnum2InterfaceAgent::capture_state(this);
    return m_obj->setProp2(prop2);
}

Enum1::Enum1Enum QmlSameEnum2Interface::func1(const Enum1::Enum1Enum param1)
{
    SameEnum2InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

Enum1::Enum1Enum QmlSameEnum2Interface::func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    SameEnum2InterfaceAgent::trace_func2(this, param1, param2);
	
    return m_obj->func2(param1,param2);
}
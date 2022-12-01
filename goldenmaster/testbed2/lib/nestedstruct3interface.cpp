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


#include "nestedstruct3interface.h"

#include <QtQml>

#include "testbed2/api/agent.h"

NestedStruct3Interface::NestedStruct3Interface(QObject *parent)
    : AbstractNestedStruct3Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_prop3(NestedStruct3())
{
}

NestedStruct3Interface::~NestedStruct3Interface()
{
}

void NestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 NestedStruct3Interface::prop1() const
{
    return m_prop1;
}

void NestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}

NestedStruct2 NestedStruct3Interface::prop2() const
{
    return m_prop2;
}

void NestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        NestedStruct3InterfaceAgent::trace_state(this);
    }
}

NestedStruct3 NestedStruct3Interface::prop3() const
{
    return m_prop3;
}

NestedStruct1 NestedStruct3Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct3InterfaceAgent::trace_func1(this, param1);
    return NestedStruct1();
}

NestedStruct1 NestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct3InterfaceAgent::trace_func2(this, param1, param2);
    return NestedStruct1();
}

NestedStruct1 NestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct3InterfaceAgent::trace_func3(this, param1, param2, param3);
    return NestedStruct1();
}

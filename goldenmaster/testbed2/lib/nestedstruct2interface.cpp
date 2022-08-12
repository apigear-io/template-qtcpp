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


#include "nestedstruct2interface.h"

#include <QtQml>

#include "../api/agent.h"

NestedStruct2Interface::NestedStruct2Interface(QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
{
}

NestedStruct2Interface::~NestedStruct2Interface()
{
}

void NestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 NestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void NestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}

NestedStruct2 NestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 NestedStruct2Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct2InterfaceAgent::trace_func1(this, param1);
    return NestedStruct1();
}

NestedStruct1 NestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct2InterfaceAgent::trace_func2(this, param1, param2);
    return NestedStruct1();
}

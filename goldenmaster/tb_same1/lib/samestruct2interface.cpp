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


#include "samestruct2interface.h"

#include <QtQml>

#include "tb_same1/api/agent.h"

SameStruct2Interface::SameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
    , m_prop1(Struct2())
    , m_prop2(Struct2())
{
}

SameStruct2Interface::~SameStruct2Interface()
{
}

void SameStruct2Interface::setProp1(const Struct2& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameStruct2InterfaceAgent::trace_state(this);
    }
}

Struct2 SameStruct2Interface::prop1() const
{
    return m_prop1;
}

void SameStruct2Interface::setProp2(const Struct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        SameStruct2InterfaceAgent::trace_state(this);
    }
}

Struct2 SameStruct2Interface::prop2() const
{
    return m_prop2;
}

Struct1 SameStruct2Interface::func1(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    SameStruct2InterfaceAgent::trace_func1(this, param1);
    return Struct1();
}

Struct1 SameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    SameStruct2InterfaceAgent::trace_func2(this, param1, param2);
    return Struct1();
}

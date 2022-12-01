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


#include "samestruct1interface.h"

#include <QtQml>

#include "tb_same1/api/agent.h"

namespace tb_same1 {

SameStruct1Interface::SameStruct1Interface(QObject *parent)
    : AbstractSameStruct1Interface(parent)
    , m_prop1(Struct1())
{
}

SameStruct1Interface::~SameStruct1Interface()
{
}

void SameStruct1Interface::setProp1(const Struct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameStruct1InterfaceAgent::trace_state(this);
    }
}

Struct1 SameStruct1Interface::prop1() const
{
    return m_prop1;
}

Struct1 SameStruct1Interface::func1(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    SameStruct1InterfaceAgent::trace_func1(this, param1);
    return Struct1();
}
} //namespace tb_same1

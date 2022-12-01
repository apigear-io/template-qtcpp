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


#include "nestedstruct1interface.h"

#include <QtQml>

#include "testbed2/api/agent.h"

namespace testbed2 {

NestedStruct1Interface::NestedStruct1Interface(QObject *parent)
    : AbstractNestedStruct1Interface(parent)
    , m_prop1(NestedStruct1())
{
}

NestedStruct1Interface::~NestedStruct1Interface()
{
}

void NestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct1InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 NestedStruct1Interface::prop1() const
{
    return m_prop1;
}

NestedStruct1 NestedStruct1Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    NestedStruct1InterfaceAgent::trace_func1(this, param1);
    return NestedStruct1();
}
} //namespace testbed2

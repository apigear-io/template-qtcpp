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


#include "sameenum1interface.h"

#include <QtQml>

namespace tb_same2 {

SameEnum1Interface::SameEnum1Interface(QObject *parent)
    : AbstractSameEnum1Interface(parent)
    , m_prop1(Enum1::Value1)
{
}

SameEnum1Interface::~SameEnum1Interface()
{
}

void SameEnum1Interface::setProp1(Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum SameEnum1Interface::prop1() const
{
    return m_prop1;
}

Enum1::Enum1Enum SameEnum1Interface::func1(Enum1::Enum1Enum param1)
{
    return Enum1::Value1;
}
} //namespace tb_same2

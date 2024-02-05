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


#include "sameenum2interface.h"

#include <QtQml>

namespace tb_same2 {

SameEnum2Interface::SameEnum2Interface(QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value1)
{
}

SameEnum2Interface::~SameEnum2Interface()
{
}

void SameEnum2Interface::setProp1(Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum SameEnum2Interface::prop1() const
{
    return m_prop1;
}

void SameEnum2Interface::setProp2(Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum SameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum SameEnum2Interface::func1(Enum1::Enum1Enum param1)
{
    return Enum1::Value1;
}

Enum1::Enum1Enum SameEnum2Interface::func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    return Enum1::Value1;
}
} //namespace tb_same2

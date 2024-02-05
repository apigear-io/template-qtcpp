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


#include "enuminterface.h"

#include <QtQml>

namespace tb_enum {

EnumInterface::EnumInterface(QObject *parent)
    : AbstractEnumInterface(parent)
    , m_prop0(Enum0::Value0)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value2)
    , m_prop3(Enum3::Value3)
{
}

EnumInterface::~EnumInterface()
{
}

void EnumInterface::setProp0(Enum0::Enum0Enum prop0)
{
    if (m_prop0 != prop0) {
        m_prop0 = prop0;
        emit prop0Changed(prop0);
    }
}

Enum0::Enum0Enum EnumInterface::prop0() const
{
    return m_prop0;
}

void EnumInterface::setProp1(Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum EnumInterface::prop1() const
{
    return m_prop1;
}

void EnumInterface::setProp2(Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum EnumInterface::prop2() const
{
    return m_prop2;
}

void EnumInterface::setProp3(Enum3::Enum3Enum prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

Enum3::Enum3Enum EnumInterface::prop3() const
{
    return m_prop3;
}

Enum0::Enum0Enum EnumInterface::func0(Enum0::Enum0Enum param0)
{
    return Enum0::Value0;
}

Enum1::Enum1Enum EnumInterface::func1(Enum1::Enum1Enum param1)
{
    return Enum1::Value1;
}

Enum2::Enum2Enum EnumInterface::func2(Enum2::Enum2Enum param2)
{
    return Enum2::Value2;
}

Enum3::Enum3Enum EnumInterface::func3(Enum3::Enum3Enum param3)
{
    return Enum3::Value3;
}
} //namespace tb_enum

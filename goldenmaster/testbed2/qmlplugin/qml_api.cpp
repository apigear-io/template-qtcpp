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
#include "qml_api.h"

namespace testbed2 {

// ********************************************************************
// Struct Factory Struct1
// ********************************************************************

Struct1 Struct1Factory::create(int in_field1)
{
    Struct1 l_Struct1;
    l_Struct1.m_field1 = in_field1;
    return l_Struct1;

}

// ********************************************************************
// Struct Factory Struct2
// ********************************************************************

Struct2 Struct2Factory::create(int in_field1, int in_field2)
{
    Struct2 l_Struct2;
    l_Struct2.m_field1 = in_field1;
    l_Struct2.m_field2 = in_field2;
    return l_Struct2;

}

// ********************************************************************
// Struct Factory Struct3
// ********************************************************************

Struct3 Struct3Factory::create(int in_field1, int in_field2, int in_field3)
{
    Struct3 l_Struct3;
    l_Struct3.m_field1 = in_field1;
    l_Struct3.m_field2 = in_field2;
    l_Struct3.m_field3 = in_field3;
    return l_Struct3;

}

// ********************************************************************
// Struct Factory Struct4
// ********************************************************************

Struct4 Struct4Factory::create(int in_field1, int in_field2, int in_field3, int in_field4)
{
    Struct4 l_Struct4;
    l_Struct4.m_field1 = in_field1;
    l_Struct4.m_field2 = in_field2;
    l_Struct4.m_field3 = in_field3;
    l_Struct4.m_field4 = in_field4;
    return l_Struct4;

}

// ********************************************************************
// Struct Factory NestedStruct1
// ********************************************************************

NestedStruct1 NestedStruct1Factory::create(Struct1 in_field1)
{
    NestedStruct1 l_NestedStruct1;
    l_NestedStruct1.m_field1 = in_field1;
    return l_NestedStruct1;

}

// ********************************************************************
// Struct Factory NestedStruct2
// ********************************************************************

NestedStruct2 NestedStruct2Factory::create(Struct1 in_field1, Struct2 in_field2)
{
    NestedStruct2 l_NestedStruct2;
    l_NestedStruct2.m_field1 = in_field1;
    l_NestedStruct2.m_field2 = in_field2;
    return l_NestedStruct2;

}

// ********************************************************************
// Struct Factory NestedStruct3
// ********************************************************************

NestedStruct3 NestedStruct3Factory::create(Struct1 in_field1, Struct2 in_field2, Struct3 in_field3)
{
    NestedStruct3 l_NestedStruct3;
    l_NestedStruct3.m_field1 = in_field1;
    l_NestedStruct3.m_field2 = in_field2;
    l_NestedStruct3.m_field3 = in_field3;
    return l_NestedStruct3;

}

} // namespace testbed2

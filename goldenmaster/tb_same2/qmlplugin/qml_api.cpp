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

namespace tb_same2 {

// ********************************************************************
// Struct Factory Struct1
// ********************************************************************

Struct1 Struct1Factory::create(int in_field1, int in_field2, int in_field3)
{
    Struct1 l_Struct1;
    l_Struct1.m_field1 = in_field1;
    l_Struct1.m_field2 = in_field2;
    l_Struct1.m_field3 = in_field3;
    return l_Struct1;

}

// ********************************************************************
// Struct Factory Struct2
// ********************************************************************

Struct2 Struct2Factory::create(int in_field1, int in_field2, int in_field3)
{
    Struct2 l_Struct2;
    l_Struct2.m_field1 = in_field1;
    l_Struct2.m_field2 = in_field2;
    l_Struct2.m_field3 = in_field3;
    return l_Struct2;

}

} // namespace tb_same2

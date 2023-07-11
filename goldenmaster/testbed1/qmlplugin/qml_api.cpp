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

namespace testbed1 {

// ********************************************************************
// Struct Factory StructBool
// ********************************************************************

StructBool StructBoolFactory::create(bool in_fieldBool)
{
    StructBool l_StructBool;
    l_StructBool.m_fieldBool = in_fieldBool;
    return l_StructBool;

}

// ********************************************************************
// Struct Factory StructInt
// ********************************************************************

StructInt StructIntFactory::create(int in_fieldInt)
{
    StructInt l_StructInt;
    l_StructInt.m_fieldInt = in_fieldInt;
    return l_StructInt;

}

// ********************************************************************
// Struct Factory StructFloat
// ********************************************************************

StructFloat StructFloatFactory::create(qreal in_fieldFloat)
{
    StructFloat l_StructFloat;
    l_StructFloat.m_fieldFloat = in_fieldFloat;
    return l_StructFloat;

}

// ********************************************************************
// Struct Factory StructString
// ********************************************************************

StructString StructStringFactory::create(QString in_fieldString)
{
    StructString l_StructString;
    l_StructString.m_fieldString = in_fieldString;
    return l_StructString;

}

} // namespace testbed1

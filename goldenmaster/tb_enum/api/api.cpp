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
#include "api.h"

namespace tb_enum {
// ********************************************************************
// Enumeration Enum0
// ********************************************************************
Enum0::Enum0Enum Enum0::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 0: return Enum0::Value0;
        case 1: return Enum0::Value1;
        case 2: return Enum0::Value2;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum0::Value0;
    }
}
// ********************************************************************
// Enumeration Enum1
// ********************************************************************
Enum1::Enum1Enum Enum1::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 1: return Enum1::Value1;
        case 2: return Enum1::Value2;
        case 3: return Enum1::Value3;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum1::Value1;
    }
}
// ********************************************************************
// Enumeration Enum2
// ********************************************************************
Enum2::Enum2Enum Enum2::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 2: return Enum2::Value2;
        case 1: return Enum2::Value1;
        case 0: return Enum2::Value0;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum2::Value2;
    }
}
// ********************************************************************
// Enumeration Enum3
// ********************************************************************
Enum3::Enum3Enum Enum3::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
        case 3: return Enum3::Value3;
        case 2: return Enum3::Value2;
        case 1: return Enum3::Value1;
        default:
            if (ok) {
                *ok = false;
            }
            return Enum3::Value3;
    }
}

// ********************************************************************
// AbstractEnumInterface abstract interface
// ********************************************************************

AbstractEnumInterface::AbstractEnumInterface(QObject *parent)
    : QObject(parent)
{
}

} // namespace tb_enum

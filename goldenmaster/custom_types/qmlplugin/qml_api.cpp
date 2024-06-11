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

namespace custom_types {

// ********************************************************************
// Struct Factory Vector3D
// ********************************************************************

Vector3D Vector3DFactory::create(qreal in_x, qreal in_y, qreal in_z)
{
    Vector3D l_Vector3D;
    l_Vector3D.m_x = in_x;
    l_Vector3D.m_y = in_y;
    l_Vector3D.m_z = in_z;
    return l_Vector3D;

}

} // namespace custom_types

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

namespace custom_types {
// ********************************************************************
// Struct Vector3D
// ********************************************************************

Vector3D::Vector3D()
    : m_x(0.0f)    , m_y(0.0f)    , m_z(0.0f)
{
}

bool Vector3D::operator==(const Vector3D &other) const
{
    return (
        m_x == other.m_x &&
        m_y == other.m_y &&
        m_z == other.m_z
    );
}

bool Vector3D::operator!=(const Vector3D &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const Vector3D &obj)
{
    stream << obj.m_x;
    stream << obj.m_y;
    stream << obj.m_z;

    return stream;
}

QDataStream &operator>>(QDataStream &stream, Vector3D &obj)
{
    qreal xValue;
    stream >> xValue;
    obj.m_x = xValue;
    qreal yValue;
    stream >> yValue;
    obj.m_y = yValue;
    qreal zValue;
    stream >> zValue;
    obj.m_z = zValue;
    return stream;
}

} // namespace custom_types

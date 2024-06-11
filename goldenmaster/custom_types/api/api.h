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
#pragma once

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(CUSTOM_TYPES_API_LIBRARY)
#  define CUSTOM_TYPES_API_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_API_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

// ********************************************************************
// Vector3D struct
// ********************************************************************
struct CUSTOM_TYPES_API_EXPORT Vector3D
{
    Q_GADGET
    Q_PROPERTY(qreal x MEMBER m_x )
    Q_PROPERTY(qreal y MEMBER m_y )
    Q_PROPERTY(qreal z MEMBER m_z )

public:
    Vector3D();
    bool operator==(const Vector3D &other) const;
    bool operator!=(const Vector3D &other) const;
    qreal m_x;
    qreal m_y;
    qreal m_z;
};

/** ostream operator. Allows writing the Vector3D value to an text output*/
CUSTOM_TYPES_API_EXPORT QDataStream& operator<<(QDataStream &stream, const Vector3D &obj);
/** istream operator. Allows reading to Vector3D value from input text*/
CUSTOM_TYPES_API_EXPORT QDataStream& operator>>(QDataStream &stream, Vector3D &obj);



} //namespace custom_types


Q_DECLARE_METATYPE(custom_types::Vector3D)

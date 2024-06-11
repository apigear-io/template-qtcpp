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

#include <QQmlEngine>
#include <QtCore>
#include <QtCore/QtGlobal>
#include <QDataStream>

#include "custom_types/api/api.h"

#if defined(CUSTOM_TYPES_QML_LIBRARY)
#  define CUSTOM_TYPES_QML_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_QML_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

// ********************************************************************
// Vector3D struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class CUSTOM_TYPES_QML_EXPORT Vector3DFactory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(CustomTypesVector3DFactory)
    QML_SINGLETON
public:
    Q_INVOKABLE custom_types::Vector3D create(qreal in_x ,qreal in_y ,qreal in_z);
};


} //namespace custom_types

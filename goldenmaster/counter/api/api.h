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

#include "custom_types/api/api.h"
#include "extern_types/api/api.h"
#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(COUNTER_API_LIBRARY)
#  define COUNTER_API_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_API_EXPORT Q_DECL_IMPORT
#endif

namespace counter {

// ********************************************************************
/**
*
* AbstractCounter is a pure interface QObject class.
* Declares:
*  - Methods defined for Counter interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for Counter interface.
*/
// ********************************************************************


class COUNTER_API_EXPORT AbstractCounter : public QObject {
    Q_OBJECT
public:
    AbstractCounter(QObject * parent=nullptr);
    /**
    * Sets the value of the vector property.
    */
    virtual void setVector(const custom_types::Vector3D& vector) = 0;
    /**
    * Gets the value of the vector property.
    */
    virtual custom_types::Vector3D vector() const = 0;
    /**
    * Sets the value of the extern_vector property.
    */
    virtual void setExternVector(const QVector3D& extern_vector) = 0;
    /**
    * Gets the value of the extern_vector property.
    */
    virtual QVector3D extern_vector() const = 0;

    virtual QVector3D increment(const QVector3D& vec) = 0;

    virtual custom_types::Vector3D decrement(const custom_types::Vector3D& vec) = 0;
signals:
    /**
    * Emitted when vector value has changed.
    */
    void vectorChanged(const custom_types::Vector3D& vector);
    /**
    * Emitted when extern_vector value has changed.
    */
    void extern_vectorChanged(const QVector3D& extern_vector);
};


} //namespace counter



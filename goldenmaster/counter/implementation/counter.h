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

#include <QtCore>

#include "counter/api/api.h"

#if defined(COUNTER_IMPL_LIBRARY)
#  define COUNTER_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace counter {

/**
* The Counter implementation.
*/
class COUNTER_IMPL_EXPORT Counter : public AbstractCounter
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);
    virtual ~Counter() override;


    /** @return value of the property vector */
    custom_types::Vector3D vector() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property vector 
    */
    void setVector(const custom_types::Vector3D& vector) override;
    /** @return value of the property extern_vector */
    QVector3D extern_vector() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property extern_vector 
    */
    void setExternVector(const QVector3D& extern_vector) override;
    QVector3D increment(const QVector3D& vec) override;
    custom_types::Vector3D decrement(const custom_types::Vector3D& vec) override;

private:
    /** vector property */
    custom_types::Vector3D m_vector;
    /** extern_vector property */
    QVector3D m_extern_vector;
};
} //namespace counter

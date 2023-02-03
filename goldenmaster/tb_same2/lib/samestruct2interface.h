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

#include "tb_same2/api/api.h"

#if defined(TB_SAME2_LIB_LIBRARY)
#  define TB_SAME2_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME2_LIB_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same2 {

/**
* The SameStruct2Interface implementation.
*/
class TB_SAME2_LIB_EXPORT SameStruct2Interface : public AbstractSameStruct2Interface
{
    Q_OBJECT
public:
    explicit SameStruct2Interface(QObject *parent = nullptr);
    virtual ~SameStruct2Interface() override;
    /** @return value of the property prop1 */
    Struct2 prop1() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property prop1 */
    void setProp1(const Struct2& prop1) override;
    /** @return value of the property prop2 */
    Struct2 prop2() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property prop2 */
    void setProp2(const Struct2& prop2) override;
    Struct1 func1(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;

private:
    /** prop1 property */
    Struct2 m_prop1;
    /** prop2 property */
    Struct2 m_prop2;
};
} //namespace tb_same2

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

#include "testbed2/api/api.h"

#if defined(TESTBED2_LIB_LIBRARY)
#  define TESTBED2_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_LIB_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {

/**
* The NestedStruct2Interface implementation.
*/
class TESTBED2_LIB_EXPORT NestedStruct2Interface : public AbstractNestedStruct2Interface
{
    Q_OBJECT
public:
    explicit NestedStruct2Interface(QObject *parent = nullptr);
    virtual ~NestedStruct2Interface() override;


    /** @return value of the property prop1 */
    NestedStruct1 prop1() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property prop1 
    */
    void setProp1(const NestedStruct1& prop1) override;
    /** @return value of the property prop2 */
    NestedStruct2 prop2() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property prop2 
    */
    void setProp2(const NestedStruct2& prop2) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;

private:
    /** prop1 property */
    NestedStruct1 m_prop1;
    /** prop2 property */
    NestedStruct2 m_prop2;
};
} //namespace testbed2

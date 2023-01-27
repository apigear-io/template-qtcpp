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
* The ManyParamInterface implementation.
*/
class TESTBED2_LIB_EXPORT ManyParamInterface : public AbstractManyParamInterface
{
    Q_OBJECT
public:
    explicit ManyParamInterface(QObject *parent = nullptr);
    virtual ~ManyParamInterface() override;
    /** @return value of the property prop1 */
    int prop1() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property prop1 */
    void setProp1(int prop1) override;
    /** @return value of the property prop2 */
    int prop2() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property prop2 */
    void setProp2(int prop2) override;
    /** @return value of the property prop3 */
    int prop3() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property prop3 */
    void setProp3(int prop3) override;
    /** @return value of the property prop4 */
    int prop4() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property prop4 */
    void setProp4(int prop4) override;
    int func1(int param1) override;
    int func2(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;

private:
    /** prop1 property */
    int m_prop1;
    /** prop2 property */
    int m_prop2;
    /** prop3 property */
    int m_prop3;
    /** prop4 property */
    int m_prop4;
};
} //namespace testbed2

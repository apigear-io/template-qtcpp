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

#include "tb_enum/api/api.h"

#if defined(TB_ENUM_IMPL_LIBRARY)
#  define TB_ENUM_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_enum {

/**
* The EnumInterface implementation.
*/
class TB_ENUM_IMPL_EXPORT EnumInterface : public AbstractEnumInterface
{
    Q_OBJECT
public:
    explicit EnumInterface(QObject *parent = nullptr);
    virtual ~EnumInterface() override;


    /** @return value of the property prop0 */
    Enum0::Enum0Enum prop0() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property prop0 
    */
    void setProp0(Enum0::Enum0Enum prop0) override;
    /** @return value of the property prop1 */
    Enum1::Enum1Enum prop1() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property prop1 
    */
    void setProp1(Enum1::Enum1Enum prop1) override;
    /** @return value of the property prop2 */
    Enum2::Enum2Enum prop2() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property prop2 
    */
    void setProp2(Enum2::Enum2Enum prop2) override;
    /** @return value of the property prop3 */
    Enum3::Enum3Enum prop3() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property prop3 
    */
    void setProp3(Enum3::Enum3Enum prop3) override;
    Enum0::Enum0Enum func0(Enum0::Enum0Enum param0) override;
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    Enum2::Enum2Enum func2(Enum2::Enum2Enum param2) override;
    Enum3::Enum3Enum func3(Enum3::Enum3Enum param3) override;

private:
    /** prop0 property */
    Enum0::Enum0Enum m_prop0;
    /** prop1 property */
    Enum1::Enum1Enum m_prop1;
    /** prop2 property */
    Enum2::Enum2Enum m_prop2;
    /** prop3 property */
    Enum3::Enum3Enum m_prop3;
};
} //namespace tb_enum

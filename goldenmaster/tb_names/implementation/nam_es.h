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

#include "tb_names/api/api.h"

#if defined(TB_NAMES_IMPL_LIBRARY)
#  define TB_NAMES_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_names {

/**
* The Nam_Es implementation.
*/
class TB_NAMES_IMPL_EXPORT NamEs : public AbstractNamEs
{
    Q_OBJECT
public:
    explicit NamEs(QObject *parent = nullptr);
    virtual ~NamEs() override;


    /** @return value of the property Switch */
    bool Switch() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property Switch 
    */
    void setSwitch(bool Switch) override;
    /** @return value of the property SOME_PROPERTY */
    int SOME_PROPERTY() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property SOME_PROPERTY 
    */
    void setSomeProperty(int SOME_PROPERTY) override;
    /** @return value of the property Some_Poperty2 */
    int Some_Poperty2() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property Some_Poperty2 
    */
    void setSomePoperty2(int Some_Poperty2) override;
    void someFunction(bool SOME_PARAM) override;
    void someFunction2(bool Some_Param) override;

private:
    /** Switch property */
    bool m_Switch;
    /** SOME_PROPERTY property */
    int m_SOME_PROPERTY;
    /** Some_Poperty2 property */
    int m_Some_Poperty2;
};
} //namespace tb_names

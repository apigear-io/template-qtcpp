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

#include "tb_simple/api/api.h"

#if defined(TB_SIMPLE_IMPL_LIBRARY)
#  define TB_SIMPLE_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

/**
* The NoOperationsInterface implementation.
*/
class TB_SIMPLE_IMPL_EXPORT NoOperationsInterface : public AbstractNoOperationsInterface
{
    Q_OBJECT
public:
    explicit NoOperationsInterface(QObject *parent = nullptr);
    virtual ~NoOperationsInterface() override;


    /** @return value of the property propBool */
    bool propBool() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propBool 
    */
    void setPropBool(bool propBool) override;
    /** @return value of the property propInt */
    int propInt() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propInt 
    */
    void setPropInt(int propInt) override;

private:
    /** propBool property */
    bool m_propBool;
    /** propInt property */
    int m_propInt;
};
} //namespace tb_simple

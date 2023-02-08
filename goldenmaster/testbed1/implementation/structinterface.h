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

#include "testbed1/api/api.h"

#if defined(TESTBED1_IMPL_LIBRARY)
#  define TESTBED1_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

/**
* The StructInterface implementation.
*/
class TESTBED1_IMPL_EXPORT StructInterface : public AbstractStructInterface
{
    Q_OBJECT
public:
    explicit StructInterface(QObject *parent = nullptr);
    virtual ~StructInterface() override;


    /** @return value of the property propBool */
    StructBool propBool() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propBool 
    */
    void setPropBool(const StructBool& propBool) override;
    /** @return value of the property propInt */
    StructInt propInt() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propInt 
    */
    void setPropInt(const StructInt& propInt) override;
    /** @return value of the property propFloat */
    StructFloat propFloat() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propFloat 
    */
    void setPropFloat(const StructFloat& propFloat) override;
    /** @return value of the property propString */
    StructString propString() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propString 
    */
    void setPropString(const StructString& propString) override;
    StructBool funcBool(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;

private:
    /** propBool property */
    StructBool m_propBool;
    /** propInt property */
    StructInt m_propInt;
    /** propFloat property */
    StructFloat m_propFloat;
    /** propString property */
    StructString m_propString;
};
} //namespace testbed1

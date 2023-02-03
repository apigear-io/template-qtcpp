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

#if defined(TESTBED1_LIB_LIBRARY)
#  define TESTBED1_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_LIB_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

/**
* The StructArrayInterface implementation.
*/
class TESTBED1_LIB_EXPORT StructArrayInterface : public AbstractStructArrayInterface
{
    Q_OBJECT
public:
    explicit StructArrayInterface(QObject *parent = nullptr);
    virtual ~StructArrayInterface() override;
    /** @return value of the property propBool */
    QList<StructBool> propBool() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property propBool */
    void setPropBool(const QList<StructBool>& propBool) override;
    /** @return value of the property propInt */
    QList<StructInt> propInt() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property propInt */
    void setPropInt(const QList<StructInt>& propInt) override;
    /** @return value of the property propFloat */
    QList<StructFloat> propFloat() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property propFloat */
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    /** @return value of the property propString */
    QList<StructString> propString() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    @param value to set for the property propString */
    void setPropString(const QList<StructString>& propString) override;
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    StructBool funcString(const QList<StructString>& paramString) override;

private:
    /** propBool property */
    QList<StructBool> m_propBool;
    /** propInt property */
    QList<StructInt> m_propInt;
    /** propFloat property */
    QList<StructFloat> m_propFloat;
    /** propString property */
    QList<StructString> m_propString;
};
} //namespace testbed1

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

class TESTBED1_LIB_EXPORT StructInterface : public AbstractStructInterface
{
    Q_OBJECT
public:
    explicit StructInterface(QObject *parent = nullptr);
    virtual ~StructInterface() override;
    StructBool propBool() const override;
    void setPropBool(const StructBool& propBool) override;
    StructInt propInt() const override;
    void setPropInt(const StructInt& propInt) override;
    StructFloat propFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    StructString propString() const override;
    void setPropString(const StructString& propString) override;
    StructBool funcBool(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;

private:
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};

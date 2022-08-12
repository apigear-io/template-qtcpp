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

#include "../api/api.h"

#if defined(TB_SAME1_LIB_LIBRARY)
#  define TB_SAME1_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_LIB_EXPORT Q_DECL_IMPORT
#endif

class TB_SAME1_LIB_EXPORT SameStruct2Interface : public AbstractSameStruct2Interface
{
    Q_OBJECT
public:
    explicit SameStruct2Interface(QObject *parent = nullptr);
    virtual ~SameStruct2Interface() override;
    Struct2 prop1() const override;
    void setProp1(const Struct2& prop1) override;
    Struct2 prop2() const override;
    void setProp2(const Struct2& prop2) override;
    Struct1 func1(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;

private:
    Struct2 m_prop1;
    Struct2 m_prop2;
};

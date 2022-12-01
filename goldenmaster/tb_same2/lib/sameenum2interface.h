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

class TB_SAME2_LIB_EXPORT SameEnum2Interface : public AbstractSameEnum2Interface
{
    Q_OBJECT
public:
    explicit SameEnum2Interface(QObject *parent = nullptr);
    virtual ~SameEnum2Interface() override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    Enum2::Enum2Enum prop2() const override;
    void setProp2(const Enum2::Enum2Enum prop2) override;
    Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    Enum1::Enum1Enum func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2) override;

private:
    Enum1::Enum1Enum m_prop1;
    Enum2::Enum2Enum m_prop2;
};

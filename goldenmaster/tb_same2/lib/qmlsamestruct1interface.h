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

#include "samestruct1interface.h"

namespace tb_same2 {

class TB_SAME2_LIB_EXPORT QmlSameStruct1Interface : public AbstractSameStruct1Interface
{
    Q_OBJECT
    Q_PROPERTY(Struct1 prop1 READ prop1 NOTIFY prop1Changed)
public:
    explicit QmlSameStruct1Interface(QObject *parent = nullptr);
    virtual ~QmlSameStruct1Interface() override;
    Struct1 prop1() const override;
    void setProp1(const Struct1& prop1) override;
    Q_INVOKABLE Struct1 func1(const Struct1& param1) override;

Q_SIGNALS:
    void sig1(const Struct1& param1);
    void prop1Changed(const Struct1& prop1);
private:
	AbstractSameStruct1Interface *m_obj;
};

} //namespace tb_same2

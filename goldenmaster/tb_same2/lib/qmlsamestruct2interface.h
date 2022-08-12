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

#include "samestruct2interface.h"

class TB_SAME2_LIB_EXPORT QmlSameStruct2Interface : public AbstractSameStruct2Interface
{
    Q_OBJECT
    Q_PROPERTY(Struct2 prop1 READ prop1 NOTIFY prop1Changed)
    Q_PROPERTY(Struct2 prop2 READ prop2 NOTIFY prop2Changed)
public:
    explicit QmlSameStruct2Interface(QObject *parent = nullptr);
    virtual ~QmlSameStruct2Interface() override;
    Struct2 prop1() const override;
    void setProp1(const Struct2& prop1) override;
    Struct2 prop2() const override;
    void setProp2(const Struct2& prop2) override;
    Q_INVOKABLE Struct1 func1(const Struct1& param1) override;
    Q_INVOKABLE Struct1 func2(const Struct1& param1, const Struct2& param2) override;

Q_SIGNALS:
    void sig1(const Struct1& param1);
    void sig2(const Struct1& param1, const Struct2& param2);
    void prop1Changed(const Struct2& prop1);
    void prop2Changed(const Struct2& prop2);
private:
	AbstractSameStruct2Interface *m_obj;
};

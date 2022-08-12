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

#include "nestedstruct3interface.h"

class TESTBED2_LIB_EXPORT QmlNestedStruct3Interface : public AbstractNestedStruct3Interface
{
    Q_OBJECT
    Q_PROPERTY(NestedStruct1 prop1 READ prop1 NOTIFY prop1Changed)
    Q_PROPERTY(NestedStruct2 prop2 READ prop2 NOTIFY prop2Changed)
    Q_PROPERTY(NestedStruct3 prop3 READ prop3 NOTIFY prop3Changed)
public:
    explicit QmlNestedStruct3Interface(QObject *parent = nullptr);
    virtual ~QmlNestedStruct3Interface() override;
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    NestedStruct2 prop2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    NestedStruct3 prop3() const override;
    void setProp3(const NestedStruct3& prop3) override;
    Q_INVOKABLE NestedStruct1 func1(const NestedStruct1& param1) override;
    Q_INVOKABLE NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    Q_INVOKABLE NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;

Q_SIGNALS:
    void sig1(const NestedStruct1& param1);
    void sig2(const NestedStruct1& param1, const NestedStruct2& param2);
    void sig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
    void prop1Changed(const NestedStruct1& prop1);
    void prop2Changed(const NestedStruct2& prop2);
    void prop3Changed(const NestedStruct3& prop3);
private:
	AbstractNestedStruct3Interface *m_obj;
};

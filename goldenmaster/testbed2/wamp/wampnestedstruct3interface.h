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
#include <QtPromise>

#include "../api/api.h"
#include "../shared/wampclient.h"

using namespace ApiGear;

class WampNestedStruct3Interface : public AbstractNestedStruct3Interface
{
    Q_OBJECT
public:
    explicit WampNestedStruct3Interface(QObject *parent = nullptr);
    virtual ~WampNestedStruct3Interface() override;

    void applyState(const json& fields);
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    void setProp1Local(const NestedStruct1& prop1);
    NestedStruct2 prop2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    void setProp2Local(const NestedStruct2& prop2);
    NestedStruct3 prop3() const override;
    void setProp3(const NestedStruct3& prop3) override;
    void setProp3Local(const NestedStruct3& prop3);
    NestedStruct1 func1(const NestedStruct1& param1) override;
    QtPromise::QPromise<NestedStruct1> func1Async(const NestedStruct1& param1);
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    QtPromise::QPromise<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2);
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    QtPromise::QPromise<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
void notifySig1(WAMP::EventArg arg);
void notifySig2(WAMP::EventArg arg);
void notifySig3(WAMP::EventArg arg);

private:
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
    NestedStruct3 m_prop3;
};

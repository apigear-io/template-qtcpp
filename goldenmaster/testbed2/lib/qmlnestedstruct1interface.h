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

#include "nestedstruct1interface.h"

namespace testbed2 {

/**
* A QML wrapper of the NestedStruct1Interface implementation.
* Uses a NestedStruct1Interface provided by an ApiFactory.
* See ApiFactory and factories that implement the ApiFactoryInterface.
*/
class TESTBED2_LIB_EXPORT QmlNestedStruct1Interface : public AbstractNestedStruct1Interface
{
    Q_OBJECT
    Q_PROPERTY(NestedStruct1 prop1 READ prop1 NOTIFY prop1Changed)
public:
    explicit QmlNestedStruct1Interface(QObject *parent = nullptr);
    ~QmlNestedStruct1Interface() override;
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    Q_INVOKABLE NestedStruct1 func1(const NestedStruct1& param1) override;

Q_SIGNALS:
    void sig1(const NestedStruct1& param1);
    void prop1Changed(const NestedStruct1& prop1);
private:
	AbstractNestedStruct1Interface *m_obj;
};

} //namespace testbed2

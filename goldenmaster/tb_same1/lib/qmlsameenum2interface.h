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

#include "sameenum2interface.h"

namespace tb_same1 {

/**
* A QML wrapper of the SameEnum2Interface implementation.
* Uses a SameEnum2Interface provided by an ApiFactory.
* See ApiFactory and factories that implement the ApiFactoryInterface.
*/
class TB_SAME1_LIB_EXPORT QmlSameEnum2Interface : public AbstractSameEnum2Interface
{
    Q_OBJECT
    Q_PROPERTY(Enum1::Enum1Enum prop1 READ prop1 NOTIFY prop1Changed)
    Q_PROPERTY(Enum2::Enum2Enum prop2 READ prop2 NOTIFY prop2Changed)
public:
    explicit QmlSameEnum2Interface(QObject *parent = nullptr);
    ~QmlSameEnum2Interface() override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    Enum2::Enum2Enum prop2() const override;
    void setProp2(const Enum2::Enum2Enum prop2) override;
    Q_INVOKABLE Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    Q_INVOKABLE Enum1::Enum1Enum func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2) override;

Q_SIGNALS:
    void sig1(const Enum1::Enum1Enum param1);
    void sig2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2);
    void prop1Changed(const Enum1::Enum1Enum prop1);
    void prop2Changed(const Enum2::Enum2Enum prop2);
private:
	AbstractSameEnum2Interface *m_obj;
};

} //namespace tb_same1

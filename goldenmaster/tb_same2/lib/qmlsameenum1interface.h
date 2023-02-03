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

#include "sameenum1interface.h"

namespace tb_same2 {

/**
* A QML wrapper of the SameEnum1Interface implementation.
* Uses a SameEnum1Interface provided by an ApiFactory.
* See ApiFactory and factories that implement the ApiFactoryInterface.
*/
class TB_SAME2_LIB_EXPORT QmlSameEnum1Interface : public AbstractSameEnum1Interface
{
    Q_OBJECT
    Q_PROPERTY(Enum1::Enum1Enum prop1 READ prop1 NOTIFY prop1Changed)
public:
    explicit QmlSameEnum1Interface(QObject *parent = nullptr);
    ~QmlSameEnum1Interface() override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    Q_INVOKABLE Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;

Q_SIGNALS:
    void sig1(const Enum1::Enum1Enum param1);
    void prop1Changed(const Enum1::Enum1Enum prop1);
private:
	AbstractSameEnum1Interface *m_obj;
};

} //namespace tb_same2

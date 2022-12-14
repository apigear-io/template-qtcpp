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

#include "enuminterface.h"

namespace tb_enum {

class TB_ENUM_LIB_EXPORT QmlEnumInterface : public AbstractEnumInterface
{
    Q_OBJECT
    Q_PROPERTY(Enum0::Enum0Enum prop0 READ prop0 NOTIFY prop0Changed)
    Q_PROPERTY(Enum1::Enum1Enum prop1 READ prop1 NOTIFY prop1Changed)
    Q_PROPERTY(Enum2::Enum2Enum prop2 READ prop2 NOTIFY prop2Changed)
    Q_PROPERTY(Enum3::Enum3Enum prop3 READ prop3 NOTIFY prop3Changed)
public:
    explicit QmlEnumInterface(QObject *parent = nullptr);
    virtual ~QmlEnumInterface() override;
    Enum0::Enum0Enum prop0() const override;
    void setProp0(const Enum0::Enum0Enum prop0) override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    Enum2::Enum2Enum prop2() const override;
    void setProp2(const Enum2::Enum2Enum prop2) override;
    Enum3::Enum3Enum prop3() const override;
    void setProp3(const Enum3::Enum3Enum prop3) override;
    Q_INVOKABLE Enum0::Enum0Enum func0(const Enum0::Enum0Enum param0) override;
    Q_INVOKABLE Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    Q_INVOKABLE Enum2::Enum2Enum func2(const Enum2::Enum2Enum param2) override;
    Q_INVOKABLE Enum3::Enum3Enum func3(const Enum3::Enum3Enum param3) override;

Q_SIGNALS:
    void sig0(const Enum0::Enum0Enum param0);
    void sig1(const Enum1::Enum1Enum param1);
    void sig2(const Enum2::Enum2Enum param2);
    void sig3(const Enum3::Enum3Enum param3);
    void prop0Changed(const Enum0::Enum0Enum prop0);
    void prop1Changed(const Enum1::Enum1Enum prop1);
    void prop2Changed(const Enum2::Enum2Enum prop2);
    void prop3Changed(const Enum3::Enum3Enum prop3);
private:
	AbstractEnumInterface *m_obj;
};

} //namespace tb_enum

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

#include "manyparaminterface.h"

namespace testbed2 {

class TESTBED2_LIB_EXPORT QmlManyParamInterface : public AbstractManyParamInterface
{
    Q_OBJECT
    Q_PROPERTY(int prop1 READ prop1 NOTIFY prop1Changed)
    Q_PROPERTY(int prop2 READ prop2 NOTIFY prop2Changed)
    Q_PROPERTY(int prop3 READ prop3 NOTIFY prop3Changed)
    Q_PROPERTY(int prop4 READ prop4 NOTIFY prop4Changed)
public:
    explicit QmlManyParamInterface(QObject *parent = nullptr);
    virtual ~QmlManyParamInterface() override;
    int prop1() const override;
    void setProp1(int prop1) override;
    int prop2() const override;
    void setProp2(int prop2) override;
    int prop3() const override;
    void setProp3(int prop3) override;
    int prop4() const override;
    void setProp4(int prop4) override;
    Q_INVOKABLE int func1(int param1) override;
    Q_INVOKABLE int func2(int param1, int param2) override;
    Q_INVOKABLE int func3(int param1, int param2, int param3) override;
    Q_INVOKABLE int func4(int param1, int param2, int param3, int param4) override;

Q_SIGNALS:
    void sig1(int param1);
    void sig2(int param1, int param2);
    void sig3(int param1, int param2, int param3);
    void sig4(int param1, int param2, int param3, int param4);
    void prop1Changed(int prop1);
    void prop2Changed(int prop2);
    void prop3Changed(int prop3);
    void prop4Changed(int prop4);
private:
	AbstractManyParamInterface *m_obj;
};

} //namespace testbed2

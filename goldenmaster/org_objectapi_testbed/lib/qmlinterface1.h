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

#include "interface1.h"

class ORG_OBJECTAPI_TESTBED_LIB_EXPORT QmlInterface1 : public AbstractInterface1
{
    Q_OBJECT
    Q_PROPERTY(bool prop1 READ prop1 NOTIFY prop1Changed)
    Q_PROPERTY(int prop2 READ prop2 NOTIFY prop2Changed)
    Q_PROPERTY(qreal prop3 READ prop3 NOTIFY prop3Changed)
    Q_PROPERTY(QString prop4 READ prop4 NOTIFY prop4Changed)
    Q_PROPERTY(QList<int> prop5 READ prop5 NOTIFY prop5Changed)
    Q_PROPERTY(Struct1 prop6 READ prop6 NOTIFY prop6Changed)
    Q_PROPERTY(int prop7 READ prop7 NOTIFY prop7Changed)
    Q_PROPERTY(QList<int> prop10 READ prop10 NOTIFY prop10Changed)
    Q_PROPERTY(QList<Struct1> prop11 READ prop11 NOTIFY prop11Changed)
    Q_PROPERTY(QList<Enum1::Enum1Enum> prop12 READ prop12 NOTIFY prop12Changed)
    Q_PROPERTY(QList<Struct1> prop14 READ prop14 NOTIFY prop14Changed)
public:
    explicit QmlInterface1(QObject *parent = nullptr);
    virtual ~QmlInterface1() override;
    bool prop1() const override;
    void setProp1(bool prop1) override;
    int prop2() const override;
    void setProp2(int prop2) override;
    qreal prop3() const override;
    void setProp3(qreal prop3) override;
    QString prop4() const override;
    void setProp4(const QString& prop4) override;
    QList<int> prop5() const override;
    void setProp5(const QList<int>& prop5) override;
    Struct1 prop6() const override;
    void setProp6(const Struct1& prop6) override;
    int prop7() const override;
    void setProp7(int prop7) override;
    QList<int> prop10() const override;
    void setProp10(const QList<int>& prop10) override;
    QList<Struct1> prop11() const override;
    void setProp11(const QList<Struct1>& prop11) override;
    QList<Enum1::Enum1Enum> prop12() const override;
    void setProp12(const QList<Enum1::Enum1Enum>& prop12) override;
    QList<Struct1> prop14() const override;
    void setProp14(const QList<Struct1>& prop14) override;
    Q_INVOKABLE void op1() override;
    Q_INVOKABLE void op2(int step) override;
    Q_INVOKABLE int op3() override;

Q_SIGNALS:
    void sig1();
    void sig2(int step);
    void sig3();
    void prop1Changed(bool prop1);
    void prop2Changed(int prop2);
    void prop3Changed(qreal prop3);
    void prop4Changed(const QString& prop4);
    void prop5Changed(const QList<int>& prop5);
    void prop6Changed(const Struct1& prop6);
    void prop7Changed(int prop7);
    void prop10Changed(const QList<int>& prop10);
    void prop11Changed(const QList<Struct1>& prop11);
    void prop12Changed(const QList<Enum1::Enum1Enum>& prop12);
    void prop14Changed(const QList<Struct1>& prop14);
private:
	AbstractInterface1 *m_obj;
};

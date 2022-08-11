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

#include "../api/api.h"

#if defined(ORG_OBJECTAPI_TESTBED_LIB_LIBRARY)
#  define ORG_OBJECTAPI_TESTBED_LIB_EXPORT Q_DECL_EXPORT
#else
#  define ORG_OBJECTAPI_TESTBED_LIB_EXPORT Q_DECL_IMPORT
#endif

class ORG_OBJECTAPI_TESTBED_LIB_EXPORT Interface1 : public AbstractInterface1
{
    Q_OBJECT
public:
    explicit Interface1(QObject *parent = nullptr);
    virtual ~Interface1() override;
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
    void op1() override;
    void op2(int step) override;
    int op3() override;

private:
    bool m_prop1;
    int m_prop2;
    qreal m_prop3;
    QString m_prop4;
    QList<int> m_prop5;
    Struct1 m_prop6;
    int m_prop7;
    QList<int> m_prop10;
    QList<Struct1> m_prop11;
    QList<Enum1::Enum1Enum> m_prop12;
    QList<Struct1> m_prop14;
};

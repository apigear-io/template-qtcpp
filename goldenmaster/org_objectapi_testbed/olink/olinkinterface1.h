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
#include "objectlink/olink/clientnode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class OLinkInterface1 : public AbstractInterface1, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkInterface1(QObject *parent = nullptr);
    virtual ~OLinkInterface1() override;

    void applyState(const json& fields);
    bool prop1() const override;
    void setProp1(bool prop1) override;
    void setProp1Local(bool prop1);
    int prop2() const override;
    void setProp2(int prop2) override;
    void setProp2Local(int prop2);
    qreal prop3() const override;
    void setProp3(qreal prop3) override;
    void setProp3Local(qreal prop3);
    QString prop4() const override;
    void setProp4(const QString& prop4) override;
    void setProp4Local(const QString& prop4);
    QList<int> prop5() const override;
    void setProp5(const QList<int>& prop5) override;
    void setProp5Local(const QList<int>& prop5);
    Struct1 prop6() const override;
    void setProp6(const Struct1& prop6) override;
    void setProp6Local(const Struct1& prop6);
    int prop7() const override;
    void setProp7(int prop7) override;
    void setProp7Local(int prop7);
    QList<int> prop10() const override;
    void setProp10(const QList<int>& prop10) override;
    void setProp10Local(const QList<int>& prop10);
    QList<Struct1> prop11() const override;
    void setProp11(const QList<Struct1>& prop11) override;
    void setProp11Local(const QList<Struct1>& prop11);
    QList<Enum1::Enum1Enum> prop12() const override;
    void setProp12(const QList<Enum1::Enum1Enum>& prop12) override;
    void setProp12Local(const QList<Enum1::Enum1Enum>& prop12);
    QList<Struct1> prop14() const override;
    void setProp14(const QList<Struct1>& prop14) override;
    void setProp14Local(const QList<Struct1>& prop14);
    void op1() override;
    QtPromise::QPromise<void> op1Async();
    void op2(int step) override;
    QtPromise::QPromise<void> op2Async(int step);
    int op3() override;
    QtPromise::QPromise<int> op3Async();
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(std::string name, json args) override;
    virtual void olinkOnPropertyChanged(std::string name, json value) override;
    virtual void olinkOnInit(std::string name, json props, IClientNode *node) override;
    virtual void olinkOnRelease() override;
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
    bool m_isReady;
    IClientNode *m_node;
};

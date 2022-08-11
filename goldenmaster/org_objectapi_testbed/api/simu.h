#pragma once

#include <QtCore>
#include "api.h"

// ********************************************************************
// SimulationInterface1 simulation interface
// ********************************************************************


class SimulationInterface1 : public AbstractInterface1
{
    Q_OBJECT
public:
    explicit SimulationInterface1(QObject *parent = nullptr);
    virtual ~SimulationInterface1() override;
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

// ********************************************************************
// SimulationInterface2 simulation interface
// ********************************************************************


class SimulationInterface2 : public AbstractInterface2
{
    Q_OBJECT
public:
    explicit SimulationInterface2(QObject *parent = nullptr);
    virtual ~SimulationInterface2() override;
    int prop200() const override;
    void setProp200(int prop200) override;
    int prop201() const override;
    void setProp201(int prop201) override;
    int prop202() const override;
    void setProp202(int prop202) override;
    qreal prop203() const override;
    void setProp203(qreal prop203) override;
    qreal prop204() const override;
    void setProp204(qreal prop204) override;
    QString prop205() const override;
    void setProp205(const QString& prop205) override;

private:
    int m_prop200;
    int m_prop201;
    int m_prop202;
    qreal m_prop203;
    qreal m_prop204;
    QString m_prop205;
};


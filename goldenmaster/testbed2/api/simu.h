#pragma once

#include <QtCore>
#include "api.h"

// ********************************************************************
// SimulationManyParamInterface simulation interface
// ********************************************************************


class SimulationManyParamInterface : public AbstractManyParamInterface
{
    Q_OBJECT
public:
    explicit SimulationManyParamInterface(QObject *parent = nullptr);
    virtual ~SimulationManyParamInterface() override;
    int prop1() const override;
    void setProp1(int prop1) override;
    int prop2() const override;
    void setProp2(int prop2) override;
    int prop3() const override;
    void setProp3(int prop3) override;
    int prop4() const override;
    void setProp4(int prop4) override;
    int func1(int param1) override;
    int func2(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;

private:
    int m_prop1;
    int m_prop2;
    int m_prop3;
    int m_prop4;
};

// ********************************************************************
// SimulationNestedStruct1Interface simulation interface
// ********************************************************************


class SimulationNestedStruct1Interface : public AbstractNestedStruct1Interface
{
    Q_OBJECT
public:
    explicit SimulationNestedStruct1Interface(QObject *parent = nullptr);
    virtual ~SimulationNestedStruct1Interface() override;
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;

private:
    NestedStruct1 m_prop1;
};

// ********************************************************************
// SimulationNestedStruct2Interface simulation interface
// ********************************************************************


class SimulationNestedStruct2Interface : public AbstractNestedStruct2Interface
{
    Q_OBJECT
public:
    explicit SimulationNestedStruct2Interface(QObject *parent = nullptr);
    virtual ~SimulationNestedStruct2Interface() override;
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    NestedStruct2 prop2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;

private:
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
};

// ********************************************************************
// SimulationNestedStruct3Interface simulation interface
// ********************************************************************


class SimulationNestedStruct3Interface : public AbstractNestedStruct3Interface
{
    Q_OBJECT
public:
    explicit SimulationNestedStruct3Interface(QObject *parent = nullptr);
    virtual ~SimulationNestedStruct3Interface() override;
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    NestedStruct2 prop2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    NestedStruct3 prop3() const override;
    void setProp3(const NestedStruct3& prop3) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;

private:
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
    NestedStruct3 m_prop3;
};


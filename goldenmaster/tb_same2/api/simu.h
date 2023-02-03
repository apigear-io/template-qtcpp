#pragma once

#include <QtCore>
#include "api.h"

namespace tb_same2 {

// ********************************************************************
// SimulationSameStruct1Interface simulation interface
// ********************************************************************


class SimulationSameStruct1Interface : public AbstractSameStruct1Interface
{
    Q_OBJECT
public:
    explicit SimulationSameStruct1Interface(QObject *parent = nullptr);
    virtual ~SimulationSameStruct1Interface() override;
    Struct1 prop1() const override;
    void setProp1(const Struct1& prop1) override;
    Struct1 func1(const Struct1& param1) override;

private:
    Struct1 m_prop1;
};

// ********************************************************************
// SimulationSameStruct2Interface simulation interface
// ********************************************************************


class SimulationSameStruct2Interface : public AbstractSameStruct2Interface
{
    Q_OBJECT
public:
    explicit SimulationSameStruct2Interface(QObject *parent = nullptr);
    virtual ~SimulationSameStruct2Interface() override;
    Struct2 prop1() const override;
    void setProp1(const Struct2& prop1) override;
    Struct2 prop2() const override;
    void setProp2(const Struct2& prop2) override;
    Struct1 func1(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;

private:
    Struct2 m_prop1;
    Struct2 m_prop2;
};

// ********************************************************************
// SimulationSameEnum1Interface simulation interface
// ********************************************************************


class SimulationSameEnum1Interface : public AbstractSameEnum1Interface
{
    Q_OBJECT
public:
    explicit SimulationSameEnum1Interface(QObject *parent = nullptr);
    virtual ~SimulationSameEnum1Interface() override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(Enum1::Enum1Enum prop1) override;
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;

private:
    Enum1::Enum1Enum m_prop1;
};

// ********************************************************************
// SimulationSameEnum2Interface simulation interface
// ********************************************************************


class SimulationSameEnum2Interface : public AbstractSameEnum2Interface
{
    Q_OBJECT
public:
    explicit SimulationSameEnum2Interface(QObject *parent = nullptr);
    virtual ~SimulationSameEnum2Interface() override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(Enum1::Enum1Enum prop1) override;
    Enum2::Enum2Enum prop2() const override;
    void setProp2(Enum2::Enum2Enum prop2) override;
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    Enum1::Enum1Enum func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2) override;

private:
    Enum1::Enum1Enum m_prop1;
    Enum2::Enum2Enum m_prop2;
};

} // namespace tb_same2

#pragma once

#include <QtCore>
#include "api.h"

namespace testbed1 {

// ********************************************************************
// SimulationStructInterface simulation interface
// ********************************************************************


class SimulationStructInterface : public AbstractStructInterface
{
    Q_OBJECT
public:
    explicit SimulationStructInterface(QObject *parent = nullptr);
    virtual ~SimulationStructInterface() override;
    StructBool propBool() const override;
    void setPropBool(const StructBool& propBool) override;
    StructInt propInt() const override;
    void setPropInt(const StructInt& propInt) override;
    StructFloat propFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    StructString propString() const override;
    void setPropString(const StructString& propString) override;
    StructBool funcBool(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;

private:
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};

// ********************************************************************
// SimulationStructArrayInterface simulation interface
// ********************************************************************


class SimulationStructArrayInterface : public AbstractStructArrayInterface
{
    Q_OBJECT
public:
    explicit SimulationStructArrayInterface(QObject *parent = nullptr);
    virtual ~SimulationStructArrayInterface() override;
    QList<StructBool> propBool() const override;
    void setPropBool(const QList<StructBool>& propBool) override;
    QList<StructInt> propInt() const override;
    void setPropInt(const QList<StructInt>& propInt) override;
    QList<StructFloat> propFloat() const override;
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    QList<StructString> propString() const override;
    void setPropString(const QList<StructString>& propString) override;
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    StructBool funcString(const QList<StructString>& paramString) override;

private:
    QList<StructBool> m_propBool;
    QList<StructInt> m_propInt;
    QList<StructFloat> m_propFloat;
    QList<StructString> m_propString;
};

} // namespace testbed1

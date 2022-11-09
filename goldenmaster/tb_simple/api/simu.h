#pragma once

#include <QtCore>
#include "api.h"

// ********************************************************************
// SimulationSimpleInterface simulation interface
// ********************************************************************


class SimulationSimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT
public:
    explicit SimulationSimpleInterface(QObject *parent = nullptr);
    virtual ~SimulationSimpleInterface() override;
    bool propBool() const override;
    void setPropBool(bool propBool) override;
    int propInt() const override;
    void setPropInt(int propInt) override;
    double propFloat() const override;
    void setPropFloat(double propFloat) override;
    QString propString() const override;
    void setPropString(const QString& propString) override;
    bool funcBool(bool paramBool) override;
    int funcInt(int paramInt) override;
    double funcFloat(double paramFloat) override;
    QString funcString(const QString& paramString) override;

private:
    bool m_propBool;
    int m_propInt;
    double m_propFloat;
    QString m_propString;
};

// ********************************************************************
// SimulationSimpleArrayInterface simulation interface
// ********************************************************************


class SimulationSimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
public:
    explicit SimulationSimpleArrayInterface(QObject *parent = nullptr);
    virtual ~SimulationSimpleArrayInterface() override;
    QList<bool> propBool() const override;
    void setPropBool(const QList<bool>& propBool) override;
    QList<int> propInt() const override;
    void setPropInt(const QList<int>& propInt) override;
    QList<double> propFloat() const override;
    void setPropFloat(const QList<double>& propFloat) override;
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QList<int> funcInt(const QList<int>& paramInt) override;
    QList<double> funcFloat(const QList<double>& paramFloat) override;
    QList<QString> funcString(const QList<QString>& paramString) override;

private:
    QList<bool> m_propBool;
    QList<int> m_propInt;
    QList<double> m_propFloat;
    QList<QString> m_propString;
};


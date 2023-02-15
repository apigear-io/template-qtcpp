#pragma once

#include <QtCore>
#include "api.h"

namespace tb_simple {

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
    qint32 propInt32() const override;
    void setPropInt32(qint32 propInt32) override;
    qint64 propInt64() const override;
    void setPropInt64(qint64 propInt64) override;
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    float propFloat32() const override;
    void setPropFloat32(float propFloat32) override;
    double propFloat64() const override;
    void setPropFloat64(double propFloat64) override;
    QString propString() const override;
    void setPropString(const QString& propString) override;
    bool funcBool(bool paramBool) override;
    int funcInt(int paramInt) override;
    qint32 funcInt32(qint32 paramInt32) override;
    qint64 funcInt64(qint64 paramInt64) override;
    qreal funcFloat(qreal paramFloat) override;
    float funcFloat32(float paramFloat32) override;
    double funcFloat64(double paramFloat) override;
    QString funcString(const QString& paramString) override;

private:
    bool m_propBool;
    int m_propInt;
    qint32 m_propInt32;
    qint64 m_propInt64;
    qreal m_propFloat;
    float m_propFloat32;
    double m_propFloat64;
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
    QList<qint32> propInt32() const override;
    void setPropInt32(const QList<qint32>& propInt32) override;
    QList<qint64> propInt64() const override;
    void setPropInt64(const QList<qint64>& propInt64) override;
    QList<qreal> propFloat() const override;
    void setPropFloat(const QList<qreal>& propFloat) override;
    QList<float> propFloat32() const override;
    void setPropFloat32(const QList<float>& propFloat32) override;
    QList<double> propFloat64() const override;
    void setPropFloat64(const QList<double>& propFloat64) override;
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QList<int> funcInt(const QList<int>& paramInt) override;
    QList<qint32> funcInt32(const QList<qint32>& paramInt32) override;
    QList<qint64> funcInt64(const QList<qint64>& paramInt64) override;
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    QList<float> funcFloat32(const QList<float>& paramFloat32) override;
    QList<double> funcFloat64(const QList<double>& paramFloat) override;
    QList<QString> funcString(const QList<QString>& paramString) override;

private:
    QList<bool> m_propBool;
    QList<int> m_propInt;
    QList<qint32> m_propInt32;
    QList<qint64> m_propInt64;
    QList<qreal> m_propFloat;
    QList<float> m_propFloat32;
    QList<double> m_propFloat64;
    QList<QString> m_propString;
};

} // namespace tb_simple

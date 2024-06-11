

#pragma once
#include "tb_simple/api/api.h"
#include "tb_simple/monitor/agent.h"
#include <memory>

#if defined(TB_SIMPLE_MONITOR_LIBRARY)
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

class SimpleArrayInterfaceTracer;

/** 
* Trace decorator for SimpleArrayInterface.
*/

class TB_SIMPLE_MONITOR_EXPORT SimpleArrayInterfaceTraced : public AbstractSimpleArrayInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The SimpleArrayInterface object to trace.
    */
    explicit SimpleArrayInterfaceTraced(std::shared_ptr<AbstractSimpleArrayInterface> impl);
    /** dtor */
    virtual ~SimpleArrayInterfaceTraced() = default;

    /** Traces funcBool and forwards call to SimpleArrayInterface implementation. */
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    
    /** Traces funcInt and forwards call to SimpleArrayInterface implementation. */
    QList<int> funcInt(const QList<int>& paramInt) override;
    
    /** Traces funcInt32 and forwards call to SimpleArrayInterface implementation. */
    QList<qint32> funcInt32(const QList<qint32>& paramInt32) override;
    
    /** Traces funcInt64 and forwards call to SimpleArrayInterface implementation. */
    QList<qint64> funcInt64(const QList<qint64>& paramInt64) override;
    
    /** Traces funcFloat and forwards call to SimpleArrayInterface implementation. */
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    
    /** Traces funcFloat32 and forwards call to SimpleArrayInterface implementation. */
    QList<float> funcFloat32(const QList<float>& paramFloat32) override;
    
    /** Traces funcFloat64 and forwards call to SimpleArrayInterface implementation. */
    QList<double> funcFloat64(const QList<double>& paramFloat) override;
    
    /** Traces funcString and forwards call to SimpleArrayInterface implementation. */
    QList<QString> funcString(const QList<QString>& paramString) override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropBool(const QList<bool>& propBool) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<bool> propBool() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropInt(const QList<int>& propInt) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<int> propInt() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropInt32(const QList<qint32>& propInt32) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<qint32> propInt32() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropInt64(const QList<qint64>& propInt64) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<qint64> propInt64() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropFloat(const QList<qreal>& propFloat) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<qreal> propFloat() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropFloat32(const QList<float>& propFloat32) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<float> propFloat32() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropFloat64(const QList<double>& propFloat64) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<double> propFloat64() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropString(const QList<QString>& propString) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QList<QString> propString() const override;
    
    /** Traces and forwards call to SimpleArrayInterface implementation. */
    void setPropReadOnlyString(const QString& propReadOnlyString) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    QString propReadOnlyString() const override;
    slots
    /**  Traces sigBool emission. */
    void traceSigBool(const QList<bool>& paramBool);
    /**  Traces sigInt emission. */
    void traceSigInt(const QList<int>& paramInt);
    /**  Traces sigInt32 emission. */
    void traceSigInt32(const QList<qint32>& paramInt32);
    /**  Traces sigInt64 emission. */
    void traceSigInt64(const QList<qint64>& paramInt64);
    /**  Traces sigFloat emission. */
    void traceSigFloat(const QList<qreal>& paramFloat);
    /**  Traces sigFloat32 emission. */
    void traceSigFloat32(const QList<float>& paramFloa32);
    /**  Traces sigFloat64 emission. */
    void traceSigFloat64(const QList<double>& paramFloat64);
    /**  Traces sigString emission. */
    void traceSigString(const QList<QString>& paramString);

private:
    /** The SimpleArrayInterface object which is traced */
    std::shared_ptr<AbstractSimpleArrayInterface> m_impl;
};
} // namespace tb_simple

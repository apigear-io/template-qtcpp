

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

class SimpleInterfaceTracer;

/** 
* Trace decorator for SimpleInterface.
*/

class TB_SIMPLE_MONITOR_EXPORT SimpleInterfaceTraced : public AbstractSimpleInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The SimpleInterface object to trace.
    */
    explicit SimpleInterfaceTraced(std::shared_ptr<AbstractSimpleInterface> impl);
    /** dtor */
    virtual ~SimpleInterfaceTraced() = default;

    /** Traces funcVoid and forwards call to SimpleInterface implementation. */
    void funcVoid() override;
    
    /** Traces funcBool and forwards call to SimpleInterface implementation. */
    bool funcBool(bool paramBool) override;
    
    /** Traces funcInt and forwards call to SimpleInterface implementation. */
    int funcInt(int paramInt) override;
    
    /** Traces funcInt32 and forwards call to SimpleInterface implementation. */
    qint32 funcInt32(qint32 paramInt32) override;
    
    /** Traces funcInt64 and forwards call to SimpleInterface implementation. */
    qint64 funcInt64(qint64 paramInt64) override;
    
    /** Traces funcFloat and forwards call to SimpleInterface implementation. */
    qreal funcFloat(qreal paramFloat) override;
    
    /** Traces funcFloat32 and forwards call to SimpleInterface implementation. */
    float funcFloat32(float paramFloat32) override;
    
    /** Traces funcFloat64 and forwards call to SimpleInterface implementation. */
    double funcFloat64(double paramFloat) override;
    
    /** Traces funcString and forwards call to SimpleInterface implementation. */
    QString funcString(const QString& paramString) override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropBool(bool propBool) override;
    /** Forwards call to SimpleInterface implementation. */
    bool propBool() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropInt(int propInt) override;
    /** Forwards call to SimpleInterface implementation. */
    int propInt() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropInt32(qint32 propInt32) override;
    /** Forwards call to SimpleInterface implementation. */
    qint32 propInt32() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropInt64(qint64 propInt64) override;
    /** Forwards call to SimpleInterface implementation. */
    qint64 propInt64() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropFloat(qreal propFloat) override;
    /** Forwards call to SimpleInterface implementation. */
    qreal propFloat() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropFloat32(float propFloat32) override;
    /** Forwards call to SimpleInterface implementation. */
    float propFloat32() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropFloat64(double propFloat64) override;
    /** Forwards call to SimpleInterface implementation. */
    double propFloat64() const override;
    
    /** Traces and forwards call to SimpleInterface implementation. */
    void setPropString(const QString& propString) override;
    /** Forwards call to SimpleInterface implementation. */
    QString propString() const override;
    slots
    /**  Traces sigVoid emission. */
    void traceSigVoid();
    /**  Traces sigBool emission. */
    void traceSigBool(bool paramBool);
    /**  Traces sigInt emission. */
    void traceSigInt(int paramInt);
    /**  Traces sigInt32 emission. */
    void traceSigInt32(qint32 paramInt32);
    /**  Traces sigInt64 emission. */
    void traceSigInt64(qint64 paramInt64);
    /**  Traces sigFloat emission. */
    void traceSigFloat(qreal paramFloat);
    /**  Traces sigFloat32 emission. */
    void traceSigFloat32(float paramFloa32);
    /**  Traces sigFloat64 emission. */
    void traceSigFloat64(double paramFloat64);
    /**  Traces sigString emission. */
    void traceSigString(const QString& paramString);

private:
    /** The SimpleInterface object which is traced */
    std::shared_ptr<AbstractSimpleInterface> m_impl;
};
} // namespace tb_simple

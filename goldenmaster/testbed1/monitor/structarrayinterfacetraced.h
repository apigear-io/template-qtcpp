

#pragma once
#include "testbed1/api/api.h"
#include "testbed1/monitor/agent.h"
#include <memory>

#if defined(TESTBED1_MONITOR_LIBRARY)
#  define TESTBED1_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

class StructArrayInterfaceTracer;

/** 
* Trace decorator for StructArrayInterface.
*/

class TESTBED1_MONITOR_EXPORT StructArrayInterfaceTraced : public AbstractStructArrayInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The StructArrayInterface object to trace.
    */
    explicit StructArrayInterfaceTraced(std::shared_ptr<AbstractStructArrayInterface> impl);
    /** dtor */
    virtual ~StructArrayInterfaceTraced() = default;

    /** Traces funcBool and forwards call to StructArrayInterface implementation. */
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    
    /** Traces funcInt and forwards call to StructArrayInterface implementation. */
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    
    /** Traces funcFloat and forwards call to StructArrayInterface implementation. */
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    
    /** Traces funcString and forwards call to StructArrayInterface implementation. */
    StructBool funcString(const QList<StructString>& paramString) override;
    
    /** Traces and forwards call to StructArrayInterface implementation. */
    void setPropBool(const QList<StructBool>& propBool) override;
    /** Forwards call to StructArrayInterface implementation. */
    QList<StructBool> propBool() const override;
    
    /** Traces and forwards call to StructArrayInterface implementation. */
    void setPropInt(const QList<StructInt>& propInt) override;
    /** Forwards call to StructArrayInterface implementation. */
    QList<StructInt> propInt() const override;
    
    /** Traces and forwards call to StructArrayInterface implementation. */
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    /** Forwards call to StructArrayInterface implementation. */
    QList<StructFloat> propFloat() const override;
    
    /** Traces and forwards call to StructArrayInterface implementation. */
    void setPropString(const QList<StructString>& propString) override;
    /** Forwards call to StructArrayInterface implementation. */
    QList<StructString> propString() const override;
    slots
    /**  Traces sigBool emission. */
    void traceSigBool(const QList<StructBool>& paramBool);
    /**  Traces sigInt emission. */
    void traceSigInt(const QList<StructInt>& paramInt);
    /**  Traces sigFloat emission. */
    void traceSigFloat(const QList<StructFloat>& paramFloat);
    /**  Traces sigString emission. */
    void traceSigString(const QList<StructString>& paramString);

private:
    /** The StructArrayInterface object which is traced */
    std::shared_ptr<AbstractStructArrayInterface> m_impl;
};
} // namespace testbed1

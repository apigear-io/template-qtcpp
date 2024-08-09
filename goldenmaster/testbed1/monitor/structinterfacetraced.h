

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

class StructInterfaceTracer;

/** 
* Trace decorator for StructInterface.
*/

class TESTBED1_MONITOR_EXPORT StructInterfaceTraced : public AbstractStructInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The StructInterface object to trace.
    */
    explicit StructInterfaceTraced(std::shared_ptr<AbstractStructInterface> impl);
    /** dtor */
    virtual ~StructInterfaceTraced() = default;

    /** Traces funcBool and forwards call to StructInterface implementation. */
    StructBool funcBool(const StructBool& paramBool) override;
    
    /** Traces funcInt and forwards call to StructInterface implementation. */
    StructInt funcInt(const StructInt& paramInt) override;
    
    /** Traces funcFloat and forwards call to StructInterface implementation. */
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    
    /** Traces funcString and forwards call to StructInterface implementation. */
    StructString funcString(const StructString& paramString) override;
    
    /** Traces and forwards call to StructInterface implementation. */
    void setPropBool(const StructBool& propBool) override;
    /** Forwards call to StructInterface implementation. */
    StructBool propBool() const override;
    
    /** Traces and forwards call to StructInterface implementation. */
    void setPropInt(const StructInt& propInt) override;
    /** Forwards call to StructInterface implementation. */
    StructInt propInt() const override;
    
    /** Traces and forwards call to StructInterface implementation. */
    void setPropFloat(const StructFloat& propFloat) override;
    /** Forwards call to StructInterface implementation. */
    StructFloat propFloat() const override;
    
    /** Traces and forwards call to StructInterface implementation. */
    void setPropString(const StructString& propString) override;
    /** Forwards call to StructInterface implementation. */
    StructString propString() const override;
    slots
    /**  Traces sigBool emission. */
    void traceSigBool(const StructBool& paramBool);
    /**  Traces sigInt emission. */
    void traceSigInt(const StructInt& paramInt);
    /**  Traces sigFloat emission. */
    void traceSigFloat(const StructFloat& paramFloat);
    /**  Traces sigString emission. */
    void traceSigString(const StructString& paramString);

private:
    /** The StructInterface object which is traced */
    std::shared_ptr<AbstractStructInterface> m_impl;
};
} // namespace testbed1

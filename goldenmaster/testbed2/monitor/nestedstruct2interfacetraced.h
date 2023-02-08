

#pragma once
#include "testbed2/api/api.h"
#include "testbed2/monitor/agent.h"
#include <memory>

#if defined(TESTBED2_MONITOR_LIBRARY)
#  define TESTBED2_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {

class NestedStruct2InterfaceTracer;

/** 
* Trace decorator for NestedStruct2Interface.
*/

class TESTBED2_MONITOR_EXPORT NestedStruct2InterfaceTraced : public AbstractNestedStruct2Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NestedStruct2Interface object to trace.
    */
    explicit NestedStruct2InterfaceTraced(std::shared_ptr<AbstractNestedStruct2Interface> impl);
    /** dtor */
    virtual ~NestedStruct2InterfaceTraced() = default;

    /** Traces func1 and forwards call to NestedStruct2Interface implementation. */
    NestedStruct1 func1(const NestedStruct1& param1) override;
    
    /** Traces func2 and forwards call to NestedStruct2Interface implementation. */
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    
    /** Traces and forwards call to NestedStruct2Interface implementation. */
    void setProp1(const NestedStruct1& prop1) override;
    /** Forwards call to NestedStruct2Interface implementation. */
    NestedStruct1 prop1() const override;
    
    /** Traces and forwards call to NestedStruct2Interface implementation. */
    void setProp2(const NestedStruct2& prop2) override;
    /** Forwards call to NestedStruct2Interface implementation. */
    NestedStruct2 prop2() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(const NestedStruct1& param1);
    /**  Traces sig2 emission. */
    void traceSig2(const NestedStruct1& param1, const NestedStruct2& param2);

private:
    /** The NestedStruct2Interface object which is traced */
    std::shared_ptr<AbstractNestedStruct2Interface> m_impl;
};
} // namespace testbed2

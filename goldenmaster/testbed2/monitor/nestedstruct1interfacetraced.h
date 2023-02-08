

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

class NestedStruct1InterfaceTracer;

/** 
* Trace decorator for NestedStruct1Interface.
*/

class TESTBED2_MONITOR_EXPORT NestedStruct1InterfaceTraced : public AbstractNestedStruct1Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NestedStruct1Interface object to trace.
    */
    explicit NestedStruct1InterfaceTraced(std::shared_ptr<AbstractNestedStruct1Interface> impl);
    /** dtor */
    virtual ~NestedStruct1InterfaceTraced() = default;

    /** Traces func1 and forwards call to NestedStruct1Interface implementation. */
    NestedStruct1 func1(const NestedStruct1& param1) override;
    
    /** Traces and forwards call to NestedStruct1Interface implementation. */
    void setProp1(const NestedStruct1& prop1) override;
    /** Forwards call to NestedStruct1Interface implementation. */
    NestedStruct1 prop1() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(const NestedStruct1& param1);

private:
    /** The NestedStruct1Interface object which is traced */
    std::shared_ptr<AbstractNestedStruct1Interface> m_impl;
};
} // namespace testbed2

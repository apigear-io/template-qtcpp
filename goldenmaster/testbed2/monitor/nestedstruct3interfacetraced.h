

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

class NestedStruct3InterfaceTracer;

/** 
* Trace decorator for NestedStruct3Interface.
*/

class TESTBED2_MONITOR_EXPORT NestedStruct3InterfaceTraced : public AbstractNestedStruct3Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NestedStruct3Interface object to trace.
    */
    explicit NestedStruct3InterfaceTraced(std::shared_ptr<AbstractNestedStruct3Interface> impl);
    /** dtor */
    virtual ~NestedStruct3InterfaceTraced() = default;

    /** Traces func1 and forwards call to NestedStruct3Interface implementation. */
    NestedStruct1 func1(const NestedStruct1& param1) override;
    
    /** Traces func2 and forwards call to NestedStruct3Interface implementation. */
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    
    /** Traces func3 and forwards call to NestedStruct3Interface implementation. */
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    
    /** Traces and forwards call to NestedStruct3Interface implementation. */
    void setProp1(const NestedStruct1& prop1) override;
    /** Forwards call to NestedStruct3Interface implementation. */
    NestedStruct1 prop1() const override;
    
    /** Traces and forwards call to NestedStruct3Interface implementation. */
    void setProp2(const NestedStruct2& prop2) override;
    /** Forwards call to NestedStruct3Interface implementation. */
    NestedStruct2 prop2() const override;
    
    /** Traces and forwards call to NestedStruct3Interface implementation. */
    void setProp3(const NestedStruct3& prop3) override;
    /** Forwards call to NestedStruct3Interface implementation. */
    NestedStruct3 prop3() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(const NestedStruct1& param1);
    /**  Traces sig2 emission. */
    void traceSig2(const NestedStruct1& param1, const NestedStruct2& param2);
    /**  Traces sig3 emission. */
    void traceSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);

private:
    /** The NestedStruct3Interface object which is traced */
    std::shared_ptr<AbstractNestedStruct3Interface> m_impl;
};
} // namespace testbed2

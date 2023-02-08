

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

class ManyParamInterfaceTracer;

/** 
* Trace decorator for ManyParamInterface.
*/

class TESTBED2_MONITOR_EXPORT ManyParamInterfaceTraced : public AbstractManyParamInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The ManyParamInterface object to trace.
    */
    explicit ManyParamInterfaceTraced(std::shared_ptr<AbstractManyParamInterface> impl);
    /** dtor */
    virtual ~ManyParamInterfaceTraced() = default;

    /** Traces func1 and forwards call to ManyParamInterface implementation. */
    int func1(int param1) override;
    
    /** Traces func2 and forwards call to ManyParamInterface implementation. */
    int func2(int param1, int param2) override;
    
    /** Traces func3 and forwards call to ManyParamInterface implementation. */
    int func3(int param1, int param2, int param3) override;
    
    /** Traces func4 and forwards call to ManyParamInterface implementation. */
    int func4(int param1, int param2, int param3, int param4) override;
    
    /** Traces and forwards call to ManyParamInterface implementation. */
    void setProp1(int prop1) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop1() const override;
    
    /** Traces and forwards call to ManyParamInterface implementation. */
    void setProp2(int prop2) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop2() const override;
    
    /** Traces and forwards call to ManyParamInterface implementation. */
    void setProp3(int prop3) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop3() const override;
    
    /** Traces and forwards call to ManyParamInterface implementation. */
    void setProp4(int prop4) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop4() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(int param1);
    /**  Traces sig2 emission. */
    void traceSig2(int param1, int param2);
    /**  Traces sig3 emission. */
    void traceSig3(int param1, int param2, int param3);
    /**  Traces sig4 emission. */
    void traceSig4(int param1, int param2, int param3, int param4);

private:
    /** The ManyParamInterface object which is traced */
    std::shared_ptr<AbstractManyParamInterface> m_impl;
};
} // namespace testbed2

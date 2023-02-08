

#pragma once
#include "tb_same1/api/api.h"
#include "tb_same1/monitor/agent.h"
#include <memory>

#if defined(TB_SAME1_MONITOR_LIBRARY)
#  define TB_SAME1_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {

class SameStruct1InterfaceTracer;

/** 
* Trace decorator for SameStruct1Interface.
*/

class TB_SAME1_MONITOR_EXPORT SameStruct1InterfaceTraced : public AbstractSameStruct1Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The SameStruct1Interface object to trace.
    */
    explicit SameStruct1InterfaceTraced(std::shared_ptr<AbstractSameStruct1Interface> impl);
    /** dtor */
    virtual ~SameStruct1InterfaceTraced() = default;

    /** Traces func1 and forwards call to SameStruct1Interface implementation. */
    Struct1 func1(const Struct1& param1) override;
    
    /** Traces and forwards call to SameStruct1Interface implementation. */
    void setProp1(const Struct1& prop1) override;
    /** Forwards call to SameStruct1Interface implementation. */
    Struct1 prop1() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(const Struct1& param1);

private:
    /** The SameStruct1Interface object which is traced */
    std::shared_ptr<AbstractSameStruct1Interface> m_impl;
};
} // namespace tb_same1

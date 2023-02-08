

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

class SameEnum1InterfaceTracer;

/** 
* Trace decorator for SameEnum1Interface.
*/

class TB_SAME1_MONITOR_EXPORT SameEnum1InterfaceTraced : public AbstractSameEnum1Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The SameEnum1Interface object to trace.
    */
    explicit SameEnum1InterfaceTraced(std::shared_ptr<AbstractSameEnum1Interface> impl);
    /** dtor */
    virtual ~SameEnum1InterfaceTraced() = default;

    /** Traces func1 and forwards call to SameEnum1Interface implementation. */
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    
    /** Traces and forwards call to SameEnum1Interface implementation. */
    void setProp1(Enum1::Enum1Enum prop1) override;
    /** Forwards call to SameEnum1Interface implementation. */
    Enum1::Enum1Enum prop1() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(Enum1::Enum1Enum param1);

private:
    /** The SameEnum1Interface object which is traced */
    std::shared_ptr<AbstractSameEnum1Interface> m_impl;
};
} // namespace tb_same1

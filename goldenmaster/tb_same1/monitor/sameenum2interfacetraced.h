

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

class SameEnum2InterfaceTracer;

/** 
* Trace decorator for SameEnum2Interface.
*/

class TB_SAME1_MONITOR_EXPORT SameEnum2InterfaceTraced : public AbstractSameEnum2Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The SameEnum2Interface object to trace.
    */
    explicit SameEnum2InterfaceTraced(std::shared_ptr<AbstractSameEnum2Interface> impl);
    /** dtor */
    virtual ~SameEnum2InterfaceTraced() = default;

    /** Traces func1 and forwards call to SameEnum2Interface implementation. */
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    
    /** Traces func2 and forwards call to SameEnum2Interface implementation. */
    Enum1::Enum1Enum func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2) override;
    
    /** Traces and forwards call to SameEnum2Interface implementation. */
    void setProp1(Enum1::Enum1Enum prop1) override;
    /** Forwards call to SameEnum2Interface implementation. */
    Enum1::Enum1Enum prop1() const override;
    
    /** Traces and forwards call to SameEnum2Interface implementation. */
    void setProp2(Enum2::Enum2Enum prop2) override;
    /** Forwards call to SameEnum2Interface implementation. */
    Enum2::Enum2Enum prop2() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(Enum1::Enum1Enum param1);
    /**  Traces sig2 emission. */
    void traceSig2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2);

private:
    /** The SameEnum2Interface object which is traced */
    std::shared_ptr<AbstractSameEnum2Interface> m_impl;
};
} // namespace tb_same1



#pragma once
#include "tb_same2/api/api.h"
#include "tb_same2/monitor/agent.h"
#include <memory>

#if defined(TB_SAME2_MONITOR_LIBRARY)
#  define TB_SAME2_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME2_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same2 {

class SameStruct2InterfaceTracer;

/** 
* Trace decorator for SameStruct2Interface.
*/

class TB_SAME2_MONITOR_EXPORT SameStruct2InterfaceTraced : public AbstractSameStruct2Interface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The SameStruct2Interface object to trace.
    */
    explicit SameStruct2InterfaceTraced(std::shared_ptr<AbstractSameStruct2Interface> impl);
    /** dtor */
    virtual ~SameStruct2InterfaceTraced() = default;

    /** Traces func1 and forwards call to SameStruct2Interface implementation. */
    Struct1 func1(const Struct1& param1) override;
    
    /** Traces func2 and forwards call to SameStruct2Interface implementation. */
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    
    /** Traces and forwards call to SameStruct2Interface implementation. */
    void setProp1(const Struct2& prop1) override;
    /** Forwards call to SameStruct2Interface implementation. */
    Struct2 prop1() const override;
    
    /** Traces and forwards call to SameStruct2Interface implementation. */
    void setProp2(const Struct2& prop2) override;
    /** Forwards call to SameStruct2Interface implementation. */
    Struct2 prop2() const override;
    slots
    /**  Traces sig1 emission. */
    void traceSig1(const Struct1& param1);
    /**  Traces sig2 emission. */
    void traceSig2(const Struct1& param1, const Struct2& param2);

private:
    /** The SameStruct2Interface object which is traced */
    std::shared_ptr<AbstractSameStruct2Interface> m_impl;
};
} // namespace tb_same2

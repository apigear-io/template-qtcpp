

#pragma once
#include "tb_enum/api/api.h"
#include "tb_enum/monitor/agent.h"
#include <memory>

#if defined(TB_ENUM_MONITOR_LIBRARY)
#  define TB_ENUM_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_enum {

class EnumInterfaceTracer;

/** 
* Trace decorator for EnumInterface.
*/

class TB_ENUM_MONITOR_EXPORT EnumInterfaceTraced : public AbstractEnumInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The EnumInterface object to trace.
    */
    explicit EnumInterfaceTraced(std::shared_ptr<AbstractEnumInterface> impl);
    /** dtor */
    virtual ~EnumInterfaceTraced() = default;

    /** Traces func0 and forwards call to EnumInterface implementation. */
    Enum0::Enum0Enum func0(Enum0::Enum0Enum param0) override;
    
    /** Traces func1 and forwards call to EnumInterface implementation. */
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    
    /** Traces func2 and forwards call to EnumInterface implementation. */
    Enum2::Enum2Enum func2(Enum2::Enum2Enum param2) override;
    
    /** Traces func3 and forwards call to EnumInterface implementation. */
    Enum3::Enum3Enum func3(Enum3::Enum3Enum param3) override;
    
    /** Traces and forwards call to EnumInterface implementation. */
    void setProp0(Enum0::Enum0Enum prop0) override;
    /** Forwards call to EnumInterface implementation. */
    Enum0::Enum0Enum prop0() const override;
    
    /** Traces and forwards call to EnumInterface implementation. */
    void setProp1(Enum1::Enum1Enum prop1) override;
    /** Forwards call to EnumInterface implementation. */
    Enum1::Enum1Enum prop1() const override;
    
    /** Traces and forwards call to EnumInterface implementation. */
    void setProp2(Enum2::Enum2Enum prop2) override;
    /** Forwards call to EnumInterface implementation. */
    Enum2::Enum2Enum prop2() const override;
    
    /** Traces and forwards call to EnumInterface implementation. */
    void setProp3(Enum3::Enum3Enum prop3) override;
    /** Forwards call to EnumInterface implementation. */
    Enum3::Enum3Enum prop3() const override;
    slots
    /**  Traces sig0 emission. */
    void traceSig0(Enum0::Enum0Enum param0);
    /**  Traces sig1 emission. */
    void traceSig1(Enum1::Enum1Enum param1);
    /**  Traces sig2 emission. */
    void traceSig2(Enum2::Enum2Enum param2);
    /**  Traces sig3 emission. */
    void traceSig3(Enum3::Enum3Enum param3);

private:
    /** The EnumInterface object which is traced */
    std::shared_ptr<AbstractEnumInterface> m_impl;
};
} // namespace tb_enum

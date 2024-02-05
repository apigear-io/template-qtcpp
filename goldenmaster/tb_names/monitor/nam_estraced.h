

#pragma once
#include "tb_names/api/api.h"
#include "tb_names/monitor/agent.h"
#include <memory>

#if defined(TB_NAMES_MONITOR_LIBRARY)
#  define TB_NAMES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_names {

class Nam_EsTracer;

/** 
* Trace decorator for NamEs.
*/

class TB_NAMES_MONITOR_EXPORT NamEsTraced : public AbstractNamEs
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The Nam_Es object to trace.
    */
    explicit NamEsTraced(std::shared_ptr<AbstractNamEs> impl);
    /** dtor */
    virtual ~NamEsTraced() = default;

    /** Traces SOME_FUNCTION and forwards call to NamEs implementation. */
    void someFunction(bool SOME_PARAM) override;
    
    /** Traces Some_Function2 and forwards call to NamEs implementation. */
    void someFunction2(bool Some_Param) override;
    
    /** Traces and forwards call to NamEs implementation. */
    void setSwitch(bool Switch) override;
    /** Forwards call to NamEs implementation. */
    bool Switch() const override;
    
    /** Traces and forwards call to NamEs implementation. */
    void setSomeProperty(int SOME_PROPERTY) override;
    /** Forwards call to NamEs implementation. */
    int SOME_PROPERTY() const override;
    
    /** Traces and forwards call to NamEs implementation. */
    void setSomePoperty2(int Some_Poperty2) override;
    /** Forwards call to NamEs implementation. */
    int Some_Poperty2() const override;
    slots
    /**  Traces SOME_SIGNAL emission. */
    void traceSomeSignal(bool SOME_PARAM);
    /**  Traces Some_Signal2 emission. */
    void traceSomeSignal2(bool Some_Param);

private:
    /** The Nam_Es object which is traced */
    std::shared_ptr<AbstractNamEs> m_impl;
};
} // namespace tb_names

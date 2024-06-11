

#pragma once
#include "tb_simple/api/api.h"
#include "tb_simple/monitor/agent.h"
#include <memory>

#if defined(TB_SIMPLE_MONITOR_LIBRARY)
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

class NoOperationsInterfaceTracer;

/** 
* Trace decorator for NoOperationsInterface.
*/

class TB_SIMPLE_MONITOR_EXPORT NoOperationsInterfaceTraced : public AbstractNoOperationsInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NoOperationsInterface object to trace.
    */
    explicit NoOperationsInterfaceTraced(std::shared_ptr<AbstractNoOperationsInterface> impl);
    /** dtor */
    virtual ~NoOperationsInterfaceTraced() = default;

    /** Traces and forwards call to NoOperationsInterface implementation. */
    void setPropBool(bool propBool) override;
    /** Forwards call to NoOperationsInterface implementation. */
    bool propBool() const override;
    
    /** Traces and forwards call to NoOperationsInterface implementation. */
    void setPropInt(int propInt) override;
    /** Forwards call to NoOperationsInterface implementation. */
    int propInt() const override;
    slots
    /**  Traces sigVoid emission. */
    void traceSigVoid();
    /**  Traces sigBool emission. */
    void traceSigBool(bool paramBool);

private:
    /** The NoOperationsInterface object which is traced */
    std::shared_ptr<AbstractNoOperationsInterface> m_impl;
};
} // namespace tb_simple

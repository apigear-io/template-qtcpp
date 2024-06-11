

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

class NoSignalsInterfaceTracer;

/** 
* Trace decorator for NoSignalsInterface.
*/

class TB_SIMPLE_MONITOR_EXPORT NoSignalsInterfaceTraced : public AbstractNoSignalsInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NoSignalsInterface object to trace.
    */
    explicit NoSignalsInterfaceTraced(std::shared_ptr<AbstractNoSignalsInterface> impl);
    /** dtor */
    virtual ~NoSignalsInterfaceTraced() = default;

    /** Traces funcVoid and forwards call to NoSignalsInterface implementation. */
    void funcVoid() override;
    
    /** Traces funcBool and forwards call to NoSignalsInterface implementation. */
    bool funcBool(bool paramBool) override;
    
    /** Traces and forwards call to NoSignalsInterface implementation. */
    void setPropBool(bool propBool) override;
    /** Forwards call to NoSignalsInterface implementation. */
    bool propBool() const override;
    
    /** Traces and forwards call to NoSignalsInterface implementation. */
    void setPropInt(int propInt) override;
    /** Forwards call to NoSignalsInterface implementation. */
    int propInt() const override;
    slots

private:
    /** The NoSignalsInterface object which is traced */
    std::shared_ptr<AbstractNoSignalsInterface> m_impl;
};
} // namespace tb_simple

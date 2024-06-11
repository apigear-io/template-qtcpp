

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

class NoPropertiesInterfaceTracer;

/** 
* Trace decorator for NoPropertiesInterface.
*/

class TB_SIMPLE_MONITOR_EXPORT NoPropertiesInterfaceTraced : public AbstractNoPropertiesInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NoPropertiesInterface object to trace.
    */
    explicit NoPropertiesInterfaceTraced(std::shared_ptr<AbstractNoPropertiesInterface> impl);
    /** dtor */
    virtual ~NoPropertiesInterfaceTraced() = default;

    /** Traces funcVoid and forwards call to NoPropertiesInterface implementation. */
    void funcVoid() override;
    
    /** Traces funcBool and forwards call to NoPropertiesInterface implementation. */
    bool funcBool(bool paramBool) override;
    slots
    /**  Traces sigVoid emission. */
    void traceSigVoid();
    /**  Traces sigBool emission. */
    void traceSigBool(bool paramBool);

private:
    /** The NoPropertiesInterface object which is traced */
    std::shared_ptr<AbstractNoPropertiesInterface> m_impl;
};
} // namespace tb_simple

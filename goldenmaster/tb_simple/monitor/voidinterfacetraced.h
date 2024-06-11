

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

class VoidInterfaceTracer;

/** 
* Trace decorator for VoidInterface.
*/

class TB_SIMPLE_MONITOR_EXPORT VoidInterfaceTraced : public AbstractVoidInterface
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The VoidInterface object to trace.
    */
    explicit VoidInterfaceTraced(std::shared_ptr<AbstractVoidInterface> impl);
    /** dtor */
    virtual ~VoidInterfaceTraced() = default;

    /** Traces funcVoid and forwards call to VoidInterface implementation. */
    void funcVoid() override;
    slots
    /**  Traces sigVoid emission. */
    void traceSigVoid();

private:
    /** The VoidInterface object which is traced */
    std::shared_ptr<AbstractVoidInterface> m_impl;
};
} // namespace tb_simple

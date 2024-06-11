
#include "voidinterfacetraced.h"
#include "tb_simple/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_simple {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

VoidInterfaceTraced::VoidInterfaceTraced(std::shared_ptr<AbstractVoidInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractVoidInterface::sigVoid, this, &VoidInterfaceTraced::sigVoid);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractVoidInterface::sigVoid, this, &VoidInterfaceTraced::traceSigVoid);

    // Connect property changed signals emitted by implementation with this object.
}

void VoidInterfaceTraced::funcVoid() 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return ;
    }
    VoidInterfaceAgent::trace_funcVoid(this );
    m_impl->funcVoid();
}

void VoidInterfaceTraced::traceSigVoid()
{
    VoidInterfaceAgent::trace_sigVoid(this );
}

} // namespace tb_simple

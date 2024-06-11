
#include "nopropertiesinterfacetraced.h"
#include "tb_simple/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_simple {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

NoPropertiesInterfaceTraced::NoPropertiesInterfaceTraced(std::shared_ptr<AbstractNoPropertiesInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractNoPropertiesInterface::sigVoid, this, &NoPropertiesInterfaceTraced::sigVoid);
     connect(m_impl.get(), &AbstractNoPropertiesInterface::sigBool, this, &NoPropertiesInterfaceTraced::sigBool);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractNoPropertiesInterface::sigVoid, this, &NoPropertiesInterfaceTraced::traceSigVoid);
     connect(m_impl.get(), &AbstractNoPropertiesInterface::sigBool, this, &NoPropertiesInterfaceTraced::traceSigBool);

    // Connect property changed signals emitted by implementation with this object.
}

void NoPropertiesInterfaceTraced::funcVoid() 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return ;
    }
    NoPropertiesInterfaceAgent::trace_funcVoid(this );
    m_impl->funcVoid();
}


bool NoPropertiesInterfaceTraced::funcBool(bool paramBool) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NoPropertiesInterfaceAgent::trace_funcBool(this, paramBool);
    return m_impl->funcBool(paramBool);
}

void NoPropertiesInterfaceTraced::traceSigVoid()
{
    NoPropertiesInterfaceAgent::trace_sigVoid(this );
}
void NoPropertiesInterfaceTraced::traceSigBool(bool paramBool)
{
    NoPropertiesInterfaceAgent::trace_sigBool(this, paramBool);
}

} // namespace tb_simple

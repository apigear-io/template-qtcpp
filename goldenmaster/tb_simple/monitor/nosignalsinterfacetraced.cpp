
#include "nosignalsinterfacetraced.h"
#include "tb_simple/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_simple {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

NoSignalsInterfaceTraced::NoSignalsInterfaceTraced(std::shared_ptr<AbstractNoSignalsInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.

    // Connect signals emitted by implementation with this object.

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractNoSignalsInterface::propBoolChanged, this, &AbstractNoSignalsInterface::propBoolChanged);
    connect(m_impl.get(), &AbstractNoSignalsInterface::propIntChanged, this, &AbstractNoSignalsInterface::propIntChanged);
}

void NoSignalsInterfaceTraced::funcVoid() 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return ;
    }
    NoSignalsInterfaceAgent::trace_funcVoid(this );
    m_impl->funcVoid();
}


bool NoSignalsInterfaceTraced::funcBool(bool paramBool) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NoSignalsInterfaceAgent::trace_funcBool(this, paramBool);
    return m_impl->funcBool(paramBool);
}

void NoSignalsInterfaceTraced::setPropBool(bool propBool)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NoSignalsInterfaceAgent::trace_state(this);
    m_impl->setPropBool(propBool);
}
bool NoSignalsInterfaceTraced::propBool() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propBool();
}

void NoSignalsInterfaceTraced::setPropInt(int propInt)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NoSignalsInterfaceAgent::trace_state(this);
    m_impl->setPropInt(propInt);
}
int NoSignalsInterfaceTraced::propInt() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propInt();
}


} // namespace tb_simple

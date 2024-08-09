
#include "nooperationsinterfacetraced.h"
#include "tb_simple/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_simple {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

NoOperationsInterfaceTraced::NoOperationsInterfaceTraced(std::shared_ptr<AbstractNoOperationsInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractNoOperationsInterface::sigVoid, this, &NoOperationsInterfaceTraced::sigVoid);
     connect(m_impl.get(), &AbstractNoOperationsInterface::sigBool, this, &NoOperationsInterfaceTraced::sigBool);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractNoOperationsInterface::sigVoid, this, &NoOperationsInterfaceTraced::traceSigVoid);
     connect(m_impl.get(), &AbstractNoOperationsInterface::sigBool, this, &NoOperationsInterfaceTraced::traceSigBool);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractNoOperationsInterface::propBoolChanged, this, &AbstractNoOperationsInterface::propBoolChanged);
    connect(m_impl.get(), &AbstractNoOperationsInterface::propIntChanged, this, &AbstractNoOperationsInterface::propIntChanged);
}
void NoOperationsInterfaceTraced::setPropBool(bool propBool)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NoOperationsInterfaceAgent::trace_state(this);
    m_impl->setPropBool(propBool);
}
bool NoOperationsInterfaceTraced::propBool() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propBool();
}

void NoOperationsInterfaceTraced::setPropInt(int propInt)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NoOperationsInterfaceAgent::trace_state(this);
    m_impl->setPropInt(propInt);
}
int NoOperationsInterfaceTraced::propInt() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propInt();
}

void NoOperationsInterfaceTraced::traceSigVoid()
{
    NoOperationsInterfaceAgent::trace_sigVoid(this );
}
void NoOperationsInterfaceTraced::traceSigBool(bool paramBool)
{
    NoOperationsInterfaceAgent::trace_sigBool(this, paramBool);
}

} // namespace tb_simple

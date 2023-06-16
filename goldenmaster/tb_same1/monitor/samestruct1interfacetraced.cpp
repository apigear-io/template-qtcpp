
#include "samestruct1interfacetraced.h"
#include "tb_same1/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_same1 {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

SameStruct1InterfaceTraced::SameStruct1InterfaceTraced(std::shared_ptr<AbstractSameStruct1Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSameStruct1Interface::sig1, this, &SameStruct1InterfaceTraced::sig1);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSameStruct1Interface::sig1, this, &SameStruct1InterfaceTraced::traceSig1);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSameStruct1Interface::prop1Changed, this, &AbstractSameStruct1Interface::prop1Changed);
}

Struct1 SameStruct1InterfaceTraced::func1(const Struct1& param1) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SameStruct1InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}

void SameStruct1InterfaceTraced::setProp1(const Struct1& prop1)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SameStruct1InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
Struct1 SameStruct1InterfaceTraced::prop1() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop1();
}

void SameStruct1InterfaceTraced::traceSig1(const Struct1& param1)
{
    SameStruct1InterfaceAgent::trace_sig1(this, param1);
}

} // namespace tb_same1

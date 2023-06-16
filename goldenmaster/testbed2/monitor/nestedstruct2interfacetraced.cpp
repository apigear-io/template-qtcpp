
#include "nestedstruct2interfacetraced.h"
#include "testbed2/monitor/agent.h"
#include "utilities/logger.h"

namespace testbed2 {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

NestedStruct2InterfaceTraced::NestedStruct2InterfaceTraced(std::shared_ptr<AbstractNestedStruct2Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractNestedStruct2Interface::sig1, this, &NestedStruct2InterfaceTraced::sig1);
     connect(m_impl.get(), &AbstractNestedStruct2Interface::sig2, this, &NestedStruct2InterfaceTraced::sig2);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractNestedStruct2Interface::sig1, this, &NestedStruct2InterfaceTraced::traceSig1);
     connect(m_impl.get(), &AbstractNestedStruct2Interface::sig2, this, &NestedStruct2InterfaceTraced::traceSig2);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractNestedStruct2Interface::prop1Changed, this, &AbstractNestedStruct2Interface::prop1Changed);
    connect(m_impl.get(), &AbstractNestedStruct2Interface::prop2Changed, this, &AbstractNestedStruct2Interface::prop2Changed);
}

NestedStruct1 NestedStruct2InterfaceTraced::func1(const NestedStruct1& param1) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NestedStruct2InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}


NestedStruct1 NestedStruct2InterfaceTraced::func2(const NestedStruct1& param1, const NestedStruct2& param2) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NestedStruct2InterfaceAgent::trace_func2(this, param1, param2);
    return m_impl->func2(param1, param2);
}

void NestedStruct2InterfaceTraced::setProp1(const NestedStruct1& prop1)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NestedStruct2InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
NestedStruct1 NestedStruct2InterfaceTraced::prop1() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop1();
}

void NestedStruct2InterfaceTraced::setProp2(const NestedStruct2& prop2)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NestedStruct2InterfaceAgent::trace_state(this);
    m_impl->setProp2(prop2);
}
NestedStruct2 NestedStruct2InterfaceTraced::prop2() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop2();
}

void NestedStruct2InterfaceTraced::traceSig1(const NestedStruct1& param1)
{
    NestedStruct2InterfaceAgent::trace_sig1(this, param1);
}
void NestedStruct2InterfaceTraced::traceSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    NestedStruct2InterfaceAgent::trace_sig2(this, param1, param2);
}

} // namespace testbed2


#include "sameenum2interfacetraced.h"
#include "tb_same1/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_same1 {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

SameEnum2InterfaceTraced::SameEnum2InterfaceTraced(std::shared_ptr<AbstractSameEnum2Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSameEnum2Interface::sig1, this, &SameEnum2InterfaceTraced::sig1);
     connect(m_impl.get(), &AbstractSameEnum2Interface::sig2, this, &SameEnum2InterfaceTraced::sig2);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSameEnum2Interface::sig1, this, &SameEnum2InterfaceTraced::traceSig1);
     connect(m_impl.get(), &AbstractSameEnum2Interface::sig2, this, &SameEnum2InterfaceTraced::traceSig2);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSameEnum2Interface::prop1Changed, this, &AbstractSameEnum2Interface::prop1Changed);
    connect(m_impl.get(), &AbstractSameEnum2Interface::prop2Changed, this, &AbstractSameEnum2Interface::prop2Changed);
}

Enum1::Enum1Enum SameEnum2InterfaceTraced::func1(Enum1::Enum1Enum param1) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SameEnum2InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}


Enum1::Enum1Enum SameEnum2InterfaceTraced::func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SameEnum2InterfaceAgent::trace_func2(this, param1, param2);
    return m_impl->func2(param1, param2);
}

void SameEnum2InterfaceTraced::setProp1(Enum1::Enum1Enum prop1)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SameEnum2InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
Enum1::Enum1Enum SameEnum2InterfaceTraced::prop1() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop1();
}

void SameEnum2InterfaceTraced::setProp2(Enum2::Enum2Enum prop2)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SameEnum2InterfaceAgent::trace_state(this);
    m_impl->setProp2(prop2);
}
Enum2::Enum2Enum SameEnum2InterfaceTraced::prop2() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop2();
}

void SameEnum2InterfaceTraced::traceSig1(Enum1::Enum1Enum param1)
{
    SameEnum2InterfaceAgent::trace_sig1(this, param1);
}
void SameEnum2InterfaceTraced::traceSig2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    SameEnum2InterfaceAgent::trace_sig2(this, param1, param2);
}

} // namespace tb_same1

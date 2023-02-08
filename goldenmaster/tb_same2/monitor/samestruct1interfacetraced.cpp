
#pragma once
#include "samestruct1interfacetraced.h"
#include "tb_same2/monitor/agent.h"

namespace tb_same2 {


SameStruct1InterfaceTraced::SameStruct1InterfaceTraced(std::shared_ptr<AbstractSameStruct1Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSameStruct1Interface::sig1, this, &SameStruct1InterfaceTraced::traceSig1);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSameStruct1Interface::sig1, this, &SameStruct1InterfaceTraced::traceSig1);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSameStruct1Interface::prop1Changed, this, &AbstractSameStruct1Interface::prop1Changed);
}

Struct1 SameStruct1InterfaceTraced::func1(const Struct1& param1) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SameStruct1InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}

void SameStruct1InterfaceTraced::setProp1(const Struct1& prop1)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SameStruct1InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
Struct1 SameStruct1InterfaceTraced::prop1() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop1();
}

void SameStruct1InterfaceTraced::traceSig1(const Struct1& param1)
{
    SameStruct1InterfaceAgent::trace_sig1(this, param1);
}

} // namespace tb_same2

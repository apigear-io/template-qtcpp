
#pragma once
#include "sameenum1interfacetraced.h"
#include "tb_same2/monitor/agent.h"

namespace tb_same2 {


SameEnum1InterfaceTraced::SameEnum1InterfaceTraced(std::shared_ptr<AbstractSameEnum1Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSameEnum1Interface::sig1, this, &SameEnum1InterfaceTraced::sig1);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSameEnum1Interface::sig1, this, &SameEnum1InterfaceTraced::traceSig1);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSameEnum1Interface::prop1Changed, this, &AbstractSameEnum1Interface::prop1Changed);
}

Enum1::Enum1Enum SameEnum1InterfaceTraced::func1(Enum1::Enum1Enum param1) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SameEnum1InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}

void SameEnum1InterfaceTraced::setProp1(Enum1::Enum1Enum prop1)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SameEnum1InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
Enum1::Enum1Enum SameEnum1InterfaceTraced::prop1() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop1();
}

void SameEnum1InterfaceTraced::traceSig1(Enum1::Enum1Enum param1)
{
    SameEnum1InterfaceAgent::trace_sig1(this, param1);
}

} // namespace tb_same2

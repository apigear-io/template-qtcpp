
#include "nestedstruct1interfacetraced.h"
#include "testbed2/monitor/agent.h"

namespace testbed2 {


NestedStruct1InterfaceTraced::NestedStruct1InterfaceTraced(std::shared_ptr<AbstractNestedStruct1Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractNestedStruct1Interface::sig1, this, &NestedStruct1InterfaceTraced::sig1);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractNestedStruct1Interface::sig1, this, &NestedStruct1InterfaceTraced::traceSig1);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractNestedStruct1Interface::prop1Changed, this, &AbstractNestedStruct1Interface::prop1Changed);
}

NestedStruct1 NestedStruct1InterfaceTraced::func1(const NestedStruct1& param1) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    NestedStruct1InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}

void NestedStruct1InterfaceTraced::setProp1(const NestedStruct1& prop1)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    NestedStruct1InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
NestedStruct1 NestedStruct1InterfaceTraced::prop1() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop1();
}

void NestedStruct1InterfaceTraced::traceSig1(const NestedStruct1& param1)
{
    NestedStruct1InterfaceAgent::trace_sig1(this, param1);
}

} // namespace testbed2

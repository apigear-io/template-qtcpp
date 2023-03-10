
#pragma once
#include "samestruct2interfacetraced.h"
#include "tb_same1/monitor/agent.h"

namespace tb_same1 {


SameStruct2InterfaceTraced::SameStruct2InterfaceTraced(std::shared_ptr<AbstractSameStruct2Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSameStruct2Interface::sig1, this, &SameStruct2InterfaceTraced::sig1);
     connect(m_impl.get(), &AbstractSameStruct2Interface::sig2, this, &SameStruct2InterfaceTraced::sig2);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSameStruct2Interface::sig1, this, &SameStruct2InterfaceTraced::traceSig1);
     connect(m_impl.get(), &AbstractSameStruct2Interface::sig2, this, &SameStruct2InterfaceTraced::traceSig2);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSameStruct2Interface::prop1Changed, this, &AbstractSameStruct2Interface::prop1Changed);
    connect(m_impl.get(), &AbstractSameStruct2Interface::prop2Changed, this, &AbstractSameStruct2Interface::prop2Changed);
}

Struct1 SameStruct2InterfaceTraced::func1(const Struct1& param1) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SameStruct2InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}


Struct1 SameStruct2InterfaceTraced::func2(const Struct1& param1, const Struct2& param2) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SameStruct2InterfaceAgent::trace_func2(this, param1, param2);
    return m_impl->func2(param1, param2);
}

void SameStruct2InterfaceTraced::setProp1(const Struct2& prop1)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SameStruct2InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
Struct2 SameStruct2InterfaceTraced::prop1() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop1();
}

void SameStruct2InterfaceTraced::setProp2(const Struct2& prop2)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SameStruct2InterfaceAgent::trace_state(this);
    m_impl->setProp2(prop2);
}
Struct2 SameStruct2InterfaceTraced::prop2() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop2();
}

void SameStruct2InterfaceTraced::traceSig1(const Struct1& param1)
{
    SameStruct2InterfaceAgent::trace_sig1(this, param1);
}
void SameStruct2InterfaceTraced::traceSig2(const Struct1& param1, const Struct2& param2)
{
    SameStruct2InterfaceAgent::trace_sig2(this, param1, param2);
}

} // namespace tb_same1

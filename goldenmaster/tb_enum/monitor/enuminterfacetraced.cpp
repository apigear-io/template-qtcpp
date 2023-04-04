
#include "enuminterfacetraced.h"
#include "tb_enum/monitor/agent.h"

namespace tb_enum {


EnumInterfaceTraced::EnumInterfaceTraced(std::shared_ptr<AbstractEnumInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractEnumInterface::sig0, this, &EnumInterfaceTraced::sig0);
     connect(m_impl.get(), &AbstractEnumInterface::sig1, this, &EnumInterfaceTraced::sig1);
     connect(m_impl.get(), &AbstractEnumInterface::sig2, this, &EnumInterfaceTraced::sig2);
     connect(m_impl.get(), &AbstractEnumInterface::sig3, this, &EnumInterfaceTraced::sig3);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractEnumInterface::sig0, this, &EnumInterfaceTraced::traceSig0);
     connect(m_impl.get(), &AbstractEnumInterface::sig1, this, &EnumInterfaceTraced::traceSig1);
     connect(m_impl.get(), &AbstractEnumInterface::sig2, this, &EnumInterfaceTraced::traceSig2);
     connect(m_impl.get(), &AbstractEnumInterface::sig3, this, &EnumInterfaceTraced::traceSig3);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractEnumInterface::prop0Changed, this, &AbstractEnumInterface::prop0Changed);
    connect(m_impl.get(), &AbstractEnumInterface::prop1Changed, this, &AbstractEnumInterface::prop1Changed);
    connect(m_impl.get(), &AbstractEnumInterface::prop2Changed, this, &AbstractEnumInterface::prop2Changed);
    connect(m_impl.get(), &AbstractEnumInterface::prop3Changed, this, &AbstractEnumInterface::prop3Changed);
}

Enum0::Enum0Enum EnumInterfaceTraced::func0(Enum0::Enum0Enum param0) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    EnumInterfaceAgent::trace_func0(this, param0);
    return m_impl->func0(param0);
}


Enum1::Enum1Enum EnumInterfaceTraced::func1(Enum1::Enum1Enum param1) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    EnumInterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}


Enum2::Enum2Enum EnumInterfaceTraced::func2(Enum2::Enum2Enum param2) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    EnumInterfaceAgent::trace_func2(this, param2);
    return m_impl->func2(param2);
}


Enum3::Enum3Enum EnumInterfaceTraced::func3(Enum3::Enum3Enum param3) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    EnumInterfaceAgent::trace_func3(this, param3);
    return m_impl->func3(param3);
}

void EnumInterfaceTraced::setProp0(Enum0::Enum0Enum prop0)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    EnumInterfaceAgent::trace_state(this);
    m_impl->setProp0(prop0);
}
Enum0::Enum0Enum EnumInterfaceTraced::prop0() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop0();
}

void EnumInterfaceTraced::setProp1(Enum1::Enum1Enum prop1)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    EnumInterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
Enum1::Enum1Enum EnumInterfaceTraced::prop1() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop1();
}

void EnumInterfaceTraced::setProp2(Enum2::Enum2Enum prop2)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    EnumInterfaceAgent::trace_state(this);
    m_impl->setProp2(prop2);
}
Enum2::Enum2Enum EnumInterfaceTraced::prop2() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop2();
}

void EnumInterfaceTraced::setProp3(Enum3::Enum3Enum prop3)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    EnumInterfaceAgent::trace_state(this);
    m_impl->setProp3(prop3);
}
Enum3::Enum3Enum EnumInterfaceTraced::prop3() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop3();
}

void EnumInterfaceTraced::traceSig0(Enum0::Enum0Enum param0)
{
    EnumInterfaceAgent::trace_sig0(this, param0);
}
void EnumInterfaceTraced::traceSig1(Enum1::Enum1Enum param1)
{
    EnumInterfaceAgent::trace_sig1(this, param1);
}
void EnumInterfaceTraced::traceSig2(Enum2::Enum2Enum param2)
{
    EnumInterfaceAgent::trace_sig2(this, param2);
}
void EnumInterfaceTraced::traceSig3(Enum3::Enum3Enum param3)
{
    EnumInterfaceAgent::trace_sig3(this, param3);
}

} // namespace tb_enum

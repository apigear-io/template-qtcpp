
#include "nestedstruct3interfacetraced.h"
#include "testbed2/monitor/agent.h"
#include "utilities/logger.h"

namespace testbed2 {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

NestedStruct3InterfaceTraced::NestedStruct3InterfaceTraced(std::shared_ptr<AbstractNestedStruct3Interface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractNestedStruct3Interface::sig1, this, &NestedStruct3InterfaceTraced::sig1);
     connect(m_impl.get(), &AbstractNestedStruct3Interface::sig2, this, &NestedStruct3InterfaceTraced::sig2);
     connect(m_impl.get(), &AbstractNestedStruct3Interface::sig3, this, &NestedStruct3InterfaceTraced::sig3);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractNestedStruct3Interface::sig1, this, &NestedStruct3InterfaceTraced::traceSig1);
     connect(m_impl.get(), &AbstractNestedStruct3Interface::sig2, this, &NestedStruct3InterfaceTraced::traceSig2);
     connect(m_impl.get(), &AbstractNestedStruct3Interface::sig3, this, &NestedStruct3InterfaceTraced::traceSig3);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractNestedStruct3Interface::prop1Changed, this, &AbstractNestedStruct3Interface::prop1Changed);
    connect(m_impl.get(), &AbstractNestedStruct3Interface::prop2Changed, this, &AbstractNestedStruct3Interface::prop2Changed);
    connect(m_impl.get(), &AbstractNestedStruct3Interface::prop3Changed, this, &AbstractNestedStruct3Interface::prop3Changed);
}

NestedStruct1 NestedStruct3InterfaceTraced::func1(const NestedStruct1& param1) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NestedStruct3InterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}


NestedStruct1 NestedStruct3InterfaceTraced::func2(const NestedStruct1& param1, const NestedStruct2& param2) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NestedStruct3InterfaceAgent::trace_func2(this, param1, param2);
    return m_impl->func2(param1, param2);
}


NestedStruct1 NestedStruct3InterfaceTraced::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    NestedStruct3InterfaceAgent::trace_func3(this, param1, param2, param3);
    return m_impl->func3(param1, param2, param3);
}

void NestedStruct3InterfaceTraced::setProp1(const NestedStruct1& prop1)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NestedStruct3InterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
NestedStruct1 NestedStruct3InterfaceTraced::prop1() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop1();
}

void NestedStruct3InterfaceTraced::setProp2(const NestedStruct2& prop2)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NestedStruct3InterfaceAgent::trace_state(this);
    m_impl->setProp2(prop2);
}
NestedStruct2 NestedStruct3InterfaceTraced::prop2() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop2();
}

void NestedStruct3InterfaceTraced::setProp3(const NestedStruct3& prop3)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NestedStruct3InterfaceAgent::trace_state(this);
    m_impl->setProp3(prop3);
}
NestedStruct3 NestedStruct3InterfaceTraced::prop3() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->prop3();
}

void NestedStruct3InterfaceTraced::traceSig1(const NestedStruct1& param1)
{
    NestedStruct3InterfaceAgent::trace_sig1(this, param1);
}
void NestedStruct3InterfaceTraced::traceSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    NestedStruct3InterfaceAgent::trace_sig2(this, param1, param2);
}
void NestedStruct3InterfaceTraced::traceSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    NestedStruct3InterfaceAgent::trace_sig3(this, param1, param2, param3);
}

} // namespace testbed2

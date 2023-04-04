
#include "manyparaminterfacetraced.h"
#include "testbed2/monitor/agent.h"

namespace testbed2 {


ManyParamInterfaceTraced::ManyParamInterfaceTraced(std::shared_ptr<AbstractManyParamInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractManyParamInterface::sig1, this, &ManyParamInterfaceTraced::sig1);
     connect(m_impl.get(), &AbstractManyParamInterface::sig2, this, &ManyParamInterfaceTraced::sig2);
     connect(m_impl.get(), &AbstractManyParamInterface::sig3, this, &ManyParamInterfaceTraced::sig3);
     connect(m_impl.get(), &AbstractManyParamInterface::sig4, this, &ManyParamInterfaceTraced::sig4);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractManyParamInterface::sig1, this, &ManyParamInterfaceTraced::traceSig1);
     connect(m_impl.get(), &AbstractManyParamInterface::sig2, this, &ManyParamInterfaceTraced::traceSig2);
     connect(m_impl.get(), &AbstractManyParamInterface::sig3, this, &ManyParamInterfaceTraced::traceSig3);
     connect(m_impl.get(), &AbstractManyParamInterface::sig4, this, &ManyParamInterfaceTraced::traceSig4);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractManyParamInterface::prop1Changed, this, &AbstractManyParamInterface::prop1Changed);
    connect(m_impl.get(), &AbstractManyParamInterface::prop2Changed, this, &AbstractManyParamInterface::prop2Changed);
    connect(m_impl.get(), &AbstractManyParamInterface::prop3Changed, this, &AbstractManyParamInterface::prop3Changed);
    connect(m_impl.get(), &AbstractManyParamInterface::prop4Changed, this, &AbstractManyParamInterface::prop4Changed);
}

int ManyParamInterfaceTraced::func1(int param1) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    ManyParamInterfaceAgent::trace_func1(this, param1);
    return m_impl->func1(param1);
}


int ManyParamInterfaceTraced::func2(int param1, int param2) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    ManyParamInterfaceAgent::trace_func2(this, param1, param2);
    return m_impl->func2(param1, param2);
}


int ManyParamInterfaceTraced::func3(int param1, int param2, int param3) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    ManyParamInterfaceAgent::trace_func3(this, param1, param2, param3);
    return m_impl->func3(param1, param2, param3);
}


int ManyParamInterfaceTraced::func4(int param1, int param2, int param3, int param4) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    ManyParamInterfaceAgent::trace_func4(this, param1, param2, param3, param4);
    return m_impl->func4(param1, param2, param3, param4);
}

void ManyParamInterfaceTraced::setProp1(int prop1)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    ManyParamInterfaceAgent::trace_state(this);
    m_impl->setProp1(prop1);
}
int ManyParamInterfaceTraced::prop1() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop1();
}

void ManyParamInterfaceTraced::setProp2(int prop2)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    ManyParamInterfaceAgent::trace_state(this);
    m_impl->setProp2(prop2);
}
int ManyParamInterfaceTraced::prop2() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop2();
}

void ManyParamInterfaceTraced::setProp3(int prop3)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    ManyParamInterfaceAgent::trace_state(this);
    m_impl->setProp3(prop3);
}
int ManyParamInterfaceTraced::prop3() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop3();
}

void ManyParamInterfaceTraced::setProp4(int prop4)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    ManyParamInterfaceAgent::trace_state(this);
    m_impl->setProp4(prop4);
}
int ManyParamInterfaceTraced::prop4() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->prop4();
}

void ManyParamInterfaceTraced::traceSig1(int param1)
{
    ManyParamInterfaceAgent::trace_sig1(this, param1);
}
void ManyParamInterfaceTraced::traceSig2(int param1, int param2)
{
    ManyParamInterfaceAgent::trace_sig2(this, param1, param2);
}
void ManyParamInterfaceTraced::traceSig3(int param1, int param2, int param3)
{
    ManyParamInterfaceAgent::trace_sig3(this, param1, param2, param3);
}
void ManyParamInterfaceTraced::traceSig4(int param1, int param2, int param3, int param4)
{
    ManyParamInterfaceAgent::trace_sig4(this, param1, param2, param3, param4);
}

} // namespace testbed2

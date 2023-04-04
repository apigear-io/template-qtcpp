
#include "structarrayinterfacetraced.h"
#include "testbed1/monitor/agent.h"

namespace testbed1 {


StructArrayInterfaceTraced::StructArrayInterfaceTraced(std::shared_ptr<AbstractStructArrayInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractStructArrayInterface::sigBool, this, &StructArrayInterfaceTraced::sigBool);
     connect(m_impl.get(), &AbstractStructArrayInterface::sigInt, this, &StructArrayInterfaceTraced::sigInt);
     connect(m_impl.get(), &AbstractStructArrayInterface::sigFloat, this, &StructArrayInterfaceTraced::sigFloat);
     connect(m_impl.get(), &AbstractStructArrayInterface::sigString, this, &StructArrayInterfaceTraced::sigString);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractStructArrayInterface::sigBool, this, &StructArrayInterfaceTraced::traceSigBool);
     connect(m_impl.get(), &AbstractStructArrayInterface::sigInt, this, &StructArrayInterfaceTraced::traceSigInt);
     connect(m_impl.get(), &AbstractStructArrayInterface::sigFloat, this, &StructArrayInterfaceTraced::traceSigFloat);
     connect(m_impl.get(), &AbstractStructArrayInterface::sigString, this, &StructArrayInterfaceTraced::traceSigString);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractStructArrayInterface::propBoolChanged, this, &AbstractStructArrayInterface::propBoolChanged);
    connect(m_impl.get(), &AbstractStructArrayInterface::propIntChanged, this, &AbstractStructArrayInterface::propIntChanged);
    connect(m_impl.get(), &AbstractStructArrayInterface::propFloatChanged, this, &AbstractStructArrayInterface::propFloatChanged);
    connect(m_impl.get(), &AbstractStructArrayInterface::propStringChanged, this, &AbstractStructArrayInterface::propStringChanged);
}

StructBool StructArrayInterfaceTraced::funcBool(const QList<StructBool>& paramBool) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    StructArrayInterfaceAgent::trace_funcBool(this, paramBool);
    return m_impl->funcBool(paramBool);
}


StructBool StructArrayInterfaceTraced::funcInt(const QList<StructInt>& paramInt) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    StructArrayInterfaceAgent::trace_funcInt(this, paramInt);
    return m_impl->funcInt(paramInt);
}


StructBool StructArrayInterfaceTraced::funcFloat(const QList<StructFloat>& paramFloat) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    StructArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
    return m_impl->funcFloat(paramFloat);
}


StructBool StructArrayInterfaceTraced::funcString(const QList<StructString>& paramString) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    StructArrayInterfaceAgent::trace_funcString(this, paramString);
    return m_impl->funcString(paramString);
}

void StructArrayInterfaceTraced::setPropBool(const QList<StructBool>& propBool)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    StructArrayInterfaceAgent::trace_state(this);
    m_impl->setPropBool(propBool);
}
QList<StructBool> StructArrayInterfaceTraced::propBool() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propBool();
}

void StructArrayInterfaceTraced::setPropInt(const QList<StructInt>& propInt)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    StructArrayInterfaceAgent::trace_state(this);
    m_impl->setPropInt(propInt);
}
QList<StructInt> StructArrayInterfaceTraced::propInt() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propInt();
}

void StructArrayInterfaceTraced::setPropFloat(const QList<StructFloat>& propFloat)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    StructArrayInterfaceAgent::trace_state(this);
    m_impl->setPropFloat(propFloat);
}
QList<StructFloat> StructArrayInterfaceTraced::propFloat() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propFloat();
}

void StructArrayInterfaceTraced::setPropString(const QList<StructString>& propString)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    StructArrayInterfaceAgent::trace_state(this);
    m_impl->setPropString(propString);
}
QList<StructString> StructArrayInterfaceTraced::propString() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propString();
}

void StructArrayInterfaceTraced::traceSigBool(const QList<StructBool>& paramBool)
{
    StructArrayInterfaceAgent::trace_sigBool(this, paramBool);
}
void StructArrayInterfaceTraced::traceSigInt(const QList<StructInt>& paramInt)
{
    StructArrayInterfaceAgent::trace_sigInt(this, paramInt);
}
void StructArrayInterfaceTraced::traceSigFloat(const QList<StructFloat>& paramFloat)
{
    StructArrayInterfaceAgent::trace_sigFloat(this, paramFloat);
}
void StructArrayInterfaceTraced::traceSigString(const QList<StructString>& paramString)
{
    StructArrayInterfaceAgent::trace_sigString(this, paramString);
}

} // namespace testbed1

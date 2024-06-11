
#include "structinterfacetraced.h"
#include "testbed1/monitor/agent.h"
#include "utilities/logger.h"

namespace testbed1 {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

StructInterfaceTraced::StructInterfaceTraced(std::shared_ptr<AbstractStructInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractStructInterface::sigBool, this, &StructInterfaceTraced::sigBool);
     connect(m_impl.get(), &AbstractStructInterface::sigInt, this, &StructInterfaceTraced::sigInt);
     connect(m_impl.get(), &AbstractStructInterface::sigFloat, this, &StructInterfaceTraced::sigFloat);
     connect(m_impl.get(), &AbstractStructInterface::sigString, this, &StructInterfaceTraced::sigString);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractStructInterface::sigBool, this, &StructInterfaceTraced::traceSigBool);
     connect(m_impl.get(), &AbstractStructInterface::sigInt, this, &StructInterfaceTraced::traceSigInt);
     connect(m_impl.get(), &AbstractStructInterface::sigFloat, this, &StructInterfaceTraced::traceSigFloat);
     connect(m_impl.get(), &AbstractStructInterface::sigString, this, &StructInterfaceTraced::traceSigString);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractStructInterface::propBoolChanged, this, &AbstractStructInterface::propBoolChanged);
    connect(m_impl.get(), &AbstractStructInterface::propIntChanged, this, &AbstractStructInterface::propIntChanged);
    connect(m_impl.get(), &AbstractStructInterface::propFloatChanged, this, &AbstractStructInterface::propFloatChanged);
    connect(m_impl.get(), &AbstractStructInterface::propStringChanged, this, &AbstractStructInterface::propStringChanged);
}

StructBool StructInterfaceTraced::funcBool(const StructBool& paramBool) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    StructInterfaceAgent::trace_funcBool(this, paramBool);
    return m_impl->funcBool(paramBool);
}


StructInt StructInterfaceTraced::funcInt(const StructInt& paramInt) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    StructInterfaceAgent::trace_funcInt(this, paramInt);
    return m_impl->funcInt(paramInt);
}


StructFloat StructInterfaceTraced::funcFloat(const StructFloat& paramFloat) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    StructInterfaceAgent::trace_funcFloat(this, paramFloat);
    return m_impl->funcFloat(paramFloat);
}


StructString StructInterfaceTraced::funcString(const StructString& paramString) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    StructInterfaceAgent::trace_funcString(this, paramString);
    return m_impl->funcString(paramString);
}

void StructInterfaceTraced::setPropBool(const StructBool& propBool)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    StructInterfaceAgent::trace_state(this);
    m_impl->setPropBool(propBool);
}
StructBool StructInterfaceTraced::propBool() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propBool();
}

void StructInterfaceTraced::setPropInt(const StructInt& propInt)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    StructInterfaceAgent::trace_state(this);
    m_impl->setPropInt(propInt);
}
StructInt StructInterfaceTraced::propInt() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propInt();
}

void StructInterfaceTraced::setPropFloat(const StructFloat& propFloat)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    StructInterfaceAgent::trace_state(this);
    m_impl->setPropFloat(propFloat);
}
StructFloat StructInterfaceTraced::propFloat() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propFloat();
}

void StructInterfaceTraced::setPropString(const StructString& propString)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    StructInterfaceAgent::trace_state(this);
    m_impl->setPropString(propString);
}
StructString StructInterfaceTraced::propString() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propString();
}

void StructInterfaceTraced::traceSigBool(const StructBool& paramBool)
{
    StructInterfaceAgent::trace_sigBool(this, paramBool);
}
void StructInterfaceTraced::traceSigInt(const StructInt& paramInt)
{
    StructInterfaceAgent::trace_sigInt(this, paramInt);
}
void StructInterfaceTraced::traceSigFloat(const StructFloat& paramFloat)
{
    StructInterfaceAgent::trace_sigFloat(this, paramFloat);
}
void StructInterfaceTraced::traceSigString(const StructString& paramString)
{
    StructInterfaceAgent::trace_sigString(this, paramString);
}

} // namespace testbed1

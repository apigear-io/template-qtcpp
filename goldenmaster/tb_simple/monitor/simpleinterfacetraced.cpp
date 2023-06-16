
#include "simpleinterfacetraced.h"
#include "tb_simple/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_simple {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

SimpleInterfaceTraced::SimpleInterfaceTraced(std::shared_ptr<AbstractSimpleInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSimpleInterface::sigVoid, this, &SimpleInterfaceTraced::sigVoid);
     connect(m_impl.get(), &AbstractSimpleInterface::sigBool, this, &SimpleInterfaceTraced::sigBool);
     connect(m_impl.get(), &AbstractSimpleInterface::sigInt, this, &SimpleInterfaceTraced::sigInt);
     connect(m_impl.get(), &AbstractSimpleInterface::sigInt32, this, &SimpleInterfaceTraced::sigInt32);
     connect(m_impl.get(), &AbstractSimpleInterface::sigInt64, this, &SimpleInterfaceTraced::sigInt64);
     connect(m_impl.get(), &AbstractSimpleInterface::sigFloat, this, &SimpleInterfaceTraced::sigFloat);
     connect(m_impl.get(), &AbstractSimpleInterface::sigFloat32, this, &SimpleInterfaceTraced::sigFloat32);
     connect(m_impl.get(), &AbstractSimpleInterface::sigFloat64, this, &SimpleInterfaceTraced::sigFloat64);
     connect(m_impl.get(), &AbstractSimpleInterface::sigString, this, &SimpleInterfaceTraced::sigString);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSimpleInterface::sigVoid, this, &SimpleInterfaceTraced::traceSigVoid);
     connect(m_impl.get(), &AbstractSimpleInterface::sigBool, this, &SimpleInterfaceTraced::traceSigBool);
     connect(m_impl.get(), &AbstractSimpleInterface::sigInt, this, &SimpleInterfaceTraced::traceSigInt);
     connect(m_impl.get(), &AbstractSimpleInterface::sigInt32, this, &SimpleInterfaceTraced::traceSigInt32);
     connect(m_impl.get(), &AbstractSimpleInterface::sigInt64, this, &SimpleInterfaceTraced::traceSigInt64);
     connect(m_impl.get(), &AbstractSimpleInterface::sigFloat, this, &SimpleInterfaceTraced::traceSigFloat);
     connect(m_impl.get(), &AbstractSimpleInterface::sigFloat32, this, &SimpleInterfaceTraced::traceSigFloat32);
     connect(m_impl.get(), &AbstractSimpleInterface::sigFloat64, this, &SimpleInterfaceTraced::traceSigFloat64);
     connect(m_impl.get(), &AbstractSimpleInterface::sigString, this, &SimpleInterfaceTraced::traceSigString);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSimpleInterface::propBoolChanged, this, &AbstractSimpleInterface::propBoolChanged);
    connect(m_impl.get(), &AbstractSimpleInterface::propIntChanged, this, &AbstractSimpleInterface::propIntChanged);
    connect(m_impl.get(), &AbstractSimpleInterface::propInt32Changed, this, &AbstractSimpleInterface::propInt32Changed);
    connect(m_impl.get(), &AbstractSimpleInterface::propInt64Changed, this, &AbstractSimpleInterface::propInt64Changed);
    connect(m_impl.get(), &AbstractSimpleInterface::propFloatChanged, this, &AbstractSimpleInterface::propFloatChanged);
    connect(m_impl.get(), &AbstractSimpleInterface::propFloat32Changed, this, &AbstractSimpleInterface::propFloat32Changed);
    connect(m_impl.get(), &AbstractSimpleInterface::propFloat64Changed, this, &AbstractSimpleInterface::propFloat64Changed);
    connect(m_impl.get(), &AbstractSimpleInterface::propStringChanged, this, &AbstractSimpleInterface::propStringChanged);
}

void SimpleInterfaceTraced::funcVoid() 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return ;
    }
    SimpleInterfaceAgent::trace_funcVoid(this );
    m_impl->funcVoid();
}


bool SimpleInterfaceTraced::funcBool(bool paramBool) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcBool(this, paramBool);
    return m_impl->funcBool(paramBool);
}


int SimpleInterfaceTraced::funcInt(int paramInt) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcInt(this, paramInt);
    return m_impl->funcInt(paramInt);
}


qint32 SimpleInterfaceTraced::funcInt32(qint32 paramInt32) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcInt32(this, paramInt32);
    return m_impl->funcInt32(paramInt32);
}


qint64 SimpleInterfaceTraced::funcInt64(qint64 paramInt64) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcInt64(this, paramInt64);
    return m_impl->funcInt64(paramInt64);
}


qreal SimpleInterfaceTraced::funcFloat(qreal paramFloat) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcFloat(this, paramFloat);
    return m_impl->funcFloat(paramFloat);
}


float SimpleInterfaceTraced::funcFloat32(float paramFloat32) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcFloat32(this, paramFloat32);
    return m_impl->funcFloat32(paramFloat32);
}


double SimpleInterfaceTraced::funcFloat64(double paramFloat) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcFloat64(this, paramFloat);
    return m_impl->funcFloat64(paramFloat);
}


QString SimpleInterfaceTraced::funcString(const QString& paramString) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    SimpleInterfaceAgent::trace_funcString(this, paramString);
    return m_impl->funcString(paramString);
}

void SimpleInterfaceTraced::setPropBool(bool propBool)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropBool(propBool);
}
bool SimpleInterfaceTraced::propBool() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propBool();
}

void SimpleInterfaceTraced::setPropInt(int propInt)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropInt(propInt);
}
int SimpleInterfaceTraced::propInt() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propInt();
}

void SimpleInterfaceTraced::setPropInt32(qint32 propInt32)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropInt32(propInt32);
}
qint32 SimpleInterfaceTraced::propInt32() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propInt32();
}

void SimpleInterfaceTraced::setPropInt64(qint64 propInt64)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropInt64(propInt64);
}
qint64 SimpleInterfaceTraced::propInt64() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propInt64();
}

void SimpleInterfaceTraced::setPropFloat(qreal propFloat)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropFloat(propFloat);
}
qreal SimpleInterfaceTraced::propFloat() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propFloat();
}

void SimpleInterfaceTraced::setPropFloat32(float propFloat32)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropFloat32(propFloat32);
}
float SimpleInterfaceTraced::propFloat32() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propFloat32();
}

void SimpleInterfaceTraced::setPropFloat64(double propFloat64)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropFloat64(propFloat64);
}
double SimpleInterfaceTraced::propFloat64() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propFloat64();
}

void SimpleInterfaceTraced::setPropString(const QString& propString)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    SimpleInterfaceAgent::trace_state(this);
    m_impl->setPropString(propString);
}
QString SimpleInterfaceTraced::propString() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->propString();
}

void SimpleInterfaceTraced::traceSigVoid()
{
    SimpleInterfaceAgent::trace_sigVoid(this );
}
void SimpleInterfaceTraced::traceSigBool(bool paramBool)
{
    SimpleInterfaceAgent::trace_sigBool(this, paramBool);
}
void SimpleInterfaceTraced::traceSigInt(int paramInt)
{
    SimpleInterfaceAgent::trace_sigInt(this, paramInt);
}
void SimpleInterfaceTraced::traceSigInt32(qint32 paramInt32)
{
    SimpleInterfaceAgent::trace_sigInt32(this, paramInt32);
}
void SimpleInterfaceTraced::traceSigInt64(qint64 paramInt64)
{
    SimpleInterfaceAgent::trace_sigInt64(this, paramInt64);
}
void SimpleInterfaceTraced::traceSigFloat(qreal paramFloat)
{
    SimpleInterfaceAgent::trace_sigFloat(this, paramFloat);
}
void SimpleInterfaceTraced::traceSigFloat32(float paramFloa32)
{
    SimpleInterfaceAgent::trace_sigFloat32(this, paramFloa32);
}
void SimpleInterfaceTraced::traceSigFloat64(double paramFloat64)
{
    SimpleInterfaceAgent::trace_sigFloat64(this, paramFloat64);
}
void SimpleInterfaceTraced::traceSigString(const QString& paramString)
{
    SimpleInterfaceAgent::trace_sigString(this, paramString);
}

} // namespace tb_simple

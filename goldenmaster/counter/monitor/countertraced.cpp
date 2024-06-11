
#include "countertraced.h"
#include "counter/monitor/agent.h"
#include "utilities/logger.h"

namespace counter {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

CounterTraced::CounterTraced(std::shared_ptr<AbstractCounter> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.

    // Connect signals emitted by implementation with this object.

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractCounter::vectorChanged, this, &AbstractCounter::vectorChanged);
    connect(m_impl.get(), &AbstractCounter::extern_vectorChanged, this, &AbstractCounter::extern_vectorChanged);
}

QVector3D CounterTraced::increment(const QVector3D& vec) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    CounterAgent::trace_increment(this, vec);
    return m_impl->increment(vec);
}


custom_types::Vector3D CounterTraced::decrement(const custom_types::Vector3D& vec) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return  {} ;
    }
    CounterAgent::trace_decrement(this, vec);
    return m_impl->decrement(vec);
}

void CounterTraced::setVector(const custom_types::Vector3D& vector)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    CounterAgent::trace_state(this);
    m_impl->setVector(vector);
}
custom_types::Vector3D CounterTraced::vector() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->vector();
}

void CounterTraced::setExternVector(const QVector3D& extern_vector)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    CounterAgent::trace_state(this);
    m_impl->setExternVector(extern_vector);
}
QVector3D CounterTraced::extern_vector() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->extern_vector();
}


} // namespace counter

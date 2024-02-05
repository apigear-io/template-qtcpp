
#include "nam_estraced.h"
#include "tb_names/monitor/agent.h"
#include "utilities/logger.h"

namespace tb_names {

const std::string noObjectToTraceLogInfo = " object to trace is invalid.";

NamEsTraced::NamEsTraced(std::shared_ptr<AbstractNamEs> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractNamEs::someSignal, this, &NamEsTraced::someSignal);
     connect(m_impl.get(), &AbstractNamEs::someSignal2, this, &NamEsTraced::someSignal2);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractNamEs::someSignal, this, &NamEsTraced::traceSomeSignal);
     connect(m_impl.get(), &AbstractNamEs::someSignal2, this, &NamEsTraced::traceSomeSignal2);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractNamEs::SwitchChanged, this, &AbstractNamEs::SwitchChanged);
    connect(m_impl.get(), &AbstractNamEs::SOME_PROPERTYChanged, this, &AbstractNamEs::SOME_PROPERTYChanged);
    connect(m_impl.get(), &AbstractNamEs::Some_Poperty2Changed, this, &AbstractNamEs::Some_Poperty2Changed);
}

void NamEsTraced::someFunction(bool SOME_PARAM) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return ;
    }
    NamEsAgent::trace_SOME_FUNCTION(this, SOME_PARAM);
    m_impl->someFunction(SOME_PARAM);
}


void NamEsTraced::someFunction2(bool Some_Param) 
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return ;
    }
    NamEsAgent::trace_Some_Function2(this, Some_Param);
    m_impl->someFunction2(Some_Param);
}

void NamEsTraced::setSwitch(bool Switch)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NamEsAgent::trace_state(this);
    m_impl->setSwitch(Switch);
}
bool NamEsTraced::Switch() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->Switch();
}

void NamEsTraced::setSomeProperty(int SOME_PROPERTY)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NamEsAgent::trace_state(this);
    m_impl->setSomeProperty(SOME_PROPERTY);
}
int NamEsTraced::SOME_PROPERTY() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->SOME_PROPERTY();
}

void NamEsTraced::setSomePoperty2(int Some_Poperty2)
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return;
    }
    NamEsAgent::trace_state(this);
    m_impl->setSomePoperty2(Some_Poperty2);
}
int NamEsTraced::Some_Poperty2() const
{
    if (!m_impl) {
        AG_LOG_WARNING(Q_FUNC_INFO + noObjectToTraceLogInfo);
        return {};
    }
    return m_impl->Some_Poperty2();
}

void NamEsTraced::traceSomeSignal(bool SOME_PARAM)
{
    NamEsAgent::trace_SOME_SIGNAL(this, SOME_PARAM);
}
void NamEsTraced::traceSomeSignal2(bool Some_Param)
{
    NamEsAgent::trace_Some_Signal2(this, Some_Param);
}

} // namespace tb_names

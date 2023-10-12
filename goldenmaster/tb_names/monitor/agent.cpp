#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace tb_names {

NamEsAgent::NamEsAgent()
{
}

QVariantMap NamEsAgent::capture_state(AbstractNamEs* obj)
{
    return QVariantMap{
        { "Switch", QVariant::fromValue(obj->Switch()) },
        { "SOME_PROPERTY", QVariant::fromValue(obj->SOME_PROPERTY()) },
        { "Some_Poperty2", QVariant::fromValue(obj->Some_Poperty2()) },
    };
}

void NamEsAgent::trace_state(AbstractNamEs* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.names.Nam_Es", fields_);
}
void NamEsAgent::trace_SOME_FUNCTION(AbstractNamEs* obj, bool SOME_PARAM)
{
    const QVariantMap &params_ {
        { "SOME_PARAM", QVariant::fromValue(SOME_PARAM) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.names.NamEs#SOME_FUNCTION", params_);
}
void NamEsAgent::trace_Some_Function2(AbstractNamEs* obj, bool Some_Param)
{
    const QVariantMap &params_ {
        { "Some_Param", QVariant::fromValue(Some_Param) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.names.NamEs#Some_Function2", params_);
}
void NamEsAgent::trace_SOME_SIGNAL(AbstractNamEs* obj, bool SOME_PARAM)
{
    const QVariantMap &params_ {
        { "SOME_PARAM", QVariant::fromValue(SOME_PARAM) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.names.NamEs#SOME_SIGNAL", params_);
}
void NamEsAgent::trace_Some_Signal2(AbstractNamEs* obj, bool Some_Param)
{
    const QVariantMap &params_ {
        { "Some_Param", QVariant::fromValue(Some_Param) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.names.NamEs#Some_Signal2", params_);
}

} // namespace tb_names
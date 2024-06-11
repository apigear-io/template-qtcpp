#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace counter {

CounterAgent::CounterAgent()
{
}

QVariantMap CounterAgent::capture_state(AbstractCounter* obj)
{
    return QVariantMap{
        { "vector", QVariant::fromValue(obj->vector()) },
        { "extern_vector", QVariant::fromValue(obj->extern_vector()) },
    };
}

void CounterAgent::trace_state(AbstractCounter* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("counter.Counter", fields_);
}
void CounterAgent::trace_increment(AbstractCounter* obj, const QVector3D& vec)
{
    const QVariantMap &params_ {
        { "vec", QVariant::fromValue(vec) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("counter.Counter#increment", params_);
}
void CounterAgent::trace_decrement(AbstractCounter* obj, const custom_types::Vector3D& vec)
{
    const QVariantMap &params_ {
        { "vec", QVariant::fromValue(vec) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("counter.Counter#decrement", params_);
}

} // namespace counter
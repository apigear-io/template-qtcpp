#include "agent.h"
#include "../../shared/agentclient.h"

Interface1Agent::Interface1Agent()
{
}

QVariantMap Interface1Agent::capture_state(AbstractInterface1* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
        { "prop3", QVariant::fromValue(obj->prop3()) },
        { "prop4", QVariant::fromValue(obj->prop4()) },
        { "prop5", QVariant::fromValue(obj->prop5()) },
        { "prop6", QVariant::fromValue(obj->prop6()) },
        { "prop7", QVariant::fromValue(obj->prop7()) },
        { "prop10", QVariant::fromValue(obj->prop10()) },
        { "prop11", QVariant::fromValue(obj->prop11()) },
        { "prop12", QVariant::fromValue(obj->prop12()) },
        { "prop14", QVariant::fromValue(obj->prop14()) },
    };
}

void Interface1Agent::trace_state(AbstractInterface1* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    AgentClient::instance()->traceState("org.objectapi.testbed.Interface1", fields_);
}
void Interface1Agent::trace_op1(AbstractInterface1* obj)
{
    const QVariantMap &params_ {
    };
    AgentClient::instance()->traceCall("org.objectapi.testbed.Interface1#op1", params_);
}
void Interface1Agent::trace_op2(AbstractInterface1* obj, int step)
{
    const QVariantMap &params_ {
        { "step", QVariant::fromValue(step) },
    };
    AgentClient::instance()->traceCall("org.objectapi.testbed.Interface1#op2", params_);
}
void Interface1Agent::trace_op3(AbstractInterface1* obj)
{
    const QVariantMap &params_ {
    };
    AgentClient::instance()->traceCall("org.objectapi.testbed.Interface1#op3", params_);
}

Interface2Agent::Interface2Agent()
{
}

QVariantMap Interface2Agent::capture_state(AbstractInterface2* obj)
{
    return QVariantMap{
        { "prop200", QVariant::fromValue(obj->prop200()) },
        { "prop201", QVariant::fromValue(obj->prop201()) },
        { "prop202", QVariant::fromValue(obj->prop202()) },
        { "prop203", QVariant::fromValue(obj->prop203()) },
        { "prop204", QVariant::fromValue(obj->prop204()) },
        { "prop205", QVariant::fromValue(obj->prop205()) },
    };
}

void Interface2Agent::trace_state(AbstractInterface2* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    AgentClient::instance()->traceState("org.objectapi.testbed.Interface2", fields_);
}
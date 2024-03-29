#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace tb_enum {

EnumInterfaceAgent::EnumInterfaceAgent()
{
}

QVariantMap EnumInterfaceAgent::capture_state(AbstractEnumInterface* obj)
{
    return QVariantMap{
        { "prop0", QVariant::fromValue(obj->prop0()) },
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
        { "prop3", QVariant::fromValue(obj->prop3()) },
    };
}

void EnumInterfaceAgent::trace_state(AbstractEnumInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.enum.EnumInterface", fields_);
}
void EnumInterfaceAgent::trace_func0(AbstractEnumInterface* obj, Enum0::Enum0Enum param0)
{
    const QVariantMap &params_ {
        { "param0", QVariant::fromValue(param0) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.enum.EnumInterface#func0", params_);
}
void EnumInterfaceAgent::trace_func1(AbstractEnumInterface* obj, Enum1::Enum1Enum param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.enum.EnumInterface#func1", params_);
}
void EnumInterfaceAgent::trace_func2(AbstractEnumInterface* obj, Enum2::Enum2Enum param2)
{
    const QVariantMap &params_ {
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.enum.EnumInterface#func2", params_);
}
void EnumInterfaceAgent::trace_func3(AbstractEnumInterface* obj, Enum3::Enum3Enum param3)
{
    const QVariantMap &params_ {
        { "param3", QVariant::fromValue(param3) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.enum.EnumInterface#func3", params_);
}
void EnumInterfaceAgent::trace_sig0(AbstractEnumInterface* obj, Enum0::Enum0Enum param0)
{
    const QVariantMap &params_ {
        { "param0", QVariant::fromValue(param0) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.enum.EnumInterface#sig0", params_);
}
void EnumInterfaceAgent::trace_sig1(AbstractEnumInterface* obj, Enum1::Enum1Enum param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.enum.EnumInterface#sig1", params_);
}
void EnumInterfaceAgent::trace_sig2(AbstractEnumInterface* obj, Enum2::Enum2Enum param2)
{
    const QVariantMap &params_ {
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.enum.EnumInterface#sig2", params_);
}
void EnumInterfaceAgent::trace_sig3(AbstractEnumInterface* obj, Enum3::Enum3Enum param3)
{
    const QVariantMap &params_ {
        { "param3", QVariant::fromValue(param3) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.enum.EnumInterface#sig3", params_);
}

} // namespace tb_enum
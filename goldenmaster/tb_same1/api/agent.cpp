#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace tb_same1 {

SameStruct1InterfaceAgent::SameStruct1InterfaceAgent()
{
}

QVariantMap SameStruct1InterfaceAgent::capture_state(AbstractSameStruct1Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
    };
}

void SameStruct1InterfaceAgent::trace_state(AbstractSameStruct1Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.same1.SameStruct1Interface", fields_);
}
void SameStruct1InterfaceAgent::trace_func1(AbstractSameStruct1Interface* obj, const Struct1& param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.same1.SameStruct1Interface#func1", params_);
}

SameStruct2InterfaceAgent::SameStruct2InterfaceAgent()
{
}

QVariantMap SameStruct2InterfaceAgent::capture_state(AbstractSameStruct2Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
    };
}

void SameStruct2InterfaceAgent::trace_state(AbstractSameStruct2Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.same1.SameStruct2Interface", fields_);
}
void SameStruct2InterfaceAgent::trace_func1(AbstractSameStruct2Interface* obj, const Struct1& param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.same1.SameStruct2Interface#func1", params_);
}
void SameStruct2InterfaceAgent::trace_func2(AbstractSameStruct2Interface* obj, const Struct1& param1, const Struct2& param2)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.same1.SameStruct2Interface#func2", params_);
}

SameEnum1InterfaceAgent::SameEnum1InterfaceAgent()
{
}

QVariantMap SameEnum1InterfaceAgent::capture_state(AbstractSameEnum1Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
    };
}

void SameEnum1InterfaceAgent::trace_state(AbstractSameEnum1Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.same1.SameEnum1Interface", fields_);
}
void SameEnum1InterfaceAgent::trace_func1(AbstractSameEnum1Interface* obj, Enum1::Enum1Enum param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.same1.SameEnum1Interface#func1", params_);
}

SameEnum2InterfaceAgent::SameEnum2InterfaceAgent()
{
}

QVariantMap SameEnum2InterfaceAgent::capture_state(AbstractSameEnum2Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
    };
}

void SameEnum2InterfaceAgent::trace_state(AbstractSameEnum2Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.same1.SameEnum2Interface", fields_);
}
void SameEnum2InterfaceAgent::trace_func1(AbstractSameEnum2Interface* obj, Enum1::Enum1Enum param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.same1.SameEnum2Interface#func1", params_);
}
void SameEnum2InterfaceAgent::trace_func2(AbstractSameEnum2Interface* obj, Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.same1.SameEnum2Interface#func2", params_);
}

} // namespace tb_same1
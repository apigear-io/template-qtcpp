#include "agent.h"
#include "apigear/monitor/agentclient.h"

ManyParamInterfaceAgent::ManyParamInterfaceAgent()
{
}

QVariantMap ManyParamInterfaceAgent::capture_state(AbstractManyParamInterface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
        { "prop3", QVariant::fromValue(obj->prop3()) },
        { "prop4", QVariant::fromValue(obj->prop4()) },
    };
}

void ManyParamInterfaceAgent::trace_state(AbstractManyParamInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("testbed2.ManyParamInterface", fields_);
}
void ManyParamInterfaceAgent::trace_func1(AbstractManyParamInterface* obj, int param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.ManyParamInterface#func1", params_);
}
void ManyParamInterfaceAgent::trace_func2(AbstractManyParamInterface* obj, int param1, int param2)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.ManyParamInterface#func2", params_);
}
void ManyParamInterfaceAgent::trace_func3(AbstractManyParamInterface* obj, int param1, int param2, int param3)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
        { "param3", QVariant::fromValue(param3) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.ManyParamInterface#func3", params_);
}
void ManyParamInterfaceAgent::trace_func4(AbstractManyParamInterface* obj, int param1, int param2, int param3, int param4)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
        { "param3", QVariant::fromValue(param3) },
        { "param4", QVariant::fromValue(param4) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.ManyParamInterface#func4", params_);
}

NestedStruct1InterfaceAgent::NestedStruct1InterfaceAgent()
{
}

QVariantMap NestedStruct1InterfaceAgent::capture_state(AbstractNestedStruct1Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
    };
}

void NestedStruct1InterfaceAgent::trace_state(AbstractNestedStruct1Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("testbed2.NestedStruct1Interface", fields_);
}
void NestedStruct1InterfaceAgent::trace_func1(AbstractNestedStruct1Interface* obj, const NestedStruct1& param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.NestedStruct1Interface#func1", params_);
}

NestedStruct2InterfaceAgent::NestedStruct2InterfaceAgent()
{
}

QVariantMap NestedStruct2InterfaceAgent::capture_state(AbstractNestedStruct2Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
    };
}

void NestedStruct2InterfaceAgent::trace_state(AbstractNestedStruct2Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("testbed2.NestedStruct2Interface", fields_);
}
void NestedStruct2InterfaceAgent::trace_func1(AbstractNestedStruct2Interface* obj, const NestedStruct1& param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.NestedStruct2Interface#func1", params_);
}
void NestedStruct2InterfaceAgent::trace_func2(AbstractNestedStruct2Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.NestedStruct2Interface#func2", params_);
}

NestedStruct3InterfaceAgent::NestedStruct3InterfaceAgent()
{
}

QVariantMap NestedStruct3InterfaceAgent::capture_state(AbstractNestedStruct3Interface* obj)
{
    return QVariantMap{
        { "prop1", QVariant::fromValue(obj->prop1()) },
        { "prop2", QVariant::fromValue(obj->prop2()) },
        { "prop3", QVariant::fromValue(obj->prop3()) },
    };
}

void NestedStruct3InterfaceAgent::trace_state(AbstractNestedStruct3Interface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("testbed2.NestedStruct3Interface", fields_);
}
void NestedStruct3InterfaceAgent::trace_func1(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.NestedStruct3Interface#func1", params_);
}
void NestedStruct3InterfaceAgent::trace_func2(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.NestedStruct3Interface#func2", params_);
}
void NestedStruct3InterfaceAgent::trace_func3(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    const QVariantMap &params_ {
        { "param1", QVariant::fromValue(param1) },
        { "param2", QVariant::fromValue(param2) },
        { "param3", QVariant::fromValue(param3) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed2.NestedStruct3Interface#func3", params_);
}
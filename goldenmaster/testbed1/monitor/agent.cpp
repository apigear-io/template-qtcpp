#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace testbed1 {

StructInterfaceAgent::StructInterfaceAgent()
{
}

QVariantMap StructInterfaceAgent::capture_state(AbstractStructInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
        { "propFloat", QVariant::fromValue(obj->propFloat()) },
        { "propString", QVariant::fromValue(obj->propString()) },
    };
}

void StructInterfaceAgent::trace_state(AbstractStructInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("testbed1.StructInterface", fields_);
}
void StructInterfaceAgent::trace_funcBool(AbstractStructInterface* obj, const StructBool& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructInterface#funcBool", params_);
}
void StructInterfaceAgent::trace_funcInt(AbstractStructInterface* obj, const StructInt& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructInterface#funcInt", params_);
}
void StructInterfaceAgent::trace_funcFloat(AbstractStructInterface* obj, const StructFloat& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructInterface#funcFloat", params_);
}
void StructInterfaceAgent::trace_funcString(AbstractStructInterface* obj, const StructString& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructInterface#funcString", params_);
}
void StructInterfaceAgent::trace_sigBool(AbstractStructInterface* obj, const StructBool& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructInterface#sigBool", params_);
}
void StructInterfaceAgent::trace_sigInt(AbstractStructInterface* obj, const StructInt& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructInterface#sigInt", params_);
}
void StructInterfaceAgent::trace_sigFloat(AbstractStructInterface* obj, const StructFloat& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructInterface#sigFloat", params_);
}
void StructInterfaceAgent::trace_sigString(AbstractStructInterface* obj, const StructString& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructInterface#sigString", params_);
}

StructArrayInterfaceAgent::StructArrayInterfaceAgent()
{
}

QVariantMap StructArrayInterfaceAgent::capture_state(AbstractStructArrayInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
        { "propFloat", QVariant::fromValue(obj->propFloat()) },
        { "propString", QVariant::fromValue(obj->propString()) },
    };
}

void StructArrayInterfaceAgent::trace_state(AbstractStructArrayInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("testbed1.StructArrayInterface", fields_);
}
void StructArrayInterfaceAgent::trace_funcBool(AbstractStructArrayInterface* obj, const QList<StructBool>& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructArrayInterface#funcBool", params_);
}
void StructArrayInterfaceAgent::trace_funcInt(AbstractStructArrayInterface* obj, const QList<StructInt>& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructArrayInterface#funcInt", params_);
}
void StructArrayInterfaceAgent::trace_funcFloat(AbstractStructArrayInterface* obj, const QList<StructFloat>& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructArrayInterface#funcFloat", params_);
}
void StructArrayInterfaceAgent::trace_funcString(AbstractStructArrayInterface* obj, const QList<StructString>& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("testbed1.StructArrayInterface#funcString", params_);
}
void StructArrayInterfaceAgent::trace_sigBool(AbstractStructArrayInterface* obj, const QList<StructBool>& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructArrayInterface#sigBool", params_);
}
void StructArrayInterfaceAgent::trace_sigInt(AbstractStructArrayInterface* obj, const QList<StructInt>& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructArrayInterface#sigInt", params_);
}
void StructArrayInterfaceAgent::trace_sigFloat(AbstractStructArrayInterface* obj, const QList<StructFloat>& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructArrayInterface#sigFloat", params_);
}
void StructArrayInterfaceAgent::trace_sigString(AbstractStructArrayInterface* obj, const QList<StructString>& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("testbed1.StructArrayInterface#sigString", params_);
}

} // namespace testbed1
#include "agent.h"
#include "../../shared/agentclient.h"

SimpleInterfaceAgent::SimpleInterfaceAgent()
{
}

QVariantMap SimpleInterfaceAgent::capture_state(AbstractSimpleInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
        { "propFloat", QVariant::fromValue(obj->propFloat()) },
        { "propString", QVariant::fromValue(obj->propString()) },
    };
}

void SimpleInterfaceAgent::trace_state(AbstractSimpleInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    AgentClient::instance()->traceState("tb.simple.SimpleInterface", fields_);
}
void SimpleInterfaceAgent::trace_funcBool(AbstractSimpleInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcBool", params_);
}
void SimpleInterfaceAgent::trace_funcInt(AbstractSimpleInterface* obj, int paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcInt", params_);
}
void SimpleInterfaceAgent::trace_funcFloat(AbstractSimpleInterface* obj, double paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcFloat", params_);
}
void SimpleInterfaceAgent::trace_funcString(AbstractSimpleInterface* obj, const QString& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcString", params_);
}

SimpleArrayInterfaceAgent::SimpleArrayInterfaceAgent()
{
}

QVariantMap SimpleArrayInterfaceAgent::capture_state(AbstractSimpleArrayInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
        { "propFloat", QVariant::fromValue(obj->propFloat()) },
        { "propString", QVariant::fromValue(obj->propString()) },
    };
}

void SimpleArrayInterfaceAgent::trace_state(AbstractSimpleArrayInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    AgentClient::instance()->traceState("tb.simple.SimpleArrayInterface", fields_);
}
void SimpleArrayInterfaceAgent::trace_funcBool(AbstractSimpleArrayInterface* obj, const QList<bool>& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcBool", params_);
}
void SimpleArrayInterfaceAgent::trace_funcInt(AbstractSimpleArrayInterface* obj, const QList<int>& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcInt", params_);
}
void SimpleArrayInterfaceAgent::trace_funcFloat(AbstractSimpleArrayInterface* obj, const QList<double>& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcFloat", params_);
}
void SimpleArrayInterfaceAgent::trace_funcString(AbstractSimpleArrayInterface* obj, const QList<QString>& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcString", params_);
}
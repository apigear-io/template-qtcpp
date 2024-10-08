#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace tb_simple {

VoidInterfaceAgent::VoidInterfaceAgent()
{
}

QVariantMap VoidInterfaceAgent::capture_state(AbstractVoidInterface* obj)
{
    return QVariantMap{
    };
}

void VoidInterfaceAgent::trace_state(AbstractVoidInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.simple.VoidInterface", fields_);
}
void VoidInterfaceAgent::trace_funcVoid(AbstractVoidInterface* obj )
{
    const QVariantMap &params_ {
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.VoidInterface#funcVoid", params_);
}
void VoidInterfaceAgent::trace_sigVoid(AbstractVoidInterface* obj )
{
    const QVariantMap &params_ {
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.VoidInterface#sigVoid", params_);
}

SimpleInterfaceAgent::SimpleInterfaceAgent()
{
}

QVariantMap SimpleInterfaceAgent::capture_state(AbstractSimpleInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
        { "propInt32", QVariant::fromValue(obj->propInt32()) },
        { "propInt64", QVariant::fromValue(obj->propInt64()) },
        { "propFloat", QVariant::fromValue(obj->propFloat()) },
        { "propFloat32", QVariant::fromValue(obj->propFloat32()) },
        { "propFloat64", QVariant::fromValue(obj->propFloat64()) },
        { "propString", QVariant::fromValue(obj->propString()) },
    };
}

void SimpleInterfaceAgent::trace_state(AbstractSimpleInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.simple.SimpleInterface", fields_);
}
void SimpleInterfaceAgent::trace_funcNoReturnValue(AbstractSimpleInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcNoReturnValue", params_);
}
void SimpleInterfaceAgent::trace_funcBool(AbstractSimpleInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcBool", params_);
}
void SimpleInterfaceAgent::trace_funcInt(AbstractSimpleInterface* obj, int paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcInt", params_);
}
void SimpleInterfaceAgent::trace_funcInt32(AbstractSimpleInterface* obj, qint32 paramInt32)
{
    const QVariantMap &params_ {
        { "paramInt32", QVariant::fromValue(paramInt32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcInt32", params_);
}
void SimpleInterfaceAgent::trace_funcInt64(AbstractSimpleInterface* obj, qint64 paramInt64)
{
    const QVariantMap &params_ {
        { "paramInt64", QVariant::fromValue(paramInt64) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcInt64", params_);
}
void SimpleInterfaceAgent::trace_funcFloat(AbstractSimpleInterface* obj, qreal paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcFloat", params_);
}
void SimpleInterfaceAgent::trace_funcFloat32(AbstractSimpleInterface* obj, float paramFloat32)
{
    const QVariantMap &params_ {
        { "paramFloat32", QVariant::fromValue(paramFloat32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcFloat32", params_);
}
void SimpleInterfaceAgent::trace_funcFloat64(AbstractSimpleInterface* obj, double paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcFloat64", params_);
}
void SimpleInterfaceAgent::trace_funcString(AbstractSimpleInterface* obj, const QString& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleInterface#funcString", params_);
}
void SimpleInterfaceAgent::trace_sigBool(AbstractSimpleInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigBool", params_);
}
void SimpleInterfaceAgent::trace_sigInt(AbstractSimpleInterface* obj, int paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigInt", params_);
}
void SimpleInterfaceAgent::trace_sigInt32(AbstractSimpleInterface* obj, qint32 paramInt32)
{
    const QVariantMap &params_ {
        { "paramInt32", QVariant::fromValue(paramInt32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigInt32", params_);
}
void SimpleInterfaceAgent::trace_sigInt64(AbstractSimpleInterface* obj, qint64 paramInt64)
{
    const QVariantMap &params_ {
        { "paramInt64", QVariant::fromValue(paramInt64) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigInt64", params_);
}
void SimpleInterfaceAgent::trace_sigFloat(AbstractSimpleInterface* obj, qreal paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigFloat", params_);
}
void SimpleInterfaceAgent::trace_sigFloat32(AbstractSimpleInterface* obj, float paramFloat32)
{
    const QVariantMap &params_ {
        { "paramFloat32", QVariant::fromValue(paramFloat32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigFloat32", params_);
}
void SimpleInterfaceAgent::trace_sigFloat64(AbstractSimpleInterface* obj, double paramFloat64)
{
    const QVariantMap &params_ {
        { "paramFloat64", QVariant::fromValue(paramFloat64) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigFloat64", params_);
}
void SimpleInterfaceAgent::trace_sigString(AbstractSimpleInterface* obj, const QString& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleInterface#sigString", params_);
}

SimpleArrayInterfaceAgent::SimpleArrayInterfaceAgent()
{
}

QVariantMap SimpleArrayInterfaceAgent::capture_state(AbstractSimpleArrayInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
        { "propInt32", QVariant::fromValue(obj->propInt32()) },
        { "propInt64", QVariant::fromValue(obj->propInt64()) },
        { "propFloat", QVariant::fromValue(obj->propFloat()) },
        { "propFloat32", QVariant::fromValue(obj->propFloat32()) },
        { "propFloat64", QVariant::fromValue(obj->propFloat64()) },
        { "propString", QVariant::fromValue(obj->propString()) },
        { "propReadOnlyString", QVariant::fromValue(obj->propReadOnlyString()) },
    };
}

void SimpleArrayInterfaceAgent::trace_state(AbstractSimpleArrayInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.simple.SimpleArrayInterface", fields_);
}
void SimpleArrayInterfaceAgent::trace_funcBool(AbstractSimpleArrayInterface* obj, const QList<bool>& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcBool", params_);
}
void SimpleArrayInterfaceAgent::trace_funcInt(AbstractSimpleArrayInterface* obj, const QList<int>& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcInt", params_);
}
void SimpleArrayInterfaceAgent::trace_funcInt32(AbstractSimpleArrayInterface* obj, const QList<qint32>& paramInt32)
{
    const QVariantMap &params_ {
        { "paramInt32", QVariant::fromValue(paramInt32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcInt32", params_);
}
void SimpleArrayInterfaceAgent::trace_funcInt64(AbstractSimpleArrayInterface* obj, const QList<qint64>& paramInt64)
{
    const QVariantMap &params_ {
        { "paramInt64", QVariant::fromValue(paramInt64) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcInt64", params_);
}
void SimpleArrayInterfaceAgent::trace_funcFloat(AbstractSimpleArrayInterface* obj, const QList<qreal>& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcFloat", params_);
}
void SimpleArrayInterfaceAgent::trace_funcFloat32(AbstractSimpleArrayInterface* obj, const QList<float>& paramFloat32)
{
    const QVariantMap &params_ {
        { "paramFloat32", QVariant::fromValue(paramFloat32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcFloat32", params_);
}
void SimpleArrayInterfaceAgent::trace_funcFloat64(AbstractSimpleArrayInterface* obj, const QList<double>& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcFloat64", params_);
}
void SimpleArrayInterfaceAgent::trace_funcString(AbstractSimpleArrayInterface* obj, const QList<QString>& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.SimpleArrayInterface#funcString", params_);
}
void SimpleArrayInterfaceAgent::trace_sigBool(AbstractSimpleArrayInterface* obj, const QList<bool>& paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigBool", params_);
}
void SimpleArrayInterfaceAgent::trace_sigInt(AbstractSimpleArrayInterface* obj, const QList<int>& paramInt)
{
    const QVariantMap &params_ {
        { "paramInt", QVariant::fromValue(paramInt) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigInt", params_);
}
void SimpleArrayInterfaceAgent::trace_sigInt32(AbstractSimpleArrayInterface* obj, const QList<qint32>& paramInt32)
{
    const QVariantMap &params_ {
        { "paramInt32", QVariant::fromValue(paramInt32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigInt32", params_);
}
void SimpleArrayInterfaceAgent::trace_sigInt64(AbstractSimpleArrayInterface* obj, const QList<qint64>& paramInt64)
{
    const QVariantMap &params_ {
        { "paramInt64", QVariant::fromValue(paramInt64) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigInt64", params_);
}
void SimpleArrayInterfaceAgent::trace_sigFloat(AbstractSimpleArrayInterface* obj, const QList<qreal>& paramFloat)
{
    const QVariantMap &params_ {
        { "paramFloat", QVariant::fromValue(paramFloat) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigFloat", params_);
}
void SimpleArrayInterfaceAgent::trace_sigFloat32(AbstractSimpleArrayInterface* obj, const QList<float>& paramFloa32)
{
    const QVariantMap &params_ {
        { "paramFloa32", QVariant::fromValue(paramFloa32) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigFloat32", params_);
}
void SimpleArrayInterfaceAgent::trace_sigFloat64(AbstractSimpleArrayInterface* obj, const QList<double>& paramFloat64)
{
    const QVariantMap &params_ {
        { "paramFloat64", QVariant::fromValue(paramFloat64) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigFloat64", params_);
}
void SimpleArrayInterfaceAgent::trace_sigString(AbstractSimpleArrayInterface* obj, const QList<QString>& paramString)
{
    const QVariantMap &params_ {
        { "paramString", QVariant::fromValue(paramString) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.SimpleArrayInterface#sigString", params_);
}

NoPropertiesInterfaceAgent::NoPropertiesInterfaceAgent()
{
}

QVariantMap NoPropertiesInterfaceAgent::capture_state(AbstractNoPropertiesInterface* obj)
{
    return QVariantMap{
    };
}

void NoPropertiesInterfaceAgent::trace_state(AbstractNoPropertiesInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.simple.NoPropertiesInterface", fields_);
}
void NoPropertiesInterfaceAgent::trace_funcVoid(AbstractNoPropertiesInterface* obj )
{
    const QVariantMap &params_ {
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.NoPropertiesInterface#funcVoid", params_);
}
void NoPropertiesInterfaceAgent::trace_funcBool(AbstractNoPropertiesInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.NoPropertiesInterface#funcBool", params_);
}
void NoPropertiesInterfaceAgent::trace_sigVoid(AbstractNoPropertiesInterface* obj )
{
    const QVariantMap &params_ {
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.NoPropertiesInterface#sigVoid", params_);
}
void NoPropertiesInterfaceAgent::trace_sigBool(AbstractNoPropertiesInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.NoPropertiesInterface#sigBool", params_);
}

NoOperationsInterfaceAgent::NoOperationsInterfaceAgent()
{
}

QVariantMap NoOperationsInterfaceAgent::capture_state(AbstractNoOperationsInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
    };
}

void NoOperationsInterfaceAgent::trace_state(AbstractNoOperationsInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.simple.NoOperationsInterface", fields_);
}
void NoOperationsInterfaceAgent::trace_sigVoid(AbstractNoOperationsInterface* obj )
{
    const QVariantMap &params_ {
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.NoOperationsInterface#sigVoid", params_);
}
void NoOperationsInterfaceAgent::trace_sigBool(AbstractNoOperationsInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("tb.simple.NoOperationsInterface#sigBool", params_);
}

NoSignalsInterfaceAgent::NoSignalsInterfaceAgent()
{
}

QVariantMap NoSignalsInterfaceAgent::capture_state(AbstractNoSignalsInterface* obj)
{
    return QVariantMap{
        { "propBool", QVariant::fromValue(obj->propBool()) },
        { "propInt", QVariant::fromValue(obj->propInt()) },
    };
}

void NoSignalsInterfaceAgent::trace_state(AbstractNoSignalsInterface* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("tb.simple.NoSignalsInterface", fields_);
}
void NoSignalsInterfaceAgent::trace_funcVoid(AbstractNoSignalsInterface* obj )
{
    const QVariantMap &params_ {
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.NoSignalsInterface#funcVoid", params_);
}
void NoSignalsInterfaceAgent::trace_funcBool(AbstractNoSignalsInterface* obj, bool paramBool)
{
    const QVariantMap &params_ {
        { "paramBool", QVariant::fromValue(paramBool) },
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("tb.simple.NoSignalsInterface#funcBool", params_);
}

} // namespace tb_simple
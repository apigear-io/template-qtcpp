#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "apigear/simulation/simulationclient.h"

using namespace ApiGear::JSONRPC;
// ********************************************************************
// SimulationStructInterface simulation interface
// ********************************************************************

SimulationStructInterface::SimulationStructInterface(QObject *parent)
    : AbstractStructInterface(parent)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationStructInterface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("propBool")) {
        setPropBool(arg.params["propBool"]);
      }
      if(arg.params.contains("propInt")) {
        setPropInt(arg.params["propInt"]);
      }
      if(arg.params.contains("propFloat")) {
        setPropFloat(arg.params["propFloat"]);
      }
      if(arg.params.contains("propString")) {
        setPropString(arg.params["propString"]);
      }
    };
    ApiGear::SimulationClient::instance()->onNotifyState("testbed1/StructInterface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationStructInterface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("propBool")) {
        setPropBool(arg.result["propBool"]);
      }
      if(arg.result.contains("propInt")) {
        setPropInt(arg.result["propInt"]);
      }
      if(arg.result.contains("propFloat")) {
        setPropFloat(arg.result["propFloat"]);
      }
      if(arg.result.contains("propString")) {
        setPropString(arg.result["propString"]);
      }
    };
    ApiGear::SimulationClient::instance()->doFetchState("testbed1/StructInterface", fetchStateFunc);

    NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg) { 
        emit sigBool(arg.params["paramBool"].get<StructBool>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructInterface#sigBool", sigBoolFunc);

    NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg) { 
        emit sigInt(arg.params["paramInt"].get<StructInt>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructInterface#sigInt", sigIntFunc);

    NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg) { 
        emit sigFloat(arg.params["paramFloat"].get<StructFloat>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructInterface#sigFloat", sigFloatFunc);

    NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg) { 
        emit sigString(arg.params["paramString"].get<StructString>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructInterface#sigString", sigStringFunc);
}

SimulationStructInterface::~SimulationStructInterface()
{
}

void SimulationStructInterface::setPropBool(const StructBool& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

StructBool SimulationStructInterface::propBool() const
{
    return m_propBool;
}

void SimulationStructInterface::setPropInt(const StructInt& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

StructInt SimulationStructInterface::propInt() const
{
    return m_propInt;
}

void SimulationStructInterface::setPropFloat(const StructFloat& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

StructFloat SimulationStructInterface::propFloat() const
{
    return m_propFloat;
}

void SimulationStructInterface::setPropString(const StructString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

StructString SimulationStructInterface::propString() const
{
    return m_propString;
}

StructBool SimulationStructInterface::funcBool(const StructBool& paramBool)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramBool"] = paramBool;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructInterface", "funcBool", params);
    return StructBool();
}

StructBool SimulationStructInterface::funcInt(const StructInt& paramInt)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt"] = paramInt;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructInterface", "funcInt", params);
    return StructBool();
}

StructFloat SimulationStructInterface::funcFloat(const StructFloat& paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructInterface", "funcFloat", params);
    return StructFloat();
}

StructString SimulationStructInterface::funcString(const StructString& paramString)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramString"] = paramString;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructInterface", "funcString", params);
    return StructString();
}
// ********************************************************************
// SimulationStructArrayInterface simulation interface
// ********************************************************************

SimulationStructArrayInterface::SimulationStructArrayInterface(QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationStructArrayInterface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("propBool")) {
        setPropBool(arg.params["propBool"]);
      }
      if(arg.params.contains("propInt")) {
        setPropInt(arg.params["propInt"]);
      }
      if(arg.params.contains("propFloat")) {
        setPropFloat(arg.params["propFloat"]);
      }
      if(arg.params.contains("propString")) {
        setPropString(arg.params["propString"]);
      }
    };
    ApiGear::SimulationClient::instance()->onNotifyState("testbed1/StructArrayInterface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationStructArrayInterface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("propBool")) {
        setPropBool(arg.result["propBool"]);
      }
      if(arg.result.contains("propInt")) {
        setPropInt(arg.result["propInt"]);
      }
      if(arg.result.contains("propFloat")) {
        setPropFloat(arg.result["propFloat"]);
      }
      if(arg.result.contains("propString")) {
        setPropString(arg.result["propString"]);
      }
    };
    ApiGear::SimulationClient::instance()->doFetchState("testbed1/StructArrayInterface", fetchStateFunc);

    NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg) { 
        emit sigBool(arg.params["paramBool"].get<QList<StructBool>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructArrayInterface#sigBool", sigBoolFunc);

    NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg) { 
        emit sigInt(arg.params["paramInt"].get<QList<StructInt>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructArrayInterface#sigInt", sigIntFunc);

    NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg) { 
        emit sigFloat(arg.params["paramFloat"].get<QList<StructFloat>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructArrayInterface#sigFloat", sigFloatFunc);

    NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg) { 
        emit sigString(arg.params["paramString"].get<QList<StructString>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("testbed1/StructArrayInterface#sigString", sigStringFunc);
}

SimulationStructArrayInterface::~SimulationStructArrayInterface()
{
}

void SimulationStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

QList<StructBool> SimulationStructArrayInterface::propBool() const
{
    return m_propBool;
}

void SimulationStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

QList<StructInt> SimulationStructArrayInterface::propInt() const
{
    return m_propInt;
}

void SimulationStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<StructFloat> SimulationStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void SimulationStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<StructString> SimulationStructArrayInterface::propString() const
{
    return m_propString;
}

StructBool SimulationStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramBool"] = paramBool;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructArrayInterface", "funcBool", params);
    return StructBool();
}

StructBool SimulationStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt"] = paramInt;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructArrayInterface", "funcInt", params);
    return StructBool();
}

StructBool SimulationStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructArrayInterface", "funcFloat", params);
    return StructBool();
}

StructBool SimulationStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramString"] = paramString;
    ApiGear::SimulationClient::instance()->doCall("testbed1/StructArrayInterface", "funcString", params);
    return StructBool();
}

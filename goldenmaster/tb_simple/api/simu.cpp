#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "apigear/simulation/simulationclient.h"

using namespace ApiGear::JSONRPC;

namespace tb_simple {
// ********************************************************************
// SimulationSimpleInterface simulation interface
// ********************************************************************

SimulationSimpleInterface::SimulationSimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propFloat(0.0)
    , m_propString(QString())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationSimpleInterface service state changes: " << QString::fromStdString(arg.params.dump());
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
    ApiGear::SimulationClient::instance()->onNotifyState("tb.simple/SimpleInterface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationSimpleInterface service fetch state: " << QString::fromStdString(arg.result.dump());
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
    ApiGear::SimulationClient::instance()->doFetchState("tb.simple/SimpleInterface", fetchStateFunc);

    NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg) { 
        emit sigBool(arg.params["paramBool"].get<bool>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigBool", sigBoolFunc);

    NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg) { 
        emit sigInt(arg.params["paramInt"].get<int>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigInt", sigIntFunc);

    NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg) { 
        emit sigFloat(arg.params["paramFloat"].get<qreal>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigFloat", sigFloatFunc);

    NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg) { 
        emit sigString(arg.params["paramString"].get<QString>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigString", sigStringFunc);
}

SimulationSimpleInterface::~SimulationSimpleInterface()
{
}

void SimulationSimpleInterface::setPropBool(bool propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

bool SimulationSimpleInterface::propBool() const
{
    return m_propBool;
}

void SimulationSimpleInterface::setPropInt(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int SimulationSimpleInterface::propInt() const
{
    return m_propInt;
}

void SimulationSimpleInterface::setPropFloat(qreal propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

qreal SimulationSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void SimulationSimpleInterface::setPropString(const QString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QString SimulationSimpleInterface::propString() const
{
    return m_propString;
}

bool SimulationSimpleInterface::funcBool(bool paramBool)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramBool"] = paramBool;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcBool", params);
    return false;
}

int SimulationSimpleInterface::funcInt(int paramInt)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt"] = paramInt;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcInt", params);
    return 0;
}

qreal SimulationSimpleInterface::funcFloat(qreal paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcFloat", params);
    return 0.0;
}

QString SimulationSimpleInterface::funcString(const QString& paramString)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramString"] = paramString;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcString", params);
    return QString();
}
// ********************************************************************
// SimulationSimpleArrayInterface simulation interface
// ********************************************************************

SimulationSimpleArrayInterface::SimulationSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propFloat(QList<qreal>())
    , m_propString(QList<QString>())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationSimpleArrayInterface service state changes: " << QString::fromStdString(arg.params.dump());
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
    ApiGear::SimulationClient::instance()->onNotifyState("tb.simple/SimpleArrayInterface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationSimpleArrayInterface service fetch state: " << QString::fromStdString(arg.result.dump());
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
    ApiGear::SimulationClient::instance()->doFetchState("tb.simple/SimpleArrayInterface", fetchStateFunc);

    NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg) { 
        emit sigBool(arg.params["paramBool"].get<QList<bool>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigBool", sigBoolFunc);

    NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg) { 
        emit sigInt(arg.params["paramInt"].get<QList<int>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigInt", sigIntFunc);

    NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg) { 
        emit sigFloat(arg.params["paramFloat"].get<QList<qreal>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigFloat", sigFloatFunc);

    NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg) { 
        emit sigString(arg.params["paramString"].get<QList<QString>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigString", sigStringFunc);
}

SimulationSimpleArrayInterface::~SimulationSimpleArrayInterface()
{
}

void SimulationSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

QList<bool> SimulationSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void SimulationSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

QList<int> SimulationSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void SimulationSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<qreal> SimulationSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void SimulationSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<QString> SimulationSimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> SimulationSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramBool"] = paramBool;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcBool", params);
    return QList<bool>();
}

QList<int> SimulationSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt"] = paramInt;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcInt", params);
    return QList<int>();
}

QList<qreal> SimulationSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcFloat", params);
    return QList<qreal>();
}

QList<QString> SimulationSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramString"] = paramString;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcString", params);
    return QList<QString>();
}

} //namespace tb_simple

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
    , m_propInt32(0)
    , m_propInt64(0LL)
    , m_propFloat(0.0f)
    , m_propFloat32(0.0f)
    , m_propFloat64(0.0)
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
      if(arg.params.contains("propInt32")) {
        setPropInt32(arg.params["propInt32"]);
      }
      if(arg.params.contains("propInt64")) {
        setPropInt64(arg.params["propInt64"]);
      }
      if(arg.params.contains("propFloat")) {
        setPropFloat(arg.params["propFloat"]);
      }
      if(arg.params.contains("propFloat32")) {
        setPropFloat32(arg.params["propFloat32"]);
      }
      if(arg.params.contains("propFloat64")) {
        setPropFloat64(arg.params["propFloat64"]);
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
      if(arg.result.contains("propInt32")) {
        setPropInt32(arg.result["propInt32"]);
      }
      if(arg.result.contains("propInt64")) {
        setPropInt64(arg.result["propInt64"]);
      }
      if(arg.result.contains("propFloat")) {
        setPropFloat(arg.result["propFloat"]);
      }
      if(arg.result.contains("propFloat32")) {
        setPropFloat32(arg.result["propFloat32"]);
      }
      if(arg.result.contains("propFloat64")) {
        setPropFloat64(arg.result["propFloat64"]);
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
    NotifyRequestFunc sigInt32Func = [this](NotifyRequestArg arg) { 
        emit sigInt32(arg.params["paramInt32"].get<qint32>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigInt32", sigInt32Func);
    NotifyRequestFunc sigInt64Func = [this](NotifyRequestArg arg) { 
        emit sigInt64(arg.params["paramInt64"].get<qint64>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigInt64", sigInt64Func);
    NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg) { 
        emit sigFloat(arg.params["paramFloat"].get<qreal>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigFloat", sigFloatFunc);
    NotifyRequestFunc sigFloat32Func = [this](NotifyRequestArg arg) { 
        emit sigFloat32(arg.params["paramFloa32"].get<float>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigFloat32", sigFloat32Func);
    NotifyRequestFunc sigFloat64Func = [this](NotifyRequestArg arg) { 
        emit sigFloat64(arg.params["paramFloat64"].get<double>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleInterface#sigFloat64", sigFloat64Func);
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

void SimulationSimpleInterface::setPropInt32(qint32 propInt32)
{
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

qint32 SimulationSimpleInterface::propInt32() const
{
    return m_propInt32;
}

void SimulationSimpleInterface::setPropInt64(qint64 propInt64)
{
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

qint64 SimulationSimpleInterface::propInt64() const
{
    return m_propInt64;
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

void SimulationSimpleInterface::setPropFloat32(float propFloat32)
{
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

float SimulationSimpleInterface::propFloat32() const
{
    return m_propFloat32;
}

void SimulationSimpleInterface::setPropFloat64(double propFloat64)
{
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

double SimulationSimpleInterface::propFloat64() const
{
    return m_propFloat64;
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

qint32 SimulationSimpleInterface::funcInt32(qint32 paramInt32)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt32"] = paramInt32;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcInt32", params);
    return 0;
}

qint64 SimulationSimpleInterface::funcInt64(qint64 paramInt64)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt64"] = paramInt64;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcInt64", params);
    return 0LL;
}

qreal SimulationSimpleInterface::funcFloat(qreal paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcFloat", params);
    return 0.0f;
}

float SimulationSimpleInterface::funcFloat32(float paramFloat32)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat32"] = paramFloat32;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcFloat32", params);
    return 0.0f;
}

double SimulationSimpleInterface::funcFloat64(double paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleInterface", "funcFloat64", params);
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
    , m_propInt32(QList<qint32>())
    , m_propInt64(QList<qint64>())
    , m_propFloat(QList<qreal>())
    , m_propFloat32(QList<float>())
    , m_propFloat64(QList<double>())
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
      if(arg.params.contains("propInt32")) {
        setPropInt32(arg.params["propInt32"]);
      }
      if(arg.params.contains("propInt64")) {
        setPropInt64(arg.params["propInt64"]);
      }
      if(arg.params.contains("propFloat")) {
        setPropFloat(arg.params["propFloat"]);
      }
      if(arg.params.contains("propFloat32")) {
        setPropFloat32(arg.params["propFloat32"]);
      }
      if(arg.params.contains("propFloat64")) {
        setPropFloat64(arg.params["propFloat64"]);
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
      if(arg.result.contains("propInt32")) {
        setPropInt32(arg.result["propInt32"]);
      }
      if(arg.result.contains("propInt64")) {
        setPropInt64(arg.result["propInt64"]);
      }
      if(arg.result.contains("propFloat")) {
        setPropFloat(arg.result["propFloat"]);
      }
      if(arg.result.contains("propFloat32")) {
        setPropFloat32(arg.result["propFloat32"]);
      }
      if(arg.result.contains("propFloat64")) {
        setPropFloat64(arg.result["propFloat64"]);
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
    NotifyRequestFunc sigInt32Func = [this](NotifyRequestArg arg) { 
        emit sigInt32(arg.params["paramInt32"].get<QList<qint32>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigInt32", sigInt32Func);
    NotifyRequestFunc sigInt64Func = [this](NotifyRequestArg arg) { 
        emit sigInt64(arg.params["paramInt64"].get<QList<qint64>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigInt64", sigInt64Func);
    NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg) { 
        emit sigFloat(arg.params["paramFloat"].get<QList<qreal>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigFloat", sigFloatFunc);
    NotifyRequestFunc sigFloat32Func = [this](NotifyRequestArg arg) { 
        emit sigFloat32(arg.params["paramFloa32"].get<QList<float>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigFloat32", sigFloat32Func);
    NotifyRequestFunc sigFloat64Func = [this](NotifyRequestArg arg) { 
        emit sigFloat64(arg.params["paramFloat64"].get<QList<double>>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.simple/SimpleArrayInterface#sigFloat64", sigFloat64Func);
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

void SimulationSimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

QList<qint32> SimulationSimpleArrayInterface::propInt32() const
{
    return m_propInt32;
}

void SimulationSimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

QList<qint64> SimulationSimpleArrayInterface::propInt64() const
{
    return m_propInt64;
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

void SimulationSimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

QList<float> SimulationSimpleArrayInterface::propFloat32() const
{
    return m_propFloat32;
}

void SimulationSimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

QList<double> SimulationSimpleArrayInterface::propFloat64() const
{
    return m_propFloat64;
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

QList<qint32> SimulationSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt32"] = paramInt32;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcInt32", params);
    return QList<qint32>();
}

QList<qint64> SimulationSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramInt64"] = paramInt64;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcInt64", params);
    return QList<qint64>();
}

QList<qreal> SimulationSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcFloat", params);
    return QList<qreal>();
}

QList<float> SimulationSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat32"] = paramFloat32;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcFloat32", params);
    return QList<float>();
}

QList<double> SimulationSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["paramFloat"] = paramFloat;
    ApiGear::SimulationClient::instance()->doCall("tb.simple/SimpleArrayInterface", "funcFloat64", params);
    return QList<double>();
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

#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "../../shared/simulationclient.h"

using namespace ApiGear::JSONRPC;
// ********************************************************************
// SimulationInterface1 simulation interface
// ********************************************************************

SimulationInterface1::SimulationInterface1(QObject *parent)
    : AbstractInterface1(parent)
    , m_prop1(false)
    , m_prop2(0)
    , m_prop3(0.0)
    , m_prop4(QString())
    , m_prop5(QList<int>())
    , m_prop6(Struct1())
    , m_prop7(0)
    , m_prop10(QList<int>())
    , m_prop11(QList<Struct1>())
    , m_prop12(QList<Enum1::Enum1Enum>())
    , m_prop14(QList<Struct1>())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationInterface1 service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
      if(arg.params.contains("prop2")) {
        setProp2(arg.params["prop2"]);
      }
      if(arg.params.contains("prop3")) {
        setProp3(arg.params["prop3"]);
      }
      if(arg.params.contains("prop4")) {
        setProp4(arg.params["prop4"]);
      }
      if(arg.params.contains("prop5")) {
        setProp5(arg.params["prop5"]);
      }
      if(arg.params.contains("prop6")) {
        setProp6(arg.params["prop6"]);
      }
      if(arg.params.contains("prop7")) {
        setProp7(arg.params["prop7"]);
      }
      if(arg.params.contains("prop10")) {
        setProp10(arg.params["prop10"]);
      }
      if(arg.params.contains("prop11")) {
        setProp11(arg.params["prop11"]);
      }
      if(arg.params.contains("prop12")) {
        setProp12(arg.params["prop12"]);
      }
      if(arg.params.contains("prop14")) {
        setProp14(arg.params["prop14"]);
      }
    };
    SimulationClient::instance()->onNotifyState("org.objectapi.testbed/Interface1", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationInterface1 service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
      if(arg.result.contains("prop2")) {
        setProp2(arg.result["prop2"]);
      }
      if(arg.result.contains("prop3")) {
        setProp3(arg.result["prop3"]);
      }
      if(arg.result.contains("prop4")) {
        setProp4(arg.result["prop4"]);
      }
      if(arg.result.contains("prop5")) {
        setProp5(arg.result["prop5"]);
      }
      if(arg.result.contains("prop6")) {
        setProp6(arg.result["prop6"]);
      }
      if(arg.result.contains("prop7")) {
        setProp7(arg.result["prop7"]);
      }
      if(arg.result.contains("prop10")) {
        setProp10(arg.result["prop10"]);
      }
      if(arg.result.contains("prop11")) {
        setProp11(arg.result["prop11"]);
      }
      if(arg.result.contains("prop12")) {
        setProp12(arg.result["prop12"]);
      }
      if(arg.result.contains("prop14")) {
        setProp14(arg.result["prop14"]);
      }
    };
    SimulationClient::instance()->doFetchState("org.objectapi.testbed/Interface1", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1();
    };
    SimulationClient::instance()->onNotify("org.objectapi.testbed/Interface1#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["step"].get<int>());
    };
    SimulationClient::instance()->onNotify("org.objectapi.testbed/Interface1#sig2", sig2Func);

    NotifyRequestFunc sig3Func = [this](NotifyRequestArg arg) { 
        emit sig3();
    };
    SimulationClient::instance()->onNotify("org.objectapi.testbed/Interface1#sig3", sig3Func);
}

SimulationInterface1::~SimulationInterface1()
{
}

void SimulationInterface1::setProp1(bool prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

bool SimulationInterface1::prop1() const
{
    return m_prop1;
}

void SimulationInterface1::setProp2(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

int SimulationInterface1::prop2() const
{
    return m_prop2;
}

void SimulationInterface1::setProp3(qreal prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

qreal SimulationInterface1::prop3() const
{
    return m_prop3;
}

void SimulationInterface1::setProp4(const QString& prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
    }
}

QString SimulationInterface1::prop4() const
{
    return m_prop4;
}

void SimulationInterface1::setProp5(const QList<int>& prop5)
{
    if (m_prop5 != prop5) {
        m_prop5 = prop5;
        emit prop5Changed(prop5);
    }
}

QList<int> SimulationInterface1::prop5() const
{
    return m_prop5;
}

void SimulationInterface1::setProp6(const Struct1& prop6)
{
    if (m_prop6 != prop6) {
        m_prop6 = prop6;
        emit prop6Changed(prop6);
    }
}

Struct1 SimulationInterface1::prop6() const
{
    return m_prop6;
}

void SimulationInterface1::setProp7(int prop7)
{
    if (m_prop7 != prop7) {
        m_prop7 = prop7;
        emit prop7Changed(prop7);
    }
}

int SimulationInterface1::prop7() const
{
    return m_prop7;
}

void SimulationInterface1::setProp10(const QList<int>& prop10)
{
    if (m_prop10 != prop10) {
        m_prop10 = prop10;
        emit prop10Changed(prop10);
    }
}

QList<int> SimulationInterface1::prop10() const
{
    return m_prop10;
}

void SimulationInterface1::setProp11(const QList<Struct1>& prop11)
{
    if (m_prop11 != prop11) {
        m_prop11 = prop11;
        emit prop11Changed(prop11);
    }
}

QList<Struct1> SimulationInterface1::prop11() const
{
    return m_prop11;
}

void SimulationInterface1::setProp12(const QList<Enum1::Enum1Enum>& prop12)
{
    if (m_prop12 != prop12) {
        m_prop12 = prop12;
        emit prop12Changed(prop12);
    }
}

QList<Enum1::Enum1Enum> SimulationInterface1::prop12() const
{
    return m_prop12;
}

void SimulationInterface1::setProp14(const QList<Struct1>& prop14)
{
    if (m_prop14 != prop14) {
        m_prop14 = prop14;
        emit prop14Changed(prop14);
    }
}

QList<Struct1> SimulationInterface1::prop14() const
{
    return m_prop14;
}

void SimulationInterface1::op1()
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    SimulationClient::instance()->doCall("org.objectapi.testbed/Interface1", "op1", params);
    return ;
}

void SimulationInterface1::op2(int step)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["step"] = step;
    SimulationClient::instance()->doCall("org.objectapi.testbed/Interface1", "op2", params);
    return ;
}

int SimulationInterface1::op3()
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    SimulationClient::instance()->doCall("org.objectapi.testbed/Interface1", "op3", params);
    return 0;
}
// ********************************************************************
// SimulationInterface2 simulation interface
// ********************************************************************

SimulationInterface2::SimulationInterface2(QObject *parent)
    : AbstractInterface2(parent)
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0)
    , m_prop204(0.0)
    , m_prop205(QString())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationInterface2 service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop200")) {
        setProp200(arg.params["prop200"]);
      }
      if(arg.params.contains("prop201")) {
        setProp201(arg.params["prop201"]);
      }
      if(arg.params.contains("prop202")) {
        setProp202(arg.params["prop202"]);
      }
      if(arg.params.contains("prop203")) {
        setProp203(arg.params["prop203"]);
      }
      if(arg.params.contains("prop204")) {
        setProp204(arg.params["prop204"]);
      }
      if(arg.params.contains("prop205")) {
        setProp205(arg.params["prop205"]);
      }
    };
    SimulationClient::instance()->onNotifyState("org.objectapi.testbed/Interface2", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationInterface2 service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop200")) {
        setProp200(arg.result["prop200"]);
      }
      if(arg.result.contains("prop201")) {
        setProp201(arg.result["prop201"]);
      }
      if(arg.result.contains("prop202")) {
        setProp202(arg.result["prop202"]);
      }
      if(arg.result.contains("prop203")) {
        setProp203(arg.result["prop203"]);
      }
      if(arg.result.contains("prop204")) {
        setProp204(arg.result["prop204"]);
      }
      if(arg.result.contains("prop205")) {
        setProp205(arg.result["prop205"]);
      }
    };
    SimulationClient::instance()->doFetchState("org.objectapi.testbed/Interface2", fetchStateFunc);
}

SimulationInterface2::~SimulationInterface2()
{
}

void SimulationInterface2::setProp200(int prop200)
{
    if (m_prop200 != prop200) {
        m_prop200 = prop200;
        emit prop200Changed(prop200);
    }
}

int SimulationInterface2::prop200() const
{
    return m_prop200;
}

void SimulationInterface2::setProp201(int prop201)
{
    if (m_prop201 != prop201) {
        m_prop201 = prop201;
        emit prop201Changed(prop201);
    }
}

int SimulationInterface2::prop201() const
{
    return m_prop201;
}

void SimulationInterface2::setProp202(int prop202)
{
    if (m_prop202 != prop202) {
        m_prop202 = prop202;
        emit prop202Changed(prop202);
    }
}

int SimulationInterface2::prop202() const
{
    return m_prop202;
}

void SimulationInterface2::setProp203(qreal prop203)
{
    if (m_prop203 != prop203) {
        m_prop203 = prop203;
        emit prop203Changed(prop203);
    }
}

qreal SimulationInterface2::prop203() const
{
    return m_prop203;
}

void SimulationInterface2::setProp204(qreal prop204)
{
    if (m_prop204 != prop204) {
        m_prop204 = prop204;
        emit prop204Changed(prop204);
    }
}

qreal SimulationInterface2::prop204() const
{
    return m_prop204;
}

void SimulationInterface2::setProp205(const QString& prop205)
{
    if (m_prop205 != prop205) {
        m_prop205 = prop205;
        emit prop205Changed(prop205);
    }
}

QString SimulationInterface2::prop205() const
{
    return m_prop205;
}

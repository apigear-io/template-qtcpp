#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "../../shared/simulationclient.h"

using namespace ApiGear::JSONRPC;
// ********************************************************************
// SimulationManyParamInterface simulation interface
// ********************************************************************

SimulationManyParamInterface::SimulationManyParamInterface(QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationManyParamInterface service state changes: " << QString::fromStdString(arg.params.dump());
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
    };
    SimulationClient::instance()->onNotifyState("testbed2/ManyParamInterface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationManyParamInterface service fetch state: " << QString::fromStdString(arg.result.dump());
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
    };
    SimulationClient::instance()->doFetchState("testbed2/ManyParamInterface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<int>());
    };
    SimulationClient::instance()->onNotify("testbed2/ManyParamInterface#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["param1"].get<int>(),arg.params["param2"].get<int>());
    };
    SimulationClient::instance()->onNotify("testbed2/ManyParamInterface#sig2", sig2Func);

    NotifyRequestFunc sig3Func = [this](NotifyRequestArg arg) { 
        emit sig3(arg.params["param1"].get<int>(),arg.params["param2"].get<int>(),arg.params["param3"].get<int>());
    };
    SimulationClient::instance()->onNotify("testbed2/ManyParamInterface#sig3", sig3Func);

    NotifyRequestFunc sig4Func = [this](NotifyRequestArg arg) { 
        emit sig4(arg.params["param1"].get<int>(),arg.params["param2"].get<int>(),arg.params["param3"].get<int>(),arg.params["param4"].get<int>());
    };
    SimulationClient::instance()->onNotify("testbed2/ManyParamInterface#sig4", sig4Func);
}

SimulationManyParamInterface::~SimulationManyParamInterface()
{
}

void SimulationManyParamInterface::setProp1(int prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

int SimulationManyParamInterface::prop1() const
{
    return m_prop1;
}

void SimulationManyParamInterface::setProp2(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

int SimulationManyParamInterface::prop2() const
{
    return m_prop2;
}

void SimulationManyParamInterface::setProp3(int prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

int SimulationManyParamInterface::prop3() const
{
    return m_prop3;
}

void SimulationManyParamInterface::setProp4(int prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
    }
}

int SimulationManyParamInterface::prop4() const
{
    return m_prop4;
}

int SimulationManyParamInterface::func1(int param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    SimulationClient::instance()->doCall("testbed2/ManyParamInterface", "func1", params);
    return 0;
}

int SimulationManyParamInterface::func2(int param1, int param2)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    SimulationClient::instance()->doCall("testbed2/ManyParamInterface", "func2", params);
    return 0;
}

int SimulationManyParamInterface::func3(int param1, int param2, int param3)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    params["param3"] = param3;
    SimulationClient::instance()->doCall("testbed2/ManyParamInterface", "func3", params);
    return 0;
}

int SimulationManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    params["param3"] = param3;
    params["param4"] = param4;
    SimulationClient::instance()->doCall("testbed2/ManyParamInterface", "func4", params);
    return 0;
}
// ********************************************************************
// SimulationNestedStruct1Interface simulation interface
// ********************************************************************

SimulationNestedStruct1Interface::SimulationNestedStruct1Interface(QObject *parent)
    : AbstractNestedStruct1Interface(parent)
    , m_prop1(NestedStruct1())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationNestedStruct1Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
    };
    SimulationClient::instance()->onNotifyState("testbed2/NestedStruct1Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationNestedStruct1Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
    };
    SimulationClient::instance()->doFetchState("testbed2/NestedStruct1Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<NestedStruct1>());
    };
    SimulationClient::instance()->onNotify("testbed2/NestedStruct1Interface#sig1", sig1Func);
}

SimulationNestedStruct1Interface::~SimulationNestedStruct1Interface()
{
}

void SimulationNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

NestedStruct1 SimulationNestedStruct1Interface::prop1() const
{
    return m_prop1;
}

NestedStruct1 SimulationNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    SimulationClient::instance()->doCall("testbed2/NestedStruct1Interface", "func1", params);
    return NestedStruct1();
}
// ********************************************************************
// SimulationNestedStruct2Interface simulation interface
// ********************************************************************

SimulationNestedStruct2Interface::SimulationNestedStruct2Interface(QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationNestedStruct2Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
      if(arg.params.contains("prop2")) {
        setProp2(arg.params["prop2"]);
      }
    };
    SimulationClient::instance()->onNotifyState("testbed2/NestedStruct2Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationNestedStruct2Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
      if(arg.result.contains("prop2")) {
        setProp2(arg.result["prop2"]);
      }
    };
    SimulationClient::instance()->doFetchState("testbed2/NestedStruct2Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<NestedStruct1>());
    };
    SimulationClient::instance()->onNotify("testbed2/NestedStruct2Interface#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["param1"].get<NestedStruct1>(),arg.params["param2"].get<NestedStruct2>());
    };
    SimulationClient::instance()->onNotify("testbed2/NestedStruct2Interface#sig2", sig2Func);
}

SimulationNestedStruct2Interface::~SimulationNestedStruct2Interface()
{
}

void SimulationNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

NestedStruct1 SimulationNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void SimulationNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

NestedStruct2 SimulationNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 SimulationNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    SimulationClient::instance()->doCall("testbed2/NestedStruct2Interface", "func1", params);
    return NestedStruct1();
}

NestedStruct1 SimulationNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    SimulationClient::instance()->doCall("testbed2/NestedStruct2Interface", "func2", params);
    return NestedStruct1();
}
// ********************************************************************
// SimulationNestedStruct3Interface simulation interface
// ********************************************************************

SimulationNestedStruct3Interface::SimulationNestedStruct3Interface(QObject *parent)
    : AbstractNestedStruct3Interface(parent)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_prop3(NestedStruct3())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationNestedStruct3Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
      if(arg.params.contains("prop2")) {
        setProp2(arg.params["prop2"]);
      }
      if(arg.params.contains("prop3")) {
        setProp3(arg.params["prop3"]);
      }
    };
    SimulationClient::instance()->onNotifyState("testbed2/NestedStruct3Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationNestedStruct3Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
      if(arg.result.contains("prop2")) {
        setProp2(arg.result["prop2"]);
      }
      if(arg.result.contains("prop3")) {
        setProp3(arg.result["prop3"]);
      }
    };
    SimulationClient::instance()->doFetchState("testbed2/NestedStruct3Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<NestedStruct1>());
    };
    SimulationClient::instance()->onNotify("testbed2/NestedStruct3Interface#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["param1"].get<NestedStruct1>(),arg.params["param2"].get<NestedStruct2>());
    };
    SimulationClient::instance()->onNotify("testbed2/NestedStruct3Interface#sig2", sig2Func);

    NotifyRequestFunc sig3Func = [this](NotifyRequestArg arg) { 
        emit sig3(arg.params["param1"].get<NestedStruct1>(),arg.params["param2"].get<NestedStruct2>(),arg.params["param3"].get<NestedStruct3>());
    };
    SimulationClient::instance()->onNotify("testbed2/NestedStruct3Interface#sig3", sig3Func);
}

SimulationNestedStruct3Interface::~SimulationNestedStruct3Interface()
{
}

void SimulationNestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

NestedStruct1 SimulationNestedStruct3Interface::prop1() const
{
    return m_prop1;
}

void SimulationNestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

NestedStruct2 SimulationNestedStruct3Interface::prop2() const
{
    return m_prop2;
}

void SimulationNestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

NestedStruct3 SimulationNestedStruct3Interface::prop3() const
{
    return m_prop3;
}

NestedStruct1 SimulationNestedStruct3Interface::func1(const NestedStruct1& param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    SimulationClient::instance()->doCall("testbed2/NestedStruct3Interface", "func1", params);
    return NestedStruct1();
}

NestedStruct1 SimulationNestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    SimulationClient::instance()->doCall("testbed2/NestedStruct3Interface", "func2", params);
    return NestedStruct1();
}

NestedStruct1 SimulationNestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    params["param3"] = param3;
    SimulationClient::instance()->doCall("testbed2/NestedStruct3Interface", "func3", params);
    return NestedStruct1();
}

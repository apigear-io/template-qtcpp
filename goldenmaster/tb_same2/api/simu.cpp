#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "apigear/simulation/simulationclient.h"

using namespace ApiGear::JSONRPC;

namespace tb_same2 {
// ********************************************************************
// SimulationSameStruct1Interface simulation interface
// ********************************************************************

SimulationSameStruct1Interface::SimulationSameStruct1Interface(QObject *parent)
    : AbstractSameStruct1Interface(parent)
    , m_prop1(Struct1())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationSameStruct1Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
    };
    ApiGear::SimulationClient::instance()->onNotifyState("tb.same2/SameStruct1Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationSameStruct1Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
    };
    ApiGear::SimulationClient::instance()->doFetchState("tb.same2/SameStruct1Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<Struct1>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.same2/SameStruct1Interface#sig1", sig1Func);
}

SimulationSameStruct1Interface::~SimulationSameStruct1Interface()
{
}

void SimulationSameStruct1Interface::setProp1(const Struct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Struct1 SimulationSameStruct1Interface::prop1() const
{
    return m_prop1;
}

Struct1 SimulationSameStruct1Interface::func1(const Struct1& param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    ApiGear::SimulationClient::instance()->doCall("tb.same2/SameStruct1Interface", "func1", params);
    return Struct1();
}
// ********************************************************************
// SimulationSameStruct2Interface simulation interface
// ********************************************************************

SimulationSameStruct2Interface::SimulationSameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
    , m_prop1(Struct2())
    , m_prop2(Struct2())
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationSameStruct2Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
      if(arg.params.contains("prop2")) {
        setProp2(arg.params["prop2"]);
      }
    };
    ApiGear::SimulationClient::instance()->onNotifyState("tb.same2/SameStruct2Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationSameStruct2Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
      if(arg.result.contains("prop2")) {
        setProp2(arg.result["prop2"]);
      }
    };
    ApiGear::SimulationClient::instance()->doFetchState("tb.same2/SameStruct2Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<Struct1>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.same2/SameStruct2Interface#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["param1"].get<Struct1>(),arg.params["param2"].get<Struct2>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.same2/SameStruct2Interface#sig2", sig2Func);
}

SimulationSameStruct2Interface::~SimulationSameStruct2Interface()
{
}

void SimulationSameStruct2Interface::setProp1(const Struct2& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Struct2 SimulationSameStruct2Interface::prop1() const
{
    return m_prop1;
}

void SimulationSameStruct2Interface::setProp2(const Struct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Struct2 SimulationSameStruct2Interface::prop2() const
{
    return m_prop2;
}

Struct1 SimulationSameStruct2Interface::func1(const Struct1& param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    ApiGear::SimulationClient::instance()->doCall("tb.same2/SameStruct2Interface", "func1", params);
    return Struct1();
}

Struct1 SimulationSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    ApiGear::SimulationClient::instance()->doCall("tb.same2/SameStruct2Interface", "func2", params);
    return Struct1();
}
// ********************************************************************
// SimulationSameEnum1Interface simulation interface
// ********************************************************************

SimulationSameEnum1Interface::SimulationSameEnum1Interface(QObject *parent)
    : AbstractSameEnum1Interface(parent)
    , m_prop1(Enum1::value1)
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationSameEnum1Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
    };
    ApiGear::SimulationClient::instance()->onNotifyState("tb.same2/SameEnum1Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationSameEnum1Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
    };
    ApiGear::SimulationClient::instance()->doFetchState("tb.same2/SameEnum1Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<Enum1::Enum1Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.same2/SameEnum1Interface#sig1", sig1Func);
}

SimulationSameEnum1Interface::~SimulationSameEnum1Interface()
{
}

void SimulationSameEnum1Interface::setProp1(const Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum SimulationSameEnum1Interface::prop1() const
{
    return m_prop1;
}

Enum1::Enum1Enum SimulationSameEnum1Interface::func1(const Enum1::Enum1Enum param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    ApiGear::SimulationClient::instance()->doCall("tb.same2/SameEnum1Interface", "func1", params);
    return Enum1::value1;
}
// ********************************************************************
// SimulationSameEnum2Interface simulation interface
// ********************************************************************

SimulationSameEnum2Interface::SimulationSameEnum2Interface(QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value1)
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationSameEnum2Interface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop1")) {
        setProp1(arg.params["prop1"]);
      }
      if(arg.params.contains("prop2")) {
        setProp2(arg.params["prop2"]);
      }
    };
    ApiGear::SimulationClient::instance()->onNotifyState("tb.same2/SameEnum2Interface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationSameEnum2Interface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop1")) {
        setProp1(arg.result["prop1"]);
      }
      if(arg.result.contains("prop2")) {
        setProp2(arg.result["prop2"]);
      }
    };
    ApiGear::SimulationClient::instance()->doFetchState("tb.same2/SameEnum2Interface", fetchStateFunc);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<Enum1::Enum1Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.same2/SameEnum2Interface#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["param1"].get<Enum1::Enum1Enum>(),arg.params["param2"].get<Enum2::Enum2Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.same2/SameEnum2Interface#sig2", sig2Func);
}

SimulationSameEnum2Interface::~SimulationSameEnum2Interface()
{
}

void SimulationSameEnum2Interface::setProp1(const Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum SimulationSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void SimulationSameEnum2Interface::setProp2(const Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum SimulationSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum SimulationSameEnum2Interface::func1(const Enum1::Enum1Enum param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    ApiGear::SimulationClient::instance()->doCall("tb.same2/SameEnum2Interface", "func1", params);
    return Enum1::value1;
}

Enum1::Enum1Enum SimulationSameEnum2Interface::func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    params["param2"] = param2;
    ApiGear::SimulationClient::instance()->doCall("tb.same2/SameEnum2Interface", "func2", params);
    return Enum1::value1;
}

} //namespace tb_same2

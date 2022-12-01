#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "apigear/simulation/simulationclient.h"

using namespace ApiGear::JSONRPC;

namespace tb_enum {
// ********************************************************************
// SimulationEnumInterface simulation interface
// ********************************************************************

SimulationEnumInterface::SimulationEnumInterface(QObject *parent)
    : AbstractEnumInterface(parent)
    , m_prop0(Enum0::value0)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value2)
    , m_prop3(Enum3::value3)
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "SimulationEnumInterface service state changes: " << QString::fromStdString(arg.params.dump());
      if(arg.params.contains("prop0")) {
        setProp0(arg.params["prop0"]);
      }
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
    ApiGear::SimulationClient::instance()->onNotifyState("tb.enum/EnumInterface", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "SimulationEnumInterface service fetch state: " << QString::fromStdString(arg.result.dump());
      if(arg.result.contains("prop0")) {
        setProp0(arg.result["prop0"]);
      }
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
    ApiGear::SimulationClient::instance()->doFetchState("tb.enum/EnumInterface", fetchStateFunc);

    NotifyRequestFunc sig0Func = [this](NotifyRequestArg arg) { 
        emit sig0(arg.params["param0"].get<Enum0::Enum0Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.enum/EnumInterface#sig0", sig0Func);

    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg) { 
        emit sig1(arg.params["param1"].get<Enum1::Enum1Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.enum/EnumInterface#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg) { 
        emit sig2(arg.params["param2"].get<Enum2::Enum2Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.enum/EnumInterface#sig2", sig2Func);

    NotifyRequestFunc sig3Func = [this](NotifyRequestArg arg) { 
        emit sig3(arg.params["param3"].get<Enum3::Enum3Enum>());
    };
    ApiGear::SimulationClient::instance()->onNotify("tb.enum/EnumInterface#sig3", sig3Func);
}

SimulationEnumInterface::~SimulationEnumInterface()
{
}

void SimulationEnumInterface::setProp0(const Enum0::Enum0Enum prop0)
{
    if (m_prop0 != prop0) {
        m_prop0 = prop0;
        emit prop0Changed(prop0);
    }
}

Enum0::Enum0Enum SimulationEnumInterface::prop0() const
{
    return m_prop0;
}

void SimulationEnumInterface::setProp1(const Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum SimulationEnumInterface::prop1() const
{
    return m_prop1;
}

void SimulationEnumInterface::setProp2(const Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum SimulationEnumInterface::prop2() const
{
    return m_prop2;
}

void SimulationEnumInterface::setProp3(const Enum3::Enum3Enum prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

Enum3::Enum3Enum SimulationEnumInterface::prop3() const
{
    return m_prop3;
}

Enum0::Enum0Enum SimulationEnumInterface::func0(const Enum0::Enum0Enum param0)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param0"] = param0;
    ApiGear::SimulationClient::instance()->doCall("tb.enum/EnumInterface", "func0", params);
    return Enum0::value0;
}

Enum1::Enum1Enum SimulationEnumInterface::func1(const Enum1::Enum1Enum param1)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param1"] = param1;
    ApiGear::SimulationClient::instance()->doCall("tb.enum/EnumInterface", "func1", params);
    return Enum1::value1;
}

Enum2::Enum2Enum SimulationEnumInterface::func2(const Enum2::Enum2Enum param2)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param2"] = param2;
    ApiGear::SimulationClient::instance()->doCall("tb.enum/EnumInterface", "func2", params);
    return Enum2::value2;
}

Enum3::Enum3Enum SimulationEnumInterface::func3(const Enum3::Enum3Enum param3)
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    params["param3"] = param3;
    ApiGear::SimulationClient::instance()->doCall("tb.enum/EnumInterface", "func3", params);
    return Enum3::value3;
}

} //namespace tb_enum

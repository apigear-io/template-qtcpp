/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/



#include "wampenuminterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampEnumInterfaceAdapter::WampEnumInterfaceAdapter(AbstractEnumInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.enum.EnumInterface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.enum.EnumInterface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.enum.EnumInterface.func0", [this](ProcedureArg arg) {
        this->handleFunc0(arg);
    });
    WampClient::instance()->doRegister("tb.enum.EnumInterface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });
    WampClient::instance()->doRegister("tb.enum.EnumInterface.func2", [this](ProcedureArg arg) {
        this->handleFunc2(arg);
    });
    WampClient::instance()->doRegister("tb.enum.EnumInterface.func3", [this](ProcedureArg arg) {
        this->handleFunc3(arg);
    });

    // setup properties
    connect(impl, &AbstractEnumInterface::prop0Changed, this, &WampEnumInterfaceAdapter::publishState);
    connect(impl, &AbstractEnumInterface::prop1Changed, this, &WampEnumInterfaceAdapter::publishState);
    connect(impl, &AbstractEnumInterface::prop2Changed, this, &WampEnumInterfaceAdapter::publishState);
    connect(impl, &AbstractEnumInterface::prop3Changed, this, &WampEnumInterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractEnumInterface::sig0, this, &WampEnumInterfaceAdapter::publishSig0);
    connect(impl, &AbstractEnumInterface::sig1, this, &WampEnumInterfaceAdapter::publishSig1);
    connect(impl, &AbstractEnumInterface::sig2, this, &WampEnumInterfaceAdapter::publishSig2);
    connect(impl, &AbstractEnumInterface::sig3, this, &WampEnumInterfaceAdapter::publishSig3);
}

WampEnumInterfaceAdapter::~WampEnumInterfaceAdapter()
{
}

json WampEnumInterfaceAdapter::captureState()
{
    return json::object({
        { "prop0", m_impl->prop0() },
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() }
    });
}

void WampEnumInterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop0")) {
        m_impl->setProp0(state["prop0"]);
    }
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
    if(state.contains("prop3")) {
        m_impl->setProp3(state["prop3"]);
    }
}

void WampEnumInterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.enum.EnumInterface", json::array(), fields);
}

void WampEnumInterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampEnumInterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampEnumInterfaceAdapter::handleFunc0(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum0::Enum0Enum& param0 = arg.args.at(0);
    const Enum0::Enum0Enum& result = m_impl->func0(param0);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampEnumInterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum1::Enum1Enum& param1 = arg.args.at(0);
    const Enum1::Enum1Enum& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampEnumInterfaceAdapter::handleFunc2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum2::Enum2Enum& param2 = arg.args.at(0);
    const Enum2::Enum2Enum& result = m_impl->func2(param2);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampEnumInterfaceAdapter::handleFunc3(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum3::Enum3Enum& param3 = arg.args.at(0);
    const Enum3::Enum3Enum& result = m_impl->func3(param3);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampEnumInterfaceAdapter::publishSig0(const Enum0::Enum0Enum param0)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param0
    });
    WampClient::instance()->doPublish("tb.enum.EnumInterface.", args, json::object());
}
void WampEnumInterfaceAdapter::publishSig1(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("tb.enum.EnumInterface.", args, json::object());
}
void WampEnumInterfaceAdapter::publishSig2(const Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param2
    });
    WampClient::instance()->doPublish("tb.enum.EnumInterface.", args, json::object());
}
void WampEnumInterfaceAdapter::publishSig3(const Enum3::Enum3Enum param3)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param3
    });
    WampClient::instance()->doPublish("tb.enum.EnumInterface.", args, json::object());
}




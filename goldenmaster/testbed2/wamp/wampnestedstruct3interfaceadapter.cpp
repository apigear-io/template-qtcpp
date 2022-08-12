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



#include "wampnestedstruct3interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampNestedStruct3InterfaceAdapter::WampNestedStruct3InterfaceAdapter(AbstractNestedStruct3Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("testbed2.NestedStruct3Interface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("testbed2.NestedStruct3Interface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("testbed2.NestedStruct3Interface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });
    WampClient::instance()->doRegister("testbed2.NestedStruct3Interface.func2", [this](ProcedureArg arg) {
        this->handleFunc2(arg);
    });
    WampClient::instance()->doRegister("testbed2.NestedStruct3Interface.func3", [this](ProcedureArg arg) {
        this->handleFunc3(arg);
    });

    // setup properties
    connect(impl, &AbstractNestedStruct3Interface::prop1Changed, this, &WampNestedStruct3InterfaceAdapter::publishState);
    connect(impl, &AbstractNestedStruct3Interface::prop2Changed, this, &WampNestedStruct3InterfaceAdapter::publishState);
    connect(impl, &AbstractNestedStruct3Interface::prop3Changed, this, &WampNestedStruct3InterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractNestedStruct3Interface::sig1, this, &WampNestedStruct3InterfaceAdapter::publishSig1);
    connect(impl, &AbstractNestedStruct3Interface::sig2, this, &WampNestedStruct3InterfaceAdapter::publishSig2);
    connect(impl, &AbstractNestedStruct3Interface::sig3, this, &WampNestedStruct3InterfaceAdapter::publishSig3);
}

WampNestedStruct3InterfaceAdapter::~WampNestedStruct3InterfaceAdapter()
{
}

json WampNestedStruct3InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() }
    });
}

void WampNestedStruct3InterfaceAdapter::applyState(const json& state)
{
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

void WampNestedStruct3InterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("testbed2.NestedStruct3Interface", json::array(), fields);
}

void WampNestedStruct3InterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampNestedStruct3InterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampNestedStruct3InterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const NestedStruct1& param1 = arg.args.at(0);
    const NestedStruct1& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampNestedStruct3InterfaceAdapter::handleFunc2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const NestedStruct1& param1 = arg.args.at(0);
    const NestedStruct2& param2 = arg.args.at(1);
    const NestedStruct1& result = m_impl->func2(param1, param2);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampNestedStruct3InterfaceAdapter::handleFunc3(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const NestedStruct1& param1 = arg.args.at(0);
    const NestedStruct2& param2 = arg.args.at(1);
    const NestedStruct3& param3 = arg.args.at(2);
    const NestedStruct1& result = m_impl->func3(param1, param2, param3);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampNestedStruct3InterfaceAdapter::publishSig1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("testbed2.NestedStruct3Interface.", args, json::object());
}
void WampNestedStruct3InterfaceAdapter::publishSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2
    });
    WampClient::instance()->doPublish("testbed2.NestedStruct3Interface.", args, json::object());
}
void WampNestedStruct3InterfaceAdapter::publishSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2,
      param3
    });
    WampClient::instance()->doPublish("testbed2.NestedStruct3Interface.", args, json::object());
}




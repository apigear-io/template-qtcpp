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



#include "wampnestedstruct2interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampNestedStruct2InterfaceAdapter::WampNestedStruct2InterfaceAdapter(AbstractNestedStruct2Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("testbed2.NestedStruct2Interface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("testbed2.NestedStruct2Interface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("testbed2.NestedStruct2Interface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });
    WampClient::instance()->doRegister("testbed2.NestedStruct2Interface.func2", [this](ProcedureArg arg) {
        this->handleFunc2(arg);
    });

    // setup properties
    connect(impl, &AbstractNestedStruct2Interface::prop1Changed, this, &WampNestedStruct2InterfaceAdapter::publishState);
    connect(impl, &AbstractNestedStruct2Interface::prop2Changed, this, &WampNestedStruct2InterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractNestedStruct2Interface::sig1, this, &WampNestedStruct2InterfaceAdapter::publishSig1);
    connect(impl, &AbstractNestedStruct2Interface::sig2, this, &WampNestedStruct2InterfaceAdapter::publishSig2);
}

WampNestedStruct2InterfaceAdapter::~WampNestedStruct2InterfaceAdapter()
{
}

json WampNestedStruct2InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void WampNestedStruct2InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}

void WampNestedStruct2InterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("testbed2.NestedStruct2Interface", json::array(), fields);
}

void WampNestedStruct2InterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampNestedStruct2InterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampNestedStruct2InterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const NestedStruct1& param1 = arg.args.at(0);
    const NestedStruct1& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampNestedStruct2InterfaceAdapter::handleFunc2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const NestedStruct1& param1 = arg.args.at(0);
    const NestedStruct2& param2 = arg.args.at(1);
    const NestedStruct1& result = m_impl->func2(param1, param2);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampNestedStruct2InterfaceAdapter::publishSig1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("testbed2.NestedStruct2Interface.", args, json::object());
}
void WampNestedStruct2InterfaceAdapter::publishSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2
    });
    WampClient::instance()->doPublish("testbed2.NestedStruct2Interface.", args, json::object());
}




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



#include "wampsamestruct1interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampSameStruct1InterfaceAdapter::WampSameStruct1InterfaceAdapter(AbstractSameStruct1Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.same2.SameStruct1Interface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.same2.SameStruct1Interface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.same2.SameStruct1Interface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });

    // setup properties
    connect(impl, &AbstractSameStruct1Interface::prop1Changed, this, &WampSameStruct1InterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractSameStruct1Interface::sig1, this, &WampSameStruct1InterfaceAdapter::publishSig1);
}

WampSameStruct1InterfaceAdapter::~WampSameStruct1InterfaceAdapter()
{
}

json WampSameStruct1InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() }
    });
}

void WampSameStruct1InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
}

void WampSameStruct1InterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.same2.SameStruct1Interface", json::array(), fields);
}

void WampSameStruct1InterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampSameStruct1InterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampSameStruct1InterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Struct1& param1 = arg.args.at(0);
    const Struct1& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampSameStruct1InterfaceAdapter::publishSig1(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("tb.same2.SameStruct1Interface.", args, json::object());
}




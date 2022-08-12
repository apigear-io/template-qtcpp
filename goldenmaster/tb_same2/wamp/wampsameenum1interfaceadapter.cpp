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



#include "wampsameenum1interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampSameEnum1InterfaceAdapter::WampSameEnum1InterfaceAdapter(AbstractSameEnum1Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.same2.SameEnum1Interface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.same2.SameEnum1Interface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.same2.SameEnum1Interface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });

    // setup properties
    connect(impl, &AbstractSameEnum1Interface::prop1Changed, this, &WampSameEnum1InterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractSameEnum1Interface::sig1, this, &WampSameEnum1InterfaceAdapter::publishSig1);
}

WampSameEnum1InterfaceAdapter::~WampSameEnum1InterfaceAdapter()
{
}

json WampSameEnum1InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() }
    });
}

void WampSameEnum1InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
}

void WampSameEnum1InterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.same2.SameEnum1Interface", json::array(), fields);
}

void WampSameEnum1InterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampSameEnum1InterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampSameEnum1InterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum1::Enum1Enum& param1 = arg.args.at(0);
    const Enum1::Enum1Enum& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampSameEnum1InterfaceAdapter::publishSig1(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("tb.same2.SameEnum1Interface.", args, json::object());
}




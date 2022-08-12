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



#include "wampsameenum2interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampSameEnum2InterfaceAdapter::WampSameEnum2InterfaceAdapter(AbstractSameEnum2Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.same2.SameEnum2Interface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.same2.SameEnum2Interface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.same2.SameEnum2Interface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });
    WampClient::instance()->doRegister("tb.same2.SameEnum2Interface.func2", [this](ProcedureArg arg) {
        this->handleFunc2(arg);
    });

    // setup properties
    connect(impl, &AbstractSameEnum2Interface::prop1Changed, this, &WampSameEnum2InterfaceAdapter::publishState);
    connect(impl, &AbstractSameEnum2Interface::prop2Changed, this, &WampSameEnum2InterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractSameEnum2Interface::sig1, this, &WampSameEnum2InterfaceAdapter::publishSig1);
    connect(impl, &AbstractSameEnum2Interface::sig2, this, &WampSameEnum2InterfaceAdapter::publishSig2);
}

WampSameEnum2InterfaceAdapter::~WampSameEnum2InterfaceAdapter()
{
}

json WampSameEnum2InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void WampSameEnum2InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}

void WampSameEnum2InterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.same2.SameEnum2Interface", json::array(), fields);
}

void WampSameEnum2InterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampSameEnum2InterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampSameEnum2InterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum1::Enum1Enum& param1 = arg.args.at(0);
    const Enum1::Enum1Enum& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSameEnum2InterfaceAdapter::handleFunc2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Enum1::Enum1Enum& param1 = arg.args.at(0);
    const Enum2::Enum2Enum& param2 = arg.args.at(1);
    const Enum1::Enum1Enum& result = m_impl->func2(param1, param2);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampSameEnum2InterfaceAdapter::publishSig1(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("tb.same2.SameEnum2Interface.", args, json::object());
}
void WampSameEnum2InterfaceAdapter::publishSig2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2
    });
    WampClient::instance()->doPublish("tb.same2.SameEnum2Interface.", args, json::object());
}




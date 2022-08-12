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



#include "wampsamestruct2interfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampSameStruct2InterfaceAdapter::WampSameStruct2InterfaceAdapter(AbstractSameStruct2Interface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.same2.SameStruct2Interface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.same2.SameStruct2Interface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.same2.SameStruct2Interface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });
    WampClient::instance()->doRegister("tb.same2.SameStruct2Interface.func2", [this](ProcedureArg arg) {
        this->handleFunc2(arg);
    });

    // setup properties
    connect(impl, &AbstractSameStruct2Interface::prop1Changed, this, &WampSameStruct2InterfaceAdapter::publishState);
    connect(impl, &AbstractSameStruct2Interface::prop2Changed, this, &WampSameStruct2InterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractSameStruct2Interface::sig1, this, &WampSameStruct2InterfaceAdapter::publishSig1);
    connect(impl, &AbstractSameStruct2Interface::sig2, this, &WampSameStruct2InterfaceAdapter::publishSig2);
}

WampSameStruct2InterfaceAdapter::~WampSameStruct2InterfaceAdapter()
{
}

json WampSameStruct2InterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void WampSameStruct2InterfaceAdapter::applyState(const json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}

void WampSameStruct2InterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.same2.SameStruct2Interface", json::array(), fields);
}

void WampSameStruct2InterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampSameStruct2InterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampSameStruct2InterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Struct1& param1 = arg.args.at(0);
    const Struct1& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSameStruct2InterfaceAdapter::handleFunc2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const Struct1& param1 = arg.args.at(0);
    const Struct2& param2 = arg.args.at(1);
    const Struct1& result = m_impl->func2(param1, param2);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampSameStruct2InterfaceAdapter::publishSig1(const Struct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("tb.same2.SameStruct2Interface.", args, json::object());
}
void WampSameStruct2InterfaceAdapter::publishSig2(const Struct1& param1, const Struct2& param2)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2
    });
    WampClient::instance()->doPublish("tb.same2.SameStruct2Interface.", args, json::object());
}




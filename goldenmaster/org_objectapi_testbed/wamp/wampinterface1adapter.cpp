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



#include "wampinterface1adapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampInterface1Adapter::WampInterface1Adapter(AbstractInterface1* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface1._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface1._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface1.op1", [this](ProcedureArg arg) {
        this->handleOp1(arg);
    });
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface1.op2", [this](ProcedureArg arg) {
        this->handleOp2(arg);
    });
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface1.op3", [this](ProcedureArg arg) {
        this->handleOp3(arg);
    });

    // setup properties
    connect(impl, &AbstractInterface1::prop1Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop2Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop3Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop4Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop5Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop6Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop7Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop10Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop11Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop12Changed, this, &WampInterface1Adapter::publishState);
    connect(impl, &AbstractInterface1::prop14Changed, this, &WampInterface1Adapter::publishState);    

    // setup signals
    connect(impl, &AbstractInterface1::sig1, this, &WampInterface1Adapter::publishSig1);
    connect(impl, &AbstractInterface1::sig2, this, &WampInterface1Adapter::publishSig2);
    connect(impl, &AbstractInterface1::sig3, this, &WampInterface1Adapter::publishSig3);
}

WampInterface1Adapter::~WampInterface1Adapter()
{
}

json WampInterface1Adapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() },
        { "prop4", m_impl->prop4() },
        { "prop5", m_impl->prop5() },
        { "prop6", m_impl->prop6() },
        { "prop7", m_impl->prop7() },
        { "prop10", m_impl->prop10() },
        { "prop11", m_impl->prop11() },
        { "prop12", m_impl->prop12() },
        { "prop14", m_impl->prop14() }
    });
}

void WampInterface1Adapter::applyState(const json& state)
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
    if(state.contains("prop4")) {
        m_impl->setProp4(state["prop4"]);
    }
    if(state.contains("prop5")) {
        m_impl->setProp5(state["prop5"]);
    }
    if(state.contains("prop6")) {
        m_impl->setProp6(state["prop6"]);
    }
    if(state.contains("prop7")) {
        m_impl->setProp7(state["prop7"]);
    }
    if(state.contains("prop10")) {
        m_impl->setProp10(state["prop10"]);
    }
    if(state.contains("prop11")) {
        m_impl->setProp11(state["prop11"]);
    }
    if(state.contains("prop12")) {
        m_impl->setProp12(state["prop12"]);
    }
    if(state.contains("prop14")) {
        m_impl->setProp14(state["prop14"]);
    }
}

void WampInterface1Adapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("org.objectapi.testbed.Interface1", json::array(), fields);
}

void WampInterface1Adapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampInterface1Adapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampInterface1Adapter::handleOp1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    m_impl->op1();
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampInterface1Adapter::handleOp2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& step = arg.args.at(0);
    m_impl->op2(step);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampInterface1Adapter::handleOp3(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& result = m_impl->op3();
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampInterface1Adapter::publishSig1()
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
    });
    WampClient::instance()->doPublish("org.objectapi.testbed.Interface1.", args, json::object());
}
void WampInterface1Adapter::publishSig2(int step)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      step
    });
    WampClient::instance()->doPublish("org.objectapi.testbed.Interface1.", args, json::object());
}
void WampInterface1Adapter::publishSig3()
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
    });
    WampClient::instance()->doPublish("org.objectapi.testbed.Interface1.", args, json::object());
}




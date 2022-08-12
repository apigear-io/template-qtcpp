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



#include "wampmanyparaminterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampManyParamInterfaceAdapter::WampManyParamInterfaceAdapter(AbstractManyParamInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("testbed2.ManyParamInterface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("testbed2.ManyParamInterface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("testbed2.ManyParamInterface.func1", [this](ProcedureArg arg) {
        this->handleFunc1(arg);
    });
    WampClient::instance()->doRegister("testbed2.ManyParamInterface.func2", [this](ProcedureArg arg) {
        this->handleFunc2(arg);
    });
    WampClient::instance()->doRegister("testbed2.ManyParamInterface.func3", [this](ProcedureArg arg) {
        this->handleFunc3(arg);
    });
    WampClient::instance()->doRegister("testbed2.ManyParamInterface.func4", [this](ProcedureArg arg) {
        this->handleFunc4(arg);
    });

    // setup properties
    connect(impl, &AbstractManyParamInterface::prop1Changed, this, &WampManyParamInterfaceAdapter::publishState);
    connect(impl, &AbstractManyParamInterface::prop2Changed, this, &WampManyParamInterfaceAdapter::publishState);
    connect(impl, &AbstractManyParamInterface::prop3Changed, this, &WampManyParamInterfaceAdapter::publishState);
    connect(impl, &AbstractManyParamInterface::prop4Changed, this, &WampManyParamInterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractManyParamInterface::sig1, this, &WampManyParamInterfaceAdapter::publishSig1);
    connect(impl, &AbstractManyParamInterface::sig2, this, &WampManyParamInterfaceAdapter::publishSig2);
    connect(impl, &AbstractManyParamInterface::sig3, this, &WampManyParamInterfaceAdapter::publishSig3);
    connect(impl, &AbstractManyParamInterface::sig4, this, &WampManyParamInterfaceAdapter::publishSig4);
}

WampManyParamInterfaceAdapter::~WampManyParamInterfaceAdapter()
{
}

json WampManyParamInterfaceAdapter::captureState()
{
    return json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() },
        { "prop4", m_impl->prop4() }
    });
}

void WampManyParamInterfaceAdapter::applyState(const json& state)
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
}

void WampManyParamInterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("testbed2.ManyParamInterface", json::array(), fields);
}

void WampManyParamInterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampManyParamInterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampManyParamInterfaceAdapter::handleFunc1(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& param1 = arg.args.at(0);
    const int& result = m_impl->func1(param1);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampManyParamInterfaceAdapter::handleFunc2(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& param1 = arg.args.at(0);
    const int& param2 = arg.args.at(1);
    const int& result = m_impl->func2(param1, param2);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampManyParamInterfaceAdapter::handleFunc3(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& param1 = arg.args.at(0);
    const int& param2 = arg.args.at(1);
    const int& param3 = arg.args.at(2);
    const int& result = m_impl->func3(param1, param2, param3);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampManyParamInterfaceAdapter::handleFunc4(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& param1 = arg.args.at(0);
    const int& param2 = arg.args.at(1);
    const int& param3 = arg.args.at(2);
    const int& param4 = arg.args.at(3);
    const int& result = m_impl->func4(param1, param2, param3, param4);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampManyParamInterfaceAdapter::publishSig1(int param1)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1
    });
    WampClient::instance()->doPublish("testbed2.ManyParamInterface.", args, json::object());
}
void WampManyParamInterfaceAdapter::publishSig2(int param1, int param2)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2
    });
    WampClient::instance()->doPublish("testbed2.ManyParamInterface.", args, json::object());
}
void WampManyParamInterfaceAdapter::publishSig3(int param1, int param2, int param3)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2,
      param3
    });
    WampClient::instance()->doPublish("testbed2.ManyParamInterface.", args, json::object());
}
void WampManyParamInterfaceAdapter::publishSig4(int param1, int param2, int param3, int param4)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      param1,
      param2,
      param3,
      param4
    });
    WampClient::instance()->doPublish("testbed2.ManyParamInterface.", args, json::object());
}




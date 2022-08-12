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



#include "wampstructinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampStructInterfaceAdapter::WampStructInterfaceAdapter(AbstractStructInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("testbed1.StructInterface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructInterface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("testbed1.StructInterface.funcBool", [this](ProcedureArg arg) {
        this->handleFuncBool(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructInterface.funcInt", [this](ProcedureArg arg) {
        this->handleFuncInt(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructInterface.funcFloat", [this](ProcedureArg arg) {
        this->handleFuncFloat(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructInterface.funcString", [this](ProcedureArg arg) {
        this->handleFuncString(arg);
    });

    // setup properties
    connect(impl, &AbstractStructInterface::propBoolChanged, this, &WampStructInterfaceAdapter::publishState);
    connect(impl, &AbstractStructInterface::propIntChanged, this, &WampStructInterfaceAdapter::publishState);
    connect(impl, &AbstractStructInterface::propFloatChanged, this, &WampStructInterfaceAdapter::publishState);
    connect(impl, &AbstractStructInterface::propStringChanged, this, &WampStructInterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractStructInterface::sigBool, this, &WampStructInterfaceAdapter::publishSigBool);
    connect(impl, &AbstractStructInterface::sigInt, this, &WampStructInterfaceAdapter::publishSigInt);
    connect(impl, &AbstractStructInterface::sigFloat, this, &WampStructInterfaceAdapter::publishSigFloat);
    connect(impl, &AbstractStructInterface::sigString, this, &WampStructInterfaceAdapter::publishSigString);
}

WampStructInterfaceAdapter::~WampStructInterfaceAdapter()
{
}

json WampStructInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void WampStructInterfaceAdapter::applyState(const json& state)
{
    if(state.contains("propBool")) {
        m_impl->setPropBool(state["propBool"]);
    }
    if(state.contains("propInt")) {
        m_impl->setPropInt(state["propInt"]);
    }
    if(state.contains("propFloat")) {
        m_impl->setPropFloat(state["propFloat"]);
    }
    if(state.contains("propString")) {
        m_impl->setPropString(state["propString"]);
    }
}

void WampStructInterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("testbed1.StructInterface", json::array(), fields);
}

void WampStructInterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampStructInterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampStructInterfaceAdapter::handleFuncBool(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const StructBool& paramBool = arg.args.at(0);
    const StructBool& result = m_impl->funcBool(paramBool);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampStructInterfaceAdapter::handleFuncInt(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const StructInt& paramInt = arg.args.at(0);
    const StructBool& result = m_impl->funcInt(paramInt);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampStructInterfaceAdapter::handleFuncFloat(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const StructFloat& paramFloat = arg.args.at(0);
    const StructFloat& result = m_impl->funcFloat(paramFloat);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampStructInterfaceAdapter::handleFuncString(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const StructString& paramString = arg.args.at(0);
    const StructString& result = m_impl->funcString(paramString);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampStructInterfaceAdapter::publishSigBool(const StructBool& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramBool
    });
    WampClient::instance()->doPublish("testbed1.StructInterface.", args, json::object());
}
void WampStructInterfaceAdapter::publishSigInt(const StructInt& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramInt
    });
    WampClient::instance()->doPublish("testbed1.StructInterface.", args, json::object());
}
void WampStructInterfaceAdapter::publishSigFloat(const StructFloat& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramFloat
    });
    WampClient::instance()->doPublish("testbed1.StructInterface.", args, json::object());
}
void WampStructInterfaceAdapter::publishSigString(const StructString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramString
    });
    WampClient::instance()->doPublish("testbed1.StructInterface.", args, json::object());
}




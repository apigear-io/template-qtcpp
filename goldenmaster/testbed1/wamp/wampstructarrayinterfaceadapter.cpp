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



#include "wampstructarrayinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampStructArrayInterfaceAdapter::WampStructArrayInterfaceAdapter(AbstractStructArrayInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("testbed1.StructArrayInterface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructArrayInterface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("testbed1.StructArrayInterface.funcBool", [this](ProcedureArg arg) {
        this->handleFuncBool(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructArrayInterface.funcInt", [this](ProcedureArg arg) {
        this->handleFuncInt(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructArrayInterface.funcFloat", [this](ProcedureArg arg) {
        this->handleFuncFloat(arg);
    });
    WampClient::instance()->doRegister("testbed1.StructArrayInterface.funcString", [this](ProcedureArg arg) {
        this->handleFuncString(arg);
    });

    // setup properties
    connect(impl, &AbstractStructArrayInterface::propBoolChanged, this, &WampStructArrayInterfaceAdapter::publishState);
    connect(impl, &AbstractStructArrayInterface::propIntChanged, this, &WampStructArrayInterfaceAdapter::publishState);
    connect(impl, &AbstractStructArrayInterface::propFloatChanged, this, &WampStructArrayInterfaceAdapter::publishState);
    connect(impl, &AbstractStructArrayInterface::propStringChanged, this, &WampStructArrayInterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractStructArrayInterface::sigBool, this, &WampStructArrayInterfaceAdapter::publishSigBool);
    connect(impl, &AbstractStructArrayInterface::sigInt, this, &WampStructArrayInterfaceAdapter::publishSigInt);
    connect(impl, &AbstractStructArrayInterface::sigFloat, this, &WampStructArrayInterfaceAdapter::publishSigFloat);
    connect(impl, &AbstractStructArrayInterface::sigString, this, &WampStructArrayInterfaceAdapter::publishSigString);
}

WampStructArrayInterfaceAdapter::~WampStructArrayInterfaceAdapter()
{
}

json WampStructArrayInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void WampStructArrayInterfaceAdapter::applyState(const json& state)
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

void WampStructArrayInterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("testbed1.StructArrayInterface", json::array(), fields);
}

void WampStructArrayInterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampStructArrayInterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampStructArrayInterfaceAdapter::handleFuncBool(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<StructBool>& paramBool = arg.args.at(0);
    const StructBool& result = m_impl->funcBool(paramBool);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampStructArrayInterfaceAdapter::handleFuncInt(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<StructInt>& paramInt = arg.args.at(0);
    const StructBool& result = m_impl->funcInt(paramInt);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampStructArrayInterfaceAdapter::handleFuncFloat(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<StructFloat>& paramFloat = arg.args.at(0);
    const StructBool& result = m_impl->funcFloat(paramFloat);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampStructArrayInterfaceAdapter::handleFuncString(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<StructString>& paramString = arg.args.at(0);
    const StructBool& result = m_impl->funcString(paramString);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampStructArrayInterfaceAdapter::publishSigBool(const QList<StructBool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramBool
    });
    WampClient::instance()->doPublish("testbed1.StructArrayInterface.", args, json::object());
}
void WampStructArrayInterfaceAdapter::publishSigInt(const QList<StructInt>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramInt
    });
    WampClient::instance()->doPublish("testbed1.StructArrayInterface.", args, json::object());
}
void WampStructArrayInterfaceAdapter::publishSigFloat(const QList<StructFloat>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramFloat
    });
    WampClient::instance()->doPublish("testbed1.StructArrayInterface.", args, json::object());
}
void WampStructArrayInterfaceAdapter::publishSigString(const QList<StructString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramString
    });
    WampClient::instance()->doPublish("testbed1.StructArrayInterface.", args, json::object());
}




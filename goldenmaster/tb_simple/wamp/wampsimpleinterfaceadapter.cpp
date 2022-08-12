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



#include "wampsimpleinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampSimpleInterfaceAdapter::WampSimpleInterfaceAdapter(AbstractSimpleInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.simple.SimpleInterface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleInterface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.simple.SimpleInterface.funcBool", [this](ProcedureArg arg) {
        this->handleFuncBool(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleInterface.funcInt", [this](ProcedureArg arg) {
        this->handleFuncInt(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleInterface.funcFloat", [this](ProcedureArg arg) {
        this->handleFuncFloat(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleInterface.funcString", [this](ProcedureArg arg) {
        this->handleFuncString(arg);
    });

    // setup properties
    connect(impl, &AbstractSimpleInterface::propBoolChanged, this, &WampSimpleInterfaceAdapter::publishState);
    connect(impl, &AbstractSimpleInterface::propIntChanged, this, &WampSimpleInterfaceAdapter::publishState);
    connect(impl, &AbstractSimpleInterface::propFloatChanged, this, &WampSimpleInterfaceAdapter::publishState);
    connect(impl, &AbstractSimpleInterface::propStringChanged, this, &WampSimpleInterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractSimpleInterface::sigBool, this, &WampSimpleInterfaceAdapter::publishSigBool);
    connect(impl, &AbstractSimpleInterface::sigInt, this, &WampSimpleInterfaceAdapter::publishSigInt);
    connect(impl, &AbstractSimpleInterface::sigFloat, this, &WampSimpleInterfaceAdapter::publishSigFloat);
    connect(impl, &AbstractSimpleInterface::sigString, this, &WampSimpleInterfaceAdapter::publishSigString);
}

WampSimpleInterfaceAdapter::~WampSimpleInterfaceAdapter()
{
}

json WampSimpleInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void WampSimpleInterfaceAdapter::applyState(const json& state)
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

void WampSimpleInterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.simple.SimpleInterface", json::array(), fields);
}

void WampSimpleInterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampSimpleInterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampSimpleInterfaceAdapter::handleFuncBool(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const bool& paramBool = arg.args.at(0);
    const bool& result = m_impl->funcBool(paramBool);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSimpleInterfaceAdapter::handleFuncInt(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const int& paramInt = arg.args.at(0);
    const int& result = m_impl->funcInt(paramInt);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSimpleInterfaceAdapter::handleFuncFloat(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const qreal& paramFloat = arg.args.at(0);
    const qreal& result = m_impl->funcFloat(paramFloat);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSimpleInterfaceAdapter::handleFuncString(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QString& paramString = arg.args.at(0);
    const QString& result = m_impl->funcString(paramString);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampSimpleInterfaceAdapter::publishSigBool(bool paramBool)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramBool
    });
    WampClient::instance()->doPublish("tb.simple.SimpleInterface.", args, json::object());
}
void WampSimpleInterfaceAdapter::publishSigInt(int paramInt)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramInt
    });
    WampClient::instance()->doPublish("tb.simple.SimpleInterface.", args, json::object());
}
void WampSimpleInterfaceAdapter::publishSigFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramFloat
    });
    WampClient::instance()->doPublish("tb.simple.SimpleInterface.", args, json::object());
}
void WampSimpleInterfaceAdapter::publishSigString(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramString
    });
    WampClient::instance()->doPublish("tb.simple.SimpleInterface.", args, json::object());
}




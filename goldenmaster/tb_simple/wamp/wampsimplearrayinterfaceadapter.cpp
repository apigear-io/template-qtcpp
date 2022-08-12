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



#include "wampsimplearrayinterfaceadapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampSimpleArrayInterfaceAdapter::WampSimpleArrayInterfaceAdapter(AbstractSimpleArrayInterface* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("tb.simple.SimpleArrayInterface._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleArrayInterface._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
    WampClient::instance()->doRegister("tb.simple.SimpleArrayInterface.funcBool", [this](ProcedureArg arg) {
        this->handleFuncBool(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleArrayInterface.funcInt", [this](ProcedureArg arg) {
        this->handleFuncInt(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleArrayInterface.funcFloat", [this](ProcedureArg arg) {
        this->handleFuncFloat(arg);
    });
    WampClient::instance()->doRegister("tb.simple.SimpleArrayInterface.funcString", [this](ProcedureArg arg) {
        this->handleFuncString(arg);
    });

    // setup properties
    connect(impl, &AbstractSimpleArrayInterface::propBoolChanged, this, &WampSimpleArrayInterfaceAdapter::publishState);
    connect(impl, &AbstractSimpleArrayInterface::propIntChanged, this, &WampSimpleArrayInterfaceAdapter::publishState);
    connect(impl, &AbstractSimpleArrayInterface::propFloatChanged, this, &WampSimpleArrayInterfaceAdapter::publishState);
    connect(impl, &AbstractSimpleArrayInterface::propStringChanged, this, &WampSimpleArrayInterfaceAdapter::publishState);    

    // setup signals
    connect(impl, &AbstractSimpleArrayInterface::sigBool, this, &WampSimpleArrayInterfaceAdapter::publishSigBool);
    connect(impl, &AbstractSimpleArrayInterface::sigInt, this, &WampSimpleArrayInterfaceAdapter::publishSigInt);
    connect(impl, &AbstractSimpleArrayInterface::sigFloat, this, &WampSimpleArrayInterfaceAdapter::publishSigFloat);
    connect(impl, &AbstractSimpleArrayInterface::sigString, this, &WampSimpleArrayInterfaceAdapter::publishSigString);
}

WampSimpleArrayInterfaceAdapter::~WampSimpleArrayInterfaceAdapter()
{
}

json WampSimpleArrayInterfaceAdapter::captureState()
{
    return json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void WampSimpleArrayInterfaceAdapter::applyState(const json& state)
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

void WampSimpleArrayInterfaceAdapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("tb.simple.SimpleArrayInterface", json::array(), fields);
}

void WampSimpleArrayInterfaceAdapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampSimpleArrayInterfaceAdapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

void WampSimpleArrayInterfaceAdapter::handleFuncBool(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<bool>& paramBool = arg.args.at(0);
    const QList<bool>& result = m_impl->funcBool(paramBool);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSimpleArrayInterfaceAdapter::handleFuncInt(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<int>& paramInt = arg.args.at(0);
    const QList<int>& result = m_impl->funcInt(paramInt);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSimpleArrayInterfaceAdapter::handleFuncFloat(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<qreal>& paramFloat = arg.args.at(0);
    const QList<qreal>& result = m_impl->funcFloat(paramFloat);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}

void WampSimpleArrayInterfaceAdapter::handleFuncString(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
    const QList<QString>& paramString = arg.args.at(0);
    const QList<QString>& result = m_impl->funcString(paramString);
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
}
void WampSimpleArrayInterfaceAdapter::publishSigBool(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramBool
    });
    WampClient::instance()->doPublish("tb.simple.SimpleArrayInterface.", args, json::object());
}
void WampSimpleArrayInterfaceAdapter::publishSigInt(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramInt
    });
    WampClient::instance()->doPublish("tb.simple.SimpleArrayInterface.", args, json::object());
}
void WampSimpleArrayInterfaceAdapter::publishSigFloat(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramFloat
    });
    WampClient::instance()->doPublish("tb.simple.SimpleArrayInterface.", args, json::object());
}
void WampSimpleArrayInterfaceAdapter::publishSigString(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
      paramString
    });
    WampClient::instance()->doPublish("tb.simple.SimpleArrayInterface.", args, json::object());
}




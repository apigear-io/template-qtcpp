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



#include "wampinterface2adapter.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

WampInterface2Adapter::WampInterface2Adapter(AbstractInterface2* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface2._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("org.objectapi.testbed.Interface2._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations

    // setup properties
    connect(impl, &AbstractInterface2::prop200Changed, this, &WampInterface2Adapter::publishState);
    connect(impl, &AbstractInterface2::prop201Changed, this, &WampInterface2Adapter::publishState);
    connect(impl, &AbstractInterface2::prop202Changed, this, &WampInterface2Adapter::publishState);
    connect(impl, &AbstractInterface2::prop203Changed, this, &WampInterface2Adapter::publishState);
    connect(impl, &AbstractInterface2::prop204Changed, this, &WampInterface2Adapter::publishState);
    connect(impl, &AbstractInterface2::prop205Changed, this, &WampInterface2Adapter::publishState);    

    // setup signals
}

WampInterface2Adapter::~WampInterface2Adapter()
{
}

json WampInterface2Adapter::captureState()
{
    return json::object({
        { "prop200", m_impl->prop200() },
        { "prop201", m_impl->prop201() },
        { "prop202", m_impl->prop202() },
        { "prop203", m_impl->prop203() },
        { "prop204", m_impl->prop204() },
        { "prop205", m_impl->prop205() }
    });
}

void WampInterface2Adapter::applyState(const json& state)
{
    if(state.contains("prop200")) {
        m_impl->setProp200(state["prop200"]);
    }
    if(state.contains("prop201")) {
        m_impl->setProp201(state["prop201"]);
    }
    if(state.contains("prop202")) {
        m_impl->setProp202(state["prop202"]);
    }
    if(state.contains("prop203")) {
        m_impl->setProp203(state["prop203"]);
    }
    if(state.contains("prop204")) {
        m_impl->setProp204(state["prop204"]);
    }
    if(state.contains("prop205")) {
        m_impl->setProp205(state["prop205"]);
    }
}

void WampInterface2Adapter::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("org.objectapi.testbed.Interface2", json::array(), fields);
}

void WampInterface2Adapter::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void WampInterface2Adapter::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}




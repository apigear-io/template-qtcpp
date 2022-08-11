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
#include "wampinterface2.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampInterface2::WampInterface2(QObject *parent)
    : AbstractInterface2(parent)
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0)
    , m_prop204(0.0)
    , m_prop205(QString())
{    
    // get initial state from service
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("org.objectapi.testbed.Interface2", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
}

WampInterface2::~WampInterface2()
{
}

void WampInterface2::applyState(const json& fields) 
{
    if(fields.contains("prop200")) {
        setProp200Local(fields["prop200"].get<int>());
    }
    if(fields.contains("prop201")) {
        setProp201Local(fields["prop201"].get<int>());
    }
    if(fields.contains("prop202")) {
        setProp202Local(fields["prop202"].get<int>());
    }
    if(fields.contains("prop203")) {
        setProp203Local(fields["prop203"].get<qreal>());
    }
    if(fields.contains("prop204")) {
        setProp204Local(fields["prop204"].get<qreal>());
    }
    if(fields.contains("prop205")) {
        setProp205Local(fields["prop205"].get<QString>());
    }
}

void WampInterface2::setProp200(int prop200)
{
    const json &fields = json::object({
        { "prop200", prop200 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._set", json::array(), fields);
}

void WampInterface2::setProp200Local(int prop200)
{
    if (m_prop200 != prop200) {
        m_prop200 = prop200;
        emit prop200Changed(prop200);
        Interface2Agent::trace_state(this);
    }
}


int WampInterface2::prop200() const
{
    return m_prop200;
}

void WampInterface2::setProp201(int prop201)
{
    const json &fields = json::object({
        { "prop201", prop201 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._set", json::array(), fields);
}

void WampInterface2::setProp201Local(int prop201)
{
    if (m_prop201 != prop201) {
        m_prop201 = prop201;
        emit prop201Changed(prop201);
        Interface2Agent::trace_state(this);
    }
}


int WampInterface2::prop201() const
{
    return m_prop201;
}

void WampInterface2::setProp202(int prop202)
{
    const json &fields = json::object({
        { "prop202", prop202 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._set", json::array(), fields);
}

void WampInterface2::setProp202Local(int prop202)
{
    if (m_prop202 != prop202) {
        m_prop202 = prop202;
        emit prop202Changed(prop202);
        Interface2Agent::trace_state(this);
    }
}


int WampInterface2::prop202() const
{
    return m_prop202;
}

void WampInterface2::setProp203(qreal prop203)
{
    const json &fields = json::object({
        { "prop203", prop203 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._set", json::array(), fields);
}

void WampInterface2::setProp203Local(qreal prop203)
{
    if (m_prop203 != prop203) {
        m_prop203 = prop203;
        emit prop203Changed(prop203);
        Interface2Agent::trace_state(this);
    }
}


qreal WampInterface2::prop203() const
{
    return m_prop203;
}

void WampInterface2::setProp204(qreal prop204)
{
    const json &fields = json::object({
        { "prop204", prop204 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._set", json::array(), fields);
}

void WampInterface2::setProp204Local(qreal prop204)
{
    if (m_prop204 != prop204) {
        m_prop204 = prop204;
        emit prop204Changed(prop204);
        Interface2Agent::trace_state(this);
    }
}


qreal WampInterface2::prop204() const
{
    return m_prop204;
}

void WampInterface2::setProp205(const QString& prop205)
{
    const json &fields = json::object({
        { "prop205", prop205 }
    });
    WampClient::instance()->doCall("org.objectapi.testbed.Interface2._set", json::array(), fields);
}

void WampInterface2::setProp205Local(const QString& prop205)
{
    if (m_prop205 != prop205) {
        m_prop205 = prop205;
        emit prop205Changed(prop205);
        Interface2Agent::trace_state(this);
    }
}


QString WampInterface2::prop205() const
{
    return m_prop205;
}


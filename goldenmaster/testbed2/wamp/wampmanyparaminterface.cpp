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
#include "wampmanyparaminterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

WampManyParamInterface::WampManyParamInterface(QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
{    
    // get initial state from service
    WampClient::instance()->doCall("testbed2.ManyParamInterface._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("testbed2.ManyParamInterface", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });
    // subscribe to signal sig1
    WampClient::instance()->doSubscribe("testbed2.ManyParamInterface.sig1", [this](WAMP::EventArg arg) {
        this->notifySig1(arg);
    });
    // subscribe to signal sig2
    WampClient::instance()->doSubscribe("testbed2.ManyParamInterface.sig2", [this](WAMP::EventArg arg) {
        this->notifySig2(arg);
    });
    // subscribe to signal sig3
    WampClient::instance()->doSubscribe("testbed2.ManyParamInterface.sig3", [this](WAMP::EventArg arg) {
        this->notifySig3(arg);
    });
    // subscribe to signal sig4
    WampClient::instance()->doSubscribe("testbed2.ManyParamInterface.sig4", [this](WAMP::EventArg arg) {
        this->notifySig4(arg);
    });
}

WampManyParamInterface::~WampManyParamInterface()
{
}

void WampManyParamInterface::applyState(const json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<int>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<int>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<int>());
    }
    if(fields.contains("prop4")) {
        setProp4Local(fields["prop4"].get<int>());
    }
}

void WampManyParamInterface::setProp1(int prop1)
{
    const json &fields = json::object({
        { "prop1", prop1 }
    });
    WampClient::instance()->doCall("testbed2.ManyParamInterface._set", json::array(), fields);
}

void WampManyParamInterface::setProp1Local(int prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        ManyParamInterfaceAgent::trace_state(this);
    }
}


int WampManyParamInterface::prop1() const
{
    return m_prop1;
}

void WampManyParamInterface::setProp2(int prop2)
{
    const json &fields = json::object({
        { "prop2", prop2 }
    });
    WampClient::instance()->doCall("testbed2.ManyParamInterface._set", json::array(), fields);
}

void WampManyParamInterface::setProp2Local(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        ManyParamInterfaceAgent::trace_state(this);
    }
}


int WampManyParamInterface::prop2() const
{
    return m_prop2;
}

void WampManyParamInterface::setProp3(int prop3)
{
    const json &fields = json::object({
        { "prop3", prop3 }
    });
    WampClient::instance()->doCall("testbed2.ManyParamInterface._set", json::array(), fields);
}

void WampManyParamInterface::setProp3Local(int prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        ManyParamInterfaceAgent::trace_state(this);
    }
}


int WampManyParamInterface::prop3() const
{
    return m_prop3;
}

void WampManyParamInterface::setProp4(int prop4)
{
    const json &fields = json::object({
        { "prop4", prop4 }
    });
    WampClient::instance()->doCall("testbed2.ManyParamInterface._set", json::array(), fields);
}

void WampManyParamInterface::setProp4Local(int prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        ManyParamInterfaceAgent::trace_state(this);
    }
}


int WampManyParamInterface::prop4() const
{
    return m_prop4;
}

int WampManyParamInterface::func1(int param1)
{
    qDebug() << Q_FUNC_INFO;
    int value{ 0 };
    func1Async(param1)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> WampManyParamInterface::func1Async(int param1)
{
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            WampClient::instance()->doCall("testbed2.ManyParamInterface.func1", json::array({param1}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const int& result = arg.args[0].get<int>();
                resolve(result);
            });
        }
    };
}

int WampManyParamInterface::func2(int param1, int param2)
{
    qDebug() << Q_FUNC_INFO;
    int value{ 0 };
    func2Async(param1, param2)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> WampManyParamInterface::func2Async(int param1, int param2)
{
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            WampClient::instance()->doCall("testbed2.ManyParamInterface.func2", json::array({param1,param2}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const int& result = arg.args[0].get<int>();
                resolve(result);
            });
        }
    };
}

int WampManyParamInterface::func3(int param1, int param2, int param3)
{
    qDebug() << Q_FUNC_INFO;
    int value{ 0 };
    func3Async(param1, param2, param3)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> WampManyParamInterface::func3Async(int param1, int param2, int param3)
{
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            WampClient::instance()->doCall("testbed2.ManyParamInterface.func3", json::array({param1,param2,param3}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const int& result = arg.args[0].get<int>();
                resolve(result);
            });
        }
    };
}

int WampManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    qDebug() << Q_FUNC_INFO;
    int value{ 0 };
    func4Async(param1, param2, param3, param4)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> WampManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            WampClient::instance()->doCall("testbed2.ManyParamInterface.func4", json::array({param1,param2,param3,param4}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const int& result = arg.args[0].get<int>();
                resolve(result);
            });
        }
    };
}

void WampManyParamInterface::notifySig1(WAMP::EventArg arg)
{
    emit sig1(arg.args[0].get<int>());
}

void WampManyParamInterface::notifySig2(WAMP::EventArg arg)
{
    emit sig2(arg.args[0].get<int>(),arg.args[1].get<int>());
}

void WampManyParamInterface::notifySig3(WAMP::EventArg arg)
{
    emit sig3(arg.args[0].get<int>(),arg.args[1].get<int>(),arg.args[2].get<int>());
}

void WampManyParamInterface::notifySig4(WAMP::EventArg arg)
{
    emit sig4(arg.args[0].get<int>(),arg.args[1].get<int>(),arg.args[2].get<int>(),arg.args[3].get<int>());
}


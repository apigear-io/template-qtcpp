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
#include "olinkstructinterface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkStructInterface::OLinkStructInterface(ClientRegistry& registry, QObject *parent)
    : AbstractStructInterface(parent)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
    , m_isReady(false)
    , m_node()
    , m_registry(registry)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = m_registry.addObjectSink(this);
}

OLinkStructInterface::~OLinkStructInterface()
{
    m_registry.removeObjectSink(this);
}

void OLinkStructInterface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<StructString>());
    }
}

void OLinkStructInterface::setPropBool(const StructBool& propBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propBool", propBool);
}

void OLinkStructInterface::setPropBoolLocal(const StructBool& propBool)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        StructInterfaceAgent::trace_state(this);
    }
}

StructBool OLinkStructInterface::propBool() const
{
    return m_propBool;
}

void OLinkStructInterface::setPropInt(const StructInt& propInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propInt", propInt);
}

void OLinkStructInterface::setPropIntLocal(const StructInt& propInt)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        StructInterfaceAgent::trace_state(this);
    }
}

StructInt OLinkStructInterface::propInt() const
{
    return m_propInt;
}

void OLinkStructInterface::setPropFloat(const StructFloat& propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propFloat", propFloat);
}

void OLinkStructInterface::setPropFloatLocal(const StructFloat& propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        StructInterfaceAgent::trace_state(this);
    }
}

StructFloat OLinkStructInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkStructInterface::setPropString(const StructString& propString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propString", propString);
}

void OLinkStructInterface::setPropStringLocal(const StructString& propString)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        StructInterfaceAgent::trace_state(this);
    }
}

StructString OLinkStructInterface::propString() const
{
    return m_propString;
}

StructBool OLinkStructInterface::funcBool(const StructBool& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcBoolAsync(paramBool)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> OLinkStructInterface::funcBoolAsync(const StructBool& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            m_node->invokeRemote("testbed1.StructInterface/funcBool", nlohmann::json::array({paramBool}), [resolve](InvokeReplyArg arg) {                
                const StructBool& value = arg.value.get<StructBool>();
                resolve(value);
            });
        }
    };
}

StructBool OLinkStructInterface::funcInt(const StructInt& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcIntAsync(paramInt)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> OLinkStructInterface::funcIntAsync(const StructInt& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            m_node->invokeRemote("testbed1.StructInterface/funcInt", nlohmann::json::array({paramInt}), [resolve](InvokeReplyArg arg) {                
                const StructBool& value = arg.value.get<StructBool>();
                resolve(value);
            });
        }
    };
}

StructFloat OLinkStructInterface::funcFloat(const StructFloat& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return StructFloat();
    }
    StructFloat value{ StructFloat() };
    funcFloatAsync(paramFloat)
        .then([&](StructFloat result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructFloat> OLinkStructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructFloat>::reject("not initialized");
    }
    return QtPromise::QPromise<StructFloat>{[&](
        const QtPromise::QPromiseResolve<StructFloat>& resolve) {
            m_node->invokeRemote("testbed1.StructInterface/funcFloat", nlohmann::json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const StructFloat& value = arg.value.get<StructFloat>();
                resolve(value);
            });
        }
    };
}

StructString OLinkStructInterface::funcString(const StructString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return StructString();
    }
    StructString value{ StructString() };
    funcStringAsync(paramString)
        .then([&](StructString result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructString> OLinkStructInterface::funcStringAsync(const StructString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructString>::reject("not initialized");
    }
    return QtPromise::QPromise<StructString>{[&](
        const QtPromise::QPromiseResolve<StructString>& resolve) {
            m_node->invokeRemote("testbed1.StructInterface/funcString", nlohmann::json::array({paramString}), [resolve](InvokeReplyArg arg) {                
                const StructString& value = arg.value.get<StructString>();
                resolve(value);
            });
        }
    };
}


std::string OLinkStructInterface::olinkObjectName()
{
    return "testbed1.StructInterface";
}

void OLinkStructInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sigBool") {
        emit sigBool(args[0].get<StructBool>());   
        return;
    }
    if(path == "sigInt") {
        emit sigInt(args[0].get<StructInt>());   
        return;
    }
    if(path == "sigFloat") {
        emit sigFloat(args[0].get<StructFloat>());   
        return;
    }
    if(path == "sigString") {
        emit sigString(args[0].get<StructString>());   
        return;
    }
}

void OLinkStructInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkStructInterface::olinkOnInit(std::string name, nlohmann::json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkStructInterface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



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
#include "olinkstructarrayinterface.h"

#include "testbed1/api/agent.h"
#include "testbed1/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed1 {

OLinkStructArrayInterface::OLinkStructArrayInterface(QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkStructArrayInterface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<QList<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<QList<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<QList<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QList<StructString>>());
    }
}

void OLinkStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propBool", propBool);
}

void OLinkStructArrayInterface::setPropBoolLocal(const QList<StructBool>& propBool)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructBool> OLinkStructArrayInterface::propBool() const
{
    return m_propBool;
}

void OLinkStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propInt", propInt);
}

void OLinkStructArrayInterface::setPropIntLocal(const QList<StructInt>& propInt)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructInt> OLinkStructArrayInterface::propInt() const
{
    return m_propInt;
}

void OLinkStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propFloat", propFloat);
}

void OLinkStructArrayInterface::setPropFloatLocal(const QList<StructFloat>& propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructFloat> OLinkStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propString", propString);
}

void OLinkStructArrayInterface::setPropStringLocal(const QList<StructString>& propString)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        StructArrayInterfaceAgent::trace_state(this);
    }
}

QList<StructString> OLinkStructArrayInterface::propString() const
{
    return m_propString;
}

StructBool OLinkStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
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

QtPromise::QPromise<StructBool> OLinkStructArrayInterface::funcBoolAsync(const QList<StructBool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), [resolve](InvokeReplyArg arg) {                
                const StructBool& value = arg.value.get<StructBool>();
                resolve(value);
            });
        }
    };
}

StructBool OLinkStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
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

QtPromise::QPromise<StructBool> OLinkStructArrayInterface::funcIntAsync(const QList<StructInt>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), [resolve](InvokeReplyArg arg) {                
                const StructBool& value = arg.value.get<StructBool>();
                resolve(value);
            });
        }
    };
}

StructBool OLinkStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcFloatAsync(paramFloat)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> OLinkStructArrayInterface::funcFloatAsync(const QList<StructFloat>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const StructBool& value = arg.value.get<StructBool>();
                resolve(value);
            });
        }
    };
}

StructBool OLinkStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return StructBool();
    }
    StructBool value{ StructBool() };
    funcStringAsync(paramString)
        .then([&](StructBool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<StructBool> OLinkStructArrayInterface::funcStringAsync(const QList<StructString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<StructBool>::reject("not initialized");
    }
    return QtPromise::QPromise<StructBool>{[&](
        const QtPromise::QPromiseResolve<StructBool>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), [resolve](InvokeReplyArg arg) {                
                const StructBool& value = arg.value.get<StructBool>();
                resolve(value);
            });
        }
    };
}


std::string OLinkStructArrayInterface::olinkObjectName()
{
    return "testbed1.StructArrayInterface";
}

void OLinkStructArrayInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<QList<StructBool>>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<QList<StructInt>>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<QList<StructFloat>>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QList<StructString>>());   
        return;
    }
}

void OLinkStructArrayInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkStructArrayInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkStructArrayInterface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}

} //namespace testbed1

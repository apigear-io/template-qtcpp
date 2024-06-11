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
#include "olinksimpleinterface.h"

#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkSimpleInterface::OLinkSimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propInt32(0)
    , m_propInt64(0LL)
    , m_propFloat(0.0f)
    , m_propFloat32(0.0f)
    , m_propFloat64(0.0)
    , m_propString(QString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkSimpleInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propInt32")) {
        setPropInt32Local(fields["propInt32"].get<qint32>());
    }
    if(fields.contains("propInt64")) {
        setPropInt64Local(fields["propInt64"].get<qint64>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<qreal>());
    }
    if(fields.contains("propFloat32")) {
        setPropFloat32Local(fields["propFloat32"].get<float>());
    }
    if(fields.contains("propFloat64")) {
        setPropFloat64Local(fields["propFloat64"].get<double>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QString>());
    }
}

void OLinkSimpleInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "propBool") {
        setPropBoolLocal(value.get<bool>());
    }
    else if ( propertyName == "propInt") {
        setPropIntLocal(value.get<int>());
    }
    else if ( propertyName == "propInt32") {
        setPropInt32Local(value.get<qint32>());
    }
    else if ( propertyName == "propInt64") {
        setPropInt64Local(value.get<qint64>());
    }
    else if ( propertyName == "propFloat") {
        setPropFloatLocal(value.get<qreal>());
    }
    else if ( propertyName == "propFloat32") {
        setPropFloat32Local(value.get<float>());
    }
    else if ( propertyName == "propFloat64") {
        setPropFloat64Local(value.get<double>());
    }
    else if ( propertyName == "propString") {
        setPropStringLocal(value.get<QString>());
    }
}

void OLinkSimpleInterface::setPropBool(bool propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propBool", propBool);
}

void OLinkSimpleInterface::setPropBoolLocal(bool propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

bool OLinkSimpleInterface::propBool() const
{
    return m_propBool;
}

void OLinkSimpleInterface::setPropInt(int propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt", propInt);
}

void OLinkSimpleInterface::setPropIntLocal(int propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int OLinkSimpleInterface::propInt() const
{
    return m_propInt;
}

void OLinkSimpleInterface::setPropInt32(qint32 propInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt32", propInt32);
}

void OLinkSimpleInterface::setPropInt32Local(qint32 propInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

qint32 OLinkSimpleInterface::propInt32() const
{
    return m_propInt32;
}

void OLinkSimpleInterface::setPropInt64(qint64 propInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt64", propInt64);
}

void OLinkSimpleInterface::setPropInt64Local(qint64 propInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

qint64 OLinkSimpleInterface::propInt64() const
{
    return m_propInt64;
}

void OLinkSimpleInterface::setPropFloat(qreal propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat", propFloat);
}

void OLinkSimpleInterface::setPropFloatLocal(qreal propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

qreal OLinkSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkSimpleInterface::setPropFloat32(float propFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat32", propFloat32);
}

void OLinkSimpleInterface::setPropFloat32Local(float propFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

float OLinkSimpleInterface::propFloat32() const
{
    return m_propFloat32;
}

void OLinkSimpleInterface::setPropFloat64(double propFloat64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat64", propFloat64);
}

void OLinkSimpleInterface::setPropFloat64Local(double propFloat64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

double OLinkSimpleInterface::propFloat64() const
{
    return m_propFloat64;
}

void OLinkSimpleInterface::setPropString(const QString& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propString", propString);
}

void OLinkSimpleInterface::setPropStringLocal(const QString& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QString OLinkSimpleInterface::propString() const
{
    return m_propString;
}


void OLinkSimpleInterface::funcNoReturnValue(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcNoReturnValueAsync(paramBool);
    future.waitForFinished();
    return;
}

QFuture<void> OLinkSimpleInterface::funcNoReturnValueAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<void>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcNoReturnValue, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->finish();
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcNoReturnValue");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), 
            [resolve](InvokeReplyArg arg) {
                resolve->finish();
            });
    return resolve->future();
}


bool OLinkSimpleInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<bool> OLinkSimpleInterface::funcBoolAsync(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<bool>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcBool, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(false);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), 
            [resolve](InvokeReplyArg arg) {
                bool value = arg.value.get<bool>();
                resolve->addResult(value);
            });
    return resolve->future();
}


int OLinkSimpleInterface::funcInt(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<int> OLinkSimpleInterface::funcIntAsync(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<int>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcInt, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(0);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), 
            [resolve](InvokeReplyArg arg) {
                int value = arg.value.get<int>();
                resolve->addResult(value);
            });
    return resolve->future();
}


qint32 OLinkSimpleInterface::funcInt32(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcInt32Async(paramInt32);
    future.waitForFinished();
    return future.result();
}

QFuture<qint32> OLinkSimpleInterface::funcInt32Async(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<qint32>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcInt32, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(0);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt32");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt32}), 
            [resolve](InvokeReplyArg arg) {
                qint32 value = arg.value.get<qint32>();
                resolve->addResult(value);
            });
    return resolve->future();
}


qint64 OLinkSimpleInterface::funcInt64(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcInt64Async(paramInt64);
    future.waitForFinished();
    return future.result();
}

QFuture<qint64> OLinkSimpleInterface::funcInt64Async(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<qint64>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcInt64, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(0LL);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt64");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt64}), 
            [resolve](InvokeReplyArg arg) {
                qint64 value = arg.value.get<qint64>();
                resolve->addResult(value);
            });
    return resolve->future();
}


qreal OLinkSimpleInterface::funcFloat(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<qreal> OLinkSimpleInterface::funcFloatAsync(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<qreal>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcFloat, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(0.0f);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), 
            [resolve](InvokeReplyArg arg) {
                qreal value = arg.value.get<qreal>();
                resolve->addResult(value);
            });
    return resolve->future();
}


float OLinkSimpleInterface::funcFloat32(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloat32Async(paramFloat32);
    future.waitForFinished();
    return future.result();
}

QFuture<float> OLinkSimpleInterface::funcFloat32Async(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<float>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcFloat32, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(0.0f);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat32");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat32}), 
            [resolve](InvokeReplyArg arg) {
                float value = arg.value.get<float>();
                resolve->addResult(value);
            });
    return resolve->future();
}


double OLinkSimpleInterface::funcFloat64(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloat64Async(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<double> OLinkSimpleInterface::funcFloat64Async(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<double>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcFloat64, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(0.0);
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat64");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), 
            [resolve](InvokeReplyArg arg) {
                double value = arg.value.get<double>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QString OLinkSimpleInterface::funcString(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<QString> OLinkSimpleInterface::funcStringAsync(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QString>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleInterface::funcString, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QString());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), 
            [resolve](InvokeReplyArg arg) {
                QString value = arg.value.get<QString>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkSimpleInterface::olinkObjectName()
{
    return "tb.simple.SimpleInterface";
}

void OLinkSimpleInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<bool>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<int>());   
        return;
    }
    if(signalName == "sigInt32") {
        emit sigInt32(args[0].get<qint32>());   
        return;
    }
    if(signalName == "sigInt64") {
        emit sigInt64(args[0].get<qint64>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<qreal>());   
        return;
    }
    if(signalName == "sigFloat32") {
        emit sigFloat32(args[0].get<float>());   
        return;
    }
    if(signalName == "sigFloat64") {
        emit sigFloat64(args[0].get<double>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QString>());   
        return;
    }
}

void OLinkSimpleInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkSimpleInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSimpleInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple

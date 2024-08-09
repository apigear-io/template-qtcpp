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
#include "olinksimplearrayinterface.h"

#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkSimpleArrayInterface::OLinkSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propInt32(QList<qint32>())
    , m_propInt64(QList<qint64>())
    , m_propFloat(QList<qreal>())
    , m_propFloat32(QList<float>())
    , m_propFloat64(QList<double>())
    , m_propString(QList<QString>())
    , m_propReadOnlyString(QString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkSimpleArrayInterface::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<QList<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<QList<int>>());
    }
    if(fields.contains("propInt32")) {
        setPropInt32Local(fields["propInt32"].get<QList<qint32>>());
    }
    if(fields.contains("propInt64")) {
        setPropInt64Local(fields["propInt64"].get<QList<qint64>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<QList<qreal>>());
    }
    if(fields.contains("propFloat32")) {
        setPropFloat32Local(fields["propFloat32"].get<QList<float>>());
    }
    if(fields.contains("propFloat64")) {
        setPropFloat64Local(fields["propFloat64"].get<QList<double>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QList<QString>>());
    }
    if(fields.contains("propReadOnlyString")) {
        setPropReadOnlyStringLocal(fields["propReadOnlyString"].get<QString>());
    }
}

void OLinkSimpleArrayInterface::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "propBool") {
        setPropBoolLocal(value.get<QList<bool>>());
    }
    else if ( propertyName == "propInt") {
        setPropIntLocal(value.get<QList<int>>());
    }
    else if ( propertyName == "propInt32") {
        setPropInt32Local(value.get<QList<qint32>>());
    }
    else if ( propertyName == "propInt64") {
        setPropInt64Local(value.get<QList<qint64>>());
    }
    else if ( propertyName == "propFloat") {
        setPropFloatLocal(value.get<QList<qreal>>());
    }
    else if ( propertyName == "propFloat32") {
        setPropFloat32Local(value.get<QList<float>>());
    }
    else if ( propertyName == "propFloat64") {
        setPropFloat64Local(value.get<QList<double>>());
    }
    else if ( propertyName == "propString") {
        setPropStringLocal(value.get<QList<QString>>());
    }
    else if ( propertyName == "propReadOnlyString") {
        setPropReadOnlyStringLocal(value.get<QString>());
    }
}

void OLinkSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propBool", propBool);
}

void OLinkSimpleArrayInterface::setPropBoolLocal(const QList<bool>& propBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

QList<bool> OLinkSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void OLinkSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt", propInt);
}

void OLinkSimpleArrayInterface::setPropIntLocal(const QList<int>& propInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

QList<int> OLinkSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void OLinkSimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt32", propInt32);
}

void OLinkSimpleArrayInterface::setPropInt32Local(const QList<qint32>& propInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

QList<qint32> OLinkSimpleArrayInterface::propInt32() const
{
    return m_propInt32;
}

void OLinkSimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt64", propInt64);
}

void OLinkSimpleArrayInterface::setPropInt64Local(const QList<qint64>& propInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

QList<qint64> OLinkSimpleArrayInterface::propInt64() const
{
    return m_propInt64;
}

void OLinkSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat", propFloat);
}

void OLinkSimpleArrayInterface::setPropFloatLocal(const QList<qreal>& propFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<qreal> OLinkSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkSimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat32", propFloat32);
}

void OLinkSimpleArrayInterface::setPropFloat32Local(const QList<float>& propFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

QList<float> OLinkSimpleArrayInterface::propFloat32() const
{
    return m_propFloat32;
}

void OLinkSimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat64", propFloat64);
}

void OLinkSimpleArrayInterface::setPropFloat64Local(const QList<double>& propFloat64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

QList<double> OLinkSimpleArrayInterface::propFloat64() const
{
    return m_propFloat64;
}

void OLinkSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propString", propString);
}

void OLinkSimpleArrayInterface::setPropStringLocal(const QList<QString>& propString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<QString> OLinkSimpleArrayInterface::propString() const
{
    return m_propString;
}

void OLinkSimpleArrayInterface::setPropReadOnlyString(const QString& propReadOnlyString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propReadOnlyString", propReadOnlyString);
}

void OLinkSimpleArrayInterface::setPropReadOnlyStringLocal(const QString& propReadOnlyString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_propReadOnlyString != propReadOnlyString) {
        m_propReadOnlyString = propReadOnlyString;
        emit propReadOnlyStringChanged(propReadOnlyString);
    }
}

QString OLinkSimpleArrayInterface::propReadOnlyString() const
{
    return m_propReadOnlyString;
}


QList<bool> OLinkSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcBoolAsync(paramBool);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<bool>> OLinkSimpleArrayInterface::funcBoolAsync(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<bool>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcBool, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<bool>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), 
            [resolve](InvokeReplyArg arg) {
                QList<bool> value = arg.value.get<QList<bool>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<int> OLinkSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcIntAsync(paramInt);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<int>> OLinkSimpleArrayInterface::funcIntAsync(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<int>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcInt, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<int>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), 
            [resolve](InvokeReplyArg arg) {
                QList<int> value = arg.value.get<QList<int>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<qint32> OLinkSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcInt32Async(paramInt32);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<qint32>> OLinkSimpleArrayInterface::funcInt32Async(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<qint32>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcInt32, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<qint32>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt32");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt32}), 
            [resolve](InvokeReplyArg arg) {
                QList<qint32> value = arg.value.get<QList<qint32>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<qint64> OLinkSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcInt64Async(paramInt64);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<qint64>> OLinkSimpleArrayInterface::funcInt64Async(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<qint64>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcInt64, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<qint64>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt64");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramInt64}), 
            [resolve](InvokeReplyArg arg) {
                QList<qint64> value = arg.value.get<QList<qint64>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<qreal> OLinkSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloatAsync(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<qreal>> OLinkSimpleArrayInterface::funcFloatAsync(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<qreal>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcFloat, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<qreal>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), 
            [resolve](InvokeReplyArg arg) {
                QList<qreal> value = arg.value.get<QList<qreal>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<float> OLinkSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloat32Async(paramFloat32);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<float>> OLinkSimpleArrayInterface::funcFloat32Async(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<float>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcFloat32, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<float>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat32");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat32}), 
            [resolve](InvokeReplyArg arg) {
                QList<float> value = arg.value.get<QList<float>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<double> OLinkSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcFloat64Async(paramFloat);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<double>> OLinkSimpleArrayInterface::funcFloat64Async(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<double>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcFloat64, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<double>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat64");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), 
            [resolve](InvokeReplyArg arg) {
                QList<double> value = arg.value.get<QList<double>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


QList<QString> OLinkSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = funcStringAsync(paramString);
    future.waitForFinished();
    return future.result();
}

QFuture<QList<QString>> OLinkSimpleArrayInterface::funcStringAsync(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QList<QString>>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkSimpleArrayInterface::funcString, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QList<QString>());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
    m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), 
            [resolve](InvokeReplyArg arg) {
                QList<QString> value = arg.value.get<QList<QString>>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkSimpleArrayInterface::olinkObjectName()
{
    return "tb.simple.SimpleArrayInterface";
}

void OLinkSimpleArrayInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<QList<bool>>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<QList<int>>());   
        return;
    }
    if(signalName == "sigInt32") {
        emit sigInt32(args[0].get<QList<qint32>>());   
        return;
    }
    if(signalName == "sigInt64") {
        emit sigInt64(args[0].get<QList<qint64>>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<QList<qreal>>());   
        return;
    }
    if(signalName == "sigFloat32") {
        emit sigFloat32(args[0].get<QList<float>>());   
        return;
    }
    if(signalName == "sigFloat64") {
        emit sigFloat64(args[0].get<QList<double>>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QList<QString>>());   
        return;
    }
}

void OLinkSimpleArrayInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkSimpleArrayInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSimpleArrayInterface::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple

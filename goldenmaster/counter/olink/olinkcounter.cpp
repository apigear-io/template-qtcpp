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
#include "olinkcounter.h"

#include "counter/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace counter {

OLinkCounter::OLinkCounter(QObject *parent)
    : AbstractCounter(parent)
    , m_vector(custom_types::Vector3D())
    , m_extern_vector(QVector3D())
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkCounter::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("vector")) {
        setVectorLocal(fields["vector"].get<custom_types::Vector3D>());
    }
    if(fields.contains("extern_vector")) {
        setExternVectorLocal(fields["extern_vector"].get<QVector3D>());
    }
}

void OLinkCounter::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "vector") {
        setVectorLocal(value.get<custom_types::Vector3D>());
    }
    else if ( propertyName == "extern_vector") {
        setExternVectorLocal(value.get<QVector3D>());
    }
}

void OLinkCounter::setVector(const custom_types::Vector3D& vector)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("counter.Counter/vector", vector);
}

void OLinkCounter::setVectorLocal(const custom_types::Vector3D& vector)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_vector != vector) {
        m_vector = vector;
        emit vectorChanged(vector);
    }
}

custom_types::Vector3D OLinkCounter::vector() const
{
    return m_vector;
}

void OLinkCounter::setExternVector(const QVector3D& extern_vector)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("counter.Counter/extern_vector", extern_vector);
}

void OLinkCounter::setExternVectorLocal(const QVector3D& extern_vector)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_extern_vector != extern_vector) {
        m_extern_vector = extern_vector;
        emit extern_vectorChanged(extern_vector);
    }
}

QVector3D OLinkCounter::extern_vector() const
{
    return m_extern_vector;
}


QVector3D OLinkCounter::increment(const QVector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = incrementAsync(vec);
    future.waitForFinished();
    return future.result();
}

QFuture<QVector3D> OLinkCounter::incrementAsync(const QVector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<QVector3D>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkCounter::increment, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(QVector3D());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "increment");
    m_node->invokeRemote(operationId, nlohmann::json::array({vec}), 
            [resolve](InvokeReplyArg arg) {
                QVector3D value = arg.value.get<QVector3D>();
                resolve->addResult(value);
            });
    return resolve->future();
}


custom_types::Vector3D OLinkCounter::decrement(const custom_types::Vector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = decrementAsync(vec);
    future.waitForFinished();
    return future.result();
}

QFuture<custom_types::Vector3D> OLinkCounter::decrementAsync(const custom_types::Vector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<custom_types::Vector3D>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + OLinkCounter::decrement, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
            resolve->addResult(custom_types::Vector3D());
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "decrement");
    m_node->invokeRemote(operationId, nlohmann::json::array({vec}), 
            [resolve](InvokeReplyArg arg) {
                custom_types::Vector3D value = arg.value.get<custom_types::Vector3D>();
                resolve->addResult(value);
            });
    return resolve->future();
}


std::string OLinkCounter::olinkObjectName()
{
    return "counter.Counter";
}

void OLinkCounter::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
}

void OLinkCounter::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void OLinkCounter::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkCounter::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace counter

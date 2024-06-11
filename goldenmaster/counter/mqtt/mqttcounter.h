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

#pragma once

#include <QtCore>
#include <QFuture>

#include "counter/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace counter {

/**
* Adapts the general Mqtt Client handler to a Counter in a way it provides access
* to remote specific for Counter services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the Counter on the server side 
* and to subscribe for the Counter changes.
*/
class COUNTER_MQTT_LIBRARY_EXPORT MqttCounter : public AbstractCounter
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttCounter(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttCounter() override;
    /**
    * Property getter
    * @return Locally stored recent value for Vector.
    */
    custom_types::Vector3D vector() const override;
    /**
    * Request setting a property on the Counter service.
    * @param The value to which set request is send for the Vector.
    */
    void setVector(const custom_types::Vector3D& vector) override;
    /**
    * Property getter
    * @return Locally stored recent value for ExternVector.
    */
    QVector3D extern_vector() const override;
    /**
    * Request setting a property on the Counter service.
    * @param The value to which set request is send for the ExternVector.
    */
    void setExternVector(const QVector3D& extern_vector) override;
    /**
    * Remote call of ICounter::increment on the Counter service.
    * Uses incrementAsync
    */
    QVector3D increment(const QVector3D& vec) override;
    /**
    * Remote call of ICounter::increment on the Counter service.
    */
    QFuture<QVector3D> incrementAsync(const QVector3D& vec);
    /**
    * Remote call of ICounter::decrement on the Counter service.
    * Uses decrementAsync
    */
    custom_types::Vector3D decrement(const custom_types::Vector3D& vec) override;
    /**
    * Remote call of ICounter::decrement on the Counter service.
    */
    QFuture<custom_types::Vector3D> decrementAsync(const custom_types::Vector3D& vec);

signals:
    /**
    * Informs if the MqttCounter is ready to send and receive messages.
    */
    void isReady();

public:
    /**
    * The name of the interface for which this mqtt client adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on server side has to have the same name.
    */
    const QString& interfaceName();

private:
    // Helper function, subscribes for property changes from the remote Counter service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for result of invoke on remote Counter service.
    void subscribeForInvokeResponses();
    /**  Updates local value for Vector and informs subscriber about the change with emit property changed signal. */
    void setVectorLocal(const nlohmann::json& input);
    /** A local value for vector */
    custom_types::Vector3D m_vector;
    /**  Updates local value for ExternVector and informs subscriber about the change with emit property changed signal. */
    void setExternVectorLocal(const nlohmann::json& input);
    /** A local value for extern_vector */
    QVector3D m_extern_vector;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttCounter.
    * Handles incoming and outgoing messages.
    */
    ApiGear::Mqtt::Client& m_client;
    /**
    * identifiers for all subscribed pair topic - callback for one direction messages without responses (or that are not a response).
    */
    std::vector<quint64> m_subscribedIds;

    // Typdef for below m_InvokeCallsInfo members.
    using InvokeRespTopic = QString;
    // Typdef for below m_InvokeCallsInfo members.
    using InvokeTopic = QString;
    // Typdef for below m_InvokeCallsInfo members.
    using InvokeRespSubscriptionId = quint64;
    /**
    * Identifiers for all subscribed pair topic - topic response,  kept by "topic".
    * Keeps and helps accessing relevant information for invoke messages.
    */
    std::map<InvokeTopic, std::pair<InvokeRespTopic, InvokeRespSubscriptionId>> m_InvokeCallsInfo;
    /**
     * Invoke response handlers associated with the call Id.
     */
    std::map<quint64, std::pair<QString, std::function<void(const nlohmann::json&)>>> m_pendingCallsInfo;
    /* Pending calls mutex */
    std::mutex m_pendingCallMutex;
};

} //namespace counter

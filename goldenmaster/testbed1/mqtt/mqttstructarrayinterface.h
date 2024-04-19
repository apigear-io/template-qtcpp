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

#include "testbed1/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace testbed1 {

/**
* Adapts the general Mqtt Client handler to a StructArrayInterface in a way it provides access
* to remote specific for StructArrayInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the StructArrayInterface on the server side 
* and to subscribe for the StructArrayInterface changes.
*/
class TESTBED1_MQTT_LIBRARY_EXPORT MqttStructArrayInterface : public AbstractStructArrayInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttStructArrayInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttStructArrayInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    QList<StructBool> propBool() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const QList<StructBool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    QList<StructInt> propInt() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const QList<StructInt>& propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    QList<StructFloat> propFloat() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    QList<StructString> propString() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const QList<StructString>& propString) override;
    /**
    * Remote call of IStructArrayInterface::funcBool on the StructArrayInterface service.
    * Uses funcBoolAsync
    */
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    /**
    * Remote call of IStructArrayInterface::funcBool on the StructArrayInterface service.
    */
    QFuture<StructBool> funcBoolAsync(const QList<StructBool>& paramBool);
    /**
    * Remote call of IStructArrayInterface::funcInt on the StructArrayInterface service.
    * Uses funcIntAsync
    */
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    /**
    * Remote call of IStructArrayInterface::funcInt on the StructArrayInterface service.
    */
    QFuture<StructBool> funcIntAsync(const QList<StructInt>& paramInt);
    /**
    * Remote call of IStructArrayInterface::funcFloat on the StructArrayInterface service.
    * Uses funcFloatAsync
    */
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    /**
    * Remote call of IStructArrayInterface::funcFloat on the StructArrayInterface service.
    */
    QFuture<StructBool> funcFloatAsync(const QList<StructFloat>& paramFloat);
    /**
    * Remote call of IStructArrayInterface::funcString on the StructArrayInterface service.
    * Uses funcStringAsync
    */
    StructBool funcString(const QList<StructString>& paramString) override;
    /**
    * Remote call of IStructArrayInterface::funcString on the StructArrayInterface service.
    */
    QFuture<StructBool> funcStringAsync(const QList<StructString>& paramString);

signals:
    /**
    * Informs if the MqttStructArrayInterface is ready to send and receive messages.
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
    // Helper function, subscribes for property changes from the remote StructArrayInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote StructArrayInterface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote StructArrayInterface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const nlohmann::json& input);
    /** A local value for propBool */
    QList<StructBool> m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const nlohmann::json& input);
    /** A local value for propInt */
    QList<StructInt> m_propInt;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(const nlohmann::json& input);
    /** A local value for propFloat */
    QList<StructFloat> m_propFloat;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const nlohmann::json& input);
    /** A local value for propString */
    QList<StructString> m_propString;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttStructArrayInterface.
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

} //namespace testbed1

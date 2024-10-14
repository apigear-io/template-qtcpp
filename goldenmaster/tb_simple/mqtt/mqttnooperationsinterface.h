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

#include "tb_simple/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace tb_simple {

/**
* Adapts the general Mqtt Client handler to a NoOperationsInterface in a way it provides access
* to remote specific for NoOperationsInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the NoOperationsInterface on the server side 
* and to subscribe for the NoOperationsInterface changes.
*/
class TB_SIMPLE_MQTT_LIBRARY_EXPORT MqttNoOperationsInterface : public AbstractNoOperationsInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttNoOperationsInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttNoOperationsInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    bool propBool() const override;
    /**
    * Request setting a property on the NoOperationsInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(bool propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    int propInt() const override;
    /**
    * Request setting a property on the NoOperationsInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(int propInt) override;
    /**
    * Use to check if the MqttNoOperationsInterface is ready to send and receive messages.
    */
    bool isReady() const;

signals:
    /**
    * Informs if the MqttNoOperationsInterface is ready to send and receive messages.
    */
    void ready();

public:
    /**
    * The name of the interface for which this mqtt client adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on server side has to have the same name.
    */
    const QString& interfaceName();

private:
    // Helper function, subscribes for property changes from the remote NoOperationsInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote NoOperationsInterface service.
    void subscribeForSignals();
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const nlohmann::json& input);
    /** A local value for propBool */
    bool m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const nlohmann::json& input);
    /** A local value for propInt */
    int m_propInt;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);
    // Helper function for handling subsbscriptions
    void handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed);

    /** An indicator if the object has fisnished initialization. */
    bool m_finishedInitialization;
    /** 
    * An abstraction layer over the connection with service for the MqttNoOperationsInterface.
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
    /* Storage for tracking pending subscriptions */
    std::vector<QString> m_pendingSubscriptions;
};

} //namespace tb_simple

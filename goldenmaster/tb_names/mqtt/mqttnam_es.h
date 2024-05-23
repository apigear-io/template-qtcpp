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

#include "tb_names/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace tb_names {

/**
* Adapts the general Mqtt Client handler to a Nam_Es in a way it provides access
* to remote specific for Nam_Es services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the Nam_Es on the server side 
* and to subscribe for the Nam_Es changes.
*/
class TB_NAMES_MQTT_LIBRARY_EXPORT MqttNam_Es : public AbstractNamEs
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttNam_Es(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttNam_Es() override;
    /**
    * Property getter
    * @return Locally stored recent value for Switch.
    */
    bool Switch() const override;
    /**
    * Request setting a property on the Nam_Es service.
    * @param The value to which set request is send for the Switch.
    */
    void setSwitch(bool Switch) override;
    /**
    * Property getter
    * @return Locally stored recent value for SomeProperty.
    */
    int SOME_PROPERTY() const override;
    /**
    * Request setting a property on the Nam_Es service.
    * @param The value to which set request is send for the SomeProperty.
    */
    void setSomeProperty(int SOME_PROPERTY) override;
    /**
    * Property getter
    * @return Locally stored recent value for SomePoperty2.
    */
    int Some_Poperty2() const override;
    /**
    * Request setting a property on the Nam_Es service.
    * @param The value to which set request is send for the SomePoperty2.
    */
    void setSomePoperty2(int Some_Poperty2) override;
    /**
    * Remote call of INamEs::SOME_FUNCTION on the Nam_Es service.
    * Uses SOME_FUNCTIONAsync
    */
    void someFunction(bool SOME_PARAM) override;
    /**
    * Remote call of INamEs::SOME_FUNCTION on the Nam_Es service.
    */
    QFuture<void> someFunctionAsync(bool SOME_PARAM);
    /**
    * Remote call of INamEs::Some_Function2 on the Nam_Es service.
    * Uses Some_Function2Async
    */
    void someFunction2(bool Some_Param) override;
    /**
    * Remote call of INamEs::Some_Function2 on the Nam_Es service.
    */
    QFuture<void> someFunction2Async(bool Some_Param);

signals:
    /**
    * Informs if the MqttNam_Es is ready to send and receive messages.
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
    // Helper function, subscribes for property changes from the remote Nam_Es service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote Nam_Es service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote Nam_Es service.
    void subscribeForInvokeResponses();
    /**  Updates local value for Switch and informs subscriber about the change with emit property changed signal. */
    void setSwitchLocal(const nlohmann::json& input);
    /** A local value for Switch */
    bool m_Switch;
    /**  Updates local value for SomeProperty and informs subscriber about the change with emit property changed signal. */
    void setSomePropertyLocal(const nlohmann::json& input);
    /** A local value for SOME_PROPERTY */
    int m_SOME_PROPERTY;
    /**  Updates local value for SomePoperty2 and informs subscriber about the change with emit property changed signal. */
    void setSomePoperty2Local(const nlohmann::json& input);
    /** A local value for Some_Poperty2 */
    int m_Some_Poperty2;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttNam_Es.
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

} //namespace tb_names

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
#include <nlohmann/json.hpp>

#include "tb_same2/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace tb_same2 {


/**
* Server side for SameStruct2Interface implements the SameStruct2Interface service.
* It is a source of data for SameStruct2Interface clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one SameStruct2Interface service in your network.
*/
class TB_SAME2_MQTT_LIBRARY_EXPORT MqttSameStruct2InterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param SameStruct2Interface The service source object, the actual SameStruct2Interface object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes SameStruct2Interface to as a service in mqtt network.
    */
    explicit MqttSameStruct2InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractSameStruct2Interface> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttSameStruct2InterfaceAdapter();
public:
    /**
    * The name of the interface for which this mqtt service adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on client side has to have the same name.
    */
    const QString& interfaceName();
    /**
    * Use to check if the MqttSameStruct2InterfaceAdapter is ready to send and receive messages.
    */
    bool isReady() const;

signals:
    /**
    * Informs if the MqttSameStruct2InterfaceAdapter is ready to send and receive messages.
    */
    void ready();
private:
    // Helper function, subscribes this adpater for property change requests from remote clients.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes this adpater for methods invoke requests from remote clients.
    void subscribeForInvokeRequests();
    // Helper function, subscribes this adpater for property changes from the SameStruct2Interface implementation.
    void connectServicePropertiesChanges();
    // Helper function, subscribes this adpater for signals emitted by the SameStruct2Interface implementation.
    void connectServiceSignals();

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    // Helper function for handling subsbscriptions
    void handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed);

    /**
    * The actual implementation of a SameStruct2Interface that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractSameStruct2Interface> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** An indicator if the object has fisnished initialization. */
    bool m_finishedInitialization;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
    /* Storage for tracking pending subscriptions */
    std::vector<QString> m_pendingSubscriptions;
};

} // namespace tb_same2

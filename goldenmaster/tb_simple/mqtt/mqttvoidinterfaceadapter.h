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

#include "tb_simple/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace tb_simple {


/**
* Server side for VoidInterface implements the VoidInterface service.
* It is a source of data for VoidInterface clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one VoidInterface service in your network.
*/
class TB_SIMPLE_MQTT_LIBRARY_EXPORT MqttVoidInterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param VoidInterface The service source object, the actual VoidInterface object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes VoidInterface to as a service in mqtt network.
    */
    explicit MqttVoidInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractVoidInterface> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttVoidInterfaceAdapter();
public:
    /**
    * The name of the interface for which this mqtt service adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on client side has to have the same name.
    */
    const QString& interfaceName();
    /**
    * Use to check if the MqttVoidInterfaceAdapter is ready to send and receive messages.
    */
    bool isReady() const;

signals:
    /**
    * Informs if the MqttVoidInterfaceAdapter is ready to send and receive messages.
    */
    void ready();
private:
    // Helper function, subscribes this adpater for methods invoke requests from remote clients.
    void subscribeForInvokeRequests();
    // Helper function, subscribes this adpater for signals emitted by the VoidInterface implementation.
    void connectServiceSignals();

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    // Helper function for handling subsbscriptions
    void handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed);

    /**
    * The actual implementation of a VoidInterface that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractVoidInterface> m_impl;
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

} // namespace tb_simple

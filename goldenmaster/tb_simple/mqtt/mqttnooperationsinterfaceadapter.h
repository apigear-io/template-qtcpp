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
* Server side for NoOperationsInterface implements the NoOperationsInterface service.
* It is a source of data for NoOperationsInterface clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one NoOperationsInterface service in your network.
*/
class TB_SIMPLE_MQTT_LIBRARY_EXPORT MqttNoOperationsInterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param NoOperationsInterface The service source object, the actual NoOperationsInterface object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes NoOperationsInterface to as a service in mqtt network.
    */
    explicit MqttNoOperationsInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNoOperationsInterface> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttNoOperationsInterfaceAdapter();
public:
    /**
    * The name of the interface for which this mqtt service adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on client side has to have the same name.
    */
    const QString& interfaceName();

private:
    // Helper function, subscribes this adpater for property change requests from remote clients.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes this adpater for property changes from the NoOperationsInterface implementation.
    void connectServicePropertiesChanges();
    // Helper function, subscribes this adpater for signals emitted by the NoOperationsInterface implementation.
    void connectServiceSignals();

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();

    /**
    * The actual implementation of a NoOperationsInterface that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractNoOperationsInterface> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
};

} // namespace tb_simple

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

#include "testbed1/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace testbed1 {


/**
* Server side for StructInterface implements the StructInterface service.
* It is a source of data for StructInterface clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one StructInterface service in your network.
*/
class TESTBED1_MQTT_LIBRARY_EXPORT MqttStructInterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param StructInterface The service source object, the actual StructInterface object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes StructInterface to as a service in mqtt network.
    */
    explicit MqttStructInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractStructInterface> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttStructInterfaceAdapter();
public:
    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be unique for the pair source object - remote node.
    * Passed in the messages topics as an object identifier.
    */
    const QString& objectName();

private:
    // Helper function, subscribes this adpater for property change requests from remote clients.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes this adpater for methods invoke requests from remote clients.
    void subscribeForInvokeRequests();
    // Helper function, subscribes this adpater for property changes from the StructInterface implementation.
    void connectServicePropertiesChanges();
    // Helper function, subscribes this adpater for signals emitted by the StructInterface implementation.
    void connectServiceSignals();
    /**
    * The actual implementation of a StructInterface that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractStructInterface> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
};

} // namespace testbed1

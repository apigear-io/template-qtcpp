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

#include "testbed2/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace testbed2 {


/**
* Server side for NestedStruct2Interface implements the NestedStruct2Interface service.
* It is a source of data for NestedStruct2Interface clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one NestedStruct2Interface service in your network.
*/
class TESTBED2_MQTT_LIBRARY_EXPORT MqttNestedStruct2InterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param NestedStruct2Interface The service source object, the actual NestedStruct2Interface object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes NestedStruct2Interface to as a service in mqtt network.
    */
    explicit MqttNestedStruct2InterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNestedStruct2Interface> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttNestedStruct2InterfaceAdapter();
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
    // Helper function, subscribes this adpater for property changes from the NestedStruct2Interface implementation.
    void connectServicePropertiesChanges();
    // Helper function, subscribes this adpater for signals emitted by the NestedStruct2Interface implementation.
    void connectServiceSignals();
    /**
    * The actual implementation of a NestedStruct2Interface that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractNestedStruct2Interface> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
};

} // namespace testbed2

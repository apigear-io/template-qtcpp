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

#include "tb_names/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace tb_names {


/**
* Server side for Nam_Es implements the Nam_Es service.
* It is a source of data for Nam_Es clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one Nam_Es service in your network.
*/
class TB_NAMES_MQTT_LIBRARY_EXPORT MqttNam_EsAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param Nam_Es The service source object, the actual Nam_Es object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes Nam_Es to as a service in mqtt network.
    */
    explicit MqttNam_EsAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractNamEs> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttNam_EsAdapter();
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
    // Helper function, subscribes this adpater for methods invoke requests from remote clients.
    void subscribeForInvokeRequests();
    // Helper function, subscribes this adpater for property changes from the Nam_Es implementation.
    void connectServicePropertiesChanges();
    // Helper function, subscribes this adpater for signals emitted by the Nam_Es implementation.
    void connectServiceSignals();

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();

    /**
    * The actual implementation of a Nam_Es that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractNamEs> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
};

} // namespace tb_names

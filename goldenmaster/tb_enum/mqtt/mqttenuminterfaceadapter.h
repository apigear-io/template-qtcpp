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

#include "tb_enum/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace tb_enum {


/**
* Server side for EnumInterface implements the EnumInterface service.
* It is a source of data for EnumInterface clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one EnumInterface service in your network.
*/
class TB_ENUM_MQTT_LIBRARY_EXPORT MqttEnumInterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param EnumInterface The service source object, the actual EnumInterface object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes EnumInterface to as a service in mqtt network.
    */
    explicit MqttEnumInterfaceAdapter(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<AbstractEnumInterface> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~MqttEnumInterfaceAdapter();
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
    // Helper function, subscribes this adpater for property changes from the EnumInterface implementation.
    void connectServicePropertiesChanges();
    // Helper function, subscribes this adpater for signals emitted by the EnumInterface implementation.
    void connectServiceSignals();
    /**
    * The actual implementation of a EnumInterface that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<AbstractEnumInterface> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
};

} // namespace tb_enum

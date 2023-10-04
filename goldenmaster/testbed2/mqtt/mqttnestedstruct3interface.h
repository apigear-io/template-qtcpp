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
*/#pragma once

#include <QtCore>
#include <QtPromise>

#include "testbed2/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace testbed2 {

/**
* Adapts the general Mqtt Client handler to a NestedStruct3Interface in a way it provides access
* to remote specific for NestedStruct3Interface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the NestedStruct3Interface on the server side 
* and to subscribe for the NestedStruct3Interface changes.
*/
class TESTBED2_MQTT_LIBRARY_EXPORT MqttNestedStruct3Interface : public AbstractNestedStruct3Interface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttNestedStruct3Interface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttNestedStruct3Interface() override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop1.
    */
    NestedStruct1 prop1() const override;
    /**
    * Request setting a property on the NestedStruct3Interface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(const NestedStruct1& prop1) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop2.
    */
    NestedStruct2 prop2() const override;
    /**
    * Request setting a property on the NestedStruct3Interface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(const NestedStruct2& prop2) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop3.
    */
    NestedStruct3 prop3() const override;
    /**
    * Request setting a property on the NestedStruct3Interface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(const NestedStruct3& prop3) override;
    /**
    * Remote call of INestedStruct3Interface::func1 on the NestedStruct3Interface service.
    * Uses func1Async
    */
    NestedStruct1 func1(const NestedStruct1& param1) override;
    /**
    * Remote call of INestedStruct3Interface::func1 on the NestedStruct3Interface service.
    */
    QtPromise::QPromise<NestedStruct1> func1Async(const NestedStruct1& param1);
    /**
    * Remote call of INestedStruct3Interface::func2 on the NestedStruct3Interface service.
    * Uses func2Async
    */
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    /**
    * Remote call of INestedStruct3Interface::func2 on the NestedStruct3Interface service.
    */
    QtPromise::QPromise<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2);
    /**
    * Remote call of INestedStruct3Interface::func3 on the NestedStruct3Interface service.
    * Uses func3Async
    */
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    /**
    * Remote call of INestedStruct3Interface::func3 on the NestedStruct3Interface service.
    */
    QtPromise::QPromise<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);

signals:
    /**
    * Informs if the MqttNestedStruct3Interface is ready to send and receive messages.
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
    // Helper function, subscribes for property changes from the remote NestedStruct3Interface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote NestedStruct3Interface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote NestedStruct3Interface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for Prop1 and informs subscriber about the change with emit property changed signal. */
    void setProp1Local(const nlohmann::json& input);
    /** A local value for prop1 */
    NestedStruct1 m_prop1;
    /**  Updates local value for Prop2 and informs subscriber about the change with emit property changed signal. */
    void setProp2Local(const nlohmann::json& input);
    /** A local value for prop2 */
    NestedStruct2 m_prop2;
    /**  Updates local value for Prop3 and informs subscriber about the change with emit property changed signal. */
    void setProp3Local(const nlohmann::json& input);
    /** A local value for prop3 */
    NestedStruct3 m_prop3;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttNestedStruct3Interface.
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
};

} //namespace testbed2

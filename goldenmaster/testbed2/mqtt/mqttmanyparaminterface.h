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
* Adapts the general Mqtt Client handler to a ManyParamInterface in a way it provides access
* to remote specific for ManyParamInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the ManyParamInterface on the server side 
* and to subscribe for the ManyParamInterface changes.
*/
class TESTBED2_MQTT_LIBRARY_EXPORT MqttManyParamInterface : public AbstractManyParamInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttManyParamInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttManyParamInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop1.
    */
    int prop1() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(int prop1) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop2.
    */
    int prop2() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(int prop2) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop3.
    */
    int prop3() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(int prop3) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop4.
    */
    int prop4() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop4.
    */
    void setProp4(int prop4) override;
    /**
    * Remote call of IManyParamInterface::func1 on the ManyParamInterface service.
    * Uses func1Async
    */
    int func1(int param1) override;
    /**
    * Remote call of IManyParamInterface::func1 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func1Async(int param1);
    /**
    * Remote call of IManyParamInterface::func2 on the ManyParamInterface service.
    * Uses func2Async
    */
    int func2(int param1, int param2) override;
    /**
    * Remote call of IManyParamInterface::func2 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func2Async(int param1, int param2);
    /**
    * Remote call of IManyParamInterface::func3 on the ManyParamInterface service.
    * Uses func3Async
    */
    int func3(int param1, int param2, int param3) override;
    /**
    * Remote call of IManyParamInterface::func3 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func3Async(int param1, int param2, int param3);
    /**
    * Remote call of IManyParamInterface::func4 on the ManyParamInterface service.
    * Uses func4Async
    */
    int func4(int param1, int param2, int param3, int param4) override;
    /**
    * Remote call of IManyParamInterface::func4 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func4Async(int param1, int param2, int param3, int param4);

signals:
    /**
    * Informs if the MqttManyParamInterface is ready to send and receive messages.
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
    // Helper function, subscribes for property changes from the remote ManyParamInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote ManyParamInterface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote ManyParamInterface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for Prop1 and informs subscriber about the change with emit property changed signal. */
    void setProp1Local(const nlohmann::json& input);
    /** A local value for prop1 */
    int m_prop1;
    /**  Updates local value for Prop2 and informs subscriber about the change with emit property changed signal. */
    void setProp2Local(const nlohmann::json& input);
    /** A local value for prop2 */
    int m_prop2;
    /**  Updates local value for Prop3 and informs subscriber about the change with emit property changed signal. */
    void setProp3Local(const nlohmann::json& input);
    /** A local value for prop3 */
    int m_prop3;
    /**  Updates local value for Prop4 and informs subscriber about the change with emit property changed signal. */
    void setProp4Local(const nlohmann::json& input);
    /** A local value for prop4 */
    int m_prop4;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttManyParamInterface.
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

} //namespace testbed2

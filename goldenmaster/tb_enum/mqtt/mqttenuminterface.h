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

#include "tb_enum/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace tb_enum {

/**
* Adapts the general Mqtt Client handler to a EnumInterface in a way it provides access
* to remote specific for EnumInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the EnumInterface on the server side 
* and to subscribe for the EnumInterface changes.
*/
class TB_ENUM_MQTT_LIBRARY_EXPORT MqttEnumInterface : public AbstractEnumInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttEnumInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttEnumInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop0.
    */
    Enum0::Enum0Enum prop0() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop0.
    */
    void setProp0(Enum0::Enum0Enum prop0) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop1.
    */
    Enum1::Enum1Enum prop1() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(Enum1::Enum1Enum prop1) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop2.
    */
    Enum2::Enum2Enum prop2() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(Enum2::Enum2Enum prop2) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop3.
    */
    Enum3::Enum3Enum prop3() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(Enum3::Enum3Enum prop3) override;
    /**
    * Remote call of IEnumInterface::func0 on the EnumInterface service.
    * Uses func0Async
    */
    Enum0::Enum0Enum func0(Enum0::Enum0Enum param0) override;
    /**
    * Remote call of IEnumInterface::func0 on the EnumInterface service.
    */
    QFuture<Enum0::Enum0Enum> func0Async(Enum0::Enum0Enum param0);
    /**
    * Remote call of IEnumInterface::func1 on the EnumInterface service.
    * Uses func1Async
    */
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    /**
    * Remote call of IEnumInterface::func1 on the EnumInterface service.
    */
    QFuture<Enum1::Enum1Enum> func1Async(Enum1::Enum1Enum param1);
    /**
    * Remote call of IEnumInterface::func2 on the EnumInterface service.
    * Uses func2Async
    */
    Enum2::Enum2Enum func2(Enum2::Enum2Enum param2) override;
    /**
    * Remote call of IEnumInterface::func2 on the EnumInterface service.
    */
    QFuture<Enum2::Enum2Enum> func2Async(Enum2::Enum2Enum param2);
    /**
    * Remote call of IEnumInterface::func3 on the EnumInterface service.
    * Uses func3Async
    */
    Enum3::Enum3Enum func3(Enum3::Enum3Enum param3) override;
    /**
    * Remote call of IEnumInterface::func3 on the EnumInterface service.
    */
    QFuture<Enum3::Enum3Enum> func3Async(Enum3::Enum3Enum param3);

signals:
    /**
    * Informs if the MqttEnumInterface is ready to send and receive messages.
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
    // Helper function, subscribes for property changes from the remote EnumInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote EnumInterface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote EnumInterface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for Prop0 and informs subscriber about the change with emit property changed signal. */
    void setProp0Local(const nlohmann::json& input);
    /** A local value for prop0 */
    Enum0::Enum0Enum m_prop0;
    /**  Updates local value for Prop1 and informs subscriber about the change with emit property changed signal. */
    void setProp1Local(const nlohmann::json& input);
    /** A local value for prop1 */
    Enum1::Enum1Enum m_prop1;
    /**  Updates local value for Prop2 and informs subscriber about the change with emit property changed signal. */
    void setProp2Local(const nlohmann::json& input);
    /** A local value for prop2 */
    Enum2::Enum2Enum m_prop2;
    /**  Updates local value for Prop3 and informs subscriber about the change with emit property changed signal. */
    void setProp3Local(const nlohmann::json& input);
    /** A local value for prop3 */
    Enum3::Enum3Enum m_prop3;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttEnumInterface.
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

} //namespace tb_enum

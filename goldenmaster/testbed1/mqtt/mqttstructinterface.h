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

#include "testbed1/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace testbed1 {

/**
* Adapts the general Mqtt Client handler to a StructInterface in a way it provides access
* to remote specific for StructInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the StructInterface on the server side 
* and to subscribe for the StructInterface changes.
*/
class TESTBED1_MQTT_LIBRARY_EXPORT MqttStructInterface : public AbstractStructInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttStructInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttStructInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    StructBool propBool() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const StructBool& propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    StructInt propInt() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const StructInt& propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    StructFloat propFloat() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const StructFloat& propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    StructString propString() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const StructString& propString) override;
    /**
    * Remote call of IStructInterface::funcBool on the StructInterface service.
    * Uses funcBoolAsync
    */
    StructBool funcBool(const StructBool& paramBool) override;
    /**
    * Remote call of IStructInterface::funcBool on the StructInterface service.
    */
    QtPromise::QPromise<StructBool> funcBoolAsync(const StructBool& paramBool);
    /**
    * Remote call of IStructInterface::funcInt on the StructInterface service.
    * Uses funcIntAsync
    */
    StructBool funcInt(const StructInt& paramInt) override;
    /**
    * Remote call of IStructInterface::funcInt on the StructInterface service.
    */
    QtPromise::QPromise<StructBool> funcIntAsync(const StructInt& paramInt);
    /**
    * Remote call of IStructInterface::funcFloat on the StructInterface service.
    * Uses funcFloatAsync
    */
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    /**
    * Remote call of IStructInterface::funcFloat on the StructInterface service.
    */
    QtPromise::QPromise<StructFloat> funcFloatAsync(const StructFloat& paramFloat);
    /**
    * Remote call of IStructInterface::funcString on the StructInterface service.
    * Uses funcStringAsync
    */
    StructString funcString(const StructString& paramString) override;
    /**
    * Remote call of IStructInterface::funcString on the StructInterface service.
    */
    QtPromise::QPromise<StructString> funcStringAsync(const StructString& paramString);

signals:
    /**
    * Informs if the MqttStructInterface is ready to send and receive messages.
    */
    void isReady();

public:
    /**
    * The name of the object for which this mqtt sink adapter is created, object on server side has to have the same name.
    * It serves as an identifier for the client registry, it has to be unique for the pair sink object - client node.
    * Used in subscriptions messages as an object identifier.
    */
    const QString& objectName();

private:
    // Helper function, subscribes for property changes from the remote StructInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote StructInterface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote StructInterface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const nlohmann::json& input);
    /** A local value for propBool */
    StructBool m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const nlohmann::json& input);
    /** A local value for propInt */
    StructInt m_propInt;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(const nlohmann::json& input);
    /** A local value for propFloat */
    StructFloat m_propFloat;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const nlohmann::json& input);
    /** A local value for propString */
    StructString m_propString;

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttStructInterface.
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

} //namespace testbed1

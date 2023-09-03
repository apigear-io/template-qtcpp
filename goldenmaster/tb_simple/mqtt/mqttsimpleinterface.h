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

#include "tb_simple/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace tb_simple {

/**
* Adapts the general Mqtt Client handler to a SimpleInterface in a way it provides access
* to remote specific for SimpleInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the SimpleInterface on the server side 
* and to subscribe for the SimpleInterface changes.
*/
class TB_SIMPLE_MQTT_LIBRARY_EXPORT MqttSimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttSimpleInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttSimpleInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    bool propBool() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(bool propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    int propInt() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(int propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt32.
    */
    qint32 propInt32() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropInt32.
    */
    void setPropInt32(qint32 propInt32) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt64.
    */
    qint64 propInt64() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropInt64.
    */
    void setPropInt64(qint64 propInt64) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    qreal propFloat() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(qreal propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat32.
    */
    float propFloat32() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropFloat32.
    */
    void setPropFloat32(float propFloat32) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat64.
    */
    double propFloat64() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropFloat64.
    */
    void setPropFloat64(double propFloat64) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    QString propString() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const QString& propString) override;
    /**
    * Remote call of ISimpleInterface::funcVoid on the SimpleInterface service.
    * Uses funcVoidAsync
    */
    void funcVoid() override;
    /**
    * Remote call of ISimpleInterface::funcVoid on the SimpleInterface service.
    */
    QtPromise::QPromise<void> funcVoidAsync();
    /**
    * Remote call of ISimpleInterface::funcBool on the SimpleInterface service.
    * Uses funcBoolAsync
    */
    bool funcBool(bool paramBool) override;
    /**
    * Remote call of ISimpleInterface::funcBool on the SimpleInterface service.
    */
    QtPromise::QPromise<bool> funcBoolAsync(bool paramBool);
    /**
    * Remote call of ISimpleInterface::funcInt on the SimpleInterface service.
    * Uses funcIntAsync
    */
    int funcInt(int paramInt) override;
    /**
    * Remote call of ISimpleInterface::funcInt on the SimpleInterface service.
    */
    QtPromise::QPromise<int> funcIntAsync(int paramInt);
    /**
    * Remote call of ISimpleInterface::funcInt32 on the SimpleInterface service.
    * Uses funcInt32Async
    */
    qint32 funcInt32(qint32 paramInt32) override;
    /**
    * Remote call of ISimpleInterface::funcInt32 on the SimpleInterface service.
    */
    QtPromise::QPromise<qint32> funcInt32Async(qint32 paramInt32);
    /**
    * Remote call of ISimpleInterface::funcInt64 on the SimpleInterface service.
    * Uses funcInt64Async
    */
    qint64 funcInt64(qint64 paramInt64) override;
    /**
    * Remote call of ISimpleInterface::funcInt64 on the SimpleInterface service.
    */
    QtPromise::QPromise<qint64> funcInt64Async(qint64 paramInt64);
    /**
    * Remote call of ISimpleInterface::funcFloat on the SimpleInterface service.
    * Uses funcFloatAsync
    */
    qreal funcFloat(qreal paramFloat) override;
    /**
    * Remote call of ISimpleInterface::funcFloat on the SimpleInterface service.
    */
    QtPromise::QPromise<qreal> funcFloatAsync(qreal paramFloat);
    /**
    * Remote call of ISimpleInterface::funcFloat32 on the SimpleInterface service.
    * Uses funcFloat32Async
    */
    float funcFloat32(float paramFloat32) override;
    /**
    * Remote call of ISimpleInterface::funcFloat32 on the SimpleInterface service.
    */
    QtPromise::QPromise<float> funcFloat32Async(float paramFloat32);
    /**
    * Remote call of ISimpleInterface::funcFloat64 on the SimpleInterface service.
    * Uses funcFloat64Async
    */
    double funcFloat64(double paramFloat) override;
    /**
    * Remote call of ISimpleInterface::funcFloat64 on the SimpleInterface service.
    */
    QtPromise::QPromise<double> funcFloat64Async(double paramFloat);
    /**
    * Remote call of ISimpleInterface::funcString on the SimpleInterface service.
    * Uses funcStringAsync
    */
    QString funcString(const QString& paramString) override;
    /**
    * Remote call of ISimpleInterface::funcString on the SimpleInterface service.
    */
    QtPromise::QPromise<QString> funcStringAsync(const QString& paramString);

signals:
    /**
    * Informs if the MqttSimpleInterface is ready to send and receive messages.
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
    // Helper function, subscribes for property changes from the remote SimpleInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote SimpleInterface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote SimpleInterface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const nlohmann::json& input);
    /** A local value for propBool */
    bool m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const nlohmann::json& input);
    /** A local value for propInt */
    int m_propInt;
    /**  Updates local value for PropInt32 and informs subscriber about the change with emit property changed signal. */
    void setPropInt32Local(const nlohmann::json& input);
    /** A local value for propInt32 */
    qint32 m_propInt32;
    /**  Updates local value for PropInt64 and informs subscriber about the change with emit property changed signal. */
    void setPropInt64Local(const nlohmann::json& input);
    /** A local value for propInt64 */
    qint64 m_propInt64;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(const nlohmann::json& input);
    /** A local value for propFloat */
    qreal m_propFloat;
    /**  Updates local value for PropFloat32 and informs subscriber about the change with emit property changed signal. */
    void setPropFloat32Local(const nlohmann::json& input);
    /** A local value for propFloat32 */
    float m_propFloat32;
    /**  Updates local value for PropFloat64 and informs subscriber about the change with emit property changed signal. */
    void setPropFloat64Local(const nlohmann::json& input);
    /** A local value for propFloat64 */
    double m_propFloat64;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const nlohmann::json& input);
    /** A local value for propString */
    QString m_propString;

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the MqttSimpleInterface.
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

} //namespace tb_simple

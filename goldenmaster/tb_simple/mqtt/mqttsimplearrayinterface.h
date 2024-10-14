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

#include "tb_simple/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace tb_simple {

/**
* Adapts the general Mqtt Client handler to a SimpleArrayInterface in a way it provides access
* to remote specific for SimpleArrayInterface services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the SimpleArrayInterface on the server side 
* and to subscribe for the SimpleArrayInterface changes.
*/
class TB_SIMPLE_MQTT_LIBRARY_EXPORT MqttSimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
public:
    /** ctor */
    explicit MqttSimpleArrayInterface(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~MqttSimpleArrayInterface() override;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    QList<bool> propBool() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const QList<bool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    QList<int> propInt() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const QList<int>& propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt32.
    */
    QList<qint32> propInt32() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt32.
    */
    void setPropInt32(const QList<qint32>& propInt32) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt64.
    */
    QList<qint64> propInt64() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt64.
    */
    void setPropInt64(const QList<qint64>& propInt64) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    QList<qreal> propFloat() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const QList<qreal>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat32.
    */
    QList<float> propFloat32() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat32.
    */
    void setPropFloat32(const QList<float>& propFloat32) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat64.
    */
    QList<double> propFloat64() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat64.
    */
    void setPropFloat64(const QList<double>& propFloat64) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    QList<QString> propString() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const QList<QString>& propString) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropReadOnlyString.
    */
    QString propReadOnlyString() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropReadOnlyString.
    */
    void setPropReadOnlyString(const QString& propReadOnlyString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    * Uses funcBoolAsync
    */
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    */
    QFuture<QList<bool>> funcBoolAsync(const QList<bool>& paramBool);
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    * Uses funcIntAsync
    */
    QList<int> funcInt(const QList<int>& paramInt) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    */
    QFuture<QList<int>> funcIntAsync(const QList<int>& paramInt);
    /**
    * Remote call of ISimpleArrayInterface::funcInt32 on the SimpleArrayInterface service.
    * Uses funcInt32Async
    */
    QList<qint32> funcInt32(const QList<qint32>& paramInt32) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt32 on the SimpleArrayInterface service.
    */
    QFuture<QList<qint32>> funcInt32Async(const QList<qint32>& paramInt32);
    /**
    * Remote call of ISimpleArrayInterface::funcInt64 on the SimpleArrayInterface service.
    * Uses funcInt64Async
    */
    QList<qint64> funcInt64(const QList<qint64>& paramInt64) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt64 on the SimpleArrayInterface service.
    */
    QFuture<QList<qint64>> funcInt64Async(const QList<qint64>& paramInt64);
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    * Uses funcFloatAsync
    */
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    */
    QFuture<QList<qreal>> funcFloatAsync(const QList<qreal>& paramFloat);
    /**
    * Remote call of ISimpleArrayInterface::funcFloat32 on the SimpleArrayInterface service.
    * Uses funcFloat32Async
    */
    QList<float> funcFloat32(const QList<float>& paramFloat32) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat32 on the SimpleArrayInterface service.
    */
    QFuture<QList<float>> funcFloat32Async(const QList<float>& paramFloat32);
    /**
    * Remote call of ISimpleArrayInterface::funcFloat64 on the SimpleArrayInterface service.
    * Uses funcFloat64Async
    */
    QList<double> funcFloat64(const QList<double>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat64 on the SimpleArrayInterface service.
    */
    QFuture<QList<double>> funcFloat64Async(const QList<double>& paramFloat);
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    * Uses funcStringAsync
    */
    QList<QString> funcString(const QList<QString>& paramString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    */
    QFuture<QList<QString>> funcStringAsync(const QList<QString>& paramString);
    /**
    * Use to check if the MqttSimpleArrayInterface is ready to send and receive messages.
    */
    bool isReady() const;

signals:
    /**
    * Informs if the MqttSimpleArrayInterface is ready to send and receive messages.
    */
    void ready();

public:
    /**
    * The name of the interface for which this mqtt client adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on server side has to have the same name.
    */
    const QString& interfaceName();

private:
    // Helper function, subscribes for property changes from the remote SimpleArrayInterface service.
    void subscribeForPropertiesChanges();
    // Helper function, subscribes for signals emitted by the remote SimpleArrayInterface service.
    void subscribeForSignals();
    // Helper function, subscribes for result of invoke on remote SimpleArrayInterface service.
    void subscribeForInvokeResponses();
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const nlohmann::json& input);
    /** A local value for propBool */
    QList<bool> m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const nlohmann::json& input);
    /** A local value for propInt */
    QList<int> m_propInt;
    /**  Updates local value for PropInt32 and informs subscriber about the change with emit property changed signal. */
    void setPropInt32Local(const nlohmann::json& input);
    /** A local value for propInt32 */
    QList<qint32> m_propInt32;
    /**  Updates local value for PropInt64 and informs subscriber about the change with emit property changed signal. */
    void setPropInt64Local(const nlohmann::json& input);
    /** A local value for propInt64 */
    QList<qint64> m_propInt64;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(const nlohmann::json& input);
    /** A local value for propFloat */
    QList<qreal> m_propFloat;
    /**  Updates local value for PropFloat32 and informs subscriber about the change with emit property changed signal. */
    void setPropFloat32Local(const nlohmann::json& input);
    /** A local value for propFloat32 */
    QList<float> m_propFloat32;
    /**  Updates local value for PropFloat64 and informs subscriber about the change with emit property changed signal. */
    void setPropFloat64Local(const nlohmann::json& input);
    /** A local value for propFloat64 */
    QList<double> m_propFloat64;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const nlohmann::json& input);
    /** A local value for propString */
    QList<QString> m_propString;
    /**  Updates local value for PropReadOnlyString and informs subscriber about the change with emit property changed signal. */
    void setPropReadOnlyStringLocal(const nlohmann::json& input);
    /** A local value for propReadOnlyString */
    QString m_propReadOnlyString;

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);
    // Helper function for handling subsbscriptions
    void handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed);

    /** An indicator if the object has fisnished initialization. */
    bool m_finishedInitialization;
    /** 
    * An abstraction layer over the connection with service for the MqttSimpleArrayInterface.
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
    /* Storage for tracking pending subscriptions */
    std::vector<QString> m_pendingSubscriptions;
};

} //namespace tb_simple

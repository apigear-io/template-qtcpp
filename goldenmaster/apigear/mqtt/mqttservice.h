/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#pragma once

#include <QtCore>

#include <QtCore>
#include <QMultiMap>
#include <QtMqtt>
#include <nlohmann/json.hpp>

#include "mqtt_common.h"
#include "payloadconverter.h"

namespace ApiGear {
namespace Mqtt {


/**
* An MQTT client wrapper that helps using an MQTT client with interfaces as services.
* Uses the MQTT version 5. It handles the connection and MQTT protocol.
* This class can serve many API objects.
*/

class APIGEAR_MQTT_EXPORT ServiceAdapter : public QObject {
    Q_OBJECT
public:

    /**
    * ctor
    * @param id. A unique id in the used broker
    */
    ServiceAdapter(QString id, QObject *parent= nullptr);

    /** dtor */
    virtual ~ServiceAdapter();

    // An alias for callback, necessary for signals/slots, which don't handle well function parameters with "const". 
    using SimpleSubscribeCallback = std::function<void(const nlohmann::json&)>;
    // An alias for callback, necessary for signals/slots, which don't handle well function parameters with "const". 
    using InvokeSubscribeCallback =  std::function<nlohmann::json(const nlohmann::json&)>;
public slots:
    // Internal handler for internal messageToWriteWithProperties signal emitted during handling invoke requests.
    void writeMessageWithProperties(const QMqttTopicName& topic, const QByteArray& message, const QMqttPublishProperties &properties);
    // Internal handler for internal messageToWrite signal emitted by emitPropertyChange or emitSignalChange.
    void writeMessage(const QMqttTopicName& topic, const QByteArray& message, bool retain);
    // Internal handler for internal subscribeTopicSignal signal, emitted by  subscribeTopic method.
    void onSubscribeTopic(quint64 id, const QString &topic, SimpleSubscribeCallback callback);
    // Internal handler of subscribeForInvokeTopicSignal signal, emitted by subscribeForInvokeTopic method.
    void onSubscribeForInvokeTopic(quint64 id, const QString &topic, InvokeSubscribeCallback callback);
    // Internal handler for an unsubscribeTopic signal.
    void onUnsubscribeTopic(quint64 id);
signals:
    /**
    * Signal emitted when this client is connected and ready to send or receive messages.
    */
    void ready();
    // Internal signal for publishing messages. Used to allow multi thread safe use.
    void messageToWriteWithProperties(const QMqttTopicName& topic, const QByteArray& message, const QMqttPublishProperties &properties);
    // Internal signal for publishing messages. Used to allow multi thread safe use.
    void messageToWrite(const QMqttTopicName& topic, const QByteArray& message, bool retain);
    // Internal signal emitted by subscribeTopic. Used to allow multi thread safe use.
    void subscribeTopicSignal(quint64 id, const QString &topic, SimpleSubscribeCallback callback);
    // Internal signal emitted by subscribeForInvokeTopic. Used to allow multi thread safe use.
    void subscribeForInvokeTopicSignal(quint64 id, const QString &topic, InvokeSubscribeCallback callback);
    /**
    * Unsubscribes the callback from a topic, and the topic if there is no more callbacks subscribed to it.
    * @param id. A subscription id of a subscribed callback for a topic.
    */
    void unsubscribeTopic(quint64 subscriptionId);

public:
    /**
    * Use to check if this object is ready to use with interface service adapters.
    * @return true if this client is connected and ready to send or receive messages, false otherwise.
    */
    bool isReady() const;
    /**
    * Id with which this object is registered within the MQTT network.
    * @return the Id of this client.
    */
    const QString& clientId() const;
    /**
    * Connects to MQTT host.
    * @param hostAddress an address of the host.
    * @port port on the host address, usually for MQTT it is 1883.
    */
    void connectToHost(QString hostAddress, int port);
    /**
    * Disconnects.
    * WARNING It doesn't unsubscribe topics. If you don't plan to re-connect please unsbuscibe by hand, or get rid of this object.
    */
    void disconnect();

    /**
    * Subscribes for receiving topic and provides a callback to be executed on receiving topic.
    * May subscribe many callbacks for same topic, all of subscribed callbacks will be executed on receiving the message.
    * @param topic. Topic of message to subscribe.
    * @param callback. A function to be executed on receiving the message with given topic
    * NOTE Remember to unsubscribe the callback with an id given here as a parameter.
    * WARNING make sure that client is already connected.
    */
    quint64 subscribeTopic(const QString &topic, SimpleSubscribeCallback callback);
    /** 
    * Subscribes for receiving topic and provides a callback to be executed on receiving topic.
    * May subscribe many callbacks for same topic, all of subscribed callbacks will be executed on receiving the message.
    * @param topic.Topic of message to subscribe.
    * @param callback.A function to be executed on receiving the message with given topic
    * @return an Id for this subscription. Remember to unsubscribe the callback with this id.
    * WARNING make sure that client is already connected.
    */
    quint64 subscribeForInvokeTopic(const QString &topic, InvokeSubscribeCallback callback);

    /**
    * Publishes message, use when property of your interface changes.
    * @param topic for property change, consists of objectName, "prop" keyword and a property name.
    * @param value. The value to which property was changed.
    */
    void emitPropertyChange(const QMqttTopicName& topic, const nlohmann::json& value);
    /**
    * Publishes message, use your interface 
    * @param topic for property change, consists of the objectName, "sig" keyword and a signal name.
    * @param arguments. Arguments with which signal was emitted.
    */
    void emitSignalChange(const QMqttTopicName& topic, const nlohmann::json& arguments);

private:
    /**
    * Helper function for handling invoke requests from network.
    * @param message. Raw QMqttMessage.
    */
    void handleInvoke(const QMqttMessage& message);
    /**The basic implementation of a mqqtt client, which gets adapted to expose interface as a service.*/
    QMqttClient m_client;
    /** Storage for subscribed topics for signals and property changes with their callbacks and subscription identifiers.*/
    QMultiMap<QMqttTopicFilter, std::pair<quint64, SimpleSubscribeCallback>> m_subscriptions;
    /** Storage for subscribed topics for method invocation requests with their callbacks and subscription identifiers.*/
    QMultiMap<QMqttTopicFilter, std::pair<quint64, InvokeSubscribeCallback>> m_invokeSubscriptions;
    /** Object used to generate ids for subscriptions.*/
    UniqueIdGenerator subscriptionIdGenerator;
};


}} // namespace ApiGear::Mqtt

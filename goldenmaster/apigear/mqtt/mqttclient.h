#pragma once

#include <QtCore>
#include <QMultiMap>
#include <QtMqtt>

#include "mqtt_common.h"
#include <nlohmann/json.hpp>
#include "payloadconverter.h"

#include <memory>
namespace ApiGear {
namespace Mqtt {

/**
 * The class adapts mqtt to be used by the API GEAR objects,
 * The class uses QMqttClient set to use version 5 of protocol.
 * It handles the connection and mqtt protocol.
 * This class can serve many API objects.
*/
class APIGEAR_MQTT_EXPORT Client : public QObject {
    Q_OBJECT

public:

    /**
    * ctor
    * @param id. A unique id in the used broker
    */
    Client(QString id, QObject *parent= nullptr);

    /** dtor */
    virtual ~Client() override = default;
    // An alias for callback, necessary for signals/slots, which don't handle well function parameters with "const". 
    using subscribeCallback = std::function<void(const nlohmann::json&)>;
    // An alias for callback, necessary for signals/slots, which don't handle well function parameters with "const".
    using invokeReplyCallback = std::function<void(const nlohmann::json&, quint64)>;
public slots:
    // Internal handler for internal messageToWriteWithProperties signal emitted during invoke requests.
    void writeMessageWithProperties(const QMqttTopicName& topic, const QByteArray& message, const QMqttPublishProperties &properties);
    // Internal handler for internal messageToWrite signal emitted by setRemoteProperty.
    void writeMessage(const QMqttTopicName& topic, const QByteArray& message);
    // Internal handler for internal subscribeTopicSignal signal, emitted by  subscribeTopic method.
    void onSubscribeTopic(quint64 id, const QString &topic, subscribeCallback callback);
    // Internal handler of subscribeForInvokeResponseSignal signal, emitted by subscribeForInvokeResponse method.
    void onSubscribeForInvokeResponse(quint64 id, const QString &topic, invokeReplyCallback callback);
    // Internal handler for an unsubscribeTopic signal.
    void onUnsubscribedTopic(quint64 subscriptionId);

signals:
    /**
    * Signal emitted when this client is connected and ready to send or receive messages.
    */
    void ready();
    /**
    * Signal emitted when this client has disconnected.
    */
    void disconnected();
    // Internal signal for publishing messages. Used to allow multi thread safe use.
    void messageToWriteWithProperties(const QMqttTopicName& topic, const QByteArray& message, const QMqttPublishProperties &properties);
    // Internal signal for publishing messages. Used to allow multi thread safe use.
    void messageToWrite(const QMqttTopicName& topic, const QByteArray& message);
    // Internal signal emitted by subscribeTopic. Used to allow multi thread safe use.
    void subscribeTopicSignal(quint64 id, const QString &topic, subscribeCallback callback);
    // Internal signal emitted by subscribeForInvokeTopic. Used to allow multi thread safe use.
    void subscribeForInvokeResponseSignal(quint64 id, const QString &topic, invokeReplyCallback callback);
    /**
    * Unsubscribes the callback from a topic, and the topic if there is no more callbacks subscribed to it.
    * @param id. A subscription id of a subscribed callback for a topic.
    */
    void unsubscribeTopic(quint64 subscriptionId);
public:
    /**
    * Use to check if this object is ready to use with interface client adapters.
    * @return true if this client is connected and ready to send or receive messages, false otherwise.
    */
    bool isReady() const;
    /**
    * Id with which this object is registered within the MQTT network.
    * @return the Id of this client.
    */
    QString clientId() const;    
    /**
    * Connects to MQTT host.
    * @param hostAddress an address of the host.
    * @port port on the host address, usually for MQTT it is 1883.
    */
    void connectToHost(QString hostAddress,int port);

    /**
    * Subscribes for receiving topic and provides a callback to be executed on receiving topic.
    * May subscribe many callbacks for same topic, all of subscribed callbacks will be executed on receiving the message.
    * @param topic. Topic of message to subscribe.
    * @param callback. A function to be executed on receiving the message with given topic
    * NOTE Remember to unsubscribe the callback with an id given here as a parameter.
    * WARNING make sure that client is already connected.
    */
    quint64 subscribeTopic(const QString &topic, subscribeCallback callback);
    /**
    * Subscribes for receiving topic and provides a callback to be executed on receiving topic.
    * May subscribe many callbacks for same topic, all of subscribed callbacks will be executed on receiving the message.
    * @param topic.Topic of message to subscribe.
    * @param callback.A function to be executed on receiving the message with given topic
    * @return an Id for this subscription. Remember to unsubscribe the callback with this id.
    * WARNING make sure that client is already connected.
    */
    quint64 subscribeForInvokeResponse(const QString &topic, invokeReplyCallback callback);

    /**
    * Publishes message, use requesting for a property of your interface to change.
    * @param topic for property change, consists of interfaceName, "set" keyword and a property name.
    * @param value. The value to which property change is requested.
    */
    void setRemoteProperty(const QMqttTopicName& topic, const nlohmann::json& value);

    /**
    * Publishes message, with request of invoking a function.
    * @param topic for invoke request, consists of interfaceName, "rpc" keyword and a method name.
    * @param arguments for invoke request.
    * @param responseTopic for property change, consists of interfaceName, "rpc" keyword method name, clientId and "response" keyword.
    * @return callId an Id of remote call request. When response will be available a callback will be called with this callId.
    */
    quint64 invokeRemote(const QMqttTopicName& topic, const nlohmann::json& arguments, const QString& responseTopic);

    /**
    * Disconnects.
    * WARNING It doesn't unsubscribe topics. If you don't plan to re-connect please unsbuscibe by hand, or get rid of this object.
    */
    void disconnect();

private:
    /**
    * Helper function for handling invoke changes of client state.
    * @param state. A Mqtt client state.
    */
    void handleClientStateChanged(QMqttClient::ClientState state);
    // Helper function for unsubscribing all subscriptions
    void unsubscribeAll();
    /**The basic implementation of a Mqtt client, which gets adapted to expose interface as a service.*/
    QMqttClient m_client;
    /** Storage for subscribed topics for signals and property changes with their callbacks and subscription identifiers.*/
    QMultiMap<QMqttTopicFilter, std::pair<quint64, subscribeCallback>> m_subscriptions;
    /** All invoke responses topic subscriptions and ids for them, stored by the topic*/
    QMultiMap<QMqttTopicFilter, std::pair<quint64, invokeReplyCallback>> m_invokeReplySubscriptions;
    /** Object used to generate ids subscriptions.*/
    UniqueIdGenerator subscriptionIdGenerator;
    /** Object used to generate ids for awaited method invocation responses callbacks.*/
    UniqueIdGenerator functionCallIdGenerator;
};

}} // namespace ApiGear::Mqtt

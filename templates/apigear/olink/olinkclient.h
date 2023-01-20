#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/consolelogger.h"
#include "olink_common.h"

#include <memory>
namespace ApiGear {
namespace ObjectLink {

class ClientRegistry;
class ClientNode;
class IObjectSink;

/**
* A class responsible for network connection for ObjectLink client side. Creates a socket
* connects it with Client Node - an abstract connection endpoint used by object sink.
* Handles linking and unlinking with remote service for the sink with regard to the connection state.
*/
class OLINKQT_EXPORT OLinkClient : public QObject {
    Q_OBJECT
public:

    /**
    * ctor
    * @param registry. A global client registry to which the client node and sink object are added.
    * Remark: the registered objects must provide unique identifiers
    */
    OLinkClient(ClientRegistry& registry, QObject *parent= nullptr);

    /** dtor */
    virtual ~OLinkClient() override;

public slots:
    /**
     * Handler for opening the connection.
     */
    void onConnected();
    /**
     * Handler for closing the connection.
     */
    void onDisconnected();
    /**
    * Handler for messages received form websocket.
    * @param msg A raw message to handle.
    */
    void handleTextMessage(const QString& message);
    /**
     * @brief Writes message into socket.
     * @param message. A message to write to socket.
     */
    void writeMessage(const QString& message);
signals:
    /**
     * Internal signal to inform this class that there is a message to write into socket (to make sure write happens in the thread socket lives in.)
     * @param message A message to write to socket.
     */
    void messageToWrite(const QString& message);
public:
    /**
    * Use this function to set up a connection to server.
    * Automatically links all the sinks that requested linking with the remote sources when connection is established.
    * @param url the server url.
    */
    void connectToHost(QUrl url=QUrl());
    /**
    * Use this function to close connection with server.
    * Automatically unlinks all the sinks that are using its connection.
    */
    void disconnect();

    ClientRegistry &registry();

    /**
    * Get underlaying client node.
    * @retunr a client node for which this OlinkConnection sets up the connection.
    */
    ClientNode* node();

    /**
    *  Use this function to setup linkage with the service object on the server side.
    * After successful linking the IObjectSink will receive confirmation from service with olinkOnInit handler call.
    * @param object An olink sink object which will be associated with network endpoint and for which linking with service object will be requested.
    */
    void linkObjectSource(std::weak_ptr<IObjectSink> objectSink);
    /**
     * Use this function to request unlinking with service object on the server side.
    * @param object An objectId no longer interested of using the service.
    */
    void unlinkObjectSource(std::string objectId);

    /** Tries to send queued messages */
    void processMessages();

    /** Returns the state of the websocket connection */
    QAbstractSocket::SocketState getConnectionState();
private:
    /** Status of a link for an object. */
    enum class LinkStatus
    {
        Linked,
        NotLinked
    };
    /** Keeps track of the objectIds served by this client with their current link status. */
    std::map<std::string, LinkStatus> m_objectLinkStatus;

    /** A global client registry, used by this Client, to which a client node and a sink object are added. */
    ClientRegistry& m_registry;
    /** The websocket used for connection.*/
    QWebSocket* m_socket;
    /** Client node that separates sinks Objects from created socket, and handles incoming and outgoing messages. */
    std::shared_ptr<ClientNode> m_node;
    /** Messages queue, store messages to send also before the connection is set. */
    QQueue<QString>  m_queue;
    /** Logger */
    ConsoleLogger m_logger;
    /** The server url to which socket connects. */
    QUrl m_serverUrl;
    /** The timer used for to retry connection if it failed. */
    QTimer* m_retryTimer;
};

}} // namespace ApiGear::ObjectLink

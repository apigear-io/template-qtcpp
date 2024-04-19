#pragma once

#include "olinkclientimpl.h"

#include "olink/consolelogger.h"
#include "olink_common.h"

#include <QThread>
#include <QtWebSockets>
#include <memory>
#include <chrono>


namespace ApiGear {
namespace ObjectLink {

class ClientRegistry;
class ClientNode;
class IObjectSink;

/**
 * Helper class for  OLinkClient, which should live in a separate thread.
 * Implements responsibility of OLinkClient.
*/
class OLinkClientImpl : public QObject {
    Q_OBJECT
public:

    /**
    * ctor
    * @param registry. A global client registry to which the client node and sink object are added.
    * Remark: the registered objects must provide unique identifiers
    */
    OLinkClientImpl(ClientRegistry& registry, QObject *parent= nullptr);

    /** dtor */
    virtual ~OLinkClientImpl() override;

private slots:
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

public slots:
    /**
    * WARNING This function needs to be called after this object is moved to separate theread.
    * It makes instances of a classes, which will be created in a thread from which the function is called.
    * This object cannot be used before init call.
    */
    void init();
    /**
    *  Implements the linking of an object
    * @param object An olink sink object to link.
    */
    void linkObjectSource(std::weak_ptr<IObjectSink> objectSink);
    /**
     * Implements unlinking from the service object on the server side.
    * @param object An objectId no longer interested of using the service.
    */
    void unlinkObjectSource(std::string objectId);
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

    /**
    *  Closes the socket and handles closing all stored objects;
    *  The object should not be used after the tearDown call().
    */
    void tearDown();

signals:
    /**
     * Internal signal to inform this class that there is a message to write into socket (to make sure write happens in the thread socket lives in.)
     * @param message A message to write to socket.
     */
    void messageToWrite(const QString& message);
    /**
     * Signal to inform about connection state changes.
     * @param status current status of a connection.
     */
    void connectionStatusChanged(QAbstractSocket::SocketState status);
public:


    /**
    * Get underlaying client node.
    * @retunr a client node for which this OlinkConnection sets up the connection.
    */
    ClientNode* node();

    /** Tries to send queued messages */
    void processMessages();

    /**
    * Informs if tearDown is already finished.
    * @retunr true if socket is closed after tearDown().
    */
    bool isFinished();
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
    QWebSocket* m_socket = nullptr;
    /** Client node that separates sinks Objects from created socket, and handles incoming and outgoing messages. */
    std::shared_ptr<ClientNode> m_node;
    /** Messages queue, store messages to send also before the connection is set. */
    QQueue<QString>  m_queue;
    /** Logger */
    ConsoleLogger m_logger;
    /** The server url to which socket connects. */
    QUrl m_serverUrl;
    /** The timer used for to retry connection if it failed. */
    QTimer* m_retryTimer = nullptr;

    /* A flag set to true after tearDown() cleand up all the resources. */
    bool m_isFinished = false;
};

}}//namepsace

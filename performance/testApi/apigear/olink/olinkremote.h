#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/consolelogger.h"
#include "olink_common.h"

#include <memory>

namespace ApiGear {
namespace ObjectLink {

class RemoteRegistry;
class RemoteNode;

/**
* Helper class to handle new server connection.
* Connects websocket with Remote Node - an abstract connection endpoint used by object source.
* It receives messages for given websocket and allows writing messages to it.
*/
class OLINKQT_EXPORT OLinkRemote : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param socket A socket used for this connection.
    * @param registry. A global registry to which network endpoints are added for linked objects.
    */
    explicit OLinkRemote(RemoteRegistry& registry, QWebSocket* socket);
    /**
    * Handler for messages received form websocket.
    * @param msg A raw message to handle.
    */
    void handleMessage(const QString& msg);
signals:
    /**
     * Internal signal to inform this class that there is a message to write into socket (to make sure write happens in the thread socket lives in.)
     * @param message A message to write to socket.
     */
    void messageToWrite(const QString& message);
public slots:
    /**
     * @brief Writes message into socket.
     * @param message. A message to write to socket.
     */
    void writeMessage(const QString& message);
    /**
     * Handler for closing the connection.
     */
    void socketDisconnected();
private:
    /** A socket used for this connection. */
    QWebSocket* m_socket;
    /**
    *   An abstract connection endpoint for services, network implementation independent.
    *   may serve several services associated with this node by the unique objectId given in link message.
    */
    std::shared_ptr<RemoteNode> m_node;
    /** Logger*/
    ConsoleLogger m_log;
    /** A global registry to which network endpoints are added for linked objects. */
    RemoteRegistry& m_registry;

};

}} // namespace ApiGear::ObjectLink

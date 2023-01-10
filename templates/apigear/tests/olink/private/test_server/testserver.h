#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <string>
#include <QString>
#include <memory>
#include <QWebSocket>
#include <QWebSocketServer>

class MessageStorage;

/**
 * A test server that stores only one, most recent incoming connection.
 * Should be used only from single thread.
 */
class TestServer
{
public:
    /** ctor
     *  @param storage A storage in which incoming message will be stored.
     *         Make sure that storage lifetime is longer than the lifetime of instance of this class.
     */
    explicit TestServer(MessageStorage& storage);

    /** Starts the server */
    void listen(const QString& host, int port);

    /** Writes message to a socket if the connection is on */
    void writeMessage(const std::string msg);

    /** Handler for new incoming connection, which will overwrite the older one */
    void onNewConnection();
    /** @retrun true if the connection is in connected state and false in all other cases. */
    bool isSocketConnected();
    /** Closes the socket of current connection */
    void closeSocket();

private:
    /** Socket for most recent connection */
    std::unique_ptr<QWebSocket> m_socket;
    /** Web Socket Server*/
    std::unique_ptr<QWebSocketServer> m_wss;
    /** Storage for the incoming messages */
    MessageStorage& m_storage;
};

#endif // TESTSERVER_H

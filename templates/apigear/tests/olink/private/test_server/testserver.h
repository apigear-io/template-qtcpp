#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <string>
#include <QString>
#include <memory>
#include <QWebSocket>
#include <QWebSocketServer>

class MessageStorage;

class TestServer
{
public:
    explicit TestServer(MessageStorage& storage);

    void listen(const QString& host, int port);
    void onNewConnection();
    bool isSocketConnected();

    const QString &name() const;

    void writeMessage(const std::string msg);
    void handleMessage(const QString& msg);
    void closeSocket();

private:
    std::unique_ptr<QWebSocket> m_socket;
    std::unique_ptr<QWebSocketServer> m_wss;
    MessageStorage& m_storage;
};

#endif // TESTSERVER_H

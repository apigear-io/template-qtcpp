#include "testserver.h"
#include "private/messagestorage.h"
#include <QTest>

TestServer::TestServer(MessageStorage& storage)
    : m_wss(new QWebSocketServer("olink", QWebSocketServer::NonSecureMode))
    , m_storage(storage)
{
}

void TestServer::listen(const QString& host, int port)
{
    qDebug() << "wss.listen()";
    m_wss->listen(QHostAddress(host), quint16(port));
    qDebug() << m_wss->serverAddress() << m_wss->serverPort();
    m_wss->connect(m_wss.get(), &QWebSocketServer::newConnection, [this](){onNewConnection();});
}

void TestServer::onNewConnection()
{
    m_socket = std::unique_ptr<QWebSocket>(m_wss->nextPendingConnection());
    m_socket->connect(m_socket.get(), &QWebSocket::textMessageReceived, [this](const auto& message){ m_storage.receiveMessage(message);});
}

bool TestServer::isSocketConnected()
{
    return m_socket && m_socket->state() == QAbstractSocket::ConnectedState;
}

void TestServer::writeMessage(const std::string msg)
{
    m_socket->sendTextMessage(QString::fromStdString(msg));
    QTest::qWait(100);
}

void TestServer::closeSocket()
{
    if (m_socket)
    {
        m_socket->close();
        (void) QTest::qWaitFor([this](){return m_socket->state() == QAbstractSocket::UnconnectedState;}, 100); // ignore result
    }
}

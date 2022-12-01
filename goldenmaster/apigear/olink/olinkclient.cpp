#include "olinkclient.h"
#include "olink_common.h"

using namespace ApiGear::ObjectLink;

OLinkClient::OLinkClient(ClientRegistry& registry, QObject* parent)
    : QObject(parent)
    , m_socket(new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this))
    , m_retryTimer(new QTimer(this))
    , m_node(registry)
    , m_registry(registry)
{
    qDebug() << Q_FUNC_INFO;
    m_node.onLog(m_logger.logFunc());
    m_registry.onLog(m_logger.logFunc());
    connect(m_socket, &QWebSocket::connected, this, &OLinkClient::onConnected);
    connect(m_socket, &QWebSocket::disconnected, this, &OLinkClient::onDisconnected);
    connect(m_socket, &QWebSocket::textMessageReceived, this, &OLinkClient::handleTextMessage);
    WriteMessageFunc func = [this](std::string msg) {
        m_queue << msg;
        processMessages();
    };
    m_node.onWrite(func);

    // socket connection retry
    m_retryTimer->setInterval(5000);

    processMessages();
}

OLinkClient::~OLinkClient()
{
}


void OLinkClient::connectToHost(QUrl url)
{
    qDebug() << Q_FUNC_INFO << url;
    if (url.isEmpty()) {
        QString serverUrl = qEnvironmentVariable("OLINK_SERVER", "ws://127.0.0.1:8182");
        m_serverUrl = QUrl(serverUrl);
    }
    else {
        m_serverUrl = url;
    }
    m_socket->open(m_serverUrl);
}

ClientRegistry& OLinkClient::registry()
{
    return m_node.registry();
}

ClientNode& OLinkClient::node()
{
    return m_node;
}

void OLinkClient::linkObjectSource(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node.registry().linkClientNode(name, &m_node);
    m_node.linkRemote(name);
}

void OLinkClient::onConnected()
{
    qDebug() << Q_FUNC_INFO << " socket connected";
    // m_node->hello();
    m_retryTimer->stop();
    processMessages();
}

void OLinkClient::onDisconnected()
{
    qDebug() << Q_FUNC_INFO << " socket disconnected";
    // m_node->goodbye();
}

void OLinkClient::handleTextMessage(const QString& message)
{
    m_node.handleMessage(message.toStdString());
}

void OLinkClient::processMessages()
{
    qDebug() << Q_FUNC_INFO;
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        m_retryTimer->stop();
    }
    else if (m_retryTimer->isActive()) {
        return;
    }
    qDebug() << "001";
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->open(m_serverUrl);
        m_retryTimer->start();
    }
    qDebug() << "002";
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "002.1";
        while (!m_queue.isEmpty()) {
            qDebug() << "003";
            // if we are using JSON we need to use txt message
            // otherwise binary messages
            //    m_socket->sendBinaryMessage(QByteArray::fromStdString(message));
            const QString& msg = QString::fromStdString(m_queue.dequeue());
            qDebug() << "write message to socket" << msg;
            m_socket->sendTextMessage(msg);
        }
    }
}
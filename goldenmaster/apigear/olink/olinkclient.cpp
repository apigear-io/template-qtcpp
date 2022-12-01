#include "olinkclient.h"
#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
#include <memory>

using namespace ApiGear::ObjectLink;

OLinkClient::OLinkClient(ClientRegistry& registry, QObject* parent)
    : QObject(parent)
    , m_registry(registry)
    , m_socket(new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this))
    , m_node(ClientNode::create(registry))
    , m_retryTimer(new QTimer(this))
{
    qDebug() << Q_FUNC_INFO;
    m_node->onLog(m_logger.logFunc());
    m_registry.onLog(m_logger.logFunc());
    connect(m_socket, &QWebSocket::connected, this, &OLinkClient::onConnected);
    connect(m_socket, &QWebSocket::disconnected, this, &OLinkClient::onDisconnected);
    connect(m_socket, &QWebSocket::textMessageReceived, this, &OLinkClient::handleTextMessage);
    WriteMessageFunc func = [this](std::string msg) {
        m_queue << msg;
        processMessages();
    };
    m_node->onWrite(func);

    // socket connection retry
    m_retryTimer->setInterval(5000);

    processMessages();
}

OLinkClient::~OLinkClient()
{
    auto copyObjectLinkStatus = m_objectLinkStatus;
    for (auto& object : copyObjectLinkStatus){
        unlinkObjectSource(object.first);
    }
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

void OLinkClient::disconnect()
{
    for (auto& object : m_objectLinkStatus){
        if (object.second != LinkStatus::NotLinked){
            m_node->unlinkRemote(object.first);
        }
    }
    m_socket->close();
}

ClientRegistry& OLinkClient::registry()
{
    return m_registry;
}

ClientNode* OLinkClient::node()
{
    return m_node.get();
}

void OLinkClient::linkObjectSource(std::weak_ptr<IObjectSink> objectSink)
{
    auto objectSinkLocked = objectSink.lock();
    if (!objectSinkLocked)
    {
        qDebug() << Q_FUNC_INFO << "Invalid object sink. Sink not linked.";
        return;
    }
    auto name = objectSinkLocked->olinkObjectName();
    m_node->registry().addSink(objectSink);

    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    if (m_socket && m_socket->state() == QAbstractSocket::ConnectedState){
        m_node->linkRemote(name);
        m_objectLinkStatus[name] = LinkStatus::Linked;
    }
    else
    {
        m_objectLinkStatus[name] = LinkStatus::NotLinked;
    }
}

void OLinkClient::unlinkObjectSource(std::string objectId)
{
    auto objectStatus = m_objectLinkStatus.find(objectId);
    if (objectStatus != m_objectLinkStatus.end()) {
        if (objectStatus->second != LinkStatus::NotLinked){
            m_node->unlinkRemote(objectId);
        }
        m_objectLinkStatus.erase(objectStatus);
    }
    m_node->registry().removeSink(objectId);
}

void OLinkClient::onConnected()
{
    qDebug() << Q_FUNC_INFO << " socket connected";
    m_retryTimer->stop();
    for (auto& object : m_objectLinkStatus)
    {
        m_node->linkRemote(object.first);
        object.second = LinkStatus::Linked;
    }
    processMessages();
}

void OLinkClient::onDisconnected()
{
    for (auto& object : m_objectLinkStatus)
    {
        object.second = LinkStatus::NotLinked;
    }
    qDebug() << Q_FUNC_INFO << " socket disconnected";
}

void OLinkClient::handleTextMessage(const QString& message)
{
    m_node->handleMessage(message.toStdString());
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




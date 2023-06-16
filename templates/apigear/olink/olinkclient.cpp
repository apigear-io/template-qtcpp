#include "olinkclient.h"
#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
#include "../utilities/logger.h"
#include <memory>

using namespace ApiGear::ObjectLink;

OLinkClient::OLinkClient(ClientRegistry& registry, QObject* parent)
    : QObject(parent)
    , m_registry(registry)
    , m_socket(new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this))
    , m_node(ClientNode::create(registry))
    , m_retryTimer(new QTimer(this))
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    m_node->onLog(m_logger.logFunc());
    m_registry.onLog(m_logger.logFunc());
    connect(m_socket, &QWebSocket::connected, this, &OLinkClient::onConnected);
    connect(m_socket, &QWebSocket::disconnected, this, &OLinkClient::onDisconnected);
    connect(m_socket, &QWebSocket::textMessageReceived, this, &OLinkClient::handleTextMessage);
    connect(this, &OLinkClient::messageToWrite, this, &OLinkClient::writeMessage);

    m_node->onWrite([this](std::string msg){messageToWrite(QString::fromStdString(msg));});

    // Socket connection retry was chosen for 1sec.
    m_retryTimer->setInterval(1000);

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
    AG_LOG_INFO(Q_FUNC_INFO + url.host().toStdString() + ":" + std::to_string(url.port()));
    if (url.isEmpty()) {
        QString serverUrl = qEnvironmentVariable("OLINK_SERVER", "ws://127.0.0.1:8182/ws");
        m_serverUrl = QUrl(serverUrl);
    }
    else {
        m_serverUrl = url;
    }
    m_socket->open(m_serverUrl);
}

void OLinkClient::disconnect()
{
    for (const auto& object : m_objectLinkStatus){
        if (object.second != LinkStatus::NotLinked){
            m_node->unlinkRemote(object.first);
        }
    }
    m_socket->close();
}

void OLinkClient::writeMessage(const QString& msg) {
    m_queue.push_back(msg);
    processMessages();
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
        AG_LOG_WARNING(Q_FUNC_INFO +  std::string(" Invalid object sink. Sink not linked."));
        return;
    }
    auto name = objectSinkLocked->olinkObjectName();
    m_node->registry().addSink(objectSink);

    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(name);
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
    AG_LOG_INFO(Q_FUNC_INFO + std::string("socket connected ") + m_serverUrl.host().toStdString() + ":" + std::to_string(m_serverUrl.port()));
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
    AG_LOG_INFO(Q_FUNC_INFO + std::string(" socket disconnected"));
}

void OLinkClient::handleTextMessage(const QString& message)
{
    m_node->handleMessage(message.toStdString());
}

void OLinkClient::processMessages()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        m_retryTimer->stop();
    }
    else if (m_retryTimer->isActive()) {
        return;
    }
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->open(m_serverUrl);
        m_retryTimer->start();
    }
    if (m_socket->state() == QAbstractSocket::ConnectedState) {

        while (!m_queue.isEmpty()) {
            // text message should be used for JSON format, binary messages for others
            auto message = m_queue.front();
            auto sentBytes = m_socket->sendTextMessage(message);
            if (sentBytes != 0){
                static const std::string log_message = "write message to socket ";
                AG_LOG_DEBUG(log_message);
                AG_LOG_DEBUG(message);
                m_queue.pop_front();
            }
            else {
                if (!m_retryTimer->isActive()) {
                    m_retryTimer->start();
                }
                break;
            }
        }
    }
}

QAbstractSocket::SocketState OLinkClient::getConnectionState()
{
    return m_socket ? m_socket->state() : QAbstractSocket::UnconnectedState;
}




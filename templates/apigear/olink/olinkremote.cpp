#include "olinkremote.h"

#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
#include <memory>

#include"../utilities/logger.h"

using namespace ApiGear::ObjectLink;

OLinkRemote::OLinkRemote(RemoteRegistry& registry, QWebSocket* socket)
    : m_socket(socket)
    , m_node(RemoteNode::createRemoteNode(registry))
    , m_registry(registry)
{
    m_node->onLog(m_log.logFunc());
    connect(m_socket, &QWebSocket::textMessageReceived, this, &OLinkRemote::handleMessage);
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(this, &OLinkRemote::messageToWrite, this, &OLinkRemote::writeMessage);

    m_node->onWrite([this](std::string msg){messageToWrite(QString::fromStdString(msg));});
}

void OLinkRemote::writeMessage(const QString &msg)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(msg);
    if(m_socket) {
        m_socket->sendTextMessage(msg);
    }
}

void OLinkRemote::handleMessage(const QString &msg)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(msg);
    m_node->handleMessage(msg.toStdString());
}

void OLinkRemote::socketDisconnected()
{
    AG_LOG_INFO("Client disconnected, connection closed");
    this->deleteLater();
}

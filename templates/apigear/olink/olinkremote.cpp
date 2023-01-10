#include "olinkremote.h"

#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
#include <memory>

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
    qDebug() << Q_FUNC_INFO << msg;
    if(m_socket) {
        m_socket->sendTextMessage(msg);
    }
}

void OLinkRemote::handleMessage(const QString &msg)
{
    qDebug() << Q_FUNC_INFO << msg;

    m_node->handleMessage(msg.toStdString());
}

void OLinkRemote::socketDisconnected()
{
    qDebug() << "Client disconnected, connection closed";
    auto objectsUsingNode = m_registry.getObjectIds(m_node);
    for (const auto objectId : objectsUsingNode)
    {
        m_registry.removeNodeFromSource(m_node, objectId);
    }
    this->deleteLater();
}

#include "olinkremote.h"

#include "olink/remotenode.h"
#include <memory>

using namespace ApiGear::ObjectLink;

OLinkRemote::OLinkRemote(RemoteRegistry& registry, QWebSocket* socket)
    : m_socket(socket)
    , m_node(registry)
    , m_registry(registry)
{
    m_node.onLog(m_log.logFunc());
    connect(m_socket, &QWebSocket::textMessageReceived, this, &OLinkRemote::handleMessage);
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    WriteMessageFunc writeFunc = [this](std::string msg) {
        writeMessage(msg);
    };
    m_node.onWrite(writeFunc);
}

void OLinkRemote::writeMessage(const std::string msg)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(msg);
    if(m_socket) {
        m_socket->sendTextMessage(QString::fromStdString(msg));
    }
}

void OLinkRemote::handleMessage(const QString &msg)
{
    qDebug() << Q_FUNC_INFO << msg;

    m_node.handleMessage(msg.toStdString());
}

void OLinkRemote::socketDisconnected()
{
    qDebug() << "Client disconnected, connection closed";
    this->deleteLater();
}
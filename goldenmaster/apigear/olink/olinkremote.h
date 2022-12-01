#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/consolelogger.h"
#include "olink_common.h"
#include "olink/remotenode.h"
#include <memory>

namespace ApiGear {
namespace ObjectLink {

class RemoteRegistry;

class OLINKQT_EXPORT OLinkRemote : public QObject
{
    Q_OBJECT
public:
    explicit OLinkRemote(RemoteRegistry& registry, QWebSocket* socket);
    void writeMessage(const std::string msg);
    void handleMessage(const QString& msg);
private:
    void socketDisconnected();
    QWebSocket* m_socket;
    RemoteNode m_node;
    ConsoleLogger m_log;
    RemoteRegistry& m_registry;
};

}} // namespace ApiGear::ObjectLink
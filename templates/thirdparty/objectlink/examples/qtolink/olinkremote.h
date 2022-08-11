#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/consolelogger.h"
#include "olink/remotenode.h"

using namespace ApiGear::ObjectLink;

class OLinkRemote : public QObject
{
    Q_OBJECT
public:
    explicit OLinkRemote(QWebSocket* socket);
    void writeMessage(const std::string msg);
    void handleMessage(const QString& msg);
private:
    QWebSocket* m_socket;
    RemoteNode m_node;
};

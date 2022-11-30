#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/clientnode.h"
#include "olink/consolelogger.h"

using namespace ApiGear::ObjectLink;

class OLinkClient : public QObject {
    Q_OBJECT
public:
    OLinkClient(QObject *parent= nullptr);
    virtual ~OLinkClient() override;
public:
    void connectToHost(QUrl url=QUrl());
    ClientRegistry &registry();
    ClientNode &node();
    std::string name() const;

    void linkObjectSource(std::string name);

    void onConnected();
    void onDisconnected();
    void handleTextMessage(const QString& message);
    void processMessages();
private:
    QWebSocket *m_socket;
    ClientNode m_node;
    QQueue<std::string> m_queue;
    ConsoleLogger m_logger;
    QUrl m_serverUrl;
    QTimer *m_retryTimer;
    ClientRegistry& m_registry;
};

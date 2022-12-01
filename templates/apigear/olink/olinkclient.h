#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/clientnode.h"
#include "olink/consolelogger.h"
#include "olink_common.h"

using namespace ApiGear::ObjectLink;

class OLINKQT_EXPORT OLinkClient : public QObject {
    Q_OBJECT
public:
    OLinkClient(ClientRegistry& registry, QObject* parent = nullptr);
    virtual ~OLinkClient() override;
public:
    void connectToHost(QUrl url = QUrl());
    ClientRegistry& registry();
    ClientNode& node();
    std::string name() const;

    void linkObjectSource(std::string name);

    void onConnected();
    void onDisconnected();
    void handleTextMessage(const QString& message);
    void processMessages();
private:
    QWebSocket* m_socket;
    ClientNode m_node;
    ClientRegistry& m_registry;
    QQueue<std::string> m_queue;
    ConsoleLogger m_logger;
    QUrl m_serverUrl;
    QTimer* m_retryTimer;
};

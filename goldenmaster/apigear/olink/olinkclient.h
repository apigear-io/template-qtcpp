#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink/consolelogger.h"
#include "olink_common.h" 

#include <memory>
namespace ApiGear {
namespace ObjectLink {

class ClientRegistry;
class ClientNode;
class IObjectSink;

class OLINKQT_EXPORT OLinkClient : public QObject {
    Q_OBJECT
public:
    OLinkClient(ClientRegistry& registry, QObject *parent= nullptr);
    virtual ~OLinkClient() override;
public:
    void connectToHost(QUrl url=QUrl());
    void disconnect();

    ClientRegistry &registry();
    ClientNode* node();
    std::string name() const;

    void linkObjectSource(std::weak_ptr<IObjectSink> objectSink);
    void unlinkObjectSource(std::string objectId);

    void onConnected();
    void onDisconnected();
    void handleTextMessage(const QString& message);
    void processMessages();
private:
    enum class LinkStatus
    {
        Linked,
        NotLinked
    };
    std::map<std::string, LinkStatus> m_objectLinkStatus;

    ClientRegistry& m_registry;
    QWebSocket* m_socket;
    std::shared_ptr<ClientNode> m_node;
    QQueue<std::string> m_queue;
    ConsoleLogger m_logger;
    QUrl m_serverUrl;
    QTimer* m_retryTimer;
};

}} // namespace ApiGear::ObjectLink

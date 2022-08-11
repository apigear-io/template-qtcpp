#pragma once

#include "wamp/types.h"
#include <QtCore>
#include <QtWebSockets>

#include "wamp/types.h"

using namespace ApiGear;

namespace ApiGear { namespace WAMP {
class Session;
} }


class WampClient : public QObject, public WAMP::IMessageWriter, public WAMP::ISessionListener, public WAMP::ILogger
{
    Q_OBJECT
public:
    explicit WampClient(QObject *parent = nullptr);
    virtual ~WampClient() override;
    static WampClient* instance();

    void onConnected();
    void handleTextMessage(const QString &message);

    void doCall(std::string procedure, WAMP::Arguments arguments, WAMP::ArgumentsKw argumentsKw, WAMP::ResponseFunc func);
    void doCall(std::string procedure, WAMP::Arguments arguments, WAMP::ArgumentsKw argumentsKw);
    void doSubscribe(std::string topic, WAMP::EventFunc func);
    void doUnSubscribe(std::string topic);

    void doRegister(std::string procedure, WAMP::ProcedureFunc func);
    void doPublish(std::string topic, WAMP::Arguments arguments, WAMP::ArgumentsKw argumentsKw) ;
    void doYield(WAMP::Id requestId, WAMP::Arguments arguments, WAMP::ArgumentsKw argumentsKw);

    void process();
    void doProcess();
    void send(const QString &messsage);

    // IMessageWriter interface
public:
    virtual void writeMessage(std::string message) override;

public: // ILogger Interface
    void info(std::string message) override;
    void debug(std::string message) override;
    void warning(std::string message) override;
    void error(std::string message) override;

    // ISessionListener interface
public:
    void onJoin() override;
    void onError(std::string error) override;
    void onEvent(std::string topic, WAMP::Arguments args, WAMP::ArgumentsKw kwargs) override;

public:
    static WampClient* s_instance;
    QQueue<QString> m_queue;
    QUrl m_serverUrl;
    QWebSocket *m_socket;
    QTimer *m_retryTimer;
    QTimer *m_delayTimer;
    bool m_loggingEnabled;

    QString m_realm;
    ApiGear::WAMP::Session *m_session;

};

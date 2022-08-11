#include "wampclient.h"
#include "wamp/session.h"

using namespace ApiGear::WAMP;

WampClient* WampClient::s_instance(nullptr);

WampClient::WampClient(QObject *parent)
    : QObject(parent)
    , m_socket(nullptr)
    , m_loggingEnabled(true)
    , m_session(new ApiGear::WAMP::Session(this, this, this, WAMP::MessageFormat::JSON))
{
    qDebug() << Q_FUNC_INFO;
    if(s_instance) {
        qFatal("WampClient can only be instantiated once");
    }

    QString serverUrl = qEnvironmentVariable("WAMP_SERVER", "ws://127.0.0.1:8080");
    m_serverUrl = QUrl(serverUrl);
    m_realm = qEnvironmentVariable("WAMP_REALM", "realm1");

    m_socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
    connect(m_socket, &QWebSocket::connected, this, &WampClient::onConnected);
    connect(m_socket, &QWebSocket::textMessageReceived, this, &WampClient::handleTextMessage);

    // socket connection retry
    m_retryTimer = new QTimer(this);
    m_retryTimer->setInterval(5000);
    // delay message sending to 
    m_delayTimer = new QTimer(this);
    m_delayTimer->setInterval(10);
    connect(m_delayTimer, &QTimer::timeout, this, &WampClient::doProcess);
    process();
}

WampClient::~WampClient()
{
    delete m_session;
}

WampClient *WampClient::instance()
{
    qDebug() << Q_FUNC_INFO;
    if(!s_instance) {
        s_instance = new WampClient(QCoreApplication::instance());
    }
    return s_instance;
}

/**
 * send session handshake when we are connected
 */
void WampClient::onConnected()
{
    m_session->init(m_realm.toStdString());
    process();
}

/**
 * handle incoming socket message and pass on to seesion for parsing.
 */
void WampClient::handleTextMessage(const QString &message)
{
    qDebug() << Q_FUNC_INFO;
    m_session->handleMessage(message.toStdString());
}

// client side functions

/**
 * call a procedure and func is called when result arrives
 */
void WampClient::doCall(std::string procedure, Arguments arguments, ArgumentsKw argumentsKw, ResponseFunc func)
{
    m_session->doCall(procedure, arguments, argumentsKw, func);
}

/**
 * call a procedure without handling the result
 */
void WampClient::doCall(std::string procedure, Arguments arguments, ArgumentsKw argumentsKw)
{
    ResponseFunc func = [](ResponseArg arg) {};
    m_session->doCall(procedure, arguments, argumentsKw, func);
}

/**
 * subscribe to a topic. On each event the func is called.
 */
void WampClient::doSubscribe(std::string topic, EventFunc func)
{
    m_session->doSubscribe(topic, func);
}

/**
 * unsubscribe from a topic
 */
void WampClient::doUnSubscribe(std::string topic)
{
    m_session->doUnsubscribe(topic);
}

// service side functions
/**
 * register a procedure with the gateway
 */
void WampClient::doRegister(std::string procedure, ProcedureFunc func)
{
    m_session->doRegister(procedure, func);
}

/**
 * publish a event to the gateway
 */
void WampClient::doPublish(std::string topic, Arguments arguments, ArgumentsKw argumentsKw) 
{
    m_session->doPublish(topic, arguments, argumentsKw);
}

/**
 * yield a result from a procedure call
 */
void WampClient::doYield(Id requestId, Arguments arguments, ArgumentsKw argumentsKw)
{
    m_session->doYield(requestId, arguments, argumentsKw);
}

// common functions

void WampClient::send(const QString &messsage)
{
    m_queue.enqueue(messsage);
    process();
}


void WampClient::writeMessage(std::string message)
{
    send(QString::fromStdString(message));
}


void WampClient::process()
{
    if(m_delayTimer->isActive()) {
        return;
    }
    m_delayTimer->start();
}

void WampClient::doProcess()
{
    qDebug() << Q_FUNC_INFO;
    m_delayTimer->stop();
    if (m_retryTimer->isActive()) {
        return;
    }
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        QNetworkRequest request(m_serverUrl);
        request.setRawHeader("Sec-WebSocket-Protocol", "wamp.2.json");
        m_socket->open(request);
        m_retryTimer->start();
    }
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        m_retryTimer->stop();
        return;
    }
    while (!m_queue.isEmpty()) {
        const QString& message = m_queue.dequeue();
        qDebug() << "send message" << message;
        m_socket->sendTextMessage(message);
    }
}


void WampClient::info(std::string message)
{
    if(m_loggingEnabled) {
        qInfo() << message.data();
    }
}

void WampClient::debug(std::string message)
{
    if(m_loggingEnabled) {
        qDebug() << message.data();
    }
}

void WampClient::warning(std::string message)
{
    if(m_loggingEnabled) {
        qWarning() << message.data();
    }
}

void WampClient::error(std::string message)
{
    if(m_loggingEnabled) {
        qWarning() << message.data();
    }
}

void WampClient::onError(std::string error)
{
    qDebug() << "onError" << QString::fromStdString(error);
}

void WampClient::onEvent(std::string topic, Arguments args, ArgumentsKw kwargs)
{
    qDebug() << "onEvent" << QString::fromStdString(topic);
}


void WampClient::onJoin()
{
    qDebug() << "onJoin";
}


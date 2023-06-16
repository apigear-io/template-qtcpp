#include "agentclient.h"
#include "../utilities/logger.h"
#include <QtNetwork>

using namespace ApiGear::Monitor;

AgentClient* AgentClient::s_instance(nullptr);


AgentClient::AgentClient(QObject *parent)
    : QObject(parent)
    , m_nextId(0)
    , m_socket(nullptr)
    , m_http(new QNetworkAccessManager(this))
{
    if(s_instance) {
        qFatal("AgentClient can only be instantiated once");
    }
    QString gatewayUrl = qEnvironmentVariable("APIGEAR_GATEWAY", "ws://localhost:8152/ws");
    m_traceUrl = QUrl(gatewayUrl);
    m_socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
    connect(m_socket, &QWebSocket::connected, this, &AgentClient::process);
    m_retryTimer = new QTimer(this);
    m_retryTimer->setInterval(5000);
    process();
    m_delayTimer = new QTimer(this);
    m_delayTimer->setInterval(150);
    connect(m_delayTimer, &QTimer::timeout, this, &AgentClient::doSendTrace);
}

AgentClient *AgentClient::instance()
{
    if(!s_instance) {
        s_instance = new AgentClient(QCoreApplication::instance());
    }
    return s_instance;
}

void AgentClient::simuCall(const QString &symbol,const QVariantList &args)
{
    send(callMessage(symbol, args));
}

void AgentClient::simuSignal(const QString &symbol, const QVariantList &args)
{
    send(signalMessage(symbol, args));
}

void AgentClient::simuState(const QString &symbol, const QVariantMap &fields)
{
    send(stateMessage(symbol, fields));
}

QJsonObject AgentClient::callMessage(const QString &symbol, const QVariantList &args)
{
    const QJsonObject &params{
        {"symbol", symbol},
        {"args", QJsonArray::fromVariantList(args)},
    };
    return QJsonObject{
        { "jsonrpc", "2.0" },
        { "id", nextId() },
        { "method",  "call"},
        { "params", params},
    };
}

QJsonObject AgentClient::signalMessage(const QString &symbol, const QVariantList &args)
{
    const QJsonObject &params{
        {"symbol", symbol},
        {"args", QJsonArray::fromVariantList(args)},
    };
    return QJsonObject{
        { "jsonrpc", "2.0" },
        { "method",  "signal"},
        { "params", params},
    };
}

QJsonObject AgentClient::stateMessage(const QString &symbol, const QVariantMap &fields)
{
    const QJsonObject &params{
        {"symbol", symbol},
        {"fields", QJsonObject::fromVariantMap(fields)},
    };
    return QJsonObject{
        { "jsonrpc", "2.0" },
        { "method",  "state"},
        { "params", params},
    };
}


// { type: 'operation', module: 'count', symbol: "Counter.increment", params: {} }
void AgentClient::traceCall(const QString &symbol, const QVariantMap &params) {
    sendTrace(traceMessage("call", symbol, params));
}

// { type: 'state', module: 'count', symbol: "Counter", state: {} }
void AgentClient::traceState(const QString &symbol, const QVariantMap &state) {
    sendTrace(traceMessage("state", symbol, state));
}


// { type: 'signal', module: 'count', symbol: "Counter.shutdown", params: {} }
void AgentClient::traceSignal(const QString &symbol, const QVariantMap &params) {
    const QJsonObject data{
        { "id", QDateTime::currentMSecsSinceEpoch() },
        { "type", "signal" },
        { "symbol", symbol },
        { "data", QJsonObject::fromVariantMap(params) },
    };
    sendTrace(traceMessage("signal", symbol, params));
}

QJsonObject AgentClient::traceMessage(const QString &type, const QString &symbol, const QVariantMap& data) {
    return QJsonObject {
        { "id", QDateTime::currentMSecsSinceEpoch() },
        { "type", type },
        { "symbol", symbol },
        { "data", QJsonObject::fromVariantMap(data) },
    };
}

void AgentClient::send(const QJsonObject &messsage)
{
    m_queue.enqueue(messsage);
    process();
}

int AgentClient::nextId() {
    m_nextId++;
    return m_nextId;
}

void AgentClient::process()
{
    QTimer::singleShot(10, this, &AgentClient::doProcess);
}

void AgentClient::doProcess()
{
    if (m_retryTimer->isActive()) {
        return;
    }
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->open(m_traceUrl);
        m_retryTimer->start();
    }
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        m_retryTimer->stop();
        return;
    }
    while (!m_queue.isEmpty()) {
        const QJsonObject &obj = m_queue.dequeue();
        const QByteArray &data = QJsonDocument(obj).toJson();
        AG_LOG_DEBUG(qPrintable(data));
        m_socket->sendBinaryMessage(data);
    }
}

void AgentClient::sendTrace(const QJsonObject &message)
{
    m_traceQueue.enqueue(message);
    if(!m_delayTimer->isActive()) {
        m_delayTimer->start();
    }
}

void AgentClient::doSendTrace()
{
    m_delayTimer->stop();
    const QString source = "1234";
    const QString address = qEnvironmentVariable("APIGEAR_TRACE_SERVER", "http://localhost:5555/monitor");
    QNetworkRequest request;
    request.setUrl(QUrl(QString("%1/%2").arg(address).arg(source)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonArray batch;
    while(!m_traceQueue.isEmpty()) {
        const QJsonObject &message = m_traceQueue.dequeue();
        batch.append(message);
    }
    if(batch.isEmpty()) {
        return;
    }
    const QByteArray& data = QJsonDocument(batch).toJson(QJsonDocument::Compact);
    AG_LOG_DEBUG(qPrintable(data));
    m_http->post(request, data);
}

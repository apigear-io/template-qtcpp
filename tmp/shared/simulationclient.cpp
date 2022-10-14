#include "simulationclient.h"
#include "jsonrpc/rpcprotocol.h"

using namespace ApiGear::JSONRPC;

SimulationClient* SimulationClient::s_instance(nullptr);

SimulationClient::SimulationClient(QObject *parent)
    : QObject(parent)
    , m_nextId(0)
    , m_socket(nullptr)
    , m_session(new RpcProtocol(this, this, this, MessageFormat::JSON))
    , m_loggingDisabled(false)
{
    if(s_instance) {
        qFatal("SimulationClient can only be instantiated once");
    }
    QString serverUrl = qEnvironmentVariable("SIMULATION_SERVER", "ws://127.0.0.1:5555/ws");
    m_serverUrl = QUrl(serverUrl);
    m_socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
    connect(m_socket, &QWebSocket::connected, this, &SimulationClient::process);
    connect(m_socket, &QWebSocket::textMessageReceived, this, &SimulationClient::handleTextMessage);
    m_retryTimer = new QTimer(this);
    m_retryTimer->setInterval(5000);
    m_delayTimer = new QTimer(this);
    m_delayTimer->setInterval(150);
    process();
}

SimulationClient::~SimulationClient()
{
    delete m_session;
}

SimulationClient *SimulationClient::instance()
{
    qDebug() << Q_FUNC_INFO;
    if(!s_instance) {
        s_instance = new SimulationClient(QCoreApplication::instance());
    }
    return s_instance;
}

void SimulationClient::doFetchState(string service, CallResponseFunc &func)
{
    qDebug() << Q_FUNC_INFO;
    Params params;
    params["service"] = service;
    m_session->doCall("simu.state", params, func);
}

void SimulationClient::doCall(std::string service, std::string operation, JSONRPC::Params args, JSONRPC::CallResponseFunc& func)
{
    qDebug() << Q_FUNC_INFO;
    Params params;
    params["service"] = service;
    params["operation"] = operation;
    params["params"] = args;
    m_session->doCall("simu.call", params, func);
}

void SimulationClient::doCall(std::string service, std::string operation, JSONRPC::Params args)
{
    qDebug() << Q_FUNC_INFO;
    JSONRPC::CallResponseFunc func = [](JSONRPC::CallResponseArg arg) {};
    Params params;
    params["service"] = service;
    params["operation"] = operation;
    params["params"] = args;
    m_session->doCall("simu.call", params, func);
}

void SimulationClient::onNotify(std::string method, JSONRPC::NotifyRequestFunc &func)
{
    qDebug() << Q_FUNC_INFO;
    // in case we haven't registered our simulation signal callback, we do it on first onNotify
    if(m_notifyRegistry.empty()) {
        NotifyRequestFunc notifyFunc = [this](NotifyRequestArg args) {
            std::string signal = args.params["service"].get<std::string>() + "#" + args.params["signal"].get<std::string>();
            if(m_notifyRegistry.count(signal) == 1) {
                const NotifyRequestFunc& func = m_notifyRegistry[signal];
                NotifyRequestArg arg;
                arg.params = args.params["params"].get<Params>();
                func(arg);
            } else {
                error("simulation no notification registered for " + signal);
            }
        };
        m_session->onNotify("simu.signal", notifyFunc);
    }
    m_notifyRegistry[method] = func;
}

void SimulationClient::onNotifyState(std::string service, JSONRPC::NotifyRequestFunc &func)
{
    qDebug() << Q_FUNC_INFO;
    // in case we haven't registered our simulation state callback, we do it on first onNotify
    if(m_notifyStateRegistry.empty()) {
        NotifyRequestFunc notifyFunc = [this](NotifyRequestArg args) {
            std::string service = args.params["service"].get<std::string>();
            if(m_notifyStateRegistry.count(service) == 1) {
                const NotifyRequestFunc& func = m_notifyStateRegistry[service];
                NotifyRequestArg arg;
                arg.params = args.params["params"].get<Params>();
                func(arg);
            } else {
                error("simulation no notification registered for state of " + service);
            }
        };
        m_session->onNotify("simu.state", notifyFunc);
    }
    m_notifyStateRegistry[service] = func;
}

void SimulationClient::notify(NotifyRequestArg args)
{
}



void SimulationClient::send(const QString &messsage)
{
    m_queue.enqueue(messsage);
    process();
}

int SimulationClient::nextId() {
    m_nextId++;
    return m_nextId;
}

void SimulationClient::handleTextMessage(const QString &message)
{
    qDebug() << Q_FUNC_INFO;
    m_session->handleMessage(message.toStdString());
}


void SimulationClient::writeMessage(std::string message)
{
    send(QString::fromStdString(message));
}

void SimulationClient::onNotify(std::string method, Params params)
{
    error("DEADEND - ignore - simulation no notification registered for " + method);
}

void SimulationClient::process()
{
    QTimer::singleShot(10, this, &SimulationClient::doProcess);
}

void SimulationClient::doProcess()
{
    qDebug() << Q_FUNC_INFO;
    if (m_retryTimer->isActive()) {
        return;
    }
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->open(m_serverUrl);
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


void SimulationClient::info(std::string message)
{
    if(!m_loggingDisabled) {
        qInfo() << message.data();
    }
}

void SimulationClient::debug(std::string message)
{
    if(!m_loggingDisabled) {
        qDebug() << message.data();
    }
}

void SimulationClient::warning(std::string message)
{
    if(!m_loggingDisabled) {
        qWarning() << message.data();
    }
}

void SimulationClient::error(std::string message)
{
    if(!m_loggingDisabled) {
        qWarning() << message.data();
    }
}




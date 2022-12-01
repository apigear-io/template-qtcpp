#pragma once

#if defined(COMPILING_SIMULATION_QT)
#  define SIMULATIONQT_EXPORT Q_DECL_EXPORT
#else
#  define SIMULATIONQT_EXPORT Q_DECL_IMPORT
#endif

#include <QtCore>
#include <QtWebSockets>

#include "jsonrpc/types.h"

namespace ApiGear
{
namespace JSONRPC {
class RpcProtocol;
}
class SIMULATIONQT_EXPORT SimulationClient : public QObject, public JSONRPC::IMessageWriter, public JSONRPC::IRpcProtocolListener, public JSONRPC::ILogger
{
    Q_OBJECT
public:
    explicit SimulationClient(QObject *parent = nullptr);
    virtual ~SimulationClient() override;
    static SimulationClient* instance();

    void doFetchState(std::string service, JSONRPC::CallResponseFunc& func);
    void doCall(std::string service, std::string operation, JSONRPC::Params args, JSONRPC::CallResponseFunc& func);
    void doCall(std::string service, std::string operation, JSONRPC::Params args);
    void onNotify(std::string method, JSONRPC::NotifyRequestFunc &func);
    void onNotifyState(std::string service, JSONRPC::NotifyRequestFunc &func);
    void notify(JSONRPC::NotifyRequestArg args);


    void process();
    void doProcess();
    void send(const QString &messsage);
    int nextId();
    void handleTextMessage(const QString &message);
public:
    virtual void writeMessage(std::string message) override;
    void onNotify(std::string method, JSONRPC::Params params) override;
    void info(std::string message) override;
    void debug(std::string message) override;
    void warning(std::string message) override;
    void error(std::string message) override;
public:
    static SimulationClient* s_instance;
    QQueue<QString> m_queue;
    int m_nextId;
    QUrl m_serverUrl;
    QWebSocket *m_socket;
    QTimer *m_retryTimer;
    QTimer *m_delayTimer;
    JSONRPC::RpcProtocol *m_session;
    std::map<std::string, JSONRPC::NotifyRequestFunc> m_notifyRegistry;
    std::map<std::string, JSONRPC::NotifyRequestFunc> m_notifyStateRegistry;
    bool m_loggingDisabled;

};

}
#pragma once

#include <QtCore>
#include <QtWebSockets>

class AgentClient : public QObject
{
    Q_OBJECT
public:
    explicit AgentClient(QObject *parent = nullptr);
    static AgentClient* instance();
    void traceCall(const QString &symbol, const QVariantMap &params=QVariantMap());
    void traceState(const QString &symbol, const QVariantMap &state);
    void traceSignal(const QString &symbol, const QVariantMap &params=QVariantMap());
    void simuCall(const QString &symbol, const QVariantList &args);
    void simuSignal(const QString &symbol, const QVariantList &args);
    void simuState(const QString &symbol, const QVariantMap &fields);
    QJsonObject callMessage(const QString& symbol, const QVariantList &args);
    QJsonObject signalMessage(const QString& symbol, const QVariantList &args);
    QJsonObject stateMessage(const QString& symbol, const QVariantMap &fields);

private:
    int nextId();
    void process();
    void doProcess();
    void send(const QJsonObject &messsage);
    void sendTrace(const QJsonObject &message);
    void doSendTrace();
    QJsonObject traceMessage(const QString &type, const QString &symbol, const QVariantMap& data);
private:
    static AgentClient* s_instance;
    QQueue<QJsonObject> m_queue;
    int m_nextId;
    QUrl m_traceUrl;
    QWebSocket *m_socket;
    QTimer *m_retryTimer;
    QNetworkAccessManager *m_http;
    QQueue<QJsonObject> m_traceQueue;
    QTimer *m_delayTimer;
};

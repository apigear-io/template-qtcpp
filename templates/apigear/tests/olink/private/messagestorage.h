#ifndef MESSAGESTORAGE_H
#define MESSAGESTORAGE_H

#include <QObject>
#include <QQueue>

class MessageStorage : public QObject
{
    Q_OBJECT
public:
    explicit MessageStorage(QObject *parent = nullptr);

    void receiveMessage(const QString& message);

    QString getMessage();

    public:
    QQueue<QString> m_messages;

};

#endif // MESSAGESTORAGE_H

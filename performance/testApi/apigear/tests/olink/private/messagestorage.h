#ifndef MESSAGESTORAGE_H
#define MESSAGESTORAGE_H

#include <QObject>
#include <QQueue>


/**
 *  Heler class that can be used to store messages from sockets.
 *  Connect receiveMessage with a signal from socket to save the message in storage.
 *  Get message from storage with getMessage.
 */
class MessageStorage : public QObject
{
    Q_OBJECT
public:
    explicit MessageStorage(QObject *parent = nullptr);
    /**
     * Saves message in storage
     * @param message. A message to be stored.
     */
    void receiveMessage(const QString& message);
    /**
     * Gets the message if it is there. Gives it a try by calling processEvent few times.
     * @return the message from the storage or an empty QString if there was no message.
     */
    QString getMessage();

private:
    /** Messages stored with receiveMEssage function */
    QQueue<QString> m_messages;

};

#endif // MESSAGESTORAGE_H

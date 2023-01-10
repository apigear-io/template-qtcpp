#include "messagestorage.h"
#include <QtCore>
MessageStorage::MessageStorage(QObject *parent)
    : QObject{parent}
{

}

QString MessageStorage::getMessage()
{
    for (size_t i = 0; i < 25; i++)
    {
        QCoreApplication::processEvents();
        if (!m_messages.isEmpty()) break;
    }
    if (m_messages.isEmpty() )
    {
        return QString();
    }
    return m_messages.takeFirst();
}

void MessageStorage::receiveMessage(const QString& message)
{
    m_messages.append(message);
}

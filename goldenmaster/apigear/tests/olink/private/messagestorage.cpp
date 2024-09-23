#include "messagestorage.h"
#include <QtCore>
#include <QTest>
MessageStorage::MessageStorage(QObject *parent)
    : QObject{parent}
{

}

QString MessageStorage::getMessage()
{
    auto messageArrived = QTest::qWaitFor([this]() {return !m_messages.isEmpty(); }, 1000);
    if (!messageArrived)
    {
        return QString();
    }
    return m_messages.takeFirst();
}

void MessageStorage::receiveMessage(const QString& message)
{
    m_messages.append(message);
}

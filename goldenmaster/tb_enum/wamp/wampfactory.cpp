#include "wampfactory.h"
#include "wampenuminterface.h"

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractEnumInterface* WampFactory::createEnumInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampEnumInterface(parent);
}

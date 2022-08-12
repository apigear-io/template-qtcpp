#include "wampfactory.h"
#include "wampsimpleinterface.h"
#include "wampsimplearrayinterface.h"

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractSimpleInterface* WampFactory::createSimpleInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampSimpleInterface(parent);
}

AbstractSimpleArrayInterface* WampFactory::createSimpleArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampSimpleArrayInterface(parent);
}

#include "wampfactory.h"
#include "wampstructinterface.h"
#include "wampstructarrayinterface.h"

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractStructInterface* WampFactory::createStructInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampStructInterface(parent);
}

AbstractStructArrayInterface* WampFactory::createStructArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampStructArrayInterface(parent);
}

#include "wampfactory.h"
#include "wampinterface1.h"
#include "wampinterface2.h"

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractInterface1* WampFactory::createInterface1(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampInterface1(parent);
}

AbstractInterface2* WampFactory::createInterface2(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampInterface2(parent);
}

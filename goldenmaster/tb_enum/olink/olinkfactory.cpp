#include "olinkfactory.h"
#include "olinkenuminterface.h"

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractEnumInterface* OLinkFactory::createEnumInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkEnumInterface(parent);
}

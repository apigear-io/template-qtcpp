#include "olinkfactory.h"
#include "olinkenuminterface.h"

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent)
    : QObject(parent)
    , m_registry(registry)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractEnumInterface* OLinkFactory::createEnumInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkEnumInterface(m_registry, parent);
}

#include "olinkfactory.h"
#include "olinksimpleinterface.h"
#include "olinksimplearrayinterface.h"

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent)
    : QObject(parent)
    , m_registry(registry)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractSimpleInterface* OLinkFactory::createSimpleInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSimpleInterface(m_registry, parent);
}

AbstractSimpleArrayInterface* OLinkFactory::createSimpleArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSimpleArrayInterface(m_registry, parent);
}

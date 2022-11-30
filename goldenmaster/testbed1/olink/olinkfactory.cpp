#include "olinkfactory.h"
#include "olinkstructinterface.h"
#include "olinkstructarrayinterface.h"

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent)
    : QObject(parent)
    , m_registry(registry)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractStructInterface* OLinkFactory::createStructInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkStructInterface(m_registry, parent);
}

AbstractStructArrayInterface* OLinkFactory::createStructArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkStructArrayInterface(m_registry, parent);
}

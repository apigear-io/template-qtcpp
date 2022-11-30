#include "olinkfactory.h"
#include "olinksamestruct1interface.h"
#include "olinksamestruct2interface.h"
#include "olinksameenum1interface.h"
#include "olinksameenum2interface.h"

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent)
    : QObject(parent)
    , m_registry(registry)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractSameStruct1Interface* OLinkFactory::createSameStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameStruct1Interface(m_registry, parent);
}

AbstractSameStruct2Interface* OLinkFactory::createSameStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameStruct2Interface(m_registry, parent);
}

AbstractSameEnum1Interface* OLinkFactory::createSameEnum1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameEnum1Interface(m_registry, parent);
}

AbstractSameEnum2Interface* OLinkFactory::createSameEnum2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameEnum2Interface(m_registry, parent);
}

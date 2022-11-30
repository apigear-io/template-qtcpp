#include "olinkfactory.h"
#include "olinkmanyparaminterface.h"
#include "olinknestedstruct1interface.h"
#include "olinknestedstruct2interface.h"
#include "olinknestedstruct3interface.h"

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent)
    : QObject(parent)
    , m_registry(registry)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractManyParamInterface* OLinkFactory::createManyParamInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkManyParamInterface(m_registry, parent);
}

AbstractNestedStruct1Interface* OLinkFactory::createNestedStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkNestedStruct1Interface(m_registry, parent);
}

AbstractNestedStruct2Interface* OLinkFactory::createNestedStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkNestedStruct2Interface(m_registry, parent);
}

AbstractNestedStruct3Interface* OLinkFactory::createNestedStruct3Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkNestedStruct3Interface(m_registry, parent);
}

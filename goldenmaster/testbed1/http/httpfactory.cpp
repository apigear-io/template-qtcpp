#include "httpfactory.h"
#include "httpstructinterface.h"
#include "httpstructarrayinterface.h"

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractStructInterface* HttpFactory::createStructInterface(QObject *parent)
{
    return new HttpStructInterface(m_network, parent);
}

AbstractStructArrayInterface* HttpFactory::createStructArrayInterface(QObject *parent)
{
    return new HttpStructArrayInterface(m_network, parent);
}

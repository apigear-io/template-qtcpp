#include "httpfactory.h"
#include "httpsimpleinterface.h"
#include "httpsimplearrayinterface.h"

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractSimpleInterface* HttpFactory::createSimpleInterface(QObject *parent)
{
    return new HttpSimpleInterface(m_network, parent);
}

AbstractSimpleArrayInterface* HttpFactory::createSimpleArrayInterface(QObject *parent)
{
    return new HttpSimpleArrayInterface(m_network, parent);
}

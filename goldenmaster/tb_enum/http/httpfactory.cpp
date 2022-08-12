#include "httpfactory.h"
#include "httpenuminterface.h"

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractEnumInterface* HttpFactory::createEnumInterface(QObject *parent)
{
    return new HttpEnumInterface(m_network, parent);
}

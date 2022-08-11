#include "httpfactory.h"
#include "httpinterface1.h"
#include "httpinterface2.h"

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractInterface1* HttpFactory::createInterface1(QObject *parent)
{
    return new HttpInterface1(m_network, parent);
}

AbstractInterface2* HttpFactory::createInterface2(QObject *parent)
{
    return new HttpInterface2(m_network, parent);
}

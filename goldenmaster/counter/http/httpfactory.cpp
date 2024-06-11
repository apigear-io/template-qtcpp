#include "httpfactory.h"
#include "httpcounter.h"

namespace counter {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractCounter> HttpFactory::createCounter(QObject *parent)
{
    return std::make_shared<HttpCounter>(m_network, parent);
}


} //namespace counter
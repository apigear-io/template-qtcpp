#include "httpfactory.h"
#include "httpstructinterface.h"
#include "httpstructarrayinterface.h"

namespace testbed1 {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractStructInterface> HttpFactory::createStructInterface(QObject *parent)
{
    return std::make_shared<HttpStructInterface>(m_network, parent);
}

std::shared_ptr<AbstractStructArrayInterface> HttpFactory::createStructArrayInterface(QObject *parent)
{
    return std::make_shared<HttpStructArrayInterface>(m_network, parent);
}


} //namespace testbed1
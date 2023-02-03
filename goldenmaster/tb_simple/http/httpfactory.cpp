#include "httpfactory.h"
#include "httpsimpleinterface.h"
#include "httpsimplearrayinterface.h"

namespace tb_simple {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractSimpleInterface> HttpFactory::createSimpleInterface(QObject *parent)
{
    return std::make_shared<HttpSimpleInterface>(m_network, parent);
}

std::shared_ptr<AbstractSimpleArrayInterface> HttpFactory::createSimpleArrayInterface(QObject *parent)
{
    return std::make_shared<HttpSimpleArrayInterface>(m_network, parent);
}


} //namespace tb_simple
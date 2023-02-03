#include "httpfactory.h"
#include "httpenuminterface.h"

namespace tb_enum {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractEnumInterface> HttpFactory::createEnumInterface(QObject *parent)
{
    return std::make_shared<HttpEnumInterface>(m_network, parent);
}


} //namespace tb_enum
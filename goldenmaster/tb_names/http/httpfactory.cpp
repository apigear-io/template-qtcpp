#include "httpfactory.h"
#include "httpnam_es.h"

namespace tb_names {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractNamEs> HttpFactory::createNamEs(QObject *parent)
{
    return std::make_shared<HttpNam_Es>(m_network, parent);
}


} //namespace tb_names
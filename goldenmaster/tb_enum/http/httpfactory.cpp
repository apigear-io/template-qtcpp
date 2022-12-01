#include "httpfactory.h"
#include "httpenuminterface.h"

namespace tb_enum {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractEnumInterface* HttpFactory::createEnumInterface(QObject *parent)
{
    return new HttpEnumInterface(m_network, parent);
}


} //namespace tb_enum
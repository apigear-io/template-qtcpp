#include "httpfactory.h"

namespace extern_types {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}


} //namespace extern_types
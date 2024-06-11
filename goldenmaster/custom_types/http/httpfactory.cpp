#include "httpfactory.h"

namespace custom_types {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}


} //namespace custom_types
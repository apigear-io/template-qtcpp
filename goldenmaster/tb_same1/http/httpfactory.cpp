#include "httpfactory.h"
#include "httpsamestruct1interface.h"
#include "httpsamestruct2interface.h"
#include "httpsameenum1interface.h"
#include "httpsameenum2interface.h"

namespace tb_same1 {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractSameStruct1Interface> HttpFactory::createSameStruct1Interface(QObject *parent)
{
    return std::make_shared<HttpSameStruct1Interface>(m_network, parent);
}

std::shared_ptr<AbstractSameStruct2Interface> HttpFactory::createSameStruct2Interface(QObject *parent)
{
    return std::make_shared<HttpSameStruct2Interface>(m_network, parent);
}

std::shared_ptr<AbstractSameEnum1Interface> HttpFactory::createSameEnum1Interface(QObject *parent)
{
    return std::make_shared<HttpSameEnum1Interface>(m_network, parent);
}

std::shared_ptr<AbstractSameEnum2Interface> HttpFactory::createSameEnum2Interface(QObject *parent)
{
    return std::make_shared<HttpSameEnum2Interface>(m_network, parent);
}


} //namespace tb_same1
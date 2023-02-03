#include "httpfactory.h"
#include "httpmanyparaminterface.h"
#include "httpnestedstruct1interface.h"
#include "httpnestedstruct2interface.h"
#include "httpnestedstruct3interface.h"

namespace testbed2 {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractManyParamInterface> HttpFactory::createManyParamInterface(QObject *parent)
{
    return std::make_shared<HttpManyParamInterface>(m_network, parent);
}

std::shared_ptr<AbstractNestedStruct1Interface> HttpFactory::createNestedStruct1Interface(QObject *parent)
{
    return std::make_shared<HttpNestedStruct1Interface>(m_network, parent);
}

std::shared_ptr<AbstractNestedStruct2Interface> HttpFactory::createNestedStruct2Interface(QObject *parent)
{
    return std::make_shared<HttpNestedStruct2Interface>(m_network, parent);
}

std::shared_ptr<AbstractNestedStruct3Interface> HttpFactory::createNestedStruct3Interface(QObject *parent)
{
    return std::make_shared<HttpNestedStruct3Interface>(m_network, parent);
}


} //namespace testbed2
#include "httpfactory.h"
#include "httpmanyparaminterface.h"
#include "httpnestedstruct1interface.h"
#include "httpnestedstruct2interface.h"
#include "httpnestedstruct3interface.h"

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractManyParamInterface* HttpFactory::createManyParamInterface(QObject *parent)
{
    return new HttpManyParamInterface(m_network, parent);
}

AbstractNestedStruct1Interface* HttpFactory::createNestedStruct1Interface(QObject *parent)
{
    return new HttpNestedStruct1Interface(m_network, parent);
}

AbstractNestedStruct2Interface* HttpFactory::createNestedStruct2Interface(QObject *parent)
{
    return new HttpNestedStruct2Interface(m_network, parent);
}

AbstractNestedStruct3Interface* HttpFactory::createNestedStruct3Interface(QObject *parent)
{
    return new HttpNestedStruct3Interface(m_network, parent);
}

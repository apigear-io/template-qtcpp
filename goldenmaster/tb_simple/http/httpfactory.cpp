#include "httpfactory.h"
#include "httpvoidinterface.h"
#include "httpsimpleinterface.h"
#include "httpsimplearrayinterface.h"
#include "httpnopropertiesinterface.h"
#include "httpnooperationsinterface.h"
#include "httpnosignalsinterface.h"

namespace tb_simple {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

std::shared_ptr<AbstractVoidInterface> HttpFactory::createVoidInterface(QObject *parent)
{
    return std::make_shared<HttpVoidInterface>(m_network, parent);
}

std::shared_ptr<AbstractSimpleInterface> HttpFactory::createSimpleInterface(QObject *parent)
{
    return std::make_shared<HttpSimpleInterface>(m_network, parent);
}

std::shared_ptr<AbstractSimpleArrayInterface> HttpFactory::createSimpleArrayInterface(QObject *parent)
{
    return std::make_shared<HttpSimpleArrayInterface>(m_network, parent);
}

std::shared_ptr<AbstractNoPropertiesInterface> HttpFactory::createNoPropertiesInterface(QObject *parent)
{
    return std::make_shared<HttpNoPropertiesInterface>(m_network, parent);
}

std::shared_ptr<AbstractNoOperationsInterface> HttpFactory::createNoOperationsInterface(QObject *parent)
{
    return std::make_shared<HttpNoOperationsInterface>(m_network, parent);
}

std::shared_ptr<AbstractNoSignalsInterface> HttpFactory::createNoSignalsInterface(QObject *parent)
{
    return std::make_shared<HttpNoSignalsInterface>(m_network, parent);
}


} //namespace tb_simple
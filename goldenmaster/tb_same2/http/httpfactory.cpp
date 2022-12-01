#include "httpfactory.h"
#include "httpsamestruct1interface.h"
#include "httpsamestruct2interface.h"
#include "httpsameenum1interface.h"
#include "httpsameenum2interface.h"

namespace tb_same2 {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

AbstractSameStruct1Interface* HttpFactory::createSameStruct1Interface(QObject *parent)
{
    return new HttpSameStruct1Interface(m_network, parent);
}

AbstractSameStruct2Interface* HttpFactory::createSameStruct2Interface(QObject *parent)
{
    return new HttpSameStruct2Interface(m_network, parent);
}

AbstractSameEnum1Interface* HttpFactory::createSameEnum1Interface(QObject *parent)
{
    return new HttpSameEnum1Interface(m_network, parent);
}

AbstractSameEnum2Interface* HttpFactory::createSameEnum2Interface(QObject *parent)
{
    return new HttpSameEnum2Interface(m_network, parent);
}


} //namespace tb_same2
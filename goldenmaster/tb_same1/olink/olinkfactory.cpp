#include "olinkfactory.h"
#include "olink/olinksamestruct1interface.h"
#include "olink/olinksamestruct2interface.h"
#include "olink/olinksameenum1interface.h"
#include "olink/olinksameenum2interface.h"

namespace tb_same1 {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractSameStruct1Interface> OLinkFactory::createSameStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto same_struct1_interface = std::make_shared<OLinkSameStruct1Interface>();
    m_client.linkObjectSource(same_struct1_interface);
    return same_struct1_interface;
}

std::shared_ptr<AbstractSameStruct2Interface> OLinkFactory::createSameStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto same_struct2_interface = std::make_shared<OLinkSameStruct2Interface>();
    m_client.linkObjectSource(same_struct2_interface);
    return same_struct2_interface;
}

std::shared_ptr<AbstractSameEnum1Interface> OLinkFactory::createSameEnum1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto same_enum1_interface = std::make_shared<OLinkSameEnum1Interface>();
    m_client.linkObjectSource(same_enum1_interface);
    return same_enum1_interface;
}

std::shared_ptr<AbstractSameEnum2Interface> OLinkFactory::createSameEnum2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto same_enum2_interface = std::make_shared<OLinkSameEnum2Interface>();
    m_client.linkObjectSource(same_enum2_interface);
    return same_enum2_interface;
}

} //namespace tb_same1
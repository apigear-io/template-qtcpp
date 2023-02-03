#include "olinkfactory.h"
#include "olink/olinkenuminterface.h"

namespace tb_enum {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractEnumInterface> OLinkFactory::createEnumInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto enum_interface = std::make_shared<OLinkEnumInterface>();
    m_client.linkObjectSource(enum_interface);
    return enum_interface;
}

} //namespace tb_enum
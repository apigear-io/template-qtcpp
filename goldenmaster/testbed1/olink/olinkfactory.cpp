#include "olinkfactory.h"
#include "olink/olinkstructinterface.h"
#include "olink/olinkstructarrayinterface.h"

namespace testbed1 {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractStructInterface> OLinkFactory::createStructInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto struct_interface = std::make_shared<OLinkStructInterface>();
    m_client.linkObjectSource(struct_interface);
    return struct_interface;
}

std::shared_ptr<AbstractStructArrayInterface> OLinkFactory::createStructArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto struct_array_interface = std::make_shared<OLinkStructArrayInterface>();
    m_client.linkObjectSource(struct_array_interface);
    return struct_array_interface;
}

} //namespace testbed1
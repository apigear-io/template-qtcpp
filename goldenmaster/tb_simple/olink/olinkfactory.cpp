#include "olinkfactory.h"
#include "utilities/logger.h"
#include "olink/olinksimpleinterface.h"
#include "olink/olinksimplearrayinterface.h"

namespace tb_simple {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractSimpleInterface> OLinkFactory::createSimpleInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto simple_interface = std::make_shared<OLinkSimpleInterface>();
    m_client.linkObjectSource(simple_interface);
    return simple_interface;
}

std::shared_ptr<AbstractSimpleArrayInterface> OLinkFactory::createSimpleArrayInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto simple_array_interface = std::make_shared<OLinkSimpleArrayInterface>();
    m_client.linkObjectSource(simple_array_interface);
    return simple_array_interface;
}

} //namespace tb_simple
#include "olinkfactory.h"
#include "utilities/logger.h"
#include "olink/olinkcounter.h"

namespace counter {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractCounter> OLinkFactory::createCounter(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto counter = std::make_shared<OLinkCounter>();
    m_client.linkObjectSource(counter);
    return counter;
}

} //namespace counter
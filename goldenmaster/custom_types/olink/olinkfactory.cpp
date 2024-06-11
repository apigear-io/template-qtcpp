#include "olinkfactory.h"
#include "utilities/logger.h"

namespace custom_types {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

} //namespace custom_types
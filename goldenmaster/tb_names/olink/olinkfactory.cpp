#include "olinkfactory.h"
#include "utilities/logger.h"
#include "olink/olinknam_es.h"

namespace tb_names {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractNamEs> OLinkFactory::createNamEs(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto nam_es = std::make_shared<OLinkNam_Es>();
    m_client.linkObjectSource(nam_es);
    return nam_es;
}

} //namespace tb_names
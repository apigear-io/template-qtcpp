#include "tracedapifactory.h"
#include "utilities/logger.h"
#include "nam_estraced.h"

namespace tb_names {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractNamEs> TracedApiFactory::createNamEs(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto namEs = m_factory.createNamEs(parent);
    return std::make_shared<NamEsTraced>(namEs);
}

} //namespace tb_names

#include "tracedapifactory.h"
#include "utilities/logger.h"

namespace extern_types {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

} //namespace extern_types

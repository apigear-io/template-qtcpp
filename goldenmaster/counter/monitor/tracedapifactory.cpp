#include "tracedapifactory.h"
#include "utilities/logger.h"
#include "countertraced.h"

namespace counter {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractCounter> TracedApiFactory::createCounter(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto counter = m_factory.createCounter(parent);
    return std::make_shared<CounterTraced>(counter);
}

} //namespace counter

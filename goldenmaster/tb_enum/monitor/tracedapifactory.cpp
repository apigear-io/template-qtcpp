#include "tracedapifactory.h"
#include "utilities/logger.h"
#include "enuminterfacetraced.h"

namespace tb_enum {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractEnumInterface> TracedApiFactory::createEnumInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto enumInterface = m_factory.createEnumInterface(parent);
    return std::make_shared<EnumInterfaceTraced>(enumInterface);
}

} //namespace tb_enum

#include "tracedapifactory.h"
#include "enuminterfacetraced.h"

namespace tb_enum {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractEnumInterface> TracedApiFactory::createEnumInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto enumInterface = m_factory.createEnumInterface(parent);
    return std::make_shared<EnumInterfaceTraced>(enumInterface);
}

} //namespace tb_enum

#include "tracedapifactory.h"
#include "utilities/logger.h"
#include "voidinterfacetraced.h"
#include "simpleinterfacetraced.h"
#include "simplearrayinterfacetraced.h"
#include "nopropertiesinterfacetraced.h"
#include "nooperationsinterfacetraced.h"
#include "nosignalsinterfacetraced.h"

namespace tb_simple {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractVoidInterface> TracedApiFactory::createVoidInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto voidInterface = m_factory.createVoidInterface(parent);
    return std::make_shared<VoidInterfaceTraced>(voidInterface);
}

std::shared_ptr<AbstractSimpleInterface> TracedApiFactory::createSimpleInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto simpleInterface = m_factory.createSimpleInterface(parent);
    return std::make_shared<SimpleInterfaceTraced>(simpleInterface);
}

std::shared_ptr<AbstractSimpleArrayInterface> TracedApiFactory::createSimpleArrayInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto simpleArrayInterface = m_factory.createSimpleArrayInterface(parent);
    return std::make_shared<SimpleArrayInterfaceTraced>(simpleArrayInterface);
}

std::shared_ptr<AbstractNoPropertiesInterface> TracedApiFactory::createNoPropertiesInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto noPropertiesInterface = m_factory.createNoPropertiesInterface(parent);
    return std::make_shared<NoPropertiesInterfaceTraced>(noPropertiesInterface);
}

std::shared_ptr<AbstractNoOperationsInterface> TracedApiFactory::createNoOperationsInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto noOperationsInterface = m_factory.createNoOperationsInterface(parent);
    return std::make_shared<NoOperationsInterfaceTraced>(noOperationsInterface);
}

std::shared_ptr<AbstractNoSignalsInterface> TracedApiFactory::createNoSignalsInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto noSignalsInterface = m_factory.createNoSignalsInterface(parent);
    return std::make_shared<NoSignalsInterfaceTraced>(noSignalsInterface);
}

} //namespace tb_simple

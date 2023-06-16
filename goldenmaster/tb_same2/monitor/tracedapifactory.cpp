#include "tracedapifactory.h"
#include "utilities/logger.h"
#include "samestruct1interfacetraced.h"
#include "samestruct2interfacetraced.h"
#include "sameenum1interfacetraced.h"
#include "sameenum2interfacetraced.h"

namespace tb_same2 {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractSameStruct1Interface> TracedApiFactory::createSameStruct1Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto sameStruct1Interface = m_factory.createSameStruct1Interface(parent);
    return std::make_shared<SameStruct1InterfaceTraced>(sameStruct1Interface);
}

std::shared_ptr<AbstractSameStruct2Interface> TracedApiFactory::createSameStruct2Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto sameStruct2Interface = m_factory.createSameStruct2Interface(parent);
    return std::make_shared<SameStruct2InterfaceTraced>(sameStruct2Interface);
}

std::shared_ptr<AbstractSameEnum1Interface> TracedApiFactory::createSameEnum1Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto sameEnum1Interface = m_factory.createSameEnum1Interface(parent);
    return std::make_shared<SameEnum1InterfaceTraced>(sameEnum1Interface);
}

std::shared_ptr<AbstractSameEnum2Interface> TracedApiFactory::createSameEnum2Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto sameEnum2Interface = m_factory.createSameEnum2Interface(parent);
    return std::make_shared<SameEnum2InterfaceTraced>(sameEnum2Interface);
}

} //namespace tb_same2

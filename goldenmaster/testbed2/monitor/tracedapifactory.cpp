#include "tracedapifactory.h"
#include "manyparaminterfacetraced.h"
#include "nestedstruct1interfacetraced.h"
#include "nestedstruct2interfacetraced.h"
#include "nestedstruct3interfacetraced.h"

namespace testbed2 {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractManyParamInterface> TracedApiFactory::createManyParamInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto manyParamInterface = m_factory.createManyParamInterface(parent);
    return std::make_shared<ManyParamInterfaceTraced>(manyParamInterface);
}

std::shared_ptr<AbstractNestedStruct1Interface> TracedApiFactory::createNestedStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto nestedStruct1Interface = m_factory.createNestedStruct1Interface(parent);
    return std::make_shared<NestedStruct1InterfaceTraced>(nestedStruct1Interface);
}

std::shared_ptr<AbstractNestedStruct2Interface> TracedApiFactory::createNestedStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto nestedStruct2Interface = m_factory.createNestedStruct2Interface(parent);
    return std::make_shared<NestedStruct2InterfaceTraced>(nestedStruct2Interface);
}

std::shared_ptr<AbstractNestedStruct3Interface> TracedApiFactory::createNestedStruct3Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto nestedStruct3Interface = m_factory.createNestedStruct3Interface(parent);
    return std::make_shared<NestedStruct3InterfaceTraced>(nestedStruct3Interface);
}

} //namespace testbed2

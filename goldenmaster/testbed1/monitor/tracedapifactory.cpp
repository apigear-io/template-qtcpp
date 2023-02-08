#include "tracedapifactory.h"
#include "structinterfacetraced.h"
#include "structarrayinterfacetraced.h"

namespace testbed1 {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractStructInterface> TracedApiFactory::createStructInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto structInterface = m_factory.createStructInterface(parent);
    return std::make_shared<StructInterfaceTraced>(structInterface);
}

std::shared_ptr<AbstractStructArrayInterface> TracedApiFactory::createStructArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto structArrayInterface = m_factory.createStructArrayInterface(parent);
    return std::make_shared<StructArrayInterfaceTraced>(structArrayInterface);
}

} //namespace testbed1

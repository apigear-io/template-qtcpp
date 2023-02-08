#include "tracedapifactory.h"
#include "simpleinterfacetraced.h"
#include "simplearrayinterfacetraced.h"

namespace tb_simple {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractSimpleInterface> TracedApiFactory::createSimpleInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto simpleInterface = m_factory.createSimpleInterface(parent);
    return std::make_shared<SimpleInterfaceTraced>(simpleInterface);
}

std::shared_ptr<AbstractSimpleArrayInterface> TracedApiFactory::createSimpleArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto simpleArrayInterface = m_factory.createSimpleArrayInterface(parent);
    return std::make_shared<SimpleArrayInterfaceTraced>(simpleArrayInterface);
}

} //namespace tb_simple

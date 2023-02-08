#include "factory.h"
#include "simpleinterface.h"
#include "simplearrayinterface.h"

namespace tb_simple {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractSimpleInterface> Factory::createSimpleInterface(QObject *parent)
{
    return std::make_shared<SimpleInterface>(parent);
}

std::shared_ptr<AbstractSimpleArrayInterface> Factory::createSimpleArrayInterface(QObject *parent)
{
    return std::make_shared<SimpleArrayInterface>(parent);
}

} // namespace tb_simple
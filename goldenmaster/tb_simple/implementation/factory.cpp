#include "factory.h"
#include "voidinterface.h"
#include "simpleinterface.h"
#include "simplearrayinterface.h"
#include "nopropertiesinterface.h"
#include "nooperationsinterface.h"
#include "nosignalsinterface.h"

namespace tb_simple {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractVoidInterface> Factory::createVoidInterface(QObject *parent)
{
    return std::make_shared<VoidInterface>(parent);
}

std::shared_ptr<AbstractSimpleInterface> Factory::createSimpleInterface(QObject *parent)
{
    return std::make_shared<SimpleInterface>(parent);
}

std::shared_ptr<AbstractSimpleArrayInterface> Factory::createSimpleArrayInterface(QObject *parent)
{
    return std::make_shared<SimpleArrayInterface>(parent);
}

std::shared_ptr<AbstractNoPropertiesInterface> Factory::createNoPropertiesInterface(QObject *parent)
{
    return std::make_shared<NoPropertiesInterface>(parent);
}

std::shared_ptr<AbstractNoOperationsInterface> Factory::createNoOperationsInterface(QObject *parent)
{
    return std::make_shared<NoOperationsInterface>(parent);
}

std::shared_ptr<AbstractNoSignalsInterface> Factory::createNoSignalsInterface(QObject *parent)
{
    return std::make_shared<NoSignalsInterface>(parent);
}

} // namespace tb_simple
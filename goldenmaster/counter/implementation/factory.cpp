#include "factory.h"
#include "counter.h"

namespace counter {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractCounter> Factory::createCounter(QObject *parent)
{
    return std::make_shared<Counter>(parent);
}

} // namespace counter
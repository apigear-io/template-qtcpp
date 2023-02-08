#include "factory.h"
#include "structinterface.h"
#include "structarrayinterface.h"

namespace testbed1 {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractStructInterface> Factory::createStructInterface(QObject *parent)
{
    return std::make_shared<StructInterface>(parent);
}

std::shared_ptr<AbstractStructArrayInterface> Factory::createStructArrayInterface(QObject *parent)
{
    return std::make_shared<StructArrayInterface>(parent);
}

} // namespace testbed1
#include "factory.h"
#include "structinterface.h"
#include "structarrayinterface.h"

namespace testbed1 {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractStructInterface* Factory::createStructInterface(QObject *parent)
{
    return new StructInterface(parent);
}

AbstractStructArrayInterface* Factory::createStructArrayInterface(QObject *parent)
{
    return new StructArrayInterface(parent);
}

} // namespace testbed1
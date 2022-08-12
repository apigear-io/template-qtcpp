#include "factory.h"
#include "simpleinterface.h"
#include "simplearrayinterface.h"

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractSimpleInterface* Factory::createSimpleInterface(QObject *parent)
{
    return new SimpleInterface(parent);
}

AbstractSimpleArrayInterface* Factory::createSimpleArrayInterface(QObject *parent)
{
    return new SimpleArrayInterface(parent);
}

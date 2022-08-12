#include "factory.h"
#include "enuminterface.h"

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractEnumInterface* Factory::createEnumInterface(QObject *parent)
{
    return new EnumInterface(parent);
}

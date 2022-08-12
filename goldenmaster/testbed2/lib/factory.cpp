#include "factory.h"
#include "manyparaminterface.h"
#include "nestedstruct1interface.h"
#include "nestedstruct2interface.h"
#include "nestedstruct3interface.h"

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractManyParamInterface* Factory::createManyParamInterface(QObject *parent)
{
    return new ManyParamInterface(parent);
}

AbstractNestedStruct1Interface* Factory::createNestedStruct1Interface(QObject *parent)
{
    return new NestedStruct1Interface(parent);
}

AbstractNestedStruct2Interface* Factory::createNestedStruct2Interface(QObject *parent)
{
    return new NestedStruct2Interface(parent);
}

AbstractNestedStruct3Interface* Factory::createNestedStruct3Interface(QObject *parent)
{
    return new NestedStruct3Interface(parent);
}

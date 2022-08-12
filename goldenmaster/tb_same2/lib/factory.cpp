#include "factory.h"
#include "samestruct1interface.h"
#include "samestruct2interface.h"
#include "sameenum1interface.h"
#include "sameenum2interface.h"

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractSameStruct1Interface* Factory::createSameStruct1Interface(QObject *parent)
{
    return new SameStruct1Interface(parent);
}

AbstractSameStruct2Interface* Factory::createSameStruct2Interface(QObject *parent)
{
    return new SameStruct2Interface(parent);
}

AbstractSameEnum1Interface* Factory::createSameEnum1Interface(QObject *parent)
{
    return new SameEnum1Interface(parent);
}

AbstractSameEnum2Interface* Factory::createSameEnum2Interface(QObject *parent)
{
    return new SameEnum2Interface(parent);
}

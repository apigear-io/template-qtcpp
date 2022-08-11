#include "factory.h"
#include "interface1.h"
#include "interface2.h"

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractInterface1* Factory::createInterface1(QObject *parent)
{
    return new Interface1(parent);
}

AbstractInterface2* Factory::createInterface2(QObject *parent)
{
    return new Interface2(parent);
}

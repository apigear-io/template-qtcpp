#include "factory.h"
#include "manyparaminterface.h"
#include "nestedstruct1interface.h"
#include "nestedstruct2interface.h"
#include "nestedstruct3interface.h"

namespace testbed2 {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractManyParamInterface> Factory::createManyParamInterface(QObject *parent)
{
    return std::make_shared<ManyParamInterface>(parent);
}

std::shared_ptr<AbstractNestedStruct1Interface> Factory::createNestedStruct1Interface(QObject *parent)
{
    return std::make_shared<NestedStruct1Interface>(parent);
}

std::shared_ptr<AbstractNestedStruct2Interface> Factory::createNestedStruct2Interface(QObject *parent)
{
    return std::make_shared<NestedStruct2Interface>(parent);
}

std::shared_ptr<AbstractNestedStruct3Interface> Factory::createNestedStruct3Interface(QObject *parent)
{
    return std::make_shared<NestedStruct3Interface>(parent);
}

} // namespace testbed2
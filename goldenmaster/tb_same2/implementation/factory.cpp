#include "factory.h"
#include "samestruct1interface.h"
#include "samestruct2interface.h"
#include "sameenum1interface.h"
#include "sameenum2interface.h"

namespace tb_same2 {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractSameStruct1Interface> Factory::createSameStruct1Interface(QObject *parent)
{
    return std::make_shared<SameStruct1Interface>(parent);
}

std::shared_ptr<AbstractSameStruct2Interface> Factory::createSameStruct2Interface(QObject *parent)
{
    return std::make_shared<SameStruct2Interface>(parent);
}

std::shared_ptr<AbstractSameEnum1Interface> Factory::createSameEnum1Interface(QObject *parent)
{
    return std::make_shared<SameEnum1Interface>(parent);
}

std::shared_ptr<AbstractSameEnum2Interface> Factory::createSameEnum2Interface(QObject *parent)
{
    return std::make_shared<SameEnum2Interface>(parent);
}

} // namespace tb_same2
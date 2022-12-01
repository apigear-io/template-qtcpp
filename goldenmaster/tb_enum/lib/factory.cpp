#include "factory.h"
#include "enuminterface.h"

namespace tb_enum {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

AbstractEnumInterface* Factory::createEnumInterface(QObject *parent)
{
    return new EnumInterface(parent);
}

} // namespace tb_enum
#include "factory.h"
#include "enuminterface.h"

namespace tb_enum {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractEnumInterface> Factory::createEnumInterface(QObject *parent)
{
    return std::make_shared<EnumInterface>(parent);
}

} // namespace tb_enum
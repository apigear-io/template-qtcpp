#include "factory.h"
#include "nam_es.h"

namespace tb_names {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

std::shared_ptr<AbstractNamEs> Factory::createNamEs(QObject *parent)
{
    return std::make_shared<NamEs>(parent);
}

} // namespace tb_names
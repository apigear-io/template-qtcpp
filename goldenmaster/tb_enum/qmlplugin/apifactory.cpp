#include "apifactory.h"
#include "tb_enum/api/api.h"


tb_enum::IApiFactory* tb_enum::ApiFactory::s_instance(nullptr);

namespace tb_enum {

ApiFactory::ApiFactory(QObject *parent)
    : QObject(parent)
{
}

void ApiFactory::set(IApiFactory *instance)
{
    if(s_instance) {
        qFatal("Can not set factory when factory already set");
    }
    s_instance = instance;
}

IApiFactory * ApiFactory::get()
{
    if(s_instance) {
        return s_instance;
    }
    return nullptr;
}

std::shared_ptr<AbstractEnumInterface> ApiFactory::createEnumInterface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createEnumInterface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set EnumInterface cannot be created. ";
    return nullptr;
};

} //namespace tb_enum

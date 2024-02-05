#include "apifactory.h"
#include "api.h"


tb_names::IApiFactory* tb_names::ApiFactory::s_instance(nullptr);

namespace tb_names {

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

std::shared_ptr<AbstractNamEs> ApiFactory::createNamEs(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createNamEs(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set NamEs cannot be created. ";
    return nullptr;
};

} //namespace tb_names
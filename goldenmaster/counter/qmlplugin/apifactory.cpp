#include "apifactory.h"
#include "counter/api/api.h"


counter::IApiFactory* counter::ApiFactory::s_instance(nullptr);

namespace counter {

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

std::shared_ptr<AbstractCounter> ApiFactory::createCounter(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createCounter(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set Counter cannot be created. ";
    return nullptr;
};

} //namespace counter

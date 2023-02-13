#include "apifactory.h"
#include "api.h"


testbed1::IApiFactory* testbed1::ApiFactory::s_instance(nullptr);

namespace testbed1 {

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

std::shared_ptr<AbstractStructInterface> ApiFactory::createStructInterface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createStructInterface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set StructInterface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractStructArrayInterface> ApiFactory::createStructArrayInterface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createStructArrayInterface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set StructArrayInterface cannot be created. ";
    return nullptr;
};

} //namespace testbed1
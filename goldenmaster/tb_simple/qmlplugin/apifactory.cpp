#include "apifactory.h"
#include "tb_simple/api/api.h"


tb_simple::IApiFactory* tb_simple::ApiFactory::s_instance(nullptr);

namespace tb_simple {

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

std::shared_ptr<AbstractSimpleInterface> ApiFactory::createSimpleInterface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createSimpleInterface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set SimpleInterface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractSimpleArrayInterface> ApiFactory::createSimpleArrayInterface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createSimpleArrayInterface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set SimpleArrayInterface cannot be created. ";
    return nullptr;
};

} //namespace tb_simple

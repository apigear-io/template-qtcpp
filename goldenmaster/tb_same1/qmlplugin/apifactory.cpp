#include "apifactory.h"
#include "tb_same1/api/api.h"


tb_same1::IApiFactory* tb_same1::ApiFactory::s_instance(nullptr);

namespace tb_same1 {

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

std::shared_ptr<AbstractSameStruct1Interface> ApiFactory::createSameStruct1Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createSameStruct1Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set SameStruct1Interface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractSameStruct2Interface> ApiFactory::createSameStruct2Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createSameStruct2Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set SameStruct2Interface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractSameEnum1Interface> ApiFactory::createSameEnum1Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createSameEnum1Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set SameEnum1Interface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractSameEnum2Interface> ApiFactory::createSameEnum2Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createSameEnum2Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set SameEnum2Interface cannot be created. ";
    return nullptr;
};

} //namespace tb_same1

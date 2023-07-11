#include "apifactory.h"
#include "testbed2/api/api.h"


testbed2::IApiFactory* testbed2::ApiFactory::s_instance(nullptr);

namespace testbed2 {

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

std::shared_ptr<AbstractManyParamInterface> ApiFactory::createManyParamInterface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createManyParamInterface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set ManyParamInterface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractNestedStruct1Interface> ApiFactory::createNestedStruct1Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createNestedStruct1Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set NestedStruct1Interface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractNestedStruct2Interface> ApiFactory::createNestedStruct2Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createNestedStruct2Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set NestedStruct2Interface cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractNestedStruct3Interface> ApiFactory::createNestedStruct3Interface(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createNestedStruct3Interface(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set NestedStruct3Interface cannot be created. ";
    return nullptr;
};

} //namespace testbed2

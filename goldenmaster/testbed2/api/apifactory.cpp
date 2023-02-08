#include "apifactory.h"
#include "simu.h"
#include "api.h"


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
    s_instance = new ApiFactory(QCoreApplication::instance());
    return s_instance;
}

std::shared_ptr<AbstractManyParamInterface> ApiFactory::createManyParamInterface(QObject *parent) 
{
    return std::make_shared<SimulationManyParamInterface>(parent);
};

std::shared_ptr<AbstractNestedStruct1Interface> ApiFactory::createNestedStruct1Interface(QObject *parent) 
{
    return std::make_shared<SimulationNestedStruct1Interface>(parent);
};

std::shared_ptr<AbstractNestedStruct2Interface> ApiFactory::createNestedStruct2Interface(QObject *parent) 
{
    return std::make_shared<SimulationNestedStruct2Interface>(parent);
};

std::shared_ptr<AbstractNestedStruct3Interface> ApiFactory::createNestedStruct3Interface(QObject *parent) 
{
    return std::make_shared<SimulationNestedStruct3Interface>(parent);
};

} //namespace testbed2
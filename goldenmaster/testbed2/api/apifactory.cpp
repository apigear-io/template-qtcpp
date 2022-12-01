#include "apifactory.h"
#include "simu.h"


testbed2::ApiFactoryInterface* testbed2::ApiFactory::s_instance(nullptr);

namespace testbed2 {

ApiFactory::ApiFactory(QObject *parent)
    : QObject(parent)
{
}

void ApiFactory::set(ApiFactoryInterface *instance)
{
    if(s_instance) {
        qFatal("Can not set factory when factory already set");
    }
    s_instance = instance;
}

ApiFactoryInterface * ApiFactory::get()
{
    if(s_instance) {
        return s_instance;
    }
    s_instance = new ApiFactory(QCoreApplication::instance());
    return s_instance;
}

AbstractManyParamInterface* ApiFactory::createManyParamInterface(QObject *parent) 
{
    return new SimulationManyParamInterface(parent);
};

AbstractNestedStruct1Interface* ApiFactory::createNestedStruct1Interface(QObject *parent) 
{
    return new SimulationNestedStruct1Interface(parent);
};

AbstractNestedStruct2Interface* ApiFactory::createNestedStruct2Interface(QObject *parent) 
{
    return new SimulationNestedStruct2Interface(parent);
};

AbstractNestedStruct3Interface* ApiFactory::createNestedStruct3Interface(QObject *parent) 
{
    return new SimulationNestedStruct3Interface(parent);
};

} //namespace testbed2
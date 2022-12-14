#include "apifactory.h"
#include "simu.h"


testbed1::ApiFactoryInterface* testbed1::ApiFactory::s_instance(nullptr);

namespace testbed1 {

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

AbstractStructInterface* ApiFactory::createStructInterface(QObject *parent) 
{
    return new SimulationStructInterface(parent);
};

AbstractStructArrayInterface* ApiFactory::createStructArrayInterface(QObject *parent) 
{
    return new SimulationStructArrayInterface(parent);
};

} //namespace testbed1
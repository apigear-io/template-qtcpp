#include "apifactory.h"
#include "simu.h"


tb_simple::ApiFactoryInterface* tb_simple::ApiFactory::s_instance(nullptr);

namespace tb_simple {

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

AbstractSimpleInterface* ApiFactory::createSimpleInterface(QObject *parent) 
{
    return new SimulationSimpleInterface(parent);
};

AbstractSimpleArrayInterface* ApiFactory::createSimpleArrayInterface(QObject *parent) 
{
    return new SimulationSimpleArrayInterface(parent);
};

} //namespace tb_simple
#include "apifactory.h"
#include "simu.h"


tb_same2::ApiFactoryInterface* tb_same2::ApiFactory::s_instance(nullptr);

namespace tb_same2 {

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

AbstractSameStruct1Interface* ApiFactory::createSameStruct1Interface(QObject *parent) 
{
    return new SimulationSameStruct1Interface(parent);
};

AbstractSameStruct2Interface* ApiFactory::createSameStruct2Interface(QObject *parent) 
{
    return new SimulationSameStruct2Interface(parent);
};

AbstractSameEnum1Interface* ApiFactory::createSameEnum1Interface(QObject *parent) 
{
    return new SimulationSameEnum1Interface(parent);
};

AbstractSameEnum2Interface* ApiFactory::createSameEnum2Interface(QObject *parent) 
{
    return new SimulationSameEnum2Interface(parent);
};

} //namespace tb_same2
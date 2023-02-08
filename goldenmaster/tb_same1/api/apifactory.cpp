#include "apifactory.h"
#include "simu.h"
#include "api.h"


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
    s_instance = new ApiFactory(QCoreApplication::instance());
    return s_instance;
}

std::shared_ptr<AbstractSameStruct1Interface> ApiFactory::createSameStruct1Interface(QObject *parent) 
{
    return std::make_shared<SimulationSameStruct1Interface>(parent);
};

std::shared_ptr<AbstractSameStruct2Interface> ApiFactory::createSameStruct2Interface(QObject *parent) 
{
    return std::make_shared<SimulationSameStruct2Interface>(parent);
};

std::shared_ptr<AbstractSameEnum1Interface> ApiFactory::createSameEnum1Interface(QObject *parent) 
{
    return std::make_shared<SimulationSameEnum1Interface>(parent);
};

std::shared_ptr<AbstractSameEnum2Interface> ApiFactory::createSameEnum2Interface(QObject *parent) 
{
    return std::make_shared<SimulationSameEnum2Interface>(parent);
};

} //namespace tb_same1
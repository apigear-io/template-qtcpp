#include "apifactory.h"
#include "simu.h"
#include "api.h"


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
    s_instance = new ApiFactory(QCoreApplication::instance());
    return s_instance;
}

std::shared_ptr<AbstractSimpleInterface> ApiFactory::createSimpleInterface(QObject *parent) 
{
    return std::make_shared<SimulationSimpleInterface>(parent);
};

std::shared_ptr<AbstractSimpleArrayInterface> ApiFactory::createSimpleArrayInterface(QObject *parent) 
{
    return std::make_shared<SimulationSimpleArrayInterface>(parent);
};

} //namespace tb_simple
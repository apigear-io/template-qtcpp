#include "apifactory.h"
#include "simu.h"
#include "api.h"


testbed1::IApiFactory* testbed1::ApiFactory::s_instance(nullptr);

namespace testbed1 {

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

std::shared_ptr<AbstractStructInterface> ApiFactory::createStructInterface(QObject *parent) 
{
    return std::make_shared<SimulationStructInterface>(parent);
};

std::shared_ptr<AbstractStructArrayInterface> ApiFactory::createStructArrayInterface(QObject *parent) 
{
    return std::make_shared<SimulationStructArrayInterface>(parent);
};

} //namespace testbed1
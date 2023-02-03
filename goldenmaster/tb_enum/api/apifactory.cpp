#include "apifactory.h"
#include "simu.h"


tb_enum::ApiFactoryInterface* tb_enum::ApiFactory::s_instance(nullptr);

namespace tb_enum {

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

std::shared_ptr<AbstractEnumInterface> ApiFactory::createEnumInterface(QObject *parent) 
{
    return std::make_shared<SimulationEnumInterface>(parent);
};

} //namespace tb_enum
#include "apifactory.h"
#include "custom_types/api/api.h"


custom_types::IApiFactory* custom_types::ApiFactory::s_instance(nullptr);

namespace custom_types {

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

} //namespace custom_types

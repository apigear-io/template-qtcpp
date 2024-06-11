#include "apifactory.h"
#include "extern_types/api/api.h"


extern_types::IApiFactory* extern_types::ApiFactory::s_instance(nullptr);

namespace extern_types {

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

} //namespace extern_types

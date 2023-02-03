#include "apifactory.h"
#include "simu.h"


{{ snake .Module.Name }}::ApiFactoryInterface* {{ snake .Module.Name }}::ApiFactory::s_instance(nullptr);

namespace {{snake  .Module.Name }} {

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

{{- range .Module.Interfaces }}

std::shared_ptr<Abstract{{Camel .Name}}> ApiFactory::create{{Camel .Name}}(QObject *parent) 
{
    return std::make_shared<Simulation{{Camel .Name}}>(parent);
};
{{- end }}

} //namespace {{snake  .Module.Name }}
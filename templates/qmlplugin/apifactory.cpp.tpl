#include "apifactory.h"
#include "{{snake .Module.Name}}/api/api.h"


{{ snake .Module.Name }}::IApiFactory* {{ snake .Module.Name }}::ApiFactory::s_instance(nullptr);

namespace {{qtNamespace .Module.Name }} {

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

{{- range .Module.Interfaces }}

std::shared_ptr<Abstract{{Camel .Name}}> ApiFactory::create{{Camel .Name}}(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->create{{Camel .Name}}(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set {{Camel .Name}} cannot be created. ";
    return nullptr;
};
{{- end }}

} //namespace {{qtNamespace .Module.Name }}

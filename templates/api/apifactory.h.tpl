{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace {{snake  .Module.Name }} {

{{- range .Module.Interfaces }}
    class Abstract{{Camel .Name}};
{{- end }}

/** 
* A Factory that creates an implementaion of interfaces in {{ .Module.Name }}.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other IApiFactory implementation.
*/
class {{ $MODULE_ID }}_EXPORT ApiFactory : public QObject, public IApiFactory
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    /** 
    * Use this function to set desired version of interface implementation factory.
    * @param instance. An instance of the factory. This object doesn't take ownership of the factory instance.
    * WARNING this function may be used only once, and only before calling ApiFactory::get(). 
    */
    static void set(IApiFactory* instance);

    /**
    * Set implementation of a factory or object of this type.
    * @return An IApiFactory implementation used to create objects.
    */
    static IApiFactory *get();

{{- range .Module.Interfaces }}
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name }}(QObject *parent) override;
{{- end }}
private:
    static IApiFactory *s_instance;
};

} //namespace {{snake  .Module.Name }}

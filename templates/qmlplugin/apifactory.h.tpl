{{- $MODULE_ID := printf "%s_QML" (SNAKE .Module.Name) }}
#pragma once

#include <QtCore>
#include "{{snake .Module.Name}}/api/iapifactory.h"

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{snake  .Module.Name }} {

{{- range .Module.Interfaces }}
    class Abstract{{Camel .Name}};
{{- end }}

/** 
* A static accesor for ApiFactory - a factory that creates an implementaion of interfaces in {{ .Module.Name }}.
* It is used by Qml versions of interface implementation (instantionated in qml) to provide a backend version.
* A proper factory instance of your choice must be set. This factory by default returns empty interfaces.
* See ApiFactoryInterface implementations.
* See Qml example which uses OlinkFactory.
*/
class {{ $MODULE_ID }}_EXPORT ApiFactory : public QObject, public IApiFactory
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    /** 
    * Use this function to set desired version of interface implementation factory.
    * @param instance. An instance of the factory. This object doesn't take ownership of the factory instance.
    */
    static void set(IApiFactory* instance);

    /**
    * Set implementation of a factory or object of this type.
    * @return An IApiFactory implementation used to create objects.
    * WARNING Make sure a factory is set before calling ApiFactory::get(). 
    */
    static IApiFactory *get();

{{- range .Module.Interfaces }}
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name }}(QObject *parent) override;
{{- end }}
private:
    static IApiFactory *s_instance;
};

} //namespace {{snake  .Module.Name }}

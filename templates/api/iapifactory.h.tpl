{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $module_id := snake .Module.Name }}
{{- cppGpl .Module }}
#pragma once

#include <QtCore>
#include <QtCore/QtGlobal>

#include <memory>


namespace {{qtNamespace .Module.Name }} {

{{- range .Module.Interfaces }}
    class Abstract{{Camel .Name}};
{{- end }}

/**
* An interface for a Factory of interfaces in {{ .Module.Name }}
* May be used to provide different implementations of your interfaces.
* Check the usage of IApiFactory in Qml versions of interface implementation.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class IApiFactory
{
public:
    virtual ~IApiFactory() = default;
{{- range .Module.Interfaces }}
    /** 
    * Create an instance of {{Camel .Name}}
    * @return The implementation of a Abstract{{Camel .Name}}.
    */
    virtual std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent = nullptr) = 0;
{{- end }}
};

} //namespace {{qtNamespace .Module.Name }}

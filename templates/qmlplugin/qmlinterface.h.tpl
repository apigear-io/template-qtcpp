{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := Camel .Interface.Name }}
{{- $namespacePrefix := printf "%s::" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_QML" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>
#include <QQmlEngine>
#include "{{snake .Module.Name}}/api/api.h"
#include <memory>
{{- $Modulename := Camel .Module.Name }}

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif


namespace {{snake .Module.Name }} {

/**
* A QML wrapper of the {{$class}} implementation.
* Uses a {{$class}} backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by {{$class}} backend or
* invoke operations on it. Have in mind that singals provided by {{$class}} backend should be
* emitted only by {{$class}} backend, emitting it on qml will not reach the {{$class}} backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class {{$MODULE_ID}}_EXPORT Qml{{$class}} : public Abstract{{$class}}
{
    Q_OBJECT
    QML_NAMED_ELEMENT({{$Modulename}}{{$class}})
{{- range .Interface.Properties }}
{{ $property := . }}
    /**
    * Exposes {{.Name}} property for qml.
        {{- if $property.Description }}
    * @param {{$property.Name}} {{$property.Description}}
    {{- end }}
    */
    Q_PROPERTY({{qtReturn $namespacePrefix .}} {{.Name}} READ {{.Name}} WRITE set{{Camel .Name}} NOTIFY {{.Name}}Changed)
{{- end }}
public:
    explicit Qml{{$class}}(QObject *parent = nullptr);
    ~Qml{{$class}}() override;

{{- range .Interface.Properties }}
    /**
    * Getter for a {{.Name}} property
    * @return A value for {{.Name}} property provided by backend.
    */
    {{qtReturn $namespacePrefix .}} {{.Name}}() const override;
    /*
    * Setter for a {{.Name}} property, requests the backend to set the {{.Name}} property
    * @param {{qtParam "" .}}  Value to set for  {{.Name}} property.
    */
    void set{{Camel .Name}}({{qtParam $namespacePrefix .}}) override;
{{- end }}

{{- range .Interface.Operations }}
{{ $operation := . }}
    /**
    * Exposes {{camel .Name}} of backend implementation to a qml.
    * {{ $operation.Description }}
{{- range $operation.Params }}
{{- $param := . }}
{{- if $param.Description }}
    * @param {{$param}} {{$param.Description}}
{{- end }}   {{- /* end if param description */}}
{{- end }}   {{- /* end range operation param*/}}  
    */
    Q_INVOKABLE {{qtReturn $namespacePrefix .Return}} {{camel .Name}}({{qtParams $namespacePrefix .Params}}) override;
{{- end }}

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
{{- range .Interface.Properties }}
    void {{.Name}}Changed({{qtParam $namespacePrefix .}});
{{- end }}
private:
    /**
    * Backend of Abstract{{$class}} type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<Abstract{{$class}}> m_obj;
};

} //namespace {{qtNamespace .Module.Name }}

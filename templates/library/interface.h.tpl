{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $classOriginal := .Interface.Name }}
{{- $class := Camel .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $class }}
{{- $interfaceNameOriginal := .Interface.Name  }}
{{- $LIB_ID := printf "%s_IMPL" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/api.h"

#if defined({{ $LIB_ID }}_LIBRARY)
#  define {{ $LIB_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $LIB_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{qtNamespace .Module.Name }} {

/**
* The {{$interfaceNameOriginal}} implementation.
{{- if .Interface.Description }}
*{{.Interface.Description}}
{{- end }}
*/
class {{ $LIB_ID }}_EXPORT {{$class}} : public Abstract{{$class}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() override;

{{ range .Interface.Properties }}
{{- $property := . }}
    {{- if $property.Description }}
    /**
    * {{$property.Name}} {{$property.Description}}
    */
    {{- end }}
    /** @return value of the property {{.Name}} */
    {{qtReturn "" .}} {{.Name}}() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property {{.Name}} 
    */
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Interface.Operations }}
{{- $operation := . }}
{{- if $operation.Description }}
    /**
    * {{$operation.Description}}
    */
{{- end }}
    {{qtReturn "" .Return}} {{camel .Name}}({{qtParams "" .Params}}) override;
{{- end }}

private:
{{- range .Interface.Properties }}
    /** {{.Name}} property */
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};
} //namespace {{qtNamespace .Module.Name }}

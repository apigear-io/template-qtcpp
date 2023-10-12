{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $interfaceClass := printf "Abstract%s" (Camel .Interface.Name) }}
{{- $class := printf "%sTraced" $interfaceName }}
{{- $MODULE_ID := printf "%s_MONITOR" (SNAKE .Module.Name) }}

#pragma once
#include "{{snake .Module.Name}}/api/api.h"
#include "{{snake .Module.Name}}/monitor/agent.h"
#include <memory>

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{ snake .Module.Name }} {

class {{.Interface.Name}}Tracer;

/** 
* Trace decorator for {{ $interfaceName }}.
*/

class {{ $MODULE_ID }}_EXPORT {{$class}} : public {{$interfaceClass}}
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The {{.Interface.Name}} object to trace.
    */
    explicit {{$class}}(std::shared_ptr<{{$interfaceClass}}> impl);
    /** dtor */
    virtual ~{{$class}}() = default;
{{- nl}}

{{- range .Interface.Operations}}
{{- $operation := . }}
    /** Traces {{$operation.Name}} and forwards call to {{$interfaceName}} implementation. */
    {{qtReturn "" .Return }} {{camel .Name}}({{qtParams "" .Params}}) override;
    {{ end -}}
{{- range .Interface.Properties}}
{{- $property := . }}
    /** Traces and forwards call to {{$interfaceName}} implementation. */
    void set{{Camel .Name}}({{qtParam "" .}}) override;
    /** Forwards call to {{$interfaceName}} implementation. */
    {{qtReturn "" .}} {{.Name}}() const override;
    {{ end -}}

slots
{{- range .Interface.Signals}}
{{- $signal := . }}
    /**  Traces {{$signal.Name}} emission. */
    void trace{{Camel $signal.Name}}({{qtParams "" .Params}});
{{- end }}

private:
    /** The {{.Interface.Name}} object which is traced */
    std::shared_ptr<{{$interfaceClass}}> m_impl;
};
} // namespace {{ snake .Module.Name }}

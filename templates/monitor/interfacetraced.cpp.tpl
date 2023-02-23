{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $interfaceClass := printf "Abstract%s" (Camel .Interface.Name) }}
{{- $class := printf "%sTraced" $interfaceName }}
#pragma once
#include "{{lower .Interface.Name}}traced.h"
#include "{{snake .Module.Name}}/monitor/agent.h"

namespace {{ snake .Module.Name }} {


{{$class}}::{{$class}}(std::shared_ptr<{{$interfaceClass}}> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
{{- range .Interface.Signals}}
{{- $signal := . }}
     connect(m_impl.get(), &{{$interfaceClass}}::{{camel $signal.Name}}, this, &{{$class}}::trace{{Camel $signal.Name}});    
{{- end }}

    // Connect signals emitted by implementation with this object.
{{- range .Interface.Signals}}
{{- $signal := . }}
     connect(m_impl.get(), &{{$interfaceClass}}::{{camel $signal.Name}}, this, &{{$class}}::trace{{Camel $signal.Name}});    
{{- end }}

    // Connect property changed signals emitted by implementation with this object.
{{- range .Interface.Properties }}
    connect(m_impl.get(), &{{$interfaceClass}}::{{.Name}}Changed, this, &{{$interfaceClass}}::{{.Name}}Changed);
{{- end }}
}

{{- range .Interface.Operations}}
{{- $operation := . }}

{{qtReturn "" $operation.Return }} {{$class}}::{{lower1 $operation.Name}}({{qtParams "" $operation.Params}}) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {{ if(not ($operation.Return.IsVoid)) }} {} {{ end }};
    }
    {{$interfaceName}}Agent::trace_{{$operation.Name}}(this, {{qtVars $operation.Params}});
    {{ if (not ($operation.Return.IsVoid)) }}return {{ end }}m_impl->{{lower1 $operation.Name}}({{ qtVars $operation.Params}});
}
{{ end -}}

{{- range .Interface.Properties}}
{{- $property := . }}
void {{$class}}::set{{Camel $property.Name}}({{qtParam "" $property}})
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    {{$interfaceName}}Agent::trace_state(this);
    m_impl->set{{Camel $property.Name}}({{qtVar $property}});
}
{{qtReturn "" $property}} {{$class}}::{{$property.Name}}() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->{{$property.Name}}();
}
{{ end -}}


{{- range .Interface.Signals}}
{{- $signal := . }}
void {{$class}}::trace{{Camel $signal.Name}}({{qtParams "" $signal.Params}})
{
    {{$interfaceName}}Agent::trace_{{$signal.Name}}(this, {{qtVars $signal.Params}});
}
{{- end }}

} // namespace {{ snake .Module.Name }}

{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $module := .Module.Name -}}
#include "agent.h"
#include "../../shared/agentclient.h"

{{- range .Module.Interfaces }}
{{- $class := printf "%sAgent" .Name }}
{{- $iface := .Name }}

{{$class}}::{{$class}}()
{
}

QVariantMap {{$class}}::capture_state(Abstract{{.Name}}* obj)
{
    return QVariantMap{
    {{- range .Properties }}
        { "{{.Name}}", QVariant::fromValue(obj->{{.Name}}()) },
    {{- end }}
    };
}

void {{$class}}::trace_state(Abstract{{.Name}}* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    AgentClient::instance()->traceState("{{$module}}.{{.Name}}", fields_);
}
{{- $iface := .Name }}
{{- range .Operations }}
void {{$class}}::trace_{{.Name}}(Abstract{{$iface}}* obj, {{qtParams "" .Params}})
{
    const QVariantMap &params_ {
        {{- range  .Params }}
        { "{{.Name}}", QVariant::fromValue({{.Name}}) },
        {{- end }}
    };
    AgentClient::instance()->traceCall("{{$module}}.{{$iface}}#{{.Name}}", params_);
}
{{- end }}
{{- end }}
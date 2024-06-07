{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $module := .Module.Name -}}
#include "agent.h"
#include "apigear/monitor/agentclient.h"

namespace {{qtNamespace .Module.Name }} {

{{- range .Module.Interfaces }}
{{- $iface := Camel .Name }}
{{- $class := printf "%sAgent" $iface}}

{{$class}}::{{$class}}()
{
}

QVariantMap {{$class}}::capture_state(Abstract{{Camel .Name}}* obj)
{
    return QVariantMap{
    {{- range .Properties }}
        { "{{.Name}}", QVariant::fromValue(obj->{{.Name}}()) },
    {{- end }}
    };
}

void {{$class}}::trace_state(Abstract{{Camel .Name}}* obj)
{
    const QVariantMap &fields_ = capture_state(obj);
    ApiGear::Monitor::AgentClient::instance()->traceState("{{$module}}.{{.Name}}", fields_);
}
{{- range .Operations }}
void {{$class}}::trace_{{.Name}}(Abstract{{$iface}}* obj{{- if (len .Params) }},{{ end}} {{qtParams "" .Params}})
{
    const QVariantMap &params_ {
        {{- range  .Params }}
        { "{{.Name}}", QVariant::fromValue({{.Name}}) },
        {{- end }}
    };
    ApiGear::Monitor::AgentClient::instance()->traceCall("{{$module}}.{{$iface}}#{{.Name}}", params_);
}
{{- end }}

{{- range .Signals }}
void {{$class}}::trace_{{.Name}}(Abstract{{$iface}}* obj{{- if (len .Params) }},{{ end}} {{qtParams "" .Params}})
{
    const QVariantMap &params_ {
        {{- range  .Params }}
        { "{{.Name}}", QVariant::fromValue({{.Name}}) },
        {{- end }}
    };
    ApiGear::Monitor::AgentClient::instance()->traceSignal("{{$module}}.{{$iface}}#{{.Name}}", params_);
}
{{- end }}

{{- end }}

} // namespace {{qtNamespace .Module.Name }}
#include "simu.h"
#include "jsonrpc/types.h"
#include "json.adapter.h"
#include "apigear/simulation/simulationclient.h"
{{- $module := .Module.Name }}

using namespace ApiGear::JSONRPC;

namespace {{snake  .Module.Name }} {

{{- range .Module.Interfaces }}
{{- $iface := .Name }}
{{- $class := printf "Simulation%s" (Camel .Name) }}
// ********************************************************************
// {{$class}} simulation interface
// ********************************************************************

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{Camel .Name}}(parent)
{{- range .Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{
    NotifyRequestFunc serviceStateFunc = [this](NotifyRequestArg arg) {
      qDebug() << "{{$class}} service state changes: " << QString::fromStdString(arg.params.dump());
      {{- range .Properties }}
      if(arg.params.contains("{{.Name}}")) {
        set{{Camel .Name}}(arg.params["{{.Name}}"]);
      }
      {{- end }}
    };
    ApiGear::SimulationClient::instance()->onNotifyState("{{$module}}/{{.Name}}", serviceStateFunc);

    CallResponseFunc fetchStateFunc = [this](CallResponseArg arg) {
      qDebug() << "{{$class}} service fetch state: " << QString::fromStdString(arg.result.dump());
      {{- range .Properties }}
      if(arg.result.contains("{{.Name}}")) {
        set{{Camel .Name}}(arg.result["{{.Name}}"]);
      }
      {{- end }}
    };
    ApiGear::SimulationClient::instance()->doFetchState("{{$module}}/{{$iface}}", fetchStateFunc);

{{- range .Signals }}
{{- $signalName := camel .Name }}
    NotifyRequestFunc {{.Name}}Func = [this](NotifyRequestArg arg) { 
        emit {{$signalName}}(
        {{- range $i, $e := .Params -}}
            {{if $i}},{{end}}arg.params["{{.Name}}"].get<{{qtReturn "" .}}>()
        {{- end -}}
        );
    };
    ApiGear::SimulationClient::instance()->onNotify("{{$module}}/{{$iface}}#{{.Name}}", {{.Name}}Func);
{{- end }}
}

{{$class}}::~{{$class}}()
{
}

{{- range .Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}
{{- range .Operations }}

{{qtReturn "" .Return}} {{$class}}::{{camel .Name}}({{qtParams "" .Params}})
{
    qDebug() << "simu::" << Q_FUNC_INFO;

    Params params;
    {{- range  .Params }}
    params["{{.Name}}"] = {{.Name}};
    {{- end }}
    ApiGear::SimulationClient::instance()->doCall("{{$module}}/{{$iface}}", "{{.Name}}", params);
    return {{qtDefault "" .Return}};
}
{{- end }}
{{- end }}

} //namespace {{snake  .Module.Name }}

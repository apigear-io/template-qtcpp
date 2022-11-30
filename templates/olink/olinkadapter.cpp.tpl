{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}
{{- $iface := .Interface.Name }}
{{- $module := .Module.Name }}



#include "{{lower $class}}.h"
{{- $iface := .Interface.Name }}

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

{{$class}}::{{$class}}(RemoteRegistry& registry, Abstract{{$iface}}* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
    m_registry.addObjectSource(this);
    
{{- range .Interface.Properties }}
    connect(m_impl, &Abstract{{$iface}}::{{.Name}}Changed, this, [=]({{qtParam "" .}}) {
        if(m_node) {
            m_node->notifyPropertyChange("{{.Module.Name}}.{{$iface}}/{{.Name}}", {{.Name}});
        }
    });
{{- end }}    
{{- range .Interface.Signals }}
    connect(m_impl, &Abstract{{$iface}}::{{.Name}}, this, [=]({{qtParams "" .Params}}) {
        if(m_node) {
            const json& args = { {{ qtVars .Params }} };
            m_node->notifySignal("{{$module}}.{{$iface}}/{{.Name}}", args);
        }
    });
{{- end }}
}

{{$class}}::~{{$class}}()
{
    m_registry.removeObjectSource(this);
}

json {{$class}}::captureState()
{
    return json::object({
{{- range $i, $e := .Interface.Properties }}{{if $i}},{{end}}
        { "{{.Name}}", m_impl->{{.Name}}() }
{{- end }}
    });
}

void {{$class}}::applyState(const json& state)
{
{{- range .Interface.Properties }}
    if(state.contains("{{.Name}}")) {
        m_impl->set{{Camel .Name}}(state["{{.Name}}"]);
    }    
{{- end }}
}


std::string {{$class}}::olinkObjectName() {
    return "{{$module}}.{{$iface}}";
}

json {{$class}}::olinkInvoke(std::string name, json args) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
{{- range .Interface.Operations }}
    if(path == "{{.Name}}") {
{{- range  $i, $e := .Params }}
        const {{qtType "" .}}& {{.Name}} = args.at({{ $i }});      
{{- end }}
{{- if .Return.IsVoid }}
        m_impl->{{.Name}}({{ .Params }});
        return json{};
{{- else }}
        {{qtReturn "" .Return}} result = m_impl->{{.Name}}({{ qtVars .Params }});
        return result;
{{- end }}
    }
{{- end }}
    return json();
}

void {{$class}}::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
{{- range .Interface.Properties }}
    if(path == "{{.Name}}") {
        {{qtReturn "" .}} {{.Name}} = value.get<{{qtReturn "" .}}>();
        m_impl->set{{Camel .Name}}({{.Name}});
    }
{{- end }}    
}

void {{$class}}::olinkLinked(std::string name, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = node;
}

void {{$class}}::olinkUnlinked(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node = nullptr;
}

json {{$class}}::olinkCollectProperties()
{
    return captureState();
}





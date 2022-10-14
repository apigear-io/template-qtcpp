{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $class := printf "Olink%sAdapter" .Name }}
{{- $iface := .Name }}
{{- $module := .Module.Name }}


#include "{{lower $class}}.h"
{{- $iface := .Name }}
#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

{{$class}}::{{$class}}(Abstract{{.Name}}* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_node(nullptr)
{
    RemoteRegistry::get().addObjectSource(this);
    
{{- range .Properties }}
    connect(m_impl, &Abstract{{.Name}}::{{.Name}}Changed, this, [=]({{qtParam "" .}}) {
        if(m_node) {
            m_node->notifyPropertyChange("{{.Module.Name}}.{{.Name}}/{{.Name}}", {{.Name}});
        }
    });
{{- end }}    
{{- range .Signals }}
    connect(m_impl, &Abstract{{$iface}}::{{.Name}}, this, [=]({{qtParams "" .Params}}) {
        if(m_node) {
            const json& args = { {{ .Params }} };
            m_node->notifySignal("{{$module}}.{{$iface}}/{{.Name}}", args);
        }
    });
{{- end }}
}

{{$class}}::~{{$class}}()
{
    RemoteRegistry::get().removeObjectSource(this);
}

json {{$class}}::captureState()
{
    return json::object({
{{- range .Properties }}
        { "{{.Name}}", m_impl->{{.Name}}() }{% unless forloop.last %},{% endunless %}
{{- end }}
    });
}

void {{$class}}::applyState(const json& state)
{
{{- range .Properties }}
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
{{- range .Operations }}
    if(path == "{{.Name}}") {
{{- range  $i, $e := .Params }}
        const {{qtReturn "" .}}& {{.Name}} = args.at({{ $i }});      
{{- end }}
{{ if .Return.IsVoid }}
        m_impl->{{.Name}}({{ .Params }});
        return json{};
{{ else }}
        {{qtReturn "" .Return}} result = m_impl->{{.Name}}({{ .Params }});
        return result;
{{- end }}
    }
{{- end }}
    return json();
}

void {{$class}}::olinkSetProperty(std::string name, json value) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
{{- range .Properties }}
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





{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "Olink%s" .Name }}
{{- $module := .Module.Name }}
{{- $iface := .Name }}
#include "{{lower $class}}.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{.Name}}(parent)
{{- range .Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

{{$class}}::~{{$class}}()
{
    ClientRegistry::get().removeObjectSink(this);
}

void {{$class}}::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
{{- range .Properties }}
    if(fields.contains("{{.Name}}")) {
        set{{Camel .Name}}Local(fields["{{.Name}}"].get<{{qtReturn "" .}}>());
    }
{{- end }}
}

{{- range .Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("{{$module}}.{{$iface}}/{{.Name}}", {{.Name}});
}

void {{$class}}::set{{Camel .Name}}Local({{qtParam "" .}})
{
    qDebug() << Q_FUNC_INFO;
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
        {{.Name}}Agent::trace_state(this);
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}


{{- range .Operations }}
{{- $return := (qtReturn "" .Return)}}

{{$return}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return {{qtDefault "" .Return}};
    }
    {{ if .Return.IsVoid }}
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const json &args = json::array({
        {{ .Params }}
    });
    m_node->invokeRemote("{{$module_id}}.{{$iface}}/{{.Name}}", args, func);
    {% else %}
    {{$return}} value{ {{qtDefault "" .Return}} };
    {{.Name}}Async({{ .Params }})
        .then([&]({{$return}} result) {
            value = result;
        })
        .wait();
    return value;
    {{- end }}
}

QtPromise::QPromise<{{$return}}> {{$class}}::{{.Name}}Async({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<{{$return}}>::reject("not initialized");
    }
    {{ if .Return.IsVoid }}
    m_node->invokeRemote("{{$module}}.{{$iface}}/{{.Name}}", json::array({
            {{ range $i, $e := .Params }}{{if $i}}, {{end}}
                {{.Name}}
            {{- end }}}));
    return QtPromise::QPromise<void>::resolve();
    {{- else}}
    return QtPromise::QPromise<{{$return}}>{[&](
        const QtPromise::QPromiseResolve<{{$return}}>& resolve) {
            m_node->invokeRemote("{{$module}}.{{$iface}}/{{.Name}}", json::array({
            {{- range $i, $e := .Params }}
                {{if $i}}, {{end}}{{.Name}}
            {{- end }}}), [resolve](InvokeReplyArg arg) {                
                const {{$return}}& value = arg.value.get<{{$return}}>();
                resolve(value);
            });
        }
    };
    {{- end}}
}

{{- end }}


std::string {{$class}}::olinkObjectName()
{
    return "{{$module}}.{{$iface}}";
}

void {{$class}}::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
{{- range .Signals }}
    if(path == "{{.Name}}") {
        emit {{.Name}}(
{{- range $i, $e := .Params }}
        {{if $i}}, {{end}}args[{{$i}}].get<{{qtReturn "" .}}>()
{{- end }}
        );   
        return;
    }
{{- end }}
}

void {{$class}}::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void {{$class}}::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void {{$class}}::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}



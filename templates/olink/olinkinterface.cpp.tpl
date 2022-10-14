{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "OLink%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}
#include "{{lower $class}}.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{.Interface.Name}}(parent)
{{- range .Interface.Properties }}
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
{{- range .Interface.Properties }}
    if(fields.contains("{{.Name}}")) {
        set{{Camel .Name}}Local(fields["{{.Name}}"].get<{{qtReturn "" .}}>());
    }
{{- end }}
}

{{- range .Interface.Properties }}

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
        {{$iface}}Agent::trace_state(this);
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}


{{- range .Interface.Operations }}
{{- $return := (qtReturn "" .Return)}}

{{$return}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return {{qtDefault "" .Return}};
    }
    {{- if .Return.IsVoid }}
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const json &args = json::array({
        {{ .Params }}
    });
    m_node->invokeRemote("{{$module_id}}.{{$iface}}/{{.Name}}", args, func);
    {{- else }}
    {{$return}} value{ {{qtDefault "" .Return}} };
    {{.Name}}Async({{ qtVars .Params }})
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
    {{- if .Return.IsVoid }}
    m_node->invokeRemote("{{$module}}.{{$iface}}/{{.Name}}", json::array({
            {{ range $i, $e := .Params }}{{if $i}}, {{end}}
                {{.Name}}
            {{- end }}}));
    return QtPromise::QPromise<void>::resolve();
    {{- else }}
    return QtPromise::QPromise<{{$return}}>{[&](
        const QtPromise::QPromiseResolve<{{$return}}>& resolve) {
            m_node->invokeRemote("{{$module}}.{{$iface}}/{{.Name}}", json::array({
            {{- range $i, $e := .Params }}{{if $i}},{{end}}{{.Name}}
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
{{- range .Interface.Signals }}
    if(path == "{{.Name}}") {
        emit {{.Name}}(
{{- range $i, $e := .Params }}{{if $i}},{{end -}}
    args[{{$i}}].get<{{qtReturn "" .}}>()
{{- end -}}
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



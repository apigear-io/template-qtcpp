{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "OLink%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}
#include "{{lower $class}}.h"

#include "{{snake .Module.Name}}/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace {{snake  .Module.Name }} {

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{Camel .Interface.Name}}(parent)
{{- range .Interface.Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void {{$class}}::applyState(const nlohmann::json& fields) 
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
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}


{{- range .Interface.Operations }}
{{- $return := (qtReturn "" .Return)}}

{{$return}} {{$class}}::{{camel .Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return {{qtDefault "" .Return}};
    }
    {{- if .Return.IsVoid }}
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const nlohmann::json &args = nlohmann::json::array({
        {{ .Params }}
    });
    m_node->invokeRemote("{{$module_id}}.{{$iface}}/{{.Name}}", args, func);
    {{- else }}
    {{$return}} value{ {{qtDefault "" .Return}} };
    {{camel .Name}}Async({{ qtVars .Params }})
        .then([&]({{$return}} result) {
            value = result;
        })
        .wait();
    return value;
    {{- end }}
}

QtPromise::QPromise<{{$return}}> {{$class}}::{{camel .Name}}Async({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<{{$return}}>::reject("not initialized");
    }
    {{- if .Return.IsVoid }}
    m_node->invokeRemote("{{$module}}.{{$iface}}/{{.Name}}", nlohmann::json::array({
            {{ range $i, $e := .Params }}{{if $i}}, {{end}}
                {{.Name}}
            {{- end }}}));
    return QtPromise::QPromise<void>::resolve();
    {{- else }}
    return QtPromise::QPromise<{{$return}}>{[&](
        const QtPromise::QPromiseResolve<{{$return}}>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}}");
            m_node->invokeRemote(operationId, nlohmann::json::array({
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

void {{$class}}::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
{{- range .Interface.Signals }}
{{- $signalName := camel .Name }}
    if(signalName == "{{.Name}}") {
        emit {{$signalName}}(
{{- range $i, $e := .Params }}{{if $i}},{{end -}}
    args[{{$i}}].get<{{qtReturn "" .}}>()
{{- end -}}
        );   
        return;
    }
{{- end }}
}

void {{$class}}::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void {{$class}}::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
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

} //namespace {{snake  .Module.Name }}

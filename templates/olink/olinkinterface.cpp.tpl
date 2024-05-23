{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "OLink%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}
#include "{{lower $class}}.h"

#include "{{snake .Module.Name}}/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>
#include <QtConcurrent>

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
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void {{$class}}::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
{{- range .Interface.Properties }}
    if(fields.contains("{{.Name}}")) {
        set{{Camel .Name}}Local(fields["{{.Name}}"].get<{{qtReturn "" .}}>());
    }
{{- end }}
}

void {{$class}}::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
{{- range $idx, $property := .Interface.Properties }}
    {{ if $idx }}else {{ end -}}if ( propertyName == "{{$property.Name}}") {
        set{{Camel $property.Name}}Local(value.get<{{qtReturn "" .}}>());
    }
{{- else -}}
    // no properties to apply state {{- /* we generate anyway for consistency */}}
    (void) propertyName;
    (void) value;
{{- end }}
}

{{- range .Interface.Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("{{$module}}.{{$iface}}/{{.Name}}", {{.Name}});
}

void {{$class}}::set{{Camel .Name}}Local({{qtParam "" .}})
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
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
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto future = {{camel .Name}}Async({{ qtVars .Params }});
    future.waitForFinished();
    {{- if .Return.IsVoid }}
    return;
    {{- else}}
    return future.result();
    {{- end }}
}

QFuture<{{$return}}> {{$class}}::{{camel .Name}}Async({{qtParams "" .Params}})
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto resolve = std::make_shared<QPromise<{{$return}}>>();
    if(!m_node) {
        static auto noConnectionLogMessage = "Cannot request call on service + {{$class}}::{{camel .Name}}, client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(noConnectionLogMessage);
        {{- if .Return.IsVoid }}
            resolve->finish();
        {{- else }}
            resolve->addResult({{qtDefault "" .Return}});
        {{- end}}
    }
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}}");
    m_node->invokeRemote(operationId, nlohmann::json::array({
            {{- range $i, $e := .Params }}{{if $i}},{{end}}{{.Name}}
            {{- end }}}), 
            [resolve](InvokeReplyArg arg) {         
                {{- if .Return.IsVoid }}
                resolve->finish();
                {{- else }}
                {{$return}} value = arg.value.get<{{$return}}>();
                resolve->addResult(value);
                {{- end}}
            });
    return resolve->future();
}

{{- end }}


std::string {{$class}}::olinkObjectName()
{
    return "{{$module}}.{{$iface}}";
}

void {{$class}}::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
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
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyProperty(propertyName, value);
}
void {{$class}}::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void {{$class}}::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace {{snake  .Module.Name }}

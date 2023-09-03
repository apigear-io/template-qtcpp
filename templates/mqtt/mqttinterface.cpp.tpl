{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{-  cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "Mqtt%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}

{{- $hasNonVoidOperations := 0 -}}
{{- range .Interface.Operations }}
    {{- if not (.Return.IsVoid) }}
        {{- $hasNonVoidOperations = 1 }}
    {{- end }}
{{- end }}

#include "{{lower $class}}.h"

#include "{{snake .Module.Name}}/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace {{snake  .Module.Name }} {

namespace
{
const QString ID = "{{$module}}/{{$iface}}";
}

{{$class}}::{{$class}}(ApiGear::Mqtt::Client& client, QObject *parent)
    : Abstract{{Camel .Interface.Name}}(parent)
{{- range .Interface.Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
    , m_isReady(false)
    , m_client(client)
{
    if (m_client.isReady())
    {
        {{- if (len .Interface.Properties) }}
        subscribeForPropertiesChanges();
        {{- end }}
        {{- if (len .Interface.Signals) }}
        subscribeForSignals();
        {{- end }}
        {{- if $hasNonVoidOperations }}
        subscribeForInvokeResponses();
        {{- end }}
    }
     connect(&m_client, &ApiGear::Mqtt::Client::ready, [this](){
        AG_LOG_DEBUG(Q_FUNC_INFO);

            {{- if (len .Interface.Properties) }}
            subscribeForPropertiesChanges();
            {{- end }}
            {{- if (len .Interface.Signals) }}
            subscribeForSignals();
            {{- end }}
            {{- if $hasNonVoidOperations }}
            subscribeForInvokeResponses();
            {{- end }}
    });
}

{{$class}}::~{{$class}}()
{
    for(auto id :m_subscribedIds)
    {
        m_client.unsubscribeTopic(id);
    }
    for(auto info :m_InvokeCallsInfo)
    {
        m_client.unsubscribeTopic(info.second.second);
    }
}

{{- range .Interface.Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    static const QString topic = objectName() + QString("/set/{{.Name}}");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, { {{.Name}} });
}

void {{$class}}::set{{Camel .Name}}Local(const nlohmann::json& input)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_{{.Name}}(input.get<{{qtReturn "" .}}>());
    if (m_{{.Name}} != in_{{.Name}})
    {
        m_{{.Name}} = in_{{.Name}};
        emit {{.Name}}Changed(in_{{.Name}});
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
    if(!m_client.isReady()) {
        return{{ if (not .Return.IsVoid) }} {{qtDefault "" .Return}} {{- end}};
    }
    {{- if .Return.IsVoid }}
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    auto arguments = nlohmann::json::array({
        {{- qtVars .Params -}}
    });
    static const QString topic = objectName() + QString("/rpc/{{.Name}}");
    m_client.invokeRemoteNoResponse(topic, arguments);
    {{- else }}
    {{$return}} value{ {{qtDefault "" .Return}} };
    {{camel .Name}}Async({{ qtVars .Params }})
        .then([&]({{$return}} result) {value = result;})
        .wait();
    return value;
    {{- end }}
}

QtPromise::QPromise<{{$return}}> {{$class}}::{{camel .Name}}Async({{qtParams "" .Params}})
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    static const QString topic = objectName() + QString("/rpc/{{.Name}}");

    if(!m_client.isReady())
    {
        return QtPromise::QPromise<{{$return}}>::reject("not initialized");
    }

    {{- if .Return.IsVoid }}
    auto arguments = nlohmann::json::array({ {{- range $i, $e := .Params }}{{if $i}}, {{ end }}{{.Name}}{{- end }} });
    m_client.invokeRemoteNoResponse(topic, arguments);
    return QtPromise::QPromise<void>::resolve();
    {{- else }}
    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_DEBUG(subscriptionIssues);
        return QtPromise::QPromise<{{$return}}>::reject("not initialized");
    }
    auto respTopic = callInfo->second.first;
    auto respSubscriptionId = callInfo->second.second;
    auto arguments = nlohmann::json::array({ {{- range $i, $e := .Params }}{{if $i}}, {{ end }}{{.Name}}{{- end }} });       
    return QtPromise::QPromise<{{$return}}>{[&](
        const QtPromise::QPromiseResolve<{{$return}}>& resolve)
        {
                m_client.invokeRemote(topic, arguments, respTopic, respSubscriptionId,
                [resolve](const auto& arg)
                {
                    {{$return}} value = arg.get<{{$return}}>();
                    resolve(value);
                });
        }
    };
    {{- end}}
}

{{- end }}


const QString& {{$class}}::objectName()
{
    return ID;
}


{{- if (len .Interface.Properties) }}
void {{$class}}::subscribeForPropertiesChanges()
{
    {{- range .Interface.Properties }}
        static const QString topic{{.Name}} = objectName() + "/prop/{{.Name}}";
        m_subscribedIds.push_back(m_client.subscribeTopic(topic{{.Name}}, [this](auto& input) { set{{Camel .Name}}Local(input);}));

    {{- end }}
}
{{- end }}

{{- if (len .Interface.Signals) }}
void {{$class}}::subscribeForSignals()
{
    {{- range .Interface.Signals }}
        static const QString topic{{.Name}} = objectName() + "/sig/{{.Name}}";
        m_subscribedIds.push_back(m_client.subscribeTopic(topic{{.Name}}, [this](const auto& input){
            emit {{camel .Name}}( {{- range $i, $e := .Params }}{{if $i}},{{end -}}
            input[{{$i}}].get<{{qtReturn "" .}}>(){{- end -}});}));

    {{- end }}
}
{{- end }}
{{- if $hasNonVoidOperations }}
void {{$class}}::subscribeForInvokeResponses()
{
    // Subscribe for invokeReply and prepare invoke call info for non void functions.
{{- range .Interface.Operations }}
{{- if not (.Return.IsVoid) }}
    const QString topic{{.Name}} = objectName() + "/rpc/{{.Name}}";
    const QString topic{{.Name}}InvokeResp = objectName() + "/rpc/{{.Name}}"+ m_client.clientId() + "/result";
    auto id_{{.Name}} = m_client.subscribeForInvokeResponse(topic{{.Name}}InvokeResp);
    m_InvokeCallsInfo[topic{{.Name}}] = std::make_pair(topic{{.Name}}InvokeResp, id_{{.Name}});
{{- end }}
{{- end }}
}
{{- end }}


} // namespace {{snake  .Module.Name }}

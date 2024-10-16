{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{-  cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "Mqtt%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}

#include "{{lower $class}}.h"

#include "{{snake .Module.Name}}/api/json.adapter.h"
#include "utilities/logger.h"

#include <QtCore>

namespace {{qtNamespace .Module.Name }} {

namespace
{
const QString InterfaceName = "{{$module}}/{{$iface}}";
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
        {{- if (len .Interface.Operations) }}
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
            {{- if (len .Interface.Operations) }}
            subscribeForInvokeResponses();
            {{- end }}
    });
    connect(&m_client, &ApiGear::Mqtt::Client::disconnected, [this](){
        m_subscribedIds.clear();
        m_InvokeCallsInfo.clear();
    });
}

{{$class}}::~{{$class}}()
{
    disconnect(&m_client, &ApiGear::Mqtt::Client::disconnected, 0, 0);
    disconnect(&m_client, &ApiGear::Mqtt::Client::ready, 0, 0);
    unsubscribeAll();
}

{{- range .Interface.Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    static const QString topic = interfaceName() + QString("/set/{{.Name}}");
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_client.isReady())
    {
        return;
    }
    m_client.setRemoteProperty(topic, nlohmann::json( {{.Name}} ));
}

void {{$class}}::set{{Camel .Name}}Local(const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto in_{{.Name}}(value.get<{{qtReturn "" .}}>());
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
    static const QString topic = interfaceName() + QString("/rpc/{{.Name}}");
    auto promise = std::make_shared<QPromise<{{$return}}>>();
    if(!m_client.isReady())
    {
        static auto subscriptionIssues = "Trying to send a message for "+ topic+", but client is not connected. Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        {{- if .Return.IsVoid }}
            promise->finish();
        {{- else }}
            promise->addResult({{qtDefault "" .Return}});
        {{- end}}
    }

    auto callInfo = m_InvokeCallsInfo.find(topic);
    if(callInfo == m_InvokeCallsInfo.end())
    {
        static auto subscriptionIssues = "Could not perform operation "+ topic+". Try reconnecting the client.";
        AG_LOG_WARNING(subscriptionIssues);
        {{- if .Return.IsVoid }}
            promise->finish();
        {{- else }}
            promise->addResult({{qtDefault "" .Return}});
        {{- end}}
    }
    auto respTopic = callInfo->second.first;
    auto arguments = nlohmann::json::array({ {{- range $i, $e := .Params }}{{if $i}}, {{ end }}{{.Name}}{{- end }} });       

    auto func = [promise](const nlohmann::json& arg)
        {
        {{- if .Return.IsVoid }}
            promise->finish();
        {{- else }}
            {{$return}} value = arg.get<{{$return}}>();
            promise->addResult(value);
        {{- end}}
        };
    auto callId = m_client.invokeRemote(topic, arguments, respTopic);
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    m_pendingCallsInfo[callId] = std::make_pair(respTopic,func);
    lock.unlock();
    return promise->future();
}

{{- end }}


const QString& {{$class}}::interfaceName()
{
    return InterfaceName;
}


{{- if (len .Interface.Properties) }}
void {{$class}}::subscribeForPropertiesChanges()
{
    {{- range .Interface.Properties }}
        const QString topic{{.Name}} = interfaceName() + "/prop/{{.Name}}";
        m_subscribedIds.push_back(m_client.subscribeTopic(topic{{.Name}}, [this](auto& value) { set{{Camel .Name}}Local(value);}));

    {{- end }}
}
{{- end }}

{{- if (len .Interface.Signals) }}
void {{$class}}::subscribeForSignals()
{
    {{- range .Interface.Signals }}
        const QString topic{{.Name}} = interfaceName() + "/sig/{{.Name}}";
        m_subscribedIds.push_back(m_client.subscribeTopic(topic{{.Name}}, [this](const nlohmann::json& argumentsArray){
            emit {{camel .Name}}( {{- range $i, $e := .Params }}{{if $i}},{{end -}}
            argumentsArray[{{$i}}].get<{{qtReturn "" .}}>(){{- end -}});}));

    {{- end }}
}
{{- end }}
{{- if (len .Interface.Operations) }}
void {{$class}}::subscribeForInvokeResponses()
{
{{- range .Interface.Operations }}
    const QString topic{{.Name}} = interfaceName() + "/rpc/{{.Name}}";
    const QString topic{{.Name}}InvokeResp = interfaceName() + "/rpc/{{.Name}}"+ m_client.clientId() + "/result";
    auto id_{{.Name}} = m_client.subscribeForInvokeResponse(topic{{.Name}}InvokeResp, 
                        [this, topic{{.Name}}InvokeResp](const nlohmann::json& value, quint64 callId)
                        {
                            findAndExecuteCall(value, callId, topic{{.Name}}InvokeResp);
                        });
    m_InvokeCallsInfo[topic{{.Name}}] = std::make_pair(topic{{.Name}}InvokeResp, id_{{.Name}});
{{- end }}
}
{{- end }}

void {{$class}}::unsubscribeAll()
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

void {{$class}}::findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic)
{
    std::function <void(const nlohmann::json&)> function;
    auto lock = std::unique_lock<std::mutex>(m_pendingCallMutex);
    auto call = m_pendingCallsInfo.find(callId);
    if (call!= m_pendingCallsInfo.end())
    {
        if (call->second.first == topic)
        {
            function = call->second.second;
            m_pendingCallsInfo.erase(call);
            lock.unlock();
        }
        else
        {
            lock.unlock();
            static std::string log = "Your call went wrong. An answear is no longer expected for ";
            AG_LOG_WARNING(log);
            AG_LOG_WARNING(topic.toStdString());
        }
    }
    if (function) function(value);
}

} // namespace {{qtNamespace .Module.Name }}

{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "Mqtt%sAdapter" .Interface.Name }}
{{- $iface := Camel .Interface.Name }}
{{- $module := .Module.Name }}


#include "{{lower $class}}.h"
#include "{{snake .Module.Name}}/api/json.adapter.h"

#include "utilities/logger.h"

#include <nlohmann/json.hpp>

#include <QtCore>


namespace {{qtNamespace .Module.Name }} {

namespace
{
const QString InterfaceName = "{{$module}}/{{$iface}}";
}


{{$class}}::{{$class}}(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<Abstract{{$iface}}> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_finishedInitialization(false)
    , m_mqttServiceAdapter(mqttServiceAdapter)
{
    if (m_mqttServiceAdapter.isReady())
    {
        {{- if (len .Interface.Properties) }}
        subscribeForPropertiesChanges();
        {{- end }}
        {{- if (len .Interface.Operations) }}
        subscribeForInvokeRequests();
        {{- end }}
        {{- if (len .Interface.Properties) }}
        connectServicePropertiesChanges();
        {{- end }}
        {{- if (len .Interface.Signals) }}
        connectServiceSignals();
        {{- end }}
    }
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, [this]()
    {
        {{- if (len .Interface.Properties) }}
        subscribeForPropertiesChanges();
        {{- end }}
        {{- if (len .Interface.Operations) }}
        subscribeForInvokeRequests();
        {{- end }}
        {{- if (len .Interface.Properties) }}
        connectServicePropertiesChanges();
        {{- end }}
        {{- if (len .Interface.Signals) }}
        connectServiceSignals();
        {{- end }}
        m_finishedInitialization = true;
    });
    
    connect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, [this](){
    AG_LOG_DEBUG(Q_FUNC_INFO);
        m_subscribedIds.clear();
    });
    m_finishedInitialization = m_mqttServiceAdapter.isReady();
}

{{$class}}::~{{$class}}()
{
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::disconnected, 0, 0);
    disconnect(&m_mqttServiceAdapter, &ApiGear::Mqtt::ServiceAdapter::ready, 0, 0);
    unsubscribeAll();
}

bool {{$class}}::isReady() const
{
    return m_finishedInitialization && m_pendingSubscriptions.empty();
}


const QString& {{$class}}::interfaceName()
{
    return InterfaceName;
}
{{ if (len .Interface.Properties) }}
void {{$class}}::subscribeForPropertiesChanges()
{
    {{- range .Interface.Properties }}
    const auto setTopic_{{.Name}} = interfaceName() + "/set/{{.Name}}";
    m_pendingSubscriptions.push_back(setTopic_{{.Name}});
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_{{.Name}},
        [this, setTopic_{{.Name}}](auto id, bool hasSucceed){handleOnSubscribed(setTopic_{{.Name}}, id, hasSucceed);},
        [this](const nlohmann::json& value)
        {
            {{qtReturn "" .}} {{.Name}} = value.get<{{qtReturn "" .}}>();
            m_impl->set{{Camel .Name}}({{.Name}});
        }));
    {{- end }}
}

{{- end }}
{{ if (len .Interface.Operations) }}
void {{$class}}::subscribeForInvokeRequests()
{
    {{- range .Interface.Operations }}
    const auto invokeTopic_{{.Name}} = interfaceName() + "/rpc/{{.Name}}";
    m_pendingSubscriptions.push_back(invokeTopic_{{.Name}});
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_{{.Name}},
        [this, invokeTopic_{{.Name}}](auto id, bool hasSucceed){handleOnSubscribed(invokeTopic_{{.Name}}, id, hasSucceed);},
        [this](const nlohmann::json& arguments)
        {
            {{- range  $i, $e := .Params }}
            {{qtType "" .}} {{.Name}} = arguments.at({{ $i }}).get<{{qtReturn "" .}}>();      
            {{- end }}
            {{- if .Return.IsVoid }}
            m_impl->{{camel .Name}}( {{ qtVars .Params }});
            return nlohmann::json {};
            {{- else }}
            auto result = m_impl->{{camel .Name}}({{ qtVars .Params }});
            return result;
            {{- end }}
        }));

    {{- end }}
}

{{- end }}
{{ if (len .Interface.Properties) }}
void {{$class}}::connectServicePropertiesChanges()
{
    {{- range .Interface.Properties }}
    const auto publishTopic_{{.Name}} = interfaceName() + "/prop/{{.Name}}";
    connect(m_impl.get(),&Abstract{{$iface}}::{{.Name}}Changed,
        this, [this, publishTopic_{{.Name}}]({{ qtParam "" . }})
        {
            m_mqttServiceAdapter.emitPropertyChange(publishTopic_{{.Name}}, {{.Name}});
        });
{{- end }}    
}
{{- end }}
{{ if (len .Interface.Signals) }}
void {{$class}}::connectServiceSignals()
{
{{- range .Interface.Signals }}
{{- $signalName := camel .Name }}
    const auto topic_{{$signalName}} = interfaceName() + "/sig/{{$signalName}}";
    connect(m_impl.get(), &Abstract{{$iface}}::{{$signalName}}, this,
        [this, topic_{{$signalName}}]({{qtParams "" .Params}})
        {
            nlohmann::json args = { {{ qtVars .Params }} };
            m_mqttServiceAdapter.emitPropertyChange(topic_{{$signalName}}, args);
        });
{{- end }}
}
{{- end }}

void {{$class}}::unsubscribeAll()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

void {{$class}}::handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed)
{
    if (!hasSucceed)
    {
        AG_LOG_WARNING("Subscription failed for  "+ topic+". Try reconnecting the client.");
        return;
    }
    auto iter = std::find_if(m_pendingSubscriptions.begin(), m_pendingSubscriptions.end(), [topic](auto element){return topic == element;});
    if (iter == m_pendingSubscriptions.end()){
         AG_LOG_WARNING("Subscription failed for  "+ topic+". Try reconnecting the client.");
        return;
    }
    m_pendingSubscriptions.erase(iter);
    if (m_finishedInitialization && m_pendingSubscriptions.empty())
    {
        emit ready();
    }
}

} // namespace {{qtNamespace .Module.Name }}

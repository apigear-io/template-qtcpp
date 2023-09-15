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


namespace {{snake  .Module.Name }} {

namespace
{
const QString ID = "{{$module}}/{{$iface}}";
}


{{$class}}::{{$class}}(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<Abstract{{$iface}}> impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
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
    });
}

{{$class}}::~{{$class}}()
{
    for(auto id :m_subscribedIds)
    {
        m_mqttServiceAdapter.unsubscribeTopic(id);
    }
}

const QString& {{$class}}::objectName()
{
    return ID;
}
{{ if (len .Interface.Properties) }}
void {{$class}}::subscribeForPropertiesChanges()
{
    {{- range .Interface.Properties }}
    const auto setTopic_{{.Name}} = objectName() + "/set/{{.Name}}";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeTopic(setTopic_{{.Name}},
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
    const auto invokeTopic_{{.Name}} = objectName() + "/rpc/{{.Name}}";
    m_subscribedIds.push_back(m_mqttServiceAdapter.subscribeForInvokeTopic(invokeTopic_{{.Name}},
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
    const auto publishTopic_{{.Name}} = objectName() + "/prop/{{.Name}}";
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
    const auto topic_{{$signalName}} = objectName() + "/sig/{{$signalName}}";
    connect(m_impl.get(), &Abstract{{$iface}}::{{$signalName}}, this,
        [this, topic_{{$signalName}}]({{qtParams "" .Params}})
        {
            nlohmann::json args = { {{ qtVars .Params }} };
            m_mqttServiceAdapter.emitPropertyChange(topic_{{$signalName}}, args);
        });
{{- end }}
}
{{- end }}

} // namespace {{snake  .Module.Name }}

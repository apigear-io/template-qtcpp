{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}
{{- $iface := .Interface.Name }}
{{- $module := .Module.Name }}



#include "{{lower $class}}.h"
{{- $iface := .Interface.Name }}

#include <nlohmann/json.hpp>
#include "{{snake .Module.Name}}/api/agent.h"
#include "{{snake .Module.Name}}/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace {{snake  .Module.Name }} {

{{$class}}::{{$class}}(RemoteRegistry& registry, Abstract{{$iface}}* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
    , m_node()
{
{{- range .Interface.Properties }}
    connect(m_impl, &Abstract{{$iface}}::{{.Name}}Changed, this,
        [=]({{ qtParam "" . }}) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}})");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, {{.Name}});
            }
        }
    });
       
{{- end }}    
{{- range .Interface.Signals }}
        connect(m_impl, &Abstract{{$iface}}::{{.Name}}, this,
            [=]({{qtParams "" .Params}}) {
                const nlohmann::json& args = { {{ qtVars .Params }} };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}})");
                for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
                    auto lockedNode = node.lock();
                    if(lockedNode) {
                        lockedNode->notifySignal(signalId, args);
                    }
                }
    });
{{- end }}
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

json {{$class}}::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(methodId);
    std::string path = Name::getMemberName(methodId);
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

void {{$class}}::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string path = Name::getMemberName(propertyId);
{{- range .Interface.Properties }}
    if(path == "{{.Name}}") {
        {{qtReturn "" .}} {{.Name}} = value.get<{{qtReturn "" .}}>();
        m_impl->set{{Camel .Name}}({{.Name}});
    }
{{- end }}    
}

void {{$class}}::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_node = node;
}

void {{$class}}::olinkUnlinked(const std::string& objectId)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_node = nullptr;
}

json {{$class}}::olinkCollectProperties()
{
    return captureState();
}

} // namespace {{snake  .Module.Name }}

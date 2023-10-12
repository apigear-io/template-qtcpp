{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}
{{- $iface := Camel .Interface.Name }}
{{- $module := .Module.Name }}



#include "{{lower $class}}.h"

#include <nlohmann/json.hpp>
#include "{{snake .Module.Name}}/api/json.adapter.h"

#include "olink/remoteregistry.h"
#include "olink/iremotenode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear::ObjectLink;

using json = nlohmann::json;

namespace {{snake  .Module.Name }} {

{{$class}}::{{$class}}(RemoteRegistry& registry, Abstract{{$iface}}* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
    , m_registry(registry)
{
{{- range .Interface.Properties }}
    connect(m_impl, &Abstract{{$iface}}::{{.Name}}Changed, this,
        [=]({{ qtParam "" . }}) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}}");
        for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
            auto lockedNode = node.lock();
            if(lockedNode) {
                lockedNode->notifyPropertyChange(propertyId, {{.Name}});
            }
        }
    });
       
{{- end }}    
{{- range .Interface.Signals }}
{{- $signalName := camel .Name }}
        connect(m_impl, &Abstract{{$iface}}::{{$signalName}}, this,
            [=]({{qtParams "" .Params}}) {
                const nlohmann::json& args = { {{ qtVars .Params }} };
                const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}}");
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
    return "{{$module}}.{{ .Interface.Name }}";
}

json {{$class}}::olinkInvoke(const std::string& methodId, const nlohmann::json& args){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(methodId);
    std::string path = Name::getMemberName(methodId);
{{- range .Interface.Operations }}
    if(path == "{{.Name}}") {
{{- range  $i, $e := .Params }}
        const {{qtType "" .}}& {{.Name}} = args.at({{ $i }});      
{{- end }}
{{- if .Return.IsVoid }}
        m_impl->{{camel .Name}}( {{ qtVars .Params }});
        return json{};
{{- else }}
        {{qtReturn "" .Return}} result = m_impl->{{camel .Name}}({{ qtVars .Params }});
        return result;
{{- end }}
    }
{{- end }}
    return json();
}

void {{$class}}::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value){
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string path = Name::getMemberName(propertyId);
{{- range .Interface.Properties }}
    if(path == "{{.Name}}") {
        {{qtReturn "" .}} {{.Name}} = value.get<{{qtReturn "" .}}>();
        m_impl->set{{Camel .Name}}({{.Name}});
    }
{{- end }}    
}

void {{$class}}::olinkLinked(const std::string& objectId, IRemoteNode *node) {
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

void {{$class}}::olinkUnlinked(const std::string& objectId)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
}

json {{$class}}::olinkCollectProperties()
{
    return captureState();
}

} // namespace {{snake  .Module.Name }}

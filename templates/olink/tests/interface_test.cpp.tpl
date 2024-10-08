{{- $class := Camel .Interface.Name  }}
{{- $olinkclass := printf "OLink%s" .Interface.Name }}
{{- $namespacePrefix := printf "%s::" (qtNamespace .Module.Name) -}}
#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olink{{lower .Interface.Name}}.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/{{lower .Interface.Name}}.h"
#include "olink/olink{{lower .Interface.Name}}adapter.h"

{{- $listqtExterns := qtExterns .Module.Externs}}
{{- $includes := (collectFields $listqtExterns  "Include")}}
{{- range .Module.Imports }}
{{- $includeName :=  printf "\"%s/api/api.h\"" (snake .Name) }}
{{- $includeName :=  printf "\"%s/api/test_struct_helper.h\"" (snake .Name) }}
{{- $includes = (appendList $includes  $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}

#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

{{- define "get_namespace"}}
        {{- $module_prefix:= printf "%s" (qtNamespace .Module.Name) }}
        {{- if (ne .Import "") }}
        {{- $module_prefix = (qtNamespace .Import ) }}
        {{- end}}
        {{- $module_prefix -}}
{{- end}}

TEST_CASE("Olink  {{.Module.Name}} {{$class}} tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto client{{$class}} = std::make_shared< {{qtNamespace .Module.Name }}::{{$olinkclass}}>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto impl{{$class}} = std::make_shared< {{qtNamespace .Module.Name }}::{{$class}}>();
    auto service{{$class}} = std::make_shared< {{qtNamespace .Module.Name }}::{{$olinkclass}}Adapter>(remote_registry, impl{{$class}}.get());
    remote_registry.addSource(service{{$class}});

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(client{{$class}});
    clientNode->linkRemote(client{{$class}}->olinkObjectName());

    {{- range .Interface.Properties }}
    {{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}
    SECTION("Test setting {{.Name}}")
    {
        bool is{{.Name}}Changed = false;
        client{{$class}}->connect(client{{$class}}.get(), &{{qtNamespace .Module.Name }}::Abstract{{$class}}::{{.Name}}Changed, [&is{{.Name}}Changed ](auto value){is{{.Name}}Changed  = true;});
        {{- if .IsArray }}
        auto test_value = {{ qtDefault $namespacePrefix . }};
	    {{- if not ( or ( .IsPrimitive)  (eq .KindType "enum")) }}
        auto element = {{ qtTestValue $namespacePrefix . }};
        {{template "get_namespace" .}}::fillTest{{.Type }}(element);
        test_value.append(element);
        {{- else }}  
        test_value.append({{ qtTestValue $namespacePrefix .}});
        {{- end }}
	{{- else }}
        {{- if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
        auto test_value = {{ qtDefault $namespacePrefix . }};
        {{template "get_namespace" .}}::fillTest{{.Type}}(test_value);
        {{- else}}
        auto test_value = {{ qtTestValue $namespacePrefix . }};
        {{- end }}
	{{- end }}
        client{{$class}}->set{{Camel .Name}}(test_value);
        REQUIRE(is{{.Name}}Changed  == true);
        REQUIRE(impl{{$class}}->{{.Name}}() == test_value);
        REQUIRE(client{{$class}}->{{.Name}}() == test_value);
    }
    {{- end }}
    {{- end }}

    clientNode->unlinkRemote(client{{$class}}->olinkObjectName());
    remote_registry.removeSource(service{{$class}}->olinkObjectName());
    client_registry.removeSink(client{{$class}}->olinkObjectName());
}

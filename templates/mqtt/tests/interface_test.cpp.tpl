{{- $class := Camel .Interface.Name  }}
{{- $namespace := qtNamespace .Module.Name   }}
{{- $mqttclient := printf "Mqtt%s" .Interface.Name }}
{{- $mqttservice := printf "Mqtt%sAdapter" .Interface.Name }}
{{- $namespacePrefix := printf "%s::" (qtNamespace .Module.Name) -}}
#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/{{lower .Interface.Name}}.h"
#include "mqtt/mqtt{{lower .Interface.Name}}.h"
#include "mqtt/mqtt{{lower .Interface.Name}}adapter.h"

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

#include "apigear/mqtt/mqttclient.h"
#include "apigear/mqtt/mqttservice.h"

{{- define "get_namespace"}}
        {{- $module_prefix:= printf "%s" (qtNamespace .Module.Name) }}
        {{- if (ne .Import "") }}
        {{- $module_prefix = (qtNamespace .Import ) }}
        {{- end}}
        {{- $module_prefix -}}
{{- end}}

// Those tests require an external mqtt broker, which is not provided here with  the mqtt feature.
// Before running tests make sure that the broker of your choice is running.

namespace{

    int timeout = 1000;//in ms
    
    class HandleCallTask : public QRunnable
    {
    public:
        HandleCallTask(std::function<void()> func)
            :execute(func)
        {
        }

        void run() override
        {
            execute();
        }

    private:
        std::function<void()> execute;
    };

}

TEST_CASE("MQTT  {{.Module.Name}} {{$class}} tests")
{
    {{- if .Interface.Operations }}
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    {{- end }}
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto client{{$class}} = std::make_shared< {{- $namespacePrefix }}{{$mqttclient}} >(client);
    auto impl{{$class}} = std::make_shared<{{ $namespacePrefix }}{{$class}}>();
    auto service{{$class}} = std::make_shared<{{$namespacePrefix}}{{$mqttservice}}>(service, impl{{$class}});

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&client{{$class}}, &service{{$class}}]() {return client{{$class}}->isReady() && service{{$class}}->isReady(); }, timeout));
    {{- range .Interface.Properties }}
    {{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}
    SECTION("Test setting {{.Name}}")
    {
        std::atomic<bool> is{{.Name}}Changed = false;
        client{{$class}}->connect(client{{$class}}.get(), &{{$namespace}}::Abstract{{$class}}::{{.Name}}Changed, [&is{{.Name}}Changed ](auto value){is{{.Name}}Changed  = true;});
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
        REQUIRE(QTest::qWaitFor([&is{{.Name}}Changed]() {return is{{.Name}}Changed  == true; }, timeout));
        REQUIRE(impl{{$class}}->{{.Name}}() == test_value);
        REQUIRE(client{{$class}}->{{.Name}}() == test_value);
    }
    {{- end }}
    {{- end }}

    {{- range .Interface.Signals }}
    SECTION("Test emit {{.Name}}")
    {
        std::atomic<bool> is{{.Name}}Emitted = false;

        {{- range $idx, $p := .Params -}}
        {{- if .IsArray }}
        auto local_{{snake .Name}}_array = {{ qtDefault $namespacePrefix . }};
        {{- if not ( or (eq .KindType "extern") ( or .IsPrimitive  (eq .KindType "enum") ) )}}
        auto element_{{$p.Name}} = {{ qtTestValue $namespacePrefix . }};
        {{template "get_namespace" .}}::fillTest{{.Type }}(element_{{$p.Name}});
        local_{{snake .Name}}_array .append(element_{{$p.Name}});
        {{- else }}
        local_{{snake .Name}}_array.append({{ qtTestValue $namespacePrefix . }});
        {{- end }}
        {{- else if not ( or (eq .KindType "extern") ( or .IsPrimitive  (eq .KindType "enum") ) )}}
        auto local_{{snake .Name}}_struct = {{ qtDefault $namespacePrefix . }};
        {{template "get_namespace" .}}::fillTest{{.Type }}(local_{{snake .Name}}_struct);
        {{- end -}}
        {{- end }}

        client{{$class}}->connect(client{{$class}}.get(), &{{$namespace}}::Abstract{{$class}}::{{camel .Name}},
        [&is{{.Name}}Emitted 
        {{- range $idx, $p := .Params -}}
        {{- if .IsArray }}, &local_{{snake .Name}}_array
        {{- else if not ( or (eq .KindType "extern") ( or .IsPrimitive  (eq .KindType "enum") ) ) }}, &local_{{snake .Name}}_struct{{- end -}}
        {{- end }}]({{qtParams $namespacePrefix .Params}})
        {
        {{- range $idx, $p := .Params }}
            REQUIRE({{ .Name}} == 
            {{- if .IsArray }} local_{{snake .Name}}_array
            {{- else if (eq .KindType "extern") }} {{ qtDefault $namespacePrefix .}}
            {{- else if  ( or .IsPrimitive  (eq .KindType "enum") ) }} {{ qtTestValue $namespacePrefix . }}
            {{- else -}} local_{{snake .Name}}_struct
            {{- end }});
        {{- end }}
            is{{.Name}}Emitted  = true;
        });

        emit impl{{$class}}->{{camel .Name}}(
    {{- range $idx, $p := .Params -}}
            {{- if $idx }}, {{end -}}
            {{- if .IsArray }}local_{{snake .Name}}_array
            {{- else if (eq .KindType "extern") }}{{ qtDefault $namespacePrefix .}}
            {{- else if  ( or .IsPrimitive  (eq .KindType "enum") ) }}{{ qtTestValue $namespacePrefix . }}
            {{- else -}}
            local_{{snake .Name}}_struct
            {{- end -}}
    {{- end -}}
        );
        REQUIRE(QTest::qWaitFor([&is{{.Name}}Emitted ]() {return is{{.Name}}Emitted   == true; }, timeout));
    }
    {{- end }}

    {{- range .Interface.Operations }}
    SECTION("Test method {{.Name}}")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([client{{$class}}, &finished](){
            {{ if (not .Return.IsVoid) }}[[maybe_unused]] auto result = {{ end }}client{{$class}}->{{camel .Name}}(
    {{- range $idx, $p := .Params -}}
            {{- if $idx }}, {{end -}}
            {{ qtDefault $namespacePrefix .}}
    {{- end -}}
        );
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method {{.Name}} async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = client{{$class}}->{{camel .Name}}Async(
    {{- range $idx, $p := .Params -}}
            {{- if $idx }}, {{end -}}
            {{ qtDefault $namespacePrefix .}}
    {{- end -}}
        );
        resultFuture.then([&finished]({{if (not .Return.IsVoid) }}{{qtReturn $namespacePrefix .Return}} /*res*/{{ end }}){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        {{- if (not .Return.IsVoid) }}
        auto return_value = resultFuture.result();
        REQUIRE(return_value == {{ qtDefault $namespacePrefix .Return }});
        {{- end }}
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    {{- end }}

    client{{$class}}.reset();
    service{{$class}}.reset();
    client.disconnect();
    service.disconnect();
}

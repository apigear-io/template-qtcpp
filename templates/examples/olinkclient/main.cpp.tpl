#include <QtQml>
#include <QGuiApplication>
#include "apigear/olink/olinkclient.h"
#include "olink/clientregistry.h"
#include "utilities/logger.h"
#include <memory>
{{- $features := .Features }}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/olink/olink{{ lower $interface.Name }}.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/monitor/{{ lower $interface.Name }}traced.h"
{{- end }}
{{- end }}
{{- end }}


// You can run this client app together with the server side app - either also example, simulation,
// or implemented olink server (may be in other technology) to play around with it.
// Have in mind, that this example only instantiates the interfaces, you need to add some action to it by yourself, like:
// changing properties or executing methods, also make sure you are subscribed for the changes and signals.
// If you use a server example try out implementing some changes like: setting some properties or emitting signals to see any effects here.
// Note that the server should be started first.
// If you are running this example from qt creator make sure that the run project settings have "run in terminal" option selected.
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::ObjectLink::OLinkClient client(registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8182/ws"));

    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $clientClassName := printf "%s%s"  $modulePrefix $class }}
    auto {{$clientClassName}} = std::make_shared< {{- snake $module.Name }}::OLink{{$interface.Name -}} >();
    client.linkObjectSource({{ $clientClassName }});
    {{- if $features.monitor }}
    {{ snake $module.Name }}::{{$class}}Traced {{$clientClassName}}Traced({{$clientClassName}} );
    {{- end }}
    {{- end }}
    {{- end }}

    {{ $propertyExampleReady := 0 -}}
    {{ $signalExampleReady := 0 -}}
    {{ $operationExampleReady := 0 -}}
    {{- range.System.Modules -}}
    {{- $module := . -}}
    {{- range $module.Interfaces -}}
    {{- $interface := . -}}

        {{- $class := printf "Abstract%s" (Camel .Name) -}}
        {{- $modulePrefix := lower1 (Camel $module.Name) -}}
        {{- $namespacePrefix := printf "%s::" (snake $module.Name) -}}
        {{- $clientClassNameCall := printf "%s%s->"  $modulePrefix (Camel $interface.Name) -}}
        {{- $clientClassNameGetPtr := printf "%s%s.get()"  $modulePrefix (Camel $interface.Name) -}}
        {{- if $features.monitor -}}
            {{- $clientClassNameCall = printf "%s%sTraced."  $modulePrefix (Camel $interface.Name) -}}
            {{- $clientClassNameGetPtr = printf "&%s%sTraced"  $modulePrefix (Camel $interface.Name) -}}
        {{- end -}}

{{- if (and (eq $propertyExampleReady  0)  (len $interface.Properties) )}}
    {{- $property := (index $interface.Properties 0) }}
    // Try out properties: subscribe for changes
    {{$clientClassNameCall}}connect({{$clientClassNameGetPtr}}, &{{ snake $module.Name }}::{{$class}}::{{$property.Name}}Changed, 
            []( {{qtParam $namespacePrefix $property}}){ 
                static const std::string message = "{{$property.Name}} property changed ";
                AG_LOG_DEBUG(message);
            });
    // or ask for change.
    auto local_{{$property.Name}} = {{qtDefault $namespacePrefix $property}};
    {{$clientClassNameCall}}set{{Camel $property.Name}}(local_{{$property.Name}});
    {{ $propertyExampleReady = 1}}
{{- end }}
{{- if (and (eq $signalExampleReady  0)  (len $interface.Signals))}}
    // Check the signals with subscribing for its change
    {{- $signal := (index $interface.Signals 0 ) }}
    {{$clientClassNameCall}}connect({{$clientClassNameGetPtr}}, &{{ snake $module.Name }}::{{$class}}::{{camel $signal.Name}}, 
        []({{qtParams $namespacePrefix $signal.Params}}){
                static const std::string message = "{{camel $signal.Name}} signal emitted ";
                AG_LOG_DEBUG(message);
        });
    {{ $signalExampleReady = 1}}
{{- end }}

{{- if ( and (eq $operationExampleReady  0) (len $interface.Operations))}}
    {{- $operation := (index $interface.Operations 0) }}
    // Play around executing your operations
    {{ if (not $operation.Return.IsVoid) }}auto method_result = {{ end }}{{$clientClassNameCall}}{{camel $operation.Name}}(
                {{- range $i, $e := $operation.Params }}
                    {{- if $i }}, {{ end }}{{qtDefault $namespacePrefix $e}}
                {{- end }}   {{- /* end range operation param*/ -}} );
    {{ $operationExampleReady = 1}}
{{- end }}
{{- if (and (and $operationExampleReady  $signalExampleReady)  $propertyExampleReady)}}
    {{- break}}
{{- end }}
{{- end}}{{/* end range over interfaces*/}}
{{- if (and (and $operationExampleReady  $signalExampleReady)  $propertyExampleReady)}}
    {{- break}}
{{- end }}
{{- end}}{{/* end range over modules*/}}

    auto result = app.exec();

    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $clientClassName := printf "%s%s"  $modulePrefix $class }}
    client.unlinkObjectSource({{ $clientClassName }}->olinkObjectName());
    {{- end }}
    {{- end }}

    return result;
}

{{- $features := .Features }}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower $interface.Name }}.h"
#include "{{snake $module.Name}}/mqtt/mqtt{{ lower $interface.Name }}adapter.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/monitor/{{ lower $interface.Name }}traced.h"
{{- end }}
{{- end }}
{{- end }}

#include <QtCore>
#include "apigear/mqtt/mqttservice.h"
#include <memory>

#include <iostream>

// You can run this service app together with the client side app - either also example,
// or implemented mqtt client (may be using other technology) to play around with it.
// Remember to use also a mqtt broker of your choice.
// Be aware that some brokers limit maximum number of messages queued per client, if you send a lot of messages consider using more clients
// e.g. one per interface.
// Have in mind, that this example only instantiates the interfaces and the services.
// To see results make sure the clients are sending request to server or add some actions by yourself.
// If you are running this example from qt creator make sure that the run project settings have "run in terminal" option selected.

int main(int argc, char *argv[]){

    QCoreApplication app(argc, argv);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $instanceName := printf "%s%s"  $modulePrefix $class }}
    {{- $serviceInstanceName := printf "%sMqtt%sService" $modulePrefix $class }}
    {{- $namespacePrefix := qtNamespace $module.Name }}
    auto {{$instanceName}} = std::make_shared<{{ $namespacePrefix }}::{{$class}}>();
    {{- if $features.monitor }}
    auto {{$instanceName}}Traced = std::make_shared<{{$namespacePrefix }}::{{$class}}Traced>({{$instanceName}} );
    auto {{$serviceInstanceName}} = std::make_shared<{{$namespacePrefix}}::Mqtt{{$interface.Name}}Adapter>(service, {{ $instanceName }}Traced);
    {{- else}}
    auto {{$serviceInstanceName}} = std::make_shared<{{$namespacePrefix}}::Mqtt{{$interface.Name}}Adapter>(service, {{ $instanceName }});
    {{- end }}
    {{- end }}
    {{- end }}

    auto result = app.exec();
    // Use the server.
    return result;
}

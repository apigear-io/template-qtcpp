{{- $features := .Features }}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower ( camel $interface.Name) }}.h"
#include "{{snake $module.Name}}/api/qml{{lower ( camel $interface.Name)}}.h"
#include "{{snake $module.Name}}/olink/olink{{ lower ( camel $interface.Name) }}adapter.h"
{{- end }}
#include "{{snake $module.Name}}/api/apifactory.h"
#include "{{snake $module.Name}}/olink/olinkfactory.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/monitor/tracedapifactory.h"
{{- end }}
{{- end }}

#include <QtCore>
#include "apigear/olink/olinkhost.h"
#include "olink/remoteregistry.h"
#include "olink/clientregistry.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "olink/olinkhost.h"
#include "olink/olinkclient.h"

#include <memory>
#include <iostream>

void registerMetaTypes();


// Example uses Olink Client as a backend for Qml Interface Wrappers
// It sets up the server with InterfaceImplemenation and wrappes it with Olink Service Adapters
// The connection is set up, and you can observe changes of your qml class by changing an interface instance.
// Normally server (with InterfaceImplemenation and Olink Service Adapter) would be in separate app
// And your UI containing the factory and a client.

int main(int argc, char *argv[]){

    registerMetaTypes();

    // Prepare Factory before app is created.
    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);

{{- range .System.Modules }}
{{- $module := . }}
    {{ snake $module.Name }}::OLinkFactory {{ snake $module.Name }}OlinkFactory(client);
    {{- if $features.monitor }}
    {{ snake $module.Name }}::TracedApiFactory {{ snake $module.Name }}TracedOlinkFactory({{ snake $module.Name }}OlinkFactory); 
    {{ snake $module.Name }}::ApiFactory::set(&{{ snake $module.Name }}TracedOlinkFactory);
    {{- else }}
    {{ snake $module.Name }}::ApiFactory::set(&{{ snake $module.Name }}OlinkFactory);
    {{- end}}
{{- end}}

    // Create main app
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(url);

    // Create server
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::OLinkHost server(registry);
    server.listen("localhost", 8182);

    // Create and add services to the server
    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $instanceName := printf "%s%s"  $modulePrefix $class }}
    {{- $serviceInstanceName := printf "%sOlink%sService" $modulePrefix $class }}
    {{ snake $module.Name }}::{{$class}} {{$instanceName}};
    auto {{$serviceInstanceName}} = std::make_shared< {{- snake $module.Name }}::OLink{{$interface.Name}}Adapter>(registry, &{{ $instanceName }});
    registry.addSource( {{- $serviceInstanceName }});
    {{- end }}
    {{- end }}

    // With services ready connect the client - all qml olink clients will be linked
    client.connectToHost(QUrl("ws://127.0.0.1:8182"));

    /**
    * You may want to try out the bindings in qml for your interface
    * by changing properites of your interface or emitting signals from here.
    * You may use sth like:
    *
    *   auto future = std::async(std::launch::async,
    *                         [&yourInterfaceInstance](){
    *   std::this_thread::sleep_for(std::chrono::milliseconds(500));
    *   yourInterfaceInstance.setYourProperty(args);
    *   std::this_thread::sleep_for(std::chrono::milliseconds(500));
    *   yourInterfaceInstance.yourSingal(args);
    */

    auto result = app.exec();

    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $serviceInstanceName := printf "%sOlink%sService" $modulePrefix $class }}
    registry.removeSource( {{- $serviceInstanceName }}->olinkObjectName());
    {{- end }}
    {{- end }}

    return result;
}

void registerMetaTypes()
{
{{- range .System.Modules }}
{{- $module := . }}
{{- $module_id := snake $module.Name }}
{{- $version := $module.Version }}
    // register enums structs and interfaces for {{$module_id}}
    {{- $Modulename := Camel $module.Name }}
    auto uri{{ snake $module.Name }} = "{{snake $module.Name }}";
{{- range $module.Enums }}
    qmlRegisterUncreatableType<{{$module_id}}::{{.Name}}>(uri{{ snake $module.Name }}, {{$version.Major}}, {{$version.Minor}}, "{{$Modulename}}{{.Name}}", "An enum can not be created");
{{- end }}

{{- range $module.Structs }}
    qRegisterMetaType<{{$module_id}}::{{.Name}}>();
    qmlRegisterUncreatableType<{{$module_id}}::{{.Name}}Factory>(uri{{ snake $module.Name }}, {{$version.Major}}, {{$version.Minor}}, "{{$Modulename}}{{.Name}}Factory", "A struct factory can not be created");
{{- end }}

{{- range $module.Interfaces }}
    qmlRegisterType<{{$module_id}}::Qml{{.Name}}>(uri{{ snake $module.Name }}, {{$version.Major}}, {{$version.Minor}}, "{{$Modulename}}{{.Name}}");
{{- end }}
{{ end }}
}

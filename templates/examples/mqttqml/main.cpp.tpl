{{- $features := .Features }}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower $interface.Name }}.h"
#include "{{snake $module.Name}}/qmlplugin/qml{{lower $interface.Name}}.h"
#include "{{snake $module.Name}}/mqtt/mqtt{{ lower $interface.Name }}adapter.h"
{{- end }}
#include "{{snake $module.Name}}/qmlplugin/apifactory.h"
#include "{{snake $module.Name}}/mqtt/mqttfactory.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/monitor/tracedapifactory.h"
{{- end }}
{{- end }}

#include <QtCore>
#include "apigear/mqtt/mqttservice.h"
#include "apigear/mqtt/mqttclient.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <memory>
#include <iostream>

#include <QtPlugin>


// This example contains service started from main and qml client.
// Remember to use also a mqtt broker of your choice.
// Be aware that some brokers limit maximum number of messages queued per client, if you send a lot of messages consider using more clients
// e.g. one per interface.
// Have in mind, that this example only instantiates the interfaces, you need to add some action to it by yourself, like:
// changing properties or executing methods, also make sure you are subscribed for the changes and signals.
// If you use a service example try out implementing some changes like: setting some properties or emitting signals to see any effects here.

int main(int argc, char *argv[]){

    // Prepare Factory before app is created.
    ApiGear::Mqtt::Client client("UniqueClientForQmlExample");
    ApiGear::Mqtt::ServiceAdapter service("UniqueService");

{{- range .System.Modules }}
{{- $module := . }}
    {{ snake $module.Name }}::MqttFactory {{ snake $module.Name }}MqttFactory(client);
    {{- if $features.monitor }}
    {{ snake $module.Name }}::TracedApiFactory {{ snake $module.Name }}TracedMqttFactory({{ snake $module.Name }}MqttFactory); 
    {{ snake $module.Name }}::ApiFactory::set(&{{ snake $module.Name }}TracedMqttFactory);
    {{- else }}
    {{ snake $module.Name }}::ApiFactory::set(&{{ snake $module.Name }}MqttFactory);
    {{- end}}
{{- end}}

    // Create main app
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);

    // Hardcoded path to plugins for runtime app, works only in this folder structure
    // You may want to try out setting QML_IMPORT_PATH and QML2_IMPORT_PATH variables instead of following line.
    app.addLibraryPath(app.applicationDirPath() + "../../imports");
    QQmlApplicationEngine engine;

    engine.load(url);

    // Connect client and service adapter
    client.connectToHost("localhost", 1883);
    service.connectToHost("localhost", 1883);


    // Create and add services
    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $instanceName := printf "%s%s"  $modulePrefix $class }}
    {{- $serviceInstanceName := printf "%sMqtt%sService" $modulePrefix $class }}
    auto {{$instanceName}} = std::make_shared<{{ snake $module.Name }}::{{$class}}>();
    auto {{$serviceInstanceName}} = std::make_shared< {{- snake $module.Name }}::Mqtt{{$interface.Name}}Adapter>(service, {{ $instanceName }});
    {{- end }}
    {{- end }}


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

    return result;
}

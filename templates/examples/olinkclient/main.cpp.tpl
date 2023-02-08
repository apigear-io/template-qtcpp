#include <QtQml>
#include <QGuiApplication>
#include "apigear/olink/olinkclient.h"
#include "olink/clientregistry.h"
#include <memory>
{{- $features := .Features }}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/olink/olink{{ lower ( camel $interface.Name) }}.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/monitor/{{ lower ( camel $interface.Name) }}traced.h"
{{- end }}
{{- end }}
{{- end }}


int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::ObjectLink::OLinkClient client(registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8182"));

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
    {{- snake $module.Name }}::{{$class}}Traced {{$clientClassName}}Traced({{$clientClassName}} );
    {{- end }}
    {{- end }}
    {{- end }}

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject *obj, const QUrl &objUrl) {
                       if (!obj && url == objUrl)
                        QCoreApplication::exit(-1);
                     },
                     Qt::QueuedConnection);
    engine.load(url);

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

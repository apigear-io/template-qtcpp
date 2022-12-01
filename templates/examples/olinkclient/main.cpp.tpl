#include <QtQml>
#include <QGuiApplication>
#include "apigear/olink/olinkclient.h"
#include "olink/clientregistry.h"
#include <memory>

{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/olink/olink{{ lower ( camel $interface.Name) }}.h"
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

    return app.exec();
}

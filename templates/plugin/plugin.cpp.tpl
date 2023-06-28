{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
{{- $module_id := snake .Module.Name }}
{{- $version := .Module.Version }}

#include "plugin.h"

#include <QtQml>

#include "{{snake .Module.Name}}/api/api.h"

{{- range .Module.Interfaces }}
#include "{{$module_id}}/api/qml{{lower .Name}}.h"
{{- end }}

void Plugin::registerTypes(const char *uri)
{

{{- $module := .Module }}
{{- $module_id := snake $module.Name }}
{{- $version := $module.Version }}
    // register enums structs and interfaces for {{$module_id}}
    {{- $Modulename := Camel $module.Name }}
{{- range $module.Enums }}
    qmlRegisterUncreatableType<{{$module_id}}::{{.Name}}>(uri, {{$version.Major}}, {{$version.Minor}}, "{{$Modulename}}{{.Name}}", "An enum can not be created");
{{- end }}

{{- range $module.Structs }}
    qRegisterMetaType<{{$module_id}}::{{.Name}}>();
    auto create{{$Modulename}}{{.Name}}FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new {{$module_id}}::{{.Name}}Factory();
    };
    const std::string uri{{$Modulename}}{{.Name}}Factory = uri + std::string(".{{.Name}}FactorySingleton");
    qmlRegisterSingletonType<{{$module_id}}::{{.Name}}Factory>(uri{{$Modulename}}{{.Name}}Factory.c_str(), {{$version.Major}}, {{$version.Minor}}, "{{$Modulename}}{{.Name}}Factory", create{{$Modulename}}{{.Name}}FactorySingleton);
{{- end }}

{{- range $module.Interfaces }}
    qmlRegisterType<{{$module_id}}::Qml{{Camel .Name}}>(uri, {{$version.Major}}, {{$version.Minor}}, "{{$Modulename}}{{.Name}}");
{{- end }}

}

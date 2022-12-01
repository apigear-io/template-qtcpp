{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
{{- $module_id := snake .Module.Name }}
{{- $version := .Module.Version }}

#include "plugin.h"

#include <QtQml>

#include "{{snake .Module.Name}}/api/api.h"

{{- range .Module.Interfaces }}
#include "{{$module_id}}/lib/qml{{lower .Name}}.h"
{{- end }}

void Plugin::registerTypes(const char *uri)
{
    // @uri {{.Module.Name}}
    // register enum
{{- range .Module.Enums }}
    qmlRegisterUncreatableType<{{.Name}}>(uri, {{$version.Major}}, {{$version.Minor}}, "{{.Name}}", "An enum can not be created");
{{- end }}

    // register structs
{{- range .Module.Structs }}
    qRegisterMetaType<{{.Name}}>();
    qmlRegisterUncreatableType<{{.Name}}Factory>(uri, {{$version.Major}}, {{$version.Minor}}, "{{.Name}}Factory", "A struct factory can not be created");
{{- end }}

    // register interfaces
{{- range .Module.Interfaces }}
    qmlRegisterType<Qml{{.Name}}>(uri, {{$version.Major}}, {{$version.Minor}}, "{{.Name}}");
{{- end }}



}

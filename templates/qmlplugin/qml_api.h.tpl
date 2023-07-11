{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := printf "%s_QML" (SNAKE .Module.Name) }}
{{- $module_id := snake .Module.Name }}
{{- $Modulename := Camel .Module.Name }}
{{- $namespacePrefix := printf "%s::" (snake .Module.Name) }}
{{- cppGpl .Module }}
{{- $version := .Module.Version }}
#pragma once

#include <QQmlEngine>
#include <QtCore>
#include <QtCore/QtGlobal>
#include <QDataStream>

#include "{{snake .Module.Name}}/api/api.h"

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{snake  .Module.Name }} {

{{- range .Module.Enums }}
{{- $class := .Name }}

struct Foreign{{ $class }} : public QObject
{
    Q_OBJECT
    QML_FOREIGN({{ $class }})
    QML_NAMED_ELEMENT({{$Modulename}}{{ $class }})
    QML_UNCREATABLE("This is enum class")
    QML_ADDED_IN_VERSION({{$version.Major}},{{$version.Minor}})
};
{{- end }}

{{- range .Module.Structs }}
{{- $class := .Name }}

// ********************************************************************
// {{$class}} struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class {{ $MODULE_ID }}_EXPORT {{$class}}Factory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION({{$version.Major}},{{$version.Minor}})
    QML_NAMED_ELEMENT({{$Modulename}}{{$class}}Factory)
    QML_SINGLETON
public:
    Q_INVOKABLE {{$module_id}}::{{$class}} create({{- range $i, $e := .Fields }}{{- if $i }} ,{{ end -}} {{qtReturn "" .}} in_{{.Name}} {{- end }});
};
{{- end }}


} //namespace {{snake  .Module.Name }}

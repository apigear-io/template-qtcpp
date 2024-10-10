{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $namespace := qtNamespace .Module.Name }}
{{- $namespacePrefix := printf "%s::" (qtNamespace .Module.Name) -}}
#pragma once

#include "api.h"
{{- $listqtExterns := qtExterns .Module.Externs}}
{{- $includes := (collectFields $listqtExterns  "Include")}}
{{- $includes = (appendList $includes "<QtCore>") }}
{{- $includes = (appendList $includes "<QtCore/QtGlobal>") }}
{{- $includes = (appendList $includes "<QDataStream>") }}
{{- range .Module.Imports }}
{{- $includeName :=  printf "\"%s/api/api.h\"" (snake .Name) }}
{{- $includes = (appendList $includes  $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{qtNamespace .Module.Name }} {

{{- range .Module.Structs }}
	{{- $structName := printf "test_%s" (snake .Name)}}
	{{- $structType := .Name}}

{{ $MODULE_ID }}_EXPORT void fillTest{{Camel .Name }}({{$structType}}& {{$structName}});
{{- end }}

}

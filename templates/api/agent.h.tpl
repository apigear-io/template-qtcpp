{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $MODULE_ID := (SNAKE .Module.Name) -}}
#pragma once

#include <QtCore>

#include "api.h"

namespace {{snake  .Module.Name }} {

{{- range .Module.Interfaces }}
{{- $class := printf "%sAgent" .Name }}
{{- $iface := .Name }}


class {{ $MODULE_ID }}_EXPORT {{$class}}
{
public:
  {{$class}}();
  static QVariantMap capture_state(Abstract{{$iface}}* obj);
  static void trace_state(Abstract{{$iface}}* obj);
  {{- range .Operations }}
  static void trace_{{.Name}}(Abstract{{$iface}}* obj, {{qtParams "" .Params}});
  {{- end }}
};
{{- end }}

} // namespace {{snake  .Module.Name }}
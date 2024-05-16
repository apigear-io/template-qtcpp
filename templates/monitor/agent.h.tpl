{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $MODULE_ID := printf "%s_MONITOR" (SNAKE .Module.Name) }}
#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/api.h"

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{qtNamespace .Module.Name }} {

{{- range .Module.Interfaces }}
{{- $iface := Camel .Name }}
{{- $class := printf "%sAgent" $iface }}


class {{ $MODULE_ID }}_EXPORT {{$class}}
{
public:
  {{$class}}();
  static QVariantMap capture_state(Abstract{{$iface}}* obj);
  static void trace_state(Abstract{{$iface}}* obj);
  {{- range .Operations }}
  static void trace_{{.Name}}(Abstract{{$iface}}* obj {{- if (len .Params) }},{{ end}} {{qtParams "" .Params}});
  {{- end }}
  {{- range .Signals }}
  static void trace_{{.Name}}(Abstract{{$iface}}* obj{{- if (len .Params) }},{{ end}} {{qtParams "" .Params}});
  {{- end }}
};
{{- end }}

} // namespace {{qtNamespace .Module.Name }}
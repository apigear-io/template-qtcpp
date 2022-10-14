{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := (SNAKE .Module.Name) }}
#pragma once

#include <QtCore>

#include "api.h"

{{- range .Module.Interfaces }}
{{- $class := printf "%sAgent" .Name }}



class {{ $MODULE_ID }}_EXPORT {{$class}}
{
public:
  {{$class}}();
  static QVariantMap capture_state(Abstract{{.Name}}* obj);
  static void trace_state(Abstract{{.Name}}* obj);
  {{- range .Operations }}
  static void trace_{{.Name}}(Abstract{{.Name}}* obj{{qtParams "" .Params}});
  {{- end }}
};
{{- end }}
{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := .Interface.Name }}
{{- $MODULE_ID := printf "%s_LIB" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/api.h"

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{snake  .Module.Name }} {

class {{ $MODULE_ID }}_EXPORT {{$class}} : public Abstract{{$class}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() override;

{{- range .Interface.Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Interface.Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}

private:
{{- range .Interface.Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};
} //namespace {{snake  .Module.Name }}

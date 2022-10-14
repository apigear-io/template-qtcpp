{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $class := .Interface.Name }}
{{- $MODULE_ID := printf "%s_LIB" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>

#include "../api/api.h"

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

class {{ $MODULE_ID }}_EXPORT {{$class}} : public Abstract{{$class}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() override;

{{- range .Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}

private:
{{- range .Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};

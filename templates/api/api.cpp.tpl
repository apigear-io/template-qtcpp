{{- $MODULE_ID := (SNAKE .Module.Name) }}
{{- cppGpl .Module }}
#include "api.h"

namespace {{snake  .Module.Name }} {

{{- range .Module.Enums }}
{{- $class := .Name }}
// ********************************************************************
// Enumeration {{$class}}
// ********************************************************************
{{$class}}::{{$class}}Enum {{$class}}::toEnum(quint8 v, bool *ok)
{
    if (ok) {
        *ok = true;
    }
    switch (v) {
{{- range .Members }}
        case {{.Value}}: return {{$class}}::{{upper1 .Name}};
{{- end }}
        default:
            if (ok) {
                *ok = false;
            }
            return {{ printf "%s::%s" .Name (upper1 .Default.Name)}};
    }
}
{{- end }}

{{- range .Module.Structs }}
{{- $class := .Name }}
// ********************************************************************
// Struct {{$class}}
// ********************************************************************

{{$class}}::{{$class}}()
{{- range $i, $e := .Fields }}    
{{- if $i }}    , {{ else }}
    : {{ end -}}
    m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{
}

bool {{$class}}::operator==(const {{$class}} &other) const
{
    return (
{{- range $i, $e := .Fields }}
{{- if $i }} &&
{{- end }}
        m_{{.Name}} == other.m_{{.Name}}
{{- end }}
    );
}

bool {{$class}}::operator!=(const {{$class}} &other) const
{
    return !(*this == other);
}

QDataStream &operator<<(QDataStream &stream, const {{$class}} &obj)
{
    {{- range .Fields }}
    stream << obj.m_{{.Name}};
    {{- end }}

    return stream;
}

QDataStream &operator>>(QDataStream &stream, {{$class}} &obj)
{
    {{- range .Fields }}
    {{ qtReturn "" . }} {{.Name}}Value;
    stream >> {{.Name}}Value;
    obj.m_{{.Name}} = {{.Name}}Value;

    {{- end }}
    return stream;
}

// ********************************************************************
// Struct Factory {{$class}}
// ********************************************************************

{{$class}} {{$class}}Factory::create()
{
    return {{$class}}();
}
{{- end }}

{{- range .Module.Interfaces }}

{{- $class := printf "Abstract%s" (Camel .Name) }}

// ********************************************************************
// {{$class}} abstract interface
// ********************************************************************

{{$class}}::{{$class}}(QObject *parent)
    : QObject(parent)
{
}

{{- end }}

} // namespace {{snake  .Module.Name }}

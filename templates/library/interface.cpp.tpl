{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
{{- $class := Camel .Interface.Name }}


#include "{{lower .Interface.Name}}.h"

#include <QtQml>

namespace {{snake  .Module.Name }} {

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{$class}}(parent)
{{- range .Interface.Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{
}

{{$class}}::~{{$class}}()
{
}

{{- range .Interface.Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}
{{- range .Interface.Operations }}

{{qtReturn "" .Return}} {{$class}}::{{camel .Name}}({{qtParams "" .Params}})
{
    return{{ if (not .Return.IsVoid) }} {{qtDefault "" .Return}} {{- end}};
}
{{- end }}
} //namespace {{snake  .Module.Name }}

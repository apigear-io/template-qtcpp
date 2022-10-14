{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{ $class := .Name }}

#include "{{lower $class}}.h"

#include <QtQml>

#include "../api/agent.h"

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{$class}}(parent)
{{- range .Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{
}

{{$class}}::~{{$class}}()
{
}

{{- range .Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
        {{.Name}}Agent::trace_state(this);
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}
{{- range .Operations }}

{{qtReturn "" .Return}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;    
    {{.Name}}Agent::trace_{{.Name}}(this, {{.join ", " .Params}});
    return {{qtDefault "" .Return}};
}
{{- end }}

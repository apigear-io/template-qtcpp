{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
{{- $class := .Interface.Name }}


#include "{{lower $class}}.h"

#include <QtQml>

#include "{{snake .Module.Name}}/api/agent.h"

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
        {{$class}}Agent::trace_state(this);
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}
{{- range .Interface.Operations }}

{{qtReturn "" .Return}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    {{$class}}Agent::trace_{{.Name}}(this, {{qtVars .Params}});
    return {{qtDefault "" .Return}};
}
{{- end }}

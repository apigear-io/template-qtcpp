{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $class := .Name }}

#include "qml{{lower $class}}.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

Qml{{$class}}::Qml{{$class}}(QObject *parent)
    : Abstract{{$class}}(parent)
{
    m_obj = ApiFactory::get()->create{{$class}}(this);
    {{- range .Properties }}
    connect(m_obj, &Abstract{{$class}}::{{.Name}}Changed, this, &Qml{{$class}}::{{.Name}}Changed);
    connect(m_obj, &Abstract{{$class}}::{{.Name}}Changed, this, &Abstract{{$class}}::{{.Name}}Changed);
    {{- end }}
    {{- range .Signals }}
    connect(m_obj, &Abstract{{$class}}::{{.Name}}, this, &Qml{{$class}}::{{.Name}});
    connect(m_obj, &Abstract{{$class}}::{{.Name}}, this, &Abstract{{$class}}::{{.Name}});
    {{- end }}
}

Qml{{$class}}::~Qml{{$class}}()
{
}

{{- range .Properties }}

{{qtReturn "" .}} Qml{{$class}}::{{.Name}}() const
{
    return m_obj->{{.Name}}();
}

void Qml{{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    {{.Name}}Agent::capture_state(this);
    return m_obj->set{{Camel .Name}}({{.Name}});
}


{{- end }}
{{- range .Operations }}

{{qtReturn "" .Return}} Qml{{$class}}::{{.Name}}({{qtParams "" .Params}})
{    
    {{.Name}}Agent::trace_{{.Name}}(this, {{ .join ", " .Params}});
	
    return m_obj->{{.Name}}({{range $i, $e := .Params}}{{if $i}}, {{end}}{{.Name}}{{- end }});
}
{{- end }}

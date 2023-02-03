{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
{{- $class := Camel .Interface.Name }}


#include "qml{{lower $class}}.h"
#include "{{snake .Module.Name}}/api/apifactory.h"
#include "{{snake .Module.Name}}/api/agent.h"

#include <QtQml>

namespace {{snake  .Module.Name }} {

Qml{{$class}}::Qml{{$class}}(QObject *parent)
    : Abstract{{$class}}(parent)
{
    m_obj = ApiFactory::get()->create{{$class}}(this);
    {{- range .Interface.Properties }}
    connect(m_obj, &Abstract{{$class}}::{{.Name}}Changed, this, &Qml{{$class}}::{{.Name}}Changed);
    connect(m_obj, &Abstract{{$class}}::{{.Name}}Changed, this, &Abstract{{$class}}::{{.Name}}Changed);
    {{- end }}
    {{- range .Interface.Signals }}
    connect(m_obj, &Abstract{{$class}}::{{.Name}}, this, &Qml{{$class}}::{{.Name}});
    connect(m_obj, &Abstract{{$class}}::{{.Name}}, this, &Abstract{{$class}}::{{.Name}});
    {{- end }}
}

Qml{{$class}}::~Qml{{$class}}()
{
}

{{- range .Interface.Properties }}

{{qtReturn "" .}} Qml{{$class}}::{{.Name}}() const
{
    return m_obj->{{.Name}}();
}

void Qml{{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    {{$class}}Agent::capture_state(this);
    return m_obj->set{{Camel .Name}}({{.Name}});
}


{{- end }}
{{- range .Interface.Operations }}

{{qtReturn "" .Return}} Qml{{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    {{$class}}Agent::trace_{{.Name}}(this, {{ qtVars .Params }});
	
    return m_obj->{{.Name}}({{range $i, $e := .Params}}{{if $i}},{{end}}{{.Name}}{{- end }});
}
{{- end }}

} //namespace {{snake  .Module.Name }}

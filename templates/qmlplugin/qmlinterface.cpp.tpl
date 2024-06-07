{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
{{- $class := Camel .Interface.Name }}


#include "qml{{lower .Interface.Name}}.h"
#include "apifactory.h"

#include <QtQml>

namespace {{qtNamespace .Module.Name }} {

Qml{{$class}}::Qml{{$class}}(QObject *parent)
    : Abstract{{$class}}(parent)
{
    m_obj = ApiFactory::get()->create{{$class}}();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as Qml{{$class}}::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as Abstract{{$class}}::Property Changed signal
    // for usage, where Qml{{$class}} is used by the AbstractTuner interface and for connections with Abstract{{$class}}::Property Changed signal
    {{- range .Interface.Properties }}
    connect(m_obj.get(), &Abstract{{$class}}::{{.Name}}Changed, this, &Qml{{$class}}::{{.Name}}Changed);
    connect(m_obj.get(), &Abstract{{$class}}::{{.Name}}Changed, this, &Abstract{{$class}}::{{.Name}}Changed);
    {{- end }}

    // Forward the singals emitted by backend implementation to Qml{{$class}} wrapper.
    //  Have in mind that there is no forwarding from the Qml{{$class}} wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    {{- range .Interface.Signals }}
    {{- $signalName := camel .Name }}
    connect(m_obj.get(), &Abstract{{$class}}::{{$signalName}}, this, &Abstract{{$class}}::{{$signalName}});
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
    return m_obj->set{{Camel .Name}}({{.Name}});
}


{{- end }}
{{- range .Interface.Operations }}

{{qtReturn "" .Return}} Qml{{$class}}::{{camel .Name}}({{qtParams "" .Params}})
{
    return m_obj->{{camel .Name}}({{range $i, $e := .Params}}{{if $i}},{{end}}{{.Name}}{{- end }});
}
{{- end }}

} //namespace {{qtNamespace .Module.Name }}

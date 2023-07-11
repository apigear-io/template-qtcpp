{{- $MODULE_ID := (SNAKE .Module.Name) }}
{{- cppGpl .Module }}
#include "qml_api.h"

namespace {{snake  .Module.Name }} {


{{- range .Module.Structs }}
{{- $class := .Name }}

// ********************************************************************
// Struct Factory {{$class}}
// ********************************************************************

{{$class}} {{$class}}Factory::create({{- range $i, $e := .Fields }}    
{{- if $i }}, {{ end -}} {{qtReturn "" .}} in_{{.Name}} {{- end }})
{
    {{$class}} l_{{$class}};
    {{- range $i, $e := .Fields }}
    l_{{$class}}.m_{{.Name}} = in_{{.Name}};
    {{- end }}
    return l_{{$class}};

}
{{- end }}

} // namespace {{snake  .Module.Name }}

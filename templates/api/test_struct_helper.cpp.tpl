{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $namespace := qtNamespace .Module.Name }}
{{- $namespacePrefix := printf "%s::" (qtNamespace .Module.Name) -}}

#include "test_struct_helper.h"

{{- range .Module.Structs }}
	{{- $structName := printf "test_%s" (snake .Name)}}
	{{- $structType := .Name}}

void {{qtNamespace .Module.Name }}::fillTest{{Camel .Name }}({{qtNamespace .Module.Name }}::{{$structType}}& {{$structName}})
{
{{- range .Fields }}
	{{- if .IsArray }}
	auto local_{{snake .Name}}_array = {{ qtDefault $namespacePrefix . }};
	{{- if not ( or (eq .KindType "extern") ( or .IsPrimitive  (eq .KindType "enum") ) )}}
	auto element{{snake .Name}} = {{ qtDefault $namespacePrefix . }};
	fillTest{{Camel .Type }}(element{{snake .Name}});
	{{- else}}
	auto element{{snake .Name}} = {{qtTestValue $namespacePrefix . }};
	{{- end }}
	local_{{snake .Name}}_array.push_back(element{{snake .Name}});
	{{$structName}}.m_{{.Name }} = local_{{snake .Name}}_array;
	{{- else if not ( or (eq .KindType "extern") ( or .IsPrimitive  (eq .KindType "enum") ) )}}
	fillTest{{Camel .Type }}({{$structName}}.m_{{.Name }});
	{{- else }}
	{{$structName}}.m_{{.Name }} = {{ qtTestValue $namespacePrefix . }};
	{{- end }}
{{- end }}
}
{{- end }}

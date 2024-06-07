{{- /* Copyright (c) ApiGear UG 2020 */ -}}
#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include "api.h"
#include "apigear/utilities/qt_native.json.adapter.h"

#include <nlohmann/json.hpp>
#include <QtCore>

{{- range .Module.Imports }}
#include "{{snake .Name}}/api/json.adapter.h"
{{- end }}


{{- if .Module.Externs }}
namespace nlohmann {

{{- range .Module.Externs }}
{{- $externQt := qtExtern . }}

{{- $type := $externQt.Name }}
{{- if (not (eq $externQt.NameSpace "")) }}
{{- $type = printf "%s::%s" $externQt.NameSpace $externQt.Name }}
{{- end }}

template<>
struct adl_serializer<{{$type}}> {
    static void to_json(nlohmann::json& j, const {{$type}}& p)
	{
		// Do serialization here
		j = nlohmann::json{
			//{"member_name", p.member }, ...
		};
    }

    static void from_json(const nlohmann::json& j, {{$type}}& p)
    {
	    // Do deserialization here, e.g.
	    // p.xyz = j.at("xyz").get<Int>();
	    p = {{$type}}();
    }
};

{{- end }}

} //namespace nlohmann
{{- end}}


namespace {{qtNamespace .Module.Name }} {

{{- range .Module.Structs }}
{{- $class := .Name }}

inline void from_json(const nlohmann::json& j, {{$class}}& p) {
{{- range .Fields }}
    if(j.contains("{{.Name}}")) {
        p.m_{{.Name}} = j["{{.Name}}"].get<{{qtReturn "" .}}>();
    }
{{- end }}
}

inline void to_json(nlohmann::json& j, const {{$class}}& p) {
    j = nlohmann::json{
{{- range $i, $e := .Fields }}{{if $i}},{{end}}
        {"{{.Name}}", p.m_{{.Name}} }
{{- end }}
        };
}
{{- end }}
} //namespace {{qtNamespace .Module.Name }}

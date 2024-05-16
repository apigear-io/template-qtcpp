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

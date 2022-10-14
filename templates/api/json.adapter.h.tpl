{{- /* Copyright (c) ApiGear UG 2020 */}}
#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include <QtCore>

inline void from_json(const nlohmann::json& j, QString& p) {
    p = QString::fromStdString(j.get<std::string>());
}

inline void to_json(nlohmann::json& j, const QString& value) {
    j = value.toStdString();
}
{{ range .Module.Structs }}
{{ $class := .Name }}

inline void from_json(const nlohmann::json& j, {{$class}}& p) {
{{ range .Fields }}
    if(j.contains("{{.Name}}")) {
        p.set{{Camel .Name}}(j["{{.Name}}"].get<{{qtReturn "" .}}>());
    }
{{- end }}
}

inline void to_json(nlohmann::json& j, const {{$class}}& p) {
    j = nlohmann::json{
{{ range $i, $e := .Fields }}
        {{if $i}}, {{end}}{"{{.Name}}", p.{{.Name}}()}
{{- end }}
        };
}
{{- end }}
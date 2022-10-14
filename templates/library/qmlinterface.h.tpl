{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $class := .Name }}
{{- $MODULE_ID := printf "%s_LIB" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>

#include "{{.Name|lower}}.h"

class {{$MODULE_ID}}_EXPORT Qml{{$class}} : public Abstract{{$class}}
{
    Q_OBJECT
{{- range .Properties }}
{% assign name = property.name %}
    Q_PROPERTY({{qtReturn "" .}} {{.Name}} READ {{.Name}} NOTIFY {{.Name}}Changed)
{{- end }}
public:
    explicit Qml{{$class}}(QObject *parent = nullptr);
    virtual ~Qml{{$class}}() override;

{{- range .Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Operations }}
    Q_INVOKABLE {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}

Q_SIGNALS:
{{- range .Signals }}
    void {{.Name}}({{qtParams "" .Params}});
{{- end }}
{{- range .Properties }}
    void {{.Name}}Changed({{qtParam "" .}});
{{- end }}
private:
	Abstract{{$class}} *m_obj;
};

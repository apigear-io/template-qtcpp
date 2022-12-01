{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := .Interface.Name }}
{{- $MODULE_ID := printf "%s_LIB" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>

#include "{{.Interface.Name|lower}}.h"

namespace {{snake  .Module.Name }} {

class {{$MODULE_ID}}_EXPORT Qml{{$class}} : public Abstract{{$class}}
{
    Q_OBJECT
{{- range .Interface.Properties }}
    Q_PROPERTY({{qtReturn "" .}} {{.Name}} READ {{.Name}} NOTIFY {{.Name}}Changed)
{{- end }}
public:
    explicit Qml{{$class}}(QObject *parent = nullptr);
    virtual ~Qml{{$class}}() override;

{{- range .Interface.Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Interface.Operations }}
    Q_INVOKABLE {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}

Q_SIGNALS:
{{- range .Interface.Signals }}
    void {{.Name}}({{qtParams "" .Params}});
{{- end }}
{{- range .Interface.Properties }}
    void {{.Name}}Changed({{qtParam "" .}});
{{- end }}
private:
	Abstract{{$class}} *m_obj;
};

} //namespace {{snake  .Module.Name }}

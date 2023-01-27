#pragma once

#include <QtCore>
#include "api.h"

namespace {{snake  .Module.Name }} {

{{- range .Module.Interfaces }}
{{- $class := printf "Simulation%s" .Name }}

// ********************************************************************
// {{$class}} simulation interface
// ********************************************************************


class {{$class}} : public Abstract{{Camel .Name}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() override;

{{- range .Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}

private:
{{- range .Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};
{{- end }}

} // namespace {{snake  .Module.Name }}

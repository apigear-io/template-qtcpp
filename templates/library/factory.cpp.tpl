#include "factory.h"

{{- range .Module.Interfaces }}
#include "{{.Name|lower}}.h"
{{- end }}

namespace {{snake  .Module.Name }} {

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

{{- range .Module.Interfaces }}

Abstract{{Camel .Name}}* Factory::create{{Camel .Name}}(QObject *parent)
{
    return new {{.Name}}(parent);
}

{{- end }}

} // namespace {{snake  .Module.Name }}
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

std::shared_ptr<Abstract{{Camel .Name}}> Factory::create{{Camel .Name}}(QObject *parent)
{
    return std::make_shared<{{Camel .Name}}>(parent);
}

{{- end }}

} // namespace {{snake  .Module.Name }}
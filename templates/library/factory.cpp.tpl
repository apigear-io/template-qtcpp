#include "factory.h"

{{ range .Module.Interfaces }}
#include "{{.Name|lower}}.h"
{{- end }}

Factory::Factory(QObject *parent)
    : QObject(parent)
{
}

{{ range .Module.Interfaces }}

Abstract{{.Name}}* Factory::create{{Camel .Name}}(QObject *parent)
{
    return new {{.Name}}(parent);
}

{{- end }}

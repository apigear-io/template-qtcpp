#include "olinkfactory.h"

{{ range .Module.Interfaces }}
#include "olink{{.Name|lower}}.h"
{{- end }}

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

{{ range .Module.Interfaces }}

Abstract{{.Name}}* OLinkFactory::create{{Camel .Name}}(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLink{{.Name}}(parent);
}

{{- end }}

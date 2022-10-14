#include "wampfactory.h"

{{ range .Module.Interfaces }}
#include "wamp{{.Name|lower}}.h"
{{- end }}

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

{{ range .Module.Interfaces }}

Abstract{{.Name}}* WampFactory::create{{Camel .Name}}(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new Wamp{{.Name}}(parent);
}

{{- end }}

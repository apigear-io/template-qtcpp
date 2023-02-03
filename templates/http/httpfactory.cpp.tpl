#include "httpfactory.h"

{{- range .Module.Interfaces }}
#include "http{{.Name|lower}}.h"
{{- end }}

namespace {{snake  .Module.Name }} {

HttpFactory::HttpFactory(QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
{
}

{{- range .Module.Interfaces }}

Abstract{{Camel .Name}}* HttpFactory::create{{Camel .Name}}(QObject *parent)
{
    return new Http{{.Name}}(m_network, parent);
}

{{- end }}


} //namespace {{snake  .Module.Name }}
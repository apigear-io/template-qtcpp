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

std::shared_ptr<Abstract{{Camel .Name}}> HttpFactory::create{{Camel .Name}}(QObject *parent)
{
    return std::make_shared<Http{{.Name}}>(m_network, parent);
}

{{- end }}


} //namespace {{snake  .Module.Name }}
#include "olinkfactory.h"
#include "utilities/logger.h"

{{- range .Module.Interfaces }}
#include "olink/olink{{.Name|lower}}.h"
{{- end }}

namespace {{snake  .Module.Name }} {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

{{- range .Module.Interfaces }}

std::shared_ptr<Abstract{{Camel .Name}}> OLinkFactory::create{{Camel .Name}}(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto {{snake .Name}} = std::make_shared<OLink{{.Name}}>();
    m_client.linkObjectSource({{snake .Name}});
    return {{snake .Name}};
}

{{- end }}

} //namespace {{snake  .Module.Name }}
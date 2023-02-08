#include "tracedapifactory.h"
{{- $moduleName := snake .Module.Name }}

{{- range .Module.Interfaces }}
{{- $filename := printf "%straced" (lower .Name) }}
#include "{{$filename}}.h"
{{- end }}

namespace {{snake  .Module.Name }} {

TracedApiFactory::TracedApiFactory(IApiFactory& factory, QObject *parent)
    : QObject(parent),
      m_factory(factory)
{
    qDebug() << Q_FUNC_INFO;
}

{{- range .Module.Interfaces }}

std::shared_ptr<Abstract{{Camel .Name}}> TracedApiFactory::create{{Camel .Name}}(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    {{- $interfaceName := camel .Name  }}
    {{- $tracedclass := printf "%sTraced" (Camel $interfaceName) }}
    auto {{ $interfaceName}} = m_factory.create{{Camel .Name}}(parent);
    return std::make_shared<{{$tracedclass}}>({{$interfaceName}});
}

{{- end }}

} //namespace {{snake  .Module.Name }}

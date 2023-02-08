#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/iapifactory.h"
#include "{{snake .Module.Name}}/api/api.h"

{{- $MODULE_ID := printf "%s_MONITOR" (SNAKE .Module.Name) }}
#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{snake  .Module.Name }} {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class {{ $MODULE_ID }}_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    /** @return Traced version of {{.Name}} created by other factory*/
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent = nullptr) override;
{{- end }}
private:
    IApiFactory& m_factory;
};

} //namespace {{snake  .Module.Name }}

#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/iapifactory.h"

{{- $LIB_ID := printf "%s_IMPL" (SNAKE .Module.Name) }}
#if defined({{ $LIB_ID }}_LIBRARY)
#  define {{ $LIB_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $LIB_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{qtNamespace .Module.Name }} {

/** 
* A Factory that creates the actual implementaion for interfaces in {{ .Module.Name }}
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class {{ $LIB_ID }}_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    /** @return implementation of {{.Name}} */
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent) override;
{{- end }}
};

} // namespace {{qtNamespace .Module.Name }}


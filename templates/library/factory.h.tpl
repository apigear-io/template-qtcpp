#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/apifactory.h"

namespace {{snake  .Module.Name }} {

/** 
* A Factory that creates the actual implementaion for interfaces in {{ .Module.Name }}
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/
class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    /** @return implementation of {{.Name}} */
    Abstract{{Camel .Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
};

} // namespace {{snake  .Module.Name }}


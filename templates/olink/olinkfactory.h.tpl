#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/apifactory.h"

namespace {{snake  .Module.Name }} {

/** 
* A Factory that creates a OlinkClient version of interfaces in {{ .Module.Name }}
* The created interfaces implementation connect with a matching service objects on server side
* that provides functionality of the interface.
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    /** @return Olink Client version of {{.Name}} */
    Abstract{{Camel .Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
};

} //namespace {{snake  .Module.Name }}

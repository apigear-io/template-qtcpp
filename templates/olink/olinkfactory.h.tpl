#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/apifactory.h"
#include <apigear/olink/olinkclient.h>

namespace {{snake  .Module.Name }} {

/** 
* A Factory that creates a OlinkClient version of interfaces in {{ .Module.Name }}
* The created interfaces implementation connect with a matching service objects on server side
* that provides functionality of the interface.
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*
* WARNING when creating the interface, make sure that server side already has the source (the interface service).
*    OR use unconnected client when creating the interface and connect it the source object is already there.
*
* WARNING Because the registry held by client cannot have multiple objects with same objectId (which is the combination of module and interface)
*         you will be able to have only one instance of each of your Interfaces connected to client at one time.
*         other interface instances wont be linked
*/

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    /** @return Olink Client version of {{.Name}} */
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent = nullptr) override;
{{- end }}
private:
    ApiGear::ObjectLink::OLinkClient& m_client;
};

} //namespace {{snake  .Module.Name }}

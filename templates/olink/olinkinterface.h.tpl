{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "OLink%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $interfaceNameOriginal := .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $interfaceName }}
#pragma once

#include <QtCore>
#include <QtPromise>

#include "{{snake .Module.Name}}/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace {{snake  .Module.Name }} {

/**
* Adapts the general OLink Client handler to a {{$interfaceNameOriginal}} in a way it provides access 
* to remote specific for {{$interfaceNameOriginal}} services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect {{$class}} to it.
* Use on client side to request changes of the {{$interfaceNameOriginal}} on the server side 
* and to subscribe for the {{$interfaceNameOriginal}} changes.
*/
class {{$class}} : public Abstract{{Camel .Interface.Name}}, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit {{$class}}(QObject *parent = nullptr);
    /** dtor */
    ~{{$class}}() override = default;

{{- range .Interface.Properties }}
{{- $property := . }}
    /**
    * Property getter
    * @return Locally stored recent value for {{Camel $property.Name}}.
    */
    {{qtReturn "" .}} {{.Name}}() const override;
    /**
    * Request setting a property on the {{$interfaceNameOriginal}} service.
    * @param The value to which set request is send for the {{Camel $property.Name}}.
    */
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Interface.Operations }}
{{- $operation := . }}
    /**
    * Remote call of {{$interfaceClass}}::{{$operation.Name}} on the {{$interfaceNameOriginal}} service.
    * Uses {{$operation.Name}}Async
    */
    {{qtReturn "" .Return}} {{camel .Name}}({{qtParams "" .Params}}) override;
    /**
    * Remote call of {{$interfaceClass}}::{{$operation.Name}} on the {{$interfaceNameOriginal}} service.
    */
    QtPromise::QPromise<{{qtReturn "" .Return}}> {{camel .Name}}Async({{qtParams "" .Params}});
{{- end }}

signals:

    /**
    * Informs if the {{$class}} is ready to send and receive messages.
    * @return true if {{$interfaceNameOriginal}} is operable, false otherwise.
    */
    void isReady();
public:

    /**
    * The name of the object for which this sink is created, object on server side has to have the same name.
    * It serves as an identifier for the client registry, it has to be unique for the pair sink object - client node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;

    /**
    * Information about signal emission on a server side to all subscribers.
    * @param signalId Unique identifier for the signal emitted from object.
    * @param args The arguments for the signal.
    */
    void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;

    /**
    * Applies the information about the property changed on server side.
    * @param propertyId Unique identifier of a changed property in object .
    * @param value The value of the property.
    */
    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;

    /** Informs this object sink that connection was is established.
    * @param interfaceId The name of the object for which link was established.
    * @param props Initial values obtained from the {{$interfaceNameOriginal}} service
    * @param the initialized link endpoint for this sink.
    */
    void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    /**
    * Informs this object sink that the link was disconnected and cannot be used anymore.
    */
    void olinkOnRelease() override;
private:
    /**
    * Applies received data to local state and publishes changes to subscribers.
    * @param the data received from {{$interfaceNameOriginal}} service.
    */
    void applyState(const nlohmann::json& fields);

{{- range .Interface.Properties }}
{{- $property := . }}
    /**  Updates local value for {{Camel $property.Name}} and informs subscriber about the change with emit property changed signal. */
    void set{{Camel .Name}}Local({{qtParam "" .}});
    /** A local value for {{$property.Name}} */
    {{qtReturn "" .}} m_{{$property.Name}};
{{- end }}
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the {{$class}}.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace {{snake  .Module.Name }}

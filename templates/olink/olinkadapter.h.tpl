{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}
{{- $interface := .Interface.Name  }}

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "{{snake .Module.Name}}/api/api.h"
#include "olink/iobjectsource.h"

namespace ApiGear {
namespace ObjectLink {
class RemoteRegistry;
class IRemoteNode;
}}

namespace {{qtNamespace .Module.Name }} {

/**
* Server side for {{.Interface.Name}} implements the {{.Interface.Name}} service.
* It is a source of data for {{.Interface.Name}} clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class {{$class}} : public QObject, public ApiGear::ObjectLink::IObjectSource
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param {{$interface}} The service source object, the actual {{$interface}} object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit {{$class}}(ApiGear::ObjectLink::RemoteRegistry& registry, Abstract{{Camel .Interface.Name}}* impl, QObject *parent = nullptr);
    virtual ~{{$class}}() = default;
public:
    /**
    * Collects all properties and their current values in the object.
    * @return a current state of properties in a nlohmann::json form.
    */
    nlohmann::json captureState();
    /**
    * Use to set a all or a subset of object properties to required values.
    * @param A set of properties and their values in a nlohmann::json form to set in the objects.
    */
    void applyState(const nlohmann::json& state);
    
    /**
    * IObjectSource::olinkObjectName implementation
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be unique for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;

    /**
    * IObjectSource::olinkInvoke
    * Applies received method invocation with given arguments on the {{$interface}} object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;

    /**
    * IObjectSource::olinkSetProperty 
    * Applies received change property request to {{$interface}} object.
    * @param name Path the property to change. Contains object name and the property name.
    * @param args Value in json format requested to set for the property.
    */
    void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override;

    /**
    * IObjectSource::olinkLinked
    * Informs this service source that the link was established.
    * @param name The name of the object for which link was established.
    * @param the initialized link endpoint.
    */
    void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode *node) override;

    /**
    * IObjectSource::olinkUnlinked
    * Informs this service source that the link was disconnected and cannot be used anymore.
    */
    void olinkUnlinked(const std::string& objectId) override;

    /**
    * IObjectSource::olinkCollectProperties
    * Gets the current state of {{$interface}} object.
    * @return the set of properties with their current values for the {{$interface}} object in json format.
    */
    nlohmann::json olinkCollectProperties() override;

private:
    /**
    * The actual implementation of a {{$interface}} that gets adapted to objectlink with {{$class}}.
    */
    Abstract{{Camel .Interface.Name}}* m_impl;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
};

} // namespace {{qtNamespace .Module.Name }}

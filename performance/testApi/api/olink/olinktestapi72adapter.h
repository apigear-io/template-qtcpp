/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "api/api/api.h"
#include "olink/iobjectsource.h"

namespace ApiGear {
namespace ObjectLink {
class RemoteRegistry;
class IRemoteNode;
}}

namespace api {

/**
* Server side for TestApi72 implements the TestApi72 service.
* It is a source of data for TestApi72 clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class OLinkTestApi72Adapter : public QObject, public ApiGear::ObjectLink::IObjectSource
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param TestApi72 The service source object, the actual TestApi72 object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit OLinkTestApi72Adapter(ApiGear::ObjectLink::RemoteRegistry& registry, AbstractTestApi72* impl, QObject *parent = nullptr);
    virtual ~OLinkTestApi72Adapter() = default;
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
    * Applies received method invocation with given arguments on the TestApi72 object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;

    /**
    * IObjectSource::olinkSetProperty 
    * Applies received change property request to TestApi72 object.
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
    * Gets the current state of TestApi72 object.
    * @return the set of properties with their current values for the TestApi72 object in json format.
    */
    nlohmann::json olinkCollectProperties() override;

private:
    /**
    * The actual implementation of a TestApi72 that gets adapted to objectlink with OLinkTestApi72Adapter.
    */
    AbstractTestApi72* m_impl;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
};

} // namespace api

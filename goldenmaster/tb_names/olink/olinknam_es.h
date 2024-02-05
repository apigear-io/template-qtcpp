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
#include <QtPromise>

#include "tb_names/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_names {

/**
* Adapts the general OLink Client handler to a Nam_Es in a way it provides access 
* to remote specific for Nam_Es services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect OLinkNam_Es to it.
* Use on client side to request changes of the Nam_Es on the server side 
* and to subscribe for the Nam_Es changes.
*/
class OLinkNam_Es : public AbstractNamEs, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit OLinkNam_Es(QObject *parent = nullptr);
    /** dtor */
    ~OLinkNam_Es() override = default;
    /**
    * Property getter
    * @return Locally stored recent value for Switch.
    */
    bool Switch() const override;
    /**
    * Request setting a property on the Nam_Es service.
    * @param The value to which set request is send for the Switch.
    */
    void setSwitch(bool Switch) override;
    /**
    * Property getter
    * @return Locally stored recent value for SomeProperty.
    */
    int SOME_PROPERTY() const override;
    /**
    * Request setting a property on the Nam_Es service.
    * @param The value to which set request is send for the SomeProperty.
    */
    void setSomeProperty(int SOME_PROPERTY) override;
    /**
    * Property getter
    * @return Locally stored recent value for SomePoperty2.
    */
    int Some_Poperty2() const override;
    /**
    * Request setting a property on the Nam_Es service.
    * @param The value to which set request is send for the SomePoperty2.
    */
    void setSomePoperty2(int Some_Poperty2) override;
    /**
    * Remote call of INamEs::SOME_FUNCTION on the Nam_Es service.
    * Uses SOME_FUNCTIONAsync
    */
    void someFunction(bool SOME_PARAM) override;
    /**
    * Remote call of INamEs::SOME_FUNCTION on the Nam_Es service.
    */
    QtPromise::QPromise<void> someFunctionAsync(bool SOME_PARAM);
    /**
    * Remote call of INamEs::Some_Function2 on the Nam_Es service.
    * Uses Some_Function2Async
    */
    void someFunction2(bool Some_Param) override;
    /**
    * Remote call of INamEs::Some_Function2 on the Nam_Es service.
    */
    QtPromise::QPromise<void> someFunction2Async(bool Some_Param);

signals:

    /**
    * Informs if the OLinkNam_Es is ready to send and receive messages.
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
    * @param props Initial values obtained from the Nam_Es service
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
    * @param the data received from Nam_Es service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Switch and informs subscriber about the change with emit property changed signal. */
    void setSwitchLocal(bool Switch);
    /** A local value for Switch */
    bool m_Switch;
    /**  Updates local value for SomeProperty and informs subscriber about the change with emit property changed signal. */
    void setSomePropertyLocal(int SOME_PROPERTY);
    /** A local value for SOME_PROPERTY */
    int m_SOME_PROPERTY;
    /**  Updates local value for SomePoperty2 and informs subscriber about the change with emit property changed signal. */
    void setSomePoperty2Local(int Some_Poperty2);
    /** A local value for Some_Poperty2 */
    int m_Some_Poperty2;
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the OLinkNam_Es.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace tb_names
